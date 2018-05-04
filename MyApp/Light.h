#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

class Light
{
	static GLuint cont;
	GLuint id = GL_MAX_LIGHTS;
	Light() {
		if (cont < GL_MAX_LIGHTS) {
			id = GL_LIGHT0 + cont;
			++cont;
			glEnable(id);
		}
	};
	~Light() {
		disable();
	};
	void disable() {
		if (id < GL_LIGHT0 + GL_MAX_LIGHTS) {
			glDisable(id);
		} 
	}
	void disable() {
		if (id < GL_LIGHT0 + GL_MAX_LIGHTS) {
			glEnable(id);
		}
	}
	GLuint id  =	GL_MAX_LIGHTS;//GL_LIGHT i	
	glm::fvec4 ambient ={ 0.1, 0.1, 0.1, 1 };
	glm::fvec4	diffuse ={ 0.5, 0.5, 0.5, 1 };
	glm::fvec4	specular ={ 0.5, 0.5, 0.5, 1 };
public:
	virtual void load()
	{			
		glLightfv(	id	, GL_AMBIENT,value_ptr(ambient));
		glLightfv(id, GL_DIFFUSE,value_ptr(diffuse));
		glLightfv(id, GL_SPECULAR,value_ptr(specular));
	};
	void setAmb	(glm::fvec4 amb);
};

