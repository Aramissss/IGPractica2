#include "Mesh.h"

using namespace glm;

//-------------------------------------------------------------------------

Mesh ::~Mesh(void) 
{
  delete[] vertices;
  delete[] colors;
}
//-------------------------------------------------------------------------

void Mesh::draw() 
{
  if (vertices != nullptr) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);  // number of coordinates per vertex, type of each coordinate 
    if (colors != nullptr) {
      glEnableClientState(GL_COLOR_ARRAY);
      glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate 
    }
	if (texCoords != nullptr){
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_DOUBLE, 0, texCoords);
	}
    glDrawArrays(type, 0, numVertices);   // kind of primitives, first, count

	  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
}
//-------------------------------------------------------------------------
Mesh * Mesh::generateTriangle(GLdouble r){
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLES;
	m->numVertices = 3;
	double PI = 3.14159265359;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(r*cos(0), r*sin(0), 0.0);
	m->vertices[1] = dvec3(r*cos(2*PI/3), r*sin(2*PI/3), 0);
	m->vertices[2] = dvec3(r*cos(4*PI/3), r*sin(4*PI/3), 0.0);



	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 0.0, 1.0, 1.0);
	m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	
	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generateTriangleRGB(GLdouble r){
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLES;
	m->numVertices = 3;
	double PI = 3.14159265359;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(r*cos(0), r*sin(0), 0.0);
	m->vertices[1] = dvec3(r*cos(2 * PI / 3), r*sin(2 * PI / 3), 0);
	m->vertices[2] = dvec3(r*cos(4 * PI / 3), r*sin(4 * PI / 3), 0.0);



	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 0.0, 1.0, 1.0);
	m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generateAxesRGB(GLdouble l)
{
  Mesh* m = new Mesh();
  m->type = GL_LINES;
  m->numVertices = 6;

  m->vertices = new dvec3[m->numVertices];
  m->vertices[0] = dvec3(0.0, 0.0, 0.0);   
  m->vertices[1] = dvec3(l, 0.0, 0);
  m->vertices[2] = dvec3(0, 0.0, 0.0);
  m->vertices[3] = dvec3(0.0, l, 0.0); 
  m->vertices[4] = dvec3(0.0, 0.0, 0.0);
  m->vertices[5] = dvec3(0.0, 0.0, l);

  m->colors = new dvec4[m->numVertices];
  m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[1] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[3] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[4] = dvec4(0.0, 0.0, 1.0, 1.0);
  m->colors[5] = dvec4(0.0, 0.0, 1.0, 1.0);
 
  return m; 
}
//-------------------------------------------------------------------------

Mesh * Mesh::generateTriPyramid(GLdouble r, GLdouble h){
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLE_FAN;
	m->numVertices = 6;
	double PI = 3.14159265359;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(0, 0, h);
	m->vertices[1] = dvec3(r*cos(0), r*sin(0), 0.0);
	m->vertices[2] = dvec3(r*cos(2 * PI / 3), r*sin(2 * PI / 3), 0);
	m->vertices[3] = dvec3(r*cos(4 * PI / 3), r*sin(4 * PI / 3), 0.0);
	m->vertices[4] = dvec3(r*cos(6 * PI / 3), r*sin(6 * PI / 3), 0);
	m->vertices[5] = dvec3(r*cos(0), r*sin(0), 0.0);



	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 0.0, 1.0, 1.0);
	m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[3] = dvec4(0.5, 0.5, 0.5, 1.0);
	m->colors[4] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[5] = dvec4(0.5, 0.5, 0.5, 1.0);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	return m;
}
//-------------------------------------------------------------------------

Mesh * Mesh::generateTriPyramidTex(GLdouble r, GLdouble h){
	Mesh* m = generateTriPyramid(r,h);

	double PI = 3.14159265359;

	m->texCoords = new dvec2[m->numVertices];

	m->texCoords[0] = dvec2(0.5, 1);
	m->texCoords[1] = dvec2(0, 0);
	m->texCoords[2] = dvec2(0.33, 0);
	m->texCoords[3] = dvec2(0.66, 0);
	m->texCoords[4] = dvec2(1, 0);
	m->texCoords[5] = dvec2(0, 0);

	return m;
}
//------------------------------------------------------------------------------
Mesh* Mesh::generateContCubo(GLdouble l){
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLE_STRIP;
	m->numVertices = 14;
	double PI = 3.14159265359;

/*	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(0.0, l, 0.0);	
	m->vertices[1] = dvec3(0.0,0.0, 0.0);
	m->vertices[2] = dvec3(l, l, 0.0);
	m->vertices[3] = dvec3(l, 0.0, 0.0);
	m->vertices[4] = dvec3(l, 0.0, l);
	m->vertices[5] = dvec3(0.0,0.0,0.0);
	m->vertices[6] = dvec3(0.0, 0.0, l);
	m->vertices[7] = dvec3(0.0,l,l);
	m->vertices[8] = dvec3(l, 0.0, l);
	m->vertices[9] = dvec3(l,l,l);
	m->vertices[10] = dvec3(l, l, 0.0);
	m->vertices[11] = dvec3(0.0, l, 0.0);
	m->vertices[12] = dvec3(l, l, l);
	m->vertices[13] = dvec3(0.0, l,l);*/

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(0.0, l, 0.0);
	m->vertices[1] = dvec3(0.0, 0.0, 0.0);
	m->vertices[2] = dvec3(l, l, 0.0);
	m->vertices[3] = dvec3(l, 0.0, 0.0);
	m->vertices[4] = dvec3(l, l, l);
	m->vertices[5] = dvec3(l, 0.0, l);
	m->vertices[6] = dvec3(0.0, l, l);
	m->vertices[7] = dvec3(0.0, 0.0, l);
	m->vertices[8] = dvec3(0.0, l, 0.0);
	m->vertices[9] = dvec3(0.0, 0.0, 0.0);



	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[3] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[4] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[5] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[6] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[7] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[8] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[9] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[10] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[11] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[12] = dvec4(0.0, 0.0, 0.0, 1.0);


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	return m;

}
Mesh* Mesh::generateContCuboTex(GLdouble l)
{
	Mesh* m = generateContCubo(l);

	m->texCoords = new dvec2[m->numVertices];

	m->texCoords[0] = dvec2(0, 1);
	m->texCoords[1] = dvec2(0, 0);
	m->texCoords[2] = dvec2(1, 1);
	m->texCoords[3] = dvec2(1, 0);
	m->texCoords[4] = dvec2(2, 1);
	m->texCoords[5] = dvec2(2, 0);
	m->texCoords[6] = dvec2(3, 1);
	m->texCoords[7] = dvec2(3, 0);
	m->texCoords[8] = dvec2(4, 1);
	m->texCoords[9] = dvec2(4, 0);
/*	m->texCoords[10] = dvec2(5, 1);
	m->texCoords[11] = dvec2(5, 0);
	m->texCoords[12] = dvec2(6, 1);
	m->texCoords[13] = dvec2(6, 0);*/

	return m;
}

Mesh* Mesh::generateRectangle(GLdouble w, GLdouble h)
{
	Mesh* m = new Mesh();
	m->type = GL_TRIANGLE_STRIP;
	m->numVertices = 4;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(-w / 2, h / 2, 0.0);
	m->vertices[1] = dvec3(-w / 2, -h / 2, 0.0);
	m->vertices[2] = dvec3(w / 2, h / 2, 0.0);
	m->vertices[3] = dvec3(w / 2, -h / 2, 0.0);


	m->colors = new dvec4[m->numVertices];
	m->colors[0] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 0.0, 1.0);
	m->colors[3] = dvec4(0.0, 0.0, 0.0, 1.0);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	return m;
}
Mesh* Mesh::generateRectangleTex(GLdouble w, GLdouble h, GLdouble rX, GLdouble rY){
	Mesh* m = generateRectangle(w, h);
	
	m->texCoords = new dvec2[m->numVertices];

	m->texCoords[0] = dvec2(0, 1+rY);
	m->texCoords[1] = dvec2(0 ,0);
	m->texCoords[2] = dvec2(1+rX, 1+rY);
	m->texCoords[3] = dvec2(1+rX,0);

	return m;
}