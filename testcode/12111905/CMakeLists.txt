project(12111905)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/GpsInfo.cpp src/VideoEncrypter.cpp src/PolicemanInfo.cpp src/VideoStorage.cpp src/VideoConfig.cpp src/VideoRecorder.cpp src/TimeManager.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:TimeManager,VideoRecorder,VideoConfig,VideoStorage,PolicemanInfo,VideoEncrypter,GpsInfo,CameraController,
# Specification Path: 

