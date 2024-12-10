project(12101748)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/TimeManager.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/CameraController.cpp src/VideoConfig.cpp src/VideoStorage.cpp src/VideoEncrypter.cpp src/GpsInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:GpsInfo,VideoEncrypter,VideoStorage,VideoConfig,CameraController,VideoRecorder,PolicemanInfo,TimeManager,
# Specification Path: 

