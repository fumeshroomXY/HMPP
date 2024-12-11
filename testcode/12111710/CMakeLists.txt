project(12111710)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoConfig.cpp src/VideoRecorder.cpp src/CameraController.cpp src/PolicemanInfo.cpp src/TimeManager.cpp src/VideoEncrypter.cpp src/GpsInfo.cpp src/VideoStorage.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass: 
# Specification Path: 

