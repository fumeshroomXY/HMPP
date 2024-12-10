project(12102003)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GpsInfo.cpp src/VideoConfig.cpp src/TimeManager.cpp src/VideoStorage.cpp src/VideoRecorder.cpp src/PolicemanInfo.cpp src/CameraController.cpp src/VideoEncrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoEncrypter,CameraController,PolicemanInfo,VideoRecorder,VideoStorage,TimeManager,VideoConfig,GpsInfo,
# Specification Path: 

