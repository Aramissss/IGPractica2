#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>
#include <vector>
#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>
using namespace glm;
class Material
{
public:
	Material();
	~Material();
	fvec4 ambient,diffuse,specular;
	// coeficientes de reflexi�n
	GLfloat	expF;
	// exponente especular
	GLuint face =GL_FRONT_AND_BACK;
	// ambos lados
	GLuint sh = GL_SMOOTH;
	// smooth shading
	virtual	void load() {
		glMaterialfv(face,	GL_AMBIENT, value_ptr(ambient));
		//...
		glShadeModel(sh);
	};
};

