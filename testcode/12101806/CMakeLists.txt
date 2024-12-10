project(12101806)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/TimeManager.cpp src/VideoConfig.cpp src/PolicemanInfo.cpp src/VideoEncrypter.cpp src/VideoStorage.cpp src/VideoRecorder.cpp src/GpsInfo.cpp src/CameraController.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:CameraController,GpsInfo,VideoRecorder,VideoStorage,VideoEncrypter,PolicemanInfo,VideoConfig,TimeManager,
# Specification Path: 

