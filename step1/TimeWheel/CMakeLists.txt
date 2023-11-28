# =========================== time wheel ===========================
file(GLOB TIME_WHEEL_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

set(LIB_NAME "time_wheel")
if (BUILD_DYNAMIC_LIB)
    add_library(${LIB_NAME} SHARED ${TIME_WHEEL_SOURCES})
    if (CMAKE_SYSTEM_NAME MATCHES "Windows")
        target_compile_definitions(${LIB_NAME} PRIVATE USE_DLL)
        target_compile_definitions(${LIB_NAME} PRIVATE EXPORT_DLL)
        set_target_properties(${LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    endif()
else()
    add_library(${LIB_NAME} STATIC ${TIME_WHEEL_SOURCES})
endif()

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# =========================== time wheel ===========================