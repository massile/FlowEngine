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
                src/Engine2D/graphics/shader.cpp src/Engine2D/graphics/shader.h
                src/Engine2D/utils/fileutils.h
                src/Engine2D/graphics/window.cpp src/Engine2D/graphics/window.h
                src/Engine2D/graphics/buffer/vertexBuffer.h src/Engine2D/graphics/buffer/vertexBuffer.cpp
                src/Engine2D/graphics/buffer/vertexArray.h src/Engine2D/graphics/buffer/vertexArray.cpp
                src/Engine2D/graphics/buffer/indexBuffer.h src/Engine2D/graphics/buffer/indexBuffer.cpp
                src/Engine2D/graphics/sprite.h src/Engine2D/graphics/sprite.cpp
                src/Engine2D/graphics/renderer2d.h src/Engine2D/graphics/renderer2d.cpp
                src/Engine2D/graphics/renderable2d.h src/Engine2D/graphics/renderable2d.cpp
                src/Engine2D/graphics/batchRenderer2d.h src/Engine2D/graphics/batchRenderer2d.cpp
                src/Engine2D/graphics/layers/layer.h src/Engine2D/graphics/layers/layer.cpp
                src/Engine2D/graphics/layers/group.h src/Engine2D/graphics/layers/group.cpp
                src/Engine2D/graphics/texture.h src/Engine2D/graphics/texture.cpp
                src/Engine2D/flow.h src/Engine2D/flow.cpp
                src/Engine2D/graphics/textureManager.cpp src/Engine2D/graphics/textureManager.h
                src/Engine2D/graphics/mask.h src/Engine2D/utils/math.h
                src/Engine2D/factories/MeshFactory.cpp src/Engine2D/factories/MeshFactory.h
                src/Engine2D/graphics/frameBuffer.cpp src/Engine2D/graphics/frameBuffer.h
                src/Engine2D/graphics/PostEffect.cpp src/Engine2D/graphics/PostEffect.h
                src/Engine2D/graphics/PostEffectPass.cpp src/Engine2D/graphics/PostEffectPass.h
                src/Engine2D/events/Event.cpp src/Engine2D/events/Event.h
                src/Engine2D/events/IEventListener.h src/Engine2D/events/KeyEvent.cpp src/Engine2D/events/KeyEvent.h
                src/Engine2D/events/KeyEvent.cpp src/Engine2D/events/KeyEvent.h
                src/Engine2D/events/MouseEvent.cpp src/Engine2D/events/MouseEvent.h)

add_definitions(-Dinterface=class)

target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine ${SOIL_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
