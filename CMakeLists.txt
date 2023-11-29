cmake_minimum_required(VERSION 3.20)

project(my-libc LANGUAGES C CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(MY_COMPANY_NAME "Infinite Technology Co., Ltd.")
option(USE_MYMATH "Use tutorial provided math implementation" ON)
option(BUILD_DYNAMIC_LIB "Build dynamic library" ON)
# enable_testing()

add_subdirectory(TimeWheel)
configure_file(my_libc_config.h.in ${CMAKE_BINARY_DIR}/my_libc_config.h)