project(12102103)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoStorage.cpp src/GpsInfo.cpp src/TimeManager.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/VideoEncrypter.cpp src/CameraController.cpp src/VideoConfig.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoConfig,CameraController,VideoEncrypter,VideoRecorder,PolicemanInfo,TimeManager,GpsInfo,VideoStorage,
# Specification Path: 

