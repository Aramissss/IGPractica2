#include "Scene.h"

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
  glEnable(GL_DEPTH_TEST); 
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glEnable(GL_CULL_FACE);

  
  camera->setAZ();
  aux = 1;
    
  // lights
  // textures  

  // objets
 
  //objetos.push_back(new TriPyramidTex(100,100));
  //objetos.push_back(new RectangleTex(100,100));;
  //objetos.push_back(new ContCubo(100));
  //objetos.push_back(new ContCuboTex(100));
  /*objetos.push_back(new Diabolo());

  objetos.push_back(new Suelo());
  objetos.push_back(new Cubo());
  objetos.push_back(new Grass());
  objetos.push_back(new GrassPot());
*/

  objetos.push_back(new Esfera(50));

  dmat4 aMat = camera->getViewMat() * 1.0 ;
  aMat = translate(aMat, dvec3(-50.0, 0.0, 0.0));
  Material m;
  objetos[0]->setModelMat(aMat);
  objetos[0]->setMaterial(m);

  objetos.push_back(new Esfera(80));

  aMat = camera->getViewMat() * 1.0;
  aMat = translate(aMat, dvec3(150.0, 0.0, 0.0));
  objetos[1]->setModelMat(aMat);

  objetos.push_back(new Esfera(60));

  aMat = camera->getViewMat() * 1.0;
  aMat = translate(aMat, dvec3(0.0, 100.0, 0.0));
  objetos[2]->setModelMat(aMat);


}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources 
  
  for each (Entity* it in objetos)
  {
	  delete it;
  }
  glDisable(GL_TEXTURE_2D);
}
//-------------------------------------------------------------------------

void Scene::render()
{
	  glMatrixMode(GL_MODELVIEW);


	  for (int i = 0; i < objetos.size(); i++){
		  camera->getVP()->setPosition(0, 0);
			objetos[i]->render(camera->getViewMat());
	  }

	  
	  //static_cast<Diabolo*>(objetos[3])->render(camera->getViewMat());
	/*for each (Entity* it in objetos)
	{
		it->render(camera->getViewMat());
	}*/
}
//-------------------------------------------------------------------------
void Scene::rotateDiabolo(GLdouble angle){
	//static_cast<Diabolo*>(objetos[0])->rotateDiabolo(angle);
}
