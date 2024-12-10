project(12101818)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoEncrypter.cpp src/VideoConfig.cpp src/CameraController.cpp src/VideoRecorder.cpp src/VideoStorage.cpp src/PolicemanInfo.cpp src/GpsInfo.cpp src/TimeManager.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:TimeManager,GpsInfo,PolicemanInfo,VideoStorage,VideoRecorder,CameraController,VideoConfig,VideoEncrypter,
# Specification Path: 

