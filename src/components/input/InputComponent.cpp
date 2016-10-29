#include "InputComponent.h"
#include "../../services/input/keyboard/Keyboard.h"
#include "../../services/input/Input.h"
#include "../../graphics/Camera.h"

void InputComponent::update(Camera &camera, float dt)
{
    using namespace glm;

    GLfloat speed = 8.0f * dt;
    vec3 velocity = camera.getVelocity();

    IKeyboard* keyboard = Input::getKeyboard();
    if(keyboard->isKeyPressed('W'))
        velocity = vec3(0, 0, speed);
    if(keyboard->isKeyPressed('S'))
        velocity = vec3(0, 0, -speed);
    if(keyboard->isKeyPressed('D'))
        velocity = vec3(speed, 0, 0);
    if(keyboard->isKeyPressed('A'))
        velocity = vec3(-speed, 0, 0);
    if(keyboard->isKeyPressed(GLFW_KEY_SPACE))
        velocity = vec3(0, speed, 0);

    camera.setVelocity(velocity);

    vec2 offset = m_sensitivity * Input::getMouse()->getCursorPositionOffset();
    GLfloat yaw = camera.getYaw();
    GLfloat pitch = camera.getPitch();

    camera.setYaw(yaw + dt * offset.x);
    camera.setPitch(pitch + dt * offset.y);

    vec3 front = vec3(
            cos(radians(yaw)) * cos(radians(pitch)),
            sin(radians(pitch)),
            sin(radians(yaw)) * cos(radians(pitch))
    );

    camera.setFront(normalize(front));
    camera.lookAt(camera.getPosition() + camera.getFront());
}
