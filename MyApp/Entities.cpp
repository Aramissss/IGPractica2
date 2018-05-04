#include "Entities.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Entity::render(dmat4 const& modelViewMat) 
{ 
	setMvM(modelViewMat); 
	draw(); 
}
//-------------------------------------------------------------------------

void Entity::draw() 
{ 
	material.load();
  if (mesh != nullptr) 
    mesh -> draw(); 
}
//-------------------------------------------------------------------------

void Entity::setMvM(dmat4 const& modelViewMat)
{
	glMatrixMode(GL_MODELVIEW);
	dmat4 aMat = modelViewMat * modelMat;
	glLoadMatrixd(value_ptr(aMat));
}
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(GLdouble l): Entity() 
{
  mesh = Mesh::generateAxesRGB(l);
}
//-------------------------------------------------------------------------

void EjesRGB::draw()
{
  glLineWidth(2);
  mesh->draw();
  glLineWidth(1);
}
//-------------------------------------------------------------------------
Triangulo::Triangulo(GLdouble r) : Entity()
{
	mesh = Mesh::generateTriangle(r);
}
//-------------------------------------------------------------------------

void Triangulo::draw()
{
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
}
//-------------------------------------------------------------------------
RectangleTex::RectangleTex(GLdouble w, GLdouble h) : Entity()
{
	
	mesh = Mesh::generateRectangleTex(w,h,1,1);
	texture.load("..\\Bmps\\chuches.bmp");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
}
//-------------------------------------------------------------------------

void RectangleTex::draw()
{
	
	texture.bind();
	mesh->draw();
	texture.unbind();
}

//-------------------------------------------------------------------------
TrianguloRGB::TrianguloRGB(GLdouble r) : Entity()
{
	mesh = Mesh::generateTriangleRGB(r);
}
//-------------------------------------------------------------------------

void TrianguloRGB::draw()
{
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
}
//-------------------------------------------------------------------------
TriPyramidTex::TriPyramidTex(GLdouble r, GLdouble h) : Entity()
{
	
	mesh = Mesh::generateTriPyramidTex(r, h);
	texture.load("..\\Bmps\\Zelda.bmp");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	
}
//-------------------------------------------------------------------------

void TriPyramidTex::draw()
{	
	texture.bind();
	mesh->draw();
	texture.unbind();
}

//-------------------------------------------------------------------------
TriPyramid::TriPyramid(GLdouble r, GLdouble h) : Entity()
{
	mesh = Mesh::generateTriPyramid(r,h);
}
//-------------------------------------------------------------------------

void TriPyramid::draw()
{
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
}

//-------------------------------------------------------------------------
ContCuboTex::ContCuboTex(GLdouble l) : Entity()
{
	mesh = Mesh::generateContCuboTex(l);
	texture.load("..\\Bmps\\emopng.bmp");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
//-------------------------------------------------------------------------

void ContCuboTex::draw()
{
	texture.bind();
	mesh->draw();
	texture.unbind();
}
//-------------------------------------------------------------------------
ContCubo::ContCubo(GLdouble l) : Entity()
{
	mesh = Mesh::generateContCubo(l);
}
//-------------------------------------------------------------------------

void ContCubo::draw()
{
	glLineWidth(2);
	mesh->draw();
	glLineWidth(1);
}
//-------------------------------------------------------------------------
Diabolo::Diabolo() : Entity()
{
	texture.load("..\\Bmps\\emopng.bmp");
	
	
}
//-------------------------------------------------------------------------

void Diabolo::draw()
{
	texture.bind();
	mesh->draw();
	texture.unbind();
}
//-------------------------------------------------------------------------
void Diabolo::rotateDiabolo(GLdouble& angle){	
	this->angle += angle;
}
void Diabolo::render(glm::dmat4 const& modelViewMat){
	glColor3d(0.4, 0.4, 0.4);
	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	dmat4 aMat = modelViewMat*modelMat;


	aMat = translate(aMat, dvec3(150.0, 30.0, 0));
	aMat = rotate(aMat, radians(angle), dvec3(0.0, 0.0, 1.0));
	glLoadMatrixd(value_ptr(aMat));
	mesh = Mesh::generateTriPyramidTex(40, 40);
	draw();

	aMat = rotate(aMat, radians(60.0), dvec3(0.0, 0.0, 1.0));
	glLoadMatrixd(value_ptr(aMat));
	mesh = Mesh::generateTriPyramidTex(40, 40);
	draw();

	
	aMat = translate(aMat, dvec3(0.0, 0.0, 80));
	glLoadMatrixd(value_ptr(aMat));
	mesh = Mesh::generateTriPyramidTex(40, -40);
	draw();
	

	aMat = rotate(aMat, radians(60.0), dvec3(0.0, 0.0, 1));
	glLoadMatrixd(value_ptr(aMat));
	mesh = Mesh::generateTriPyramidTex(40, -40);
	draw();


	

}

//-------------------------------------------------------------------------
Cubo::Cubo(){
	texture.load("..\\Bmps\\container2.bmp");
	texture2.load("..\\Bmps\\chuches.bmp");
}
void Cubo::draw()
{
	mesh->draw();
}
void Cubo::render(glm::dmat4 const& modelViewMat){

	glColor3d(0.4, 0.4, 0.2);
	glMatrixMode(GL_MODELVIEW);

	dmat4 aMat = modelViewMat * modelMat;
	mesh = Mesh::generateRectangleTex(100, 100, 0, 0);
	aMat = translate(aMat, dvec3(0, 137.5, 32.5));
	aMat = rotate(aMat, radians(40.0), dvec3(1.0, 0.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	texture.bind();
	draw();
	texture.unbind();

	glEnable(GL_CULL_FACE);
	aMat = modelViewMat * modelMat;
	mesh = Mesh::generateRectangleTex(100, 100, 0, 0);
	aMat = translate(aMat, dvec3(0, 0, 50));
	aMat = rotate(aMat, radians(90.0), dvec3(1.0, 0.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	texture.bind();
	glCullFace(GL_BACK);
	draw();
	texture.unbind();
	texture2.bind();
	glCullFace(GL_FRONT);
	draw();
	texture2.unbind();

	aMat = modelViewMat * modelMat;
	mesh = Mesh::generateContCuboTex(100);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	aMat = translate(aMat, dvec3(-50, 0, 0));
	glLoadMatrixd(value_ptr(aMat));
	texture.bind();
	glCullFace(GL_FRONT);
	draw();
	texture.unbind();
	texture2.bind();
	glCullFace(GL_BACK);
	draw();
	texture2.unbind();
	glDisable(GL_CULL_FACE);

}

Suelo::Suelo()
{
	texture.load("..\\Bmps\\baldosaC.bmp");
}

void Suelo::draw()
{
	texture.bind();
	mesh->draw();
	texture.unbind();
}

void Suelo::render(glm::dmat4 const& modelViewMat)
{
	glColor3d(0.4, 0.4, 0.4);
	glMatrixMode(GL_MODELVIEW);

	dmat4 aMat = modelViewMat * modelMat;
	mesh = Mesh::generateRectangleTex(1000, 1000, 5,5);
	aMat = rotate(aMat, radians(90.0), dvec3(1.0, 0.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	draw();
}

Grass::Grass()
{
	glm::ivec3 color = { 0, 0, 0 };
	texture.load("..\\Bmps\\grass.bmp", color,255);
}

void Grass::draw()
{
	texture.bind();
	mesh->draw();
	texture.unbind();
}

void Grass::render(glm::dmat4 const& modelViewMat)
{
	
	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glColor3d(0.4, 0.4, 0.2);
	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	dmat4 aMat = modelViewMat * modelMat;

	mesh = Mesh::generateRectangleTex(300, 300, 0, 0);
	aMat = translate(aMat, dvec3(-350.0, 150.0, 400.0));
	aMat = rotate(aMat, radians(45.0), dvec3(0.0, 1.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	draw();

	aMat = modelViewMat * modelMat;
	mesh = Mesh::generateRectangleTex(300, 300, 0, 0);
	aMat = translate(aMat, dvec3(-350.0, 150.0, 400.0));
	aMat = rotate(aMat, radians(135.0), dvec3(0.0, 1.0, 0.0));
	glLoadMatrixd(value_ptr(aMat));
	draw();

	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	
}

GrassPot::GrassPot()
{
	texture.load("..\\Bmps\\window.bmp", 100);
}

void GrassPot::draw()
{
	texture.bind();
	mesh->draw();
	texture.unbind();
}

void GrassPot::render(glm::dmat4 const& modelViewMat)
{
	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor3d(0.4, 0.4, 0.2);
	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	dmat4 aMat = modelViewMat * modelMat;

	mesh = Mesh::generateContCuboTex(325);
	aMat = translate(aMat, dvec3(-500.0, 0.0, 200.0));
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLoadMatrixd(value_ptr(aMat));
	draw();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	
}

Esfera::Esfera(GLfloat radius)
{
	//En la luz para cambiar la variable static hay que hacer      tipo  nombre::variable = loquesea    en el cpp
	texture.load("..\\datosP2\\mars.bmp");
	material.load();
	qobj = gluNewQuadric();
	radio = radius;
}

void Esfera::render(glm::dmat4 const & modelViewMat)
{
	dmat4 aMat = modelViewMat * modelMat;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(aMat));
	draw();
}

void Esfera::draw()
{			
	texture.bind();
	gluQuadricTexture(qobj, TRUE);
	gluSphere(qobj, radio, 32, 8);	
	texture.unbind();
}
