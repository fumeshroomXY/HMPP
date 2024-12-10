project(12101453)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/Videoencrypter.cpp src/Videorecorder.cpp src/Videostorage.cpp src/Timemanager.cpp src/GPSInfo.cpp src/Policemaninfo.cpp src/Videoconfig.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:Videoconfig,Policemaninfo,GPSInfo,Timemanager,Videostorage,Videorecorder,Videoencrypter,CameraController,
# Specification Path: 

