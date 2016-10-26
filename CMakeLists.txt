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

add_executable(FlowEngine src/main.cpp src/ui/Window.cpp src/ui/Window.h src/graphics/Shader.cpp src/graphics/Shader.h src/parse/File.cpp src/parse/File.h src/graphics/Mesh.cpp src/graphics/Mesh.h src/graphics/Texture.cpp src/graphics/Texture.h)
target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine ${SOIL_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
