//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"
//-------------------------------------------------------------------------

class Entity 
{
public:
  Entity() : modelMat(1.0) { };
  virtual ~Entity() { delete mesh; };

  virtual void render(glm::dmat4 const& modelViewMat);
  void  setModelMat( glm::dmat4  const& mMat) {  modelMat =  mMat;  }
  void  setMaterial(  Material  const& mt) { material = mt;}
  void  setTexture(	  Texture  const&  tex  ) {  texture  = tex; };
  
protected:
	Texture texture;
	Texture texture2;
	Material material;
	Mesh* mesh = nullptr;
	glm::dmat4 modelMat;
	virtual void draw();
	virtual void setMvM(glm::dmat4 const& modelViewMat);
};

//-------------------------------------------------------------------------

class EjesRGB : public Entity 
{
public:
  EjesRGB(GLdouble l);
  ~EjesRGB() { };
  virtual void draw();
};

//-------------------------------------------------------------------------

class Triangulo : public Entity
{
public:
	Triangulo(GLdouble r);
	~Triangulo(){};
	virtual void draw();
};

//-------------------------------------------------------------------------

class TrianguloRGB : public Entity
{
public:
	TrianguloRGB(GLdouble r);
	~TrianguloRGB(){};
	virtual void draw();
};

//-------------------------------------------------------------------------

class RectangleTex : public Entity
{
public:
	RectangleTex(GLdouble w, GLdouble h);
	~RectangleTex(){};
	virtual void draw();
};

//-------------------------------------------------------------------------
class TriPyramid : public Entity
{
public:
	TriPyramid(GLdouble r, GLdouble h);
	~TriPyramid(){};
	virtual void draw();
};
//-------------------------------------------------------------------------
class TriPyramidTex : public Entity
{
public:
	TriPyramidTex(GLdouble r, GLdouble h);
	~TriPyramidTex(){};
	virtual void draw();
};


//-------------------------------------------------------------------------
class ContCubo : public Entity
{
public:
	ContCubo(GLdouble l);
	~ContCubo(){};
	virtual void draw();
};

//-------------------------------------------------------------------------
class ContCuboTex : public Entity
{
public:
	ContCuboTex(GLdouble l);
	~ContCuboTex(){};
	virtual void draw();
};
//-------------------------------------------------------------------------
class Diabolo : public Entity
{
public:
	Diabolo();
	void render(glm::dmat4 const& modelViewMat);
	void rotateDiabolo(GLdouble& angle);
	GLdouble angle=0;
	~Diabolo(){};
	virtual void draw();
};
class Cubo : public Entity
{
public:
	Cubo();
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
	~Cubo(){};
};

class Suelo : public Entity
{
public:
	Suelo();
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
	~Suelo(){};
};

class Grass : public Entity
{
public:
	Grass();
	~Grass(){}
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
};

class GrassPot : public Entity
{
public:
	GrassPot();
	~GrassPot(){}
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
};
class Esfera : public Entity
{
public:
	Esfera(GLfloat radius, GLfloat posX, GLfloat posY, GLfloat posZ);
	~Esfera() {};
	void render(glm::dmat4 const& modelViewMat);
	virtual void draw();
	GLUquadricObj* qobj;
	GLfloat radio;
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

#endif //_H_Entities_H_