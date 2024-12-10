project(12102025)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoEncrypter.cpp src/TimeManager.cpp src/VideoStorage.cpp src/GpsInfo.cpp src/VideoConfig.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/CameraController.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:CameraController,VideoRecorder,PolicemanInfo,VideoConfig,GpsInfo,VideoStorage,TimeManager,VideoEncrypter,
# Specification Path: 

