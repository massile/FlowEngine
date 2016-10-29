#include "CameraInputComponent.h"
#include "../../graphics/Camera.h"
#include "../../services/input/keyboard/IKeyboard.h"
#include "../../services/input/Input.h"

void CameraInputComponent::update(Object* object, float dt)
{
    using namespace glm;
    Camera* camera = static_cast<Camera*>(object);

    GLfloat speed = 5.0f * dt;

    IKeyboard* keyboard = Input::getKeyboard();
    if(keyboard->isKeyPressed('W'))
        camera->setVelocityLocal(vec3(0, 0, speed));
    if(keyboard->isKeyPressed('S'))
        camera->setVelocityLocal(vec3(0, 0, -speed));
    if(keyboard->isKeyPressed('A'))
        camera->setVelocityLocal(vec3(speed, 0, 0));
    if(keyboard->isKeyPressed('D'))
        camera->setVelocityLocal(vec3(-speed, 0, 0));
    if(keyboard->isKeyPressed(GLFW_KEY_SPACE))
        camera->setVelocityLocal(vec3(0, speed, 0));

    camera->translate(camera->getVelocity());

    vec2 offset = SENSITIVITY * Input::getMouse()->getCursorPositionOffset();
    GLfloat yaw = camera->getYaw();
    GLfloat pitch = camera->getPitch();

    camera->setYaw(yaw + dt * offset.x);
    camera->setPitch(pitch + dt * offset.y);

    yaw = camera->getYaw();
    pitch = camera->getPitch();
    vec3 front = vec3(
            cos(radians(yaw)) * cos(radians(pitch)),
            sin(radians(pitch)),
            sin(radians(yaw)) * cos(radians(pitch))
    );

    camera->setFront(normalize(front));
    camera->lookAt(camera->getPosition() + camera->getFront());

}
