#include "Camera.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>
#include<math.h>

using namespace glm;

//-------------------------------------------------------------------------

 void Viewport::setSize(GLsizei aw, GLsizei ah) 
 { 
   w = aw; 
   h = ah; 
   set(); 
 }
 //-------------------------------------------------------------------------

 void Viewport::set() 
 { 
   glViewport(x, y, w, h);
 }
//-------------------------------------------------------------------------
 void Viewport::setPosition(GLint X, GLint Y){
	 x = X;
	 y = Y;
	 set();
 }

void Camera::setAZ() 
{
  eye= dvec3(0, 200, 500);
  look= dvec3(0, 0, 0);
  up= dvec3(0, 1, 0);
  right = normalize(cross(up, -front));
  viewMat = lookAt(eye, look, up);
  setVM();
}
//-------------------------------------------------------------------------

void Camera::set3D() 
{
  eye= dvec3(500, 500, 500);
  look= dvec3(0, 10, 0);
  up= dvec3(0, 1, 0);
  right = normalize(cross(up, -front));
  viewMat = lookAt(eye, look, up);
  setVM();
}
//-------------------------------------------------------------------------

void Camera::setVM() 
{
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixd(value_ptr(viewMat));
}
//-------------------------------------------------------------------------
void Camera::setPrj()
{
	if (orto){//Pasa a perspectiva
		nearVal = yTop;
		projMat = frustum(xLeft*factScale, xRight*factScale, yBot*factScale, yTop*factScale, nearVal, farVal);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixd(value_ptr(projMat));
		glMatrixMode(GL_MODELVIEW);
		orto = false;
		
	}
	else{//Pasa a ortogonal
		projMat = ortho(xLeft*factScale, xRight*factScale, yBot*factScale, yTop*factScale, nearVal, farVal);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixd(value_ptr(projMat));
		glMatrixMode(GL_MODELVIEW);
		orto = true;
	}
}
//-------------------------------------------------------------------------

void Camera::pitch(GLdouble a) 
{  
	rotatePY(a, 0);
  //viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(1.0, 0, 0));
}
//-------------------------------------------------------------------------
void Camera::yaw(GLdouble a)
{
	rotatePY(0, a);
  //viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(0, 1.0, 0));
}
//-------------------------------------------------------------------------
void Camera::roll(GLdouble a)
{
  viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(0, 0, 1.0));
}
//-------------------------------------------------------------------------

void Camera::scale(GLdouble s)
{ 
  factScale -= s; 
  if (s < 0) s = 0.01;
  setPM(); 
}
//-------------------------------------------------------------------------

void Camera::setSize(GLdouble aw, GLdouble ah) 
{
  xRight = aw / 2.0;
  xLeft = -xRight;
  yTop = ah / 2.0;
  yBot = -yTop;
 
  setPM();
}
//-------------------------------------------------------------------------

void Camera::setPM() 
{
  projMat = ortho(xLeft*factScale, xRight*factScale, yBot*factScale, yTop*factScale, nearVal, farVal);
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixd(value_ptr(projMat));
  glMatrixMode(GL_MODELVIEW);
}
//-------------------------------------------------------------------------
void Camera::moveLR(GLdouble cs)
{
	eye = eye + (right * cs);
	look = look + (right * cs);
	viewMat = lookAt(eye, look, up);

}
//-------------------------------------------------------------------------
void Camera::moveFB(GLdouble cs)
{
	eye = eye + (front * cs);
	viewMat = lookAt(eye, eye + front, up);
}
//-------------------------------------------------------------------------
void Camera::moveUD(GLdouble cs)
{
	eye = eye + (up * cs);
	look = look + (up * cs);
	viewMat = lookAt(eye, look, up);
}

void Camera::rotatePY(GLdouble incrPitch, GLdouble incrYaw)
{
	Pitch += incrPitch; Yaw += incrYaw; // Actualizar los ángulos
	if (Pitch > 89.5) Pitch = 89.5; // Limitar los ángulos
	else if (Pitch < -89.5) Pitch = -89.5;
	if (Yaw > 89.5) Yaw = 89.5; // Limitar los ángulos
	else if (Yaw < -89.5) Yaw = -89.5;
		// Actualizar la dirección de vista
	front.x = sin(radians(Yaw)) * cos(radians(Pitch));
	front.y = sin(radians(Pitch));
	front.z = -cos(radians(Yaw)) * cos(radians(Pitch));
	front = glm::normalize(front);
	viewMat = lookAt(eye, eye + front, up);
}


