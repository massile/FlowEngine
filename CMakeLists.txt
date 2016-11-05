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

add_executable(FlowEngine
                src/Engine2D/graphics/shader.cpp src/Engine2D/graphics/shader.h
                src/Engine2D/utils/fileutils.h
                src/Engine2D/graphics/window.cpp src/Engine2D/graphics/window.h
                src/Engine2D/graphics/buffer/vertexBuffer.h src/Engine2D/graphics/buffer/vertexBuffer.cpp
                src/Engine2D/graphics/buffer/vertexArray.h src/Engine2D/graphics/buffer/vertexArray.cpp
                src/Engine2D/graphics/buffer/indexBuffer.h src/Engine2D/graphics/buffer/indexBuffer.cpp
                src/Engine2D/graphics/sprite.h src/Engine2D/graphics/sprite.cpp
                src/Engine2D/graphics/batchRenderer2d.h src/Engine2D/graphics/batchRenderer2d.cpp
                src/Engine2D/graphics/layers/layer.h src/Engine2D/graphics/layers/layer.cpp
                src/Engine2D/graphics/layers/tileLayer.h src/Engine2D/graphics/layers/tileLayer.cpp
                src/Engine2D/main.cpp)
target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine ${SOIL_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
