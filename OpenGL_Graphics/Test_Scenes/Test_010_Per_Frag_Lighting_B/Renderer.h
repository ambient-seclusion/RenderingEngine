#pragma once

#include <OGLRenderer.h>
#include <Camera.h>
#include <HeightMap.h>

class Renderer : public OGLRenderer {
public:
	Renderer(Window &parent);
	virtual ~Renderer(void);

	virtual void RenderScene();
	virtual void UpdateScene(float msec);

protected:
	void DrawHeightmap();
	void DrawWater();
	void DrawGrass(float xoff, float zoff);
	void DrawSkybox();

	Shader* lightShader;
	Shader* reflectShader;
	Shader*	grassShader;
	Shader* skyboxShader;

	HeightMap* heightMap;
	Mesh*      quad;
	Mesh*      quadGrass;
	Light*     light;
	Camera*    camera;

	GLuint     cubeMap;
	float      waterRotate;
};