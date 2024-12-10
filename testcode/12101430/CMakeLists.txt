project(12101430)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GPSInfo.cpp src/Timemanager.cpp src/Videostorage.cpp src/Videoencrypter.cpp src/Videorecorder.cpp src/Videoconfig.cpp src/CameraController.cpp src/Policemaninfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:Policemaninfo,CameraController,Videoconfig,Videorecorder,Videoencrypter,Videostorage,Timemanager,GPSInfo,
# Specification Path: 

