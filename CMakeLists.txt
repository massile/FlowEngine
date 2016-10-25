cmake_minimum_required(VERSION 3.6)
project(FlowEngine)

# Use C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GLEW REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(FlowEngine src/main.cpp src/ui/Window.cpp src/ui/Window.h)
target_link_libraries(FlowEngine ${GLEW_LIBRARIES})
target_link_libraries(FlowEngine ${OPENGL_gl_LIBRARY})
target_link_libraries(FlowEngine glfw ${GLFW_LIBRARIES})
