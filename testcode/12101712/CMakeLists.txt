project(12101712)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/PolicemanInfo.cpp src/CameraController.cpp src/VideoStorage.cpp src/VideoRecorder.cpp src/VideoEncrypter.cpp src/TimeManager.cpp src/GpsInfo.cpp src/VideoConfig.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoConfig,GpsInfo,TimeManager,VideoEncrypter,VideoRecorder,VideoStorage,CameraController,PolicemanInfo,
# Specification Path: 

