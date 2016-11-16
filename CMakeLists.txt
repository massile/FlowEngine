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
        src/graphics/Shader.cpp src/graphics/Shader.h
        src/utils/FileUtils.h
        src/graphics/Window.cpp src/graphics/Window.h
        src/graphics/buffer/VertexBuffer.h src/graphics/buffer/VertexBuffer.cpp
        src/graphics/buffer/VertexArray.h src/graphics/buffer/VertexArray.cpp
        src/graphics/buffer/IndexBuffer.h src/graphics/buffer/IndexBuffer.cpp
        src/graphics/Sprite.h src/graphics/Sprite.cpp
        src/graphics/Renderer2d.h src/graphics/Renderer2d.cpp
        src/graphics/Sprite.h src/graphics/Sprite.cpp
        src/graphics/BatchRenderer2d.h src/graphics/BatchRenderer2d.cpp
        src/graphics/layers/Layer2D.h src/graphics/layers/Layer2D.cpp
        src/graphics/layers/Group.h src/graphics/layers/Group.cpp
        src/graphics/Texture.h src/graphics/Texture.cpp
        src/Flow.h src/Flow.cpp
        src/graphics/TextureManager.cpp src/graphics/TextureManager.h
        src/graphics/Mask.h src/utils/Math.h
        src/factories/MeshFactory.cpp src/factories/MeshFactory.h
        src/graphics/FrameBuffer.cpp src/graphics/FrameBuffer.h
        src/graphics/PostEffect.cpp src/graphics/PostEffect.h
        src/graphics/PostEffectPass.cpp src/graphics/PostEffectPass.h
        src/events/Event.cpp src/events/Event.h
        src/events/IEventListener.h src/events/KeyEvent.cpp src/events/KeyEvent.h
        src/events/KeyEvent.cpp src/events/KeyEvent.h
        src/events/MouseEvent.cpp src/events/MouseEvent.h
        src/api/API.cpp src/api/API.h
        src/graphics/IRenderer.h src/graphics/Renderer3d.h
        src/graphics/Mesh.cpp src/graphics/Mesh.h
        src/graphics/Vertex.h src/graphics/Scene.cpp src/graphics/Scene.h
        src/graphics/layers/Layer2D.h src/graphics/layers/Layer3D.cpp
        src/graphics/layers/Layer3D.h src/graphics/layers/Layer.h
        src/graphics/ForwardRenderer.cpp src/graphics/ForwardRenderer.h src/graphics/IRenderable.h)

add_definitions(-Dinterface=class)

target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine ${SOIL_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
