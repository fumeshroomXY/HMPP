project(12102050)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/GpsInfo.cpp src/TimeManager.cpp src/VideoStorage.cpp src/VideoConfig.cpp src/VideoEncrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoEncrypter,VideoConfig,VideoStorage,TimeManager,GpsInfo,VideoRecorder,PolicemanInfo,CameraController,
# Specification Path: 

