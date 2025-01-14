project(12111424)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoEncrypter.cpp src/GpsInfo.cpp src/VideoStorage.cpp src/TimeManager.cpp src/VideoRecorder.cpp src/PolicemanInfo.cpp src/CameraController.cpp src/VideoConfig.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoConfig,CameraController,PolicemanInfo,VideoRecorder,TimeManager,VideoStorage,GpsInfo,VideoEncrypter,
# Specification Path: 

