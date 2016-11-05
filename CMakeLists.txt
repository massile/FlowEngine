cmake_minimum_required(VERSION 3.6)
project(FlowEngine)

# Compile in current directory, in the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Use C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GLEW REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_library(SOIL_LIBRARY SOIL REQUIRED)

add_library(FlowEngine SHARED src/services/ui/window/Window.cpp src/services/ui/window/Window.h src/graphics/Shader.cpp src/graphics/Shader.h src/parse/File.cpp src/parse/File.h src/graphics/Mesh.cpp src/graphics/Mesh.h src/graphics/Texture.cpp src/graphics/Texture.h src/graphics/Camera.h src/parse/Parser.h src/parse/ObjParser.cpp src/parse/ObjParser.h src/graphics/Light.h src/services/ui/window/IWindow.h src/services/ui/Ui.cpp src/services/ui/Ui.h src/services/input/keyboard/Keyboard.cpp src/services/input/keyboard/Keyboard.h src/services/input/mouse/Mouse.cpp src/services/input/mouse/Mouse.h src/services/input/mouse/IMouse.h src/services/input/Input.cpp src/services/input/Input.h src/components/input/InputComponent.h src/components/shader/ShaderComponent.h src/graphics/Object.cpp src/graphics/Object.h src/components/shader/CameraShaderComponent.cpp src/components/shader/CameraShaderComponent.h src/components/shader/LightShaderComponent.cpp src/components/shader/LightShaderComponent.h src/services/environment/Environment.h src/services/environment/Environment.cpp src/services/environment/graphics/Graphics.cpp src/services/environment/graphics/Graphics.h src/providers/Provider.cpp)
target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine ${SOIL_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
