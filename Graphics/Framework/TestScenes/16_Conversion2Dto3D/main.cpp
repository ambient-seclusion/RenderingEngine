#pragma comment(lib, "nclgl.lib")
#pragma comment(lib, "glu32.lib")

#include "./GraphicsFramework/window.h"
#include "Renderer.h"

int main() {
	Window w("3D to 2D Projection!", 1280,960,false);
	if(!w.HasInitialised()) {
		return -1;
	}

	Renderer renderer(w);
	if(!renderer.HasInitialised()) {
		return -1;
	}

	w.LockMouseToWindow(true);
	w.ShowOSPointer(false);

	while(w.UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)){
		renderer.UpdateScene(w.GetTimer()->GetTimedMS());
		renderer.RenderScene();
	}

	return 0;
}