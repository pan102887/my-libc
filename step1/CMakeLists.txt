cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME Tutorial)

project(${PROJECT_NAME} LANGUAGES C CXX VERSION 0.1.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(USE_MYMATH "Use tutorial provided math implementation" ON)
option(BUILD_DYNAMIC_LIB "Build dynamic library" ON)

add_subdirectory(MathFunctions)

add_executable(${PROJECT_NAME} tutorial.cpp)
configure_file(project_config.h.in ${PROJECT_SOURCE_DIR}/include/project_config.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE MathFunctions)