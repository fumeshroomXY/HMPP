project(12101515)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoEncrypter.cpp src/VideoConfig.cpp src/PolicemanInfo.cpp src/CameraController.cpp src/GpsInfo.cpp src/TimeManager.cpp src/VideoRecorder.cpp src/VideoStorage.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoStorage,VideoRecorder,TimeManager,GpsInfo,CameraController,PolicemanInfo,VideoConfig,VideoEncrypter,
# Specification Path: 

