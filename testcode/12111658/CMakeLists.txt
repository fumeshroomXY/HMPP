project(12111658)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoEncrypter.cpp src/VideoRecorder.cpp src/VideoStorage.cpp src/VideoConfig.cpp src/PolicemanInfo.cpp src/CameraController.cpp src/GpsInfo.cpp src/TimeManager.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:TimeManager,GpsInfo,CameraController,PolicemanInfo,VideoConfig,VideoStorage,VideoRecorder,VideoEncrypter,
# Specification Path: 

