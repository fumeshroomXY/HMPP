project(12102108)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/PolicemanInfo.cpp src/VideoRecorder.cpp src/TimeManager.cpp src/VideoStorage.cpp src/VideoConfig.cpp src/VideoEncrypter.cpp src/GpsInfo.cpp src/CameraController.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:CameraController,GpsInfo,VideoEncrypter,VideoConfig,VideoStorage,TimeManager,VideoRecorder,PolicemanInfo,
# Specification Path: 

