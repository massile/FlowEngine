cmake_minimum_required(VERSION 3.6)
project(FlowEngine)

# Compile in current directory, in the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Use C++ 11
set(CMAKE_CXX_FLAGS "-O3 -std=c++11")
set(CMAKE_BUILD_TYPE Release)

find_package(GLEW REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_library(SOIL_LIBRARY SOIL REQUIRED)

add_library(FlowEngine STATIC
                src/graphics/shader.cpp src/graphics/shader.h
                src/utils/fileutils.h
                src/graphics/window.cpp src/graphics/window.h
                src/graphics/buffer/vertexBuffer.h src/graphics/buffer/vertexBuffer.cpp
                src/graphics/buffer/vertexArray.h src/graphics/buffer/vertexArray.cpp
                src/graphics/buffer/indexBuffer.h src/graphics/buffer/indexBuffer.cpp
                src/graphics/sprite.h src/graphics/sprite.cpp
                src/graphics/renderer2d.h src/graphics/renderer2d.cpp
                src/graphics/renderable2d.h src/graphics/renderable2d.cpp
                src/graphics/batchRenderer2d.h src/graphics/batchRenderer2d.cpp
                src/graphics/layers/layer.h src/graphics/layers/layer.cpp
                src/graphics/layers/group.h src/graphics/layers/group.cpp
                src/graphics/texture.h src/graphics/texture.cpp
                src/flow.h src/flow.cpp
                src/graphics/textureManager.cpp src/graphics/textureManager.h
                src/graphics/mask.h src/utils/math.h
                src/factories/MeshFactory.cpp src/factories/MeshFactory.h
                src/graphics/frameBuffer.cpp src/graphics/frameBuffer.h
                src/graphics/PostEffect.cpp src/graphics/PostEffect.h
                src/graphics/PostEffectPass.cpp src/graphics/PostEffectPass.h
                src/events/Event.cpp src/events/Event.h
                src/events/IEventListener.h src/events/KeyEvent.cpp src/events/KeyEvent.h
                src/events/KeyEvent.cpp src/events/KeyEvent.h
                src/events/MouseEvent.cpp src/events/MouseEvent.h
                src/api/API.cpp src/api/API.h)

add_definitions(-Dinterface=class)

target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine ${SOIL_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
