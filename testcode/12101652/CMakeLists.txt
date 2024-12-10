project(12101652)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/GpsInfo.cpp src/VideoConfig.cpp src/VideoStorage.cpp src/TimeManager.cpp src/VideoEncrypter.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass: 
# Specification Path: 

