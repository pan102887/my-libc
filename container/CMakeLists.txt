# =============================== container lib ===============================
set(LIB_NAME "my_container_lib")
set(LIB_VERSION_MAJOR 0)
set(LIB_VERSION_MINOR 1)
set(LIB_VERSION_PATCH 0)

file(GLOB LIB_SOURCES
    ${CMAKE_SOURCE_DIR}/common/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

if(BUILD_DYNAMIC_LIB)
    add_library(${LIB_NAME} SHARED ${LIB_SOURCES})

    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        target_compile_definitions(${LIB_NAME} PRIVATE USE_DLL)
        target_compile_definitions(${LIB_NAME} PRIVATE EXPORT_DLL)
        set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    endif()
else()
    add_library(${LIB_NAME} STATIC ${LIB_SOURCES})
endif()

target_include_directories(${LIB_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_SOURCE_DIR}/common
)

# =============================== container lib ===============================