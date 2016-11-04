#include <iostream>

#include "graphics/Shader.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"

#include "components/input/CameraInputComponent.h"
#include "components/input/LightInputComponent.h"
#include "components/physics/CameraPhysicsComponent.h"
#include "components/shader/CameraShaderComponent.h"
#include "components/shader/LightShaderComponent.h"
#include "services/environment/Environment.h"
#include "components/graphics/MeshGraphicsComponent.h"
#include "providers/AppProvider.h"

int main()
{
    AppProvider provider = AppProvider();
    provider.record();

    Shader* shader = Environment::getWorld()->getShader("shader");

    Camera* cam = new Camera(
        new CameraInputComponent(),
        new CameraPhysicsComponent(),
        new CameraShaderComponent()
    );

    Light light(
        new LightInputComponent(),
        nullptr,
        new LightShaderComponent()
    );

    Object rock(
        nullptr,
        nullptr,
        nullptr,
        new MeshGraphicsComponent()
    );

    provider.registerCamera(cam);
    provider.registerLight(light);
    provider.registerPerFrame(rock);

    provider.run(*shader);

 	return 0;
}