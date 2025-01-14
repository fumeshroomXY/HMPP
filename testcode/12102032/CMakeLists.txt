project(12102032)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/TimeManager.cpp src/VideoStorage.cpp src/GpsInfo.cpp src/PolicemanInfo.cpp src/VideoEncrypter.cpp src/VideoConfig.cpp src/VideoRecorder.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoRecorder,VideoConfig,VideoEncrypter,PolicemanInfo,GpsInfo,VideoStorage,TimeManager,CameraController,
# Specification Path: 

