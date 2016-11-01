#include "LightInputComponent.h"
#include "../../graphics/Light.h"
#include "../../services/input/keyboard/IKeyboard.h"
#include "../../services/input/Input.h"

void LightInputComponent::update(Object* object, float dt)
{
    using namespace glm;
    Light* light = static_cast<Light*>(object);

    GLfloat speed = 5.0f * dt;

    IKeyboard* keyboard = Input::getKeyboard();
    if(keyboard->isKeyPressed('I'))
        light->translate(vec3(0, speed, 0));
    if(keyboard->isKeyPressed('K'))
        light->translate(vec3(0, -speed, 0));
    if(keyboard->isKeyPressed('J'))
        light->translate(vec3(speed, 0, 0));
    if(keyboard->isKeyPressed('L'))
        light->translate(vec3(-speed, 0, 0));
    if(keyboard->isKeyPressed('O'))
        light->translate(vec3(0, 0, speed));
    if(keyboard->isKeyPressed('U'))
        light->translate(vec3(0, 0, -speed));
}
