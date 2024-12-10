project(12102011)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoRecorder.cpp src/CameraController.cpp src/VideoEncrypter.cpp src/VideoConfig.cpp src/TimeManager.cpp src/PolicemanInfo.cpp src/VideoStorage.cpp src/GpsInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:GpsInfo,VideoStorage,PolicemanInfo,TimeManager,VideoConfig,VideoEncrypter,CameraController,VideoRecorder,
# Specification Path: 

