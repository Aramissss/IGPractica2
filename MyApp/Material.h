#pragma once
class Material
{
public:
	Material();
	~Material();
	fvec4 ambient,diffuse,specular;
	// coeficientes de reflexión
	GLfloat	expF;
	// exponente especular
	GLuint face =GL_FRONT_AND_BACK;
	// ambos lados
	GLuint sh = GL_SMOOTH;
	// smooth shading
	virtual	void load() {
		glMaterialfv(face,	GL_AMBIENT, value_ptr(ambient));
		//Faltan cosas aquí xd
		glShadeModel(sh);
	};
};

