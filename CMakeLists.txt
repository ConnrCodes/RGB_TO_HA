cmake_minimum_required(VERSION 3.16)
project(RGBToHA VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform-specific settings
if(WIN32)
    set(PLATFORM "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
    set(OUTPUT_SUFFIX "-pxm.dll")
    set(UNIVERSAL_OUTPUT "RGBToHA-Universal.zip")
elseif(APPLE)
    set(PLATFORM "macOS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
    set(OUTPUT_SUFFIX "-pxm.dylib")
    set(UNIVERSAL_OUTPUT "RGBToHA-Universal.zip")
    
    # Enable universal binary support for Intel + Apple Silicon
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15")
else()
    set(PLATFORM "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
    set(OUTPUT_SUFFIX "-pxm.so")
    set(UNIVERSAL_OUTPUT "RGBToHA-Universal.zip")
endif()

# Find Qt5/6
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
if(NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
endif()

# PixInsight SDK paths (adjust these for your installation)
if(WIN32)
    set(PIXINSIGHT_SDK_PATH "C:/PCL/src")
    set(PIXINSIGHT_INCLUDE_PATH "C:/PCL/src/include")
    set(PIXINSIGHT_LIB_PATH "C:/PCL/src/lib")
elseif(APPLE)
    set(PIXINSIGHT_SDK_PATH "/Applications/PixInsight/PCL/src")
    set(PIXINSIGHT_INCLUDE_PATH "/Applications/PixInsight/PCL/src/include")
    set(PIXINSIGHT_LIB_PATH "/Applications/PixInsight/PCL/src/lib")
else()
    set(PIXINSIGHT_SDK_PATH "/opt/PixInsight/PCL/src")
    set(PIXINSIGHT_INCLUDE_PATH "/opt/PixInsight/PCL/src/include")
    set(PIXINSIGHT_LIB_PATH "/opt/PixInsight/PCL/src/lib")
endif()

# Include directories
include_directories(
    ${PIXINSIGHT_INCLUDE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Source files
set(SOURCES
    RGBToHAProcess.cpp
    RGBToHAInterface.cpp
    RGBToHAModule.cpp
)

# Create shared library
add_library(RGBToHA SHARED ${SOURCES})

# Set output name
set_target_properties(RGBToHA PROPERTIES
    OUTPUT_NAME "RGBToHA${OUTPUT_SUFFIX}"
    PREFIX ""
)

# Link libraries
target_link_libraries(RGBToHA
    Qt::Core
    Qt::Widgets
    ${PIXINSIGHT_LIB_PATH}/pcl
)

# Compiler-specific flags
if(MSVC)
    target_compile_options(RGBToHA PRIVATE /W3)
else()
    target_compile_options(RGBToHA PRIVATE -Wall -Wextra)
endif()

# Installation
install(TARGETS RGBToHA
    LIBRARY DESTINATION "PixInsight/modules"
    RUNTIME DESTINATION "PixInsight/modules"
)

# Create universal package
if(WIN32 OR APPLE)
    # Create universal package with all architectures
    add_custom_target(universal_package ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/universal
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:RGBToHA> ${CMAKE_BINARY_DIR}/universal/
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/README.md ${CMAKE_BINARY_DIR}/universal/
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/LICENSE ${CMAKE_BINARY_DIR}/universal/
        COMMAND ${CMAKE_COMMAND} -E tar "cf" ${CMAKE_BINARY_DIR}/${UNIVERSAL_OUTPUT} --format=zip ${CMAKE_BINARY_DIR}/universal/
        DEPENDS RGBToHA
        COMMENT "Creating universal package: ${UNIVERSAL_OUTPUT}"
    )
endif()

# Print configuration info
message(STATUS "Building RGB to HA Conversion Plugin")
message(STATUS "Platform: ${PLATFORM}")
message(STATUS "Output: RGBToHA${OUTPUT_SUFFIX}")
message(STATUS "Universal Package: ${UNIVERSAL_OUTPUT}")
message(STATUS "PixInsight SDK: ${PIXINSIGHT_SDK_PATH}")

if(APPLE)
    message(STATUS "Universal Binary: Intel x86_64 + Apple Silicon arm64")
endif() 