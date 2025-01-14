project(12111406)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoStorage.cpp src/TimeManager.cpp src/VideoRecorder.cpp src/GpsInfo.cpp src/PolicemanInfo.cpp src/VideoConfig.cpp src/VideoEncrypter.cpp src/CameraController.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:CameraController,VideoEncrypter,VideoConfig,PolicemanInfo,GpsInfo,VideoRecorder,TimeManager,VideoStorage,
# Specification Path: 

