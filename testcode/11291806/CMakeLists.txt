project(11291806)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/Student.cpp src/CustomerRegistration.cpp src/ReceiveCommandsFromUsers.cpp src/CustomerLoginAndAuthentication.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:CustomerLoginAndAuthentication,ReceiveCommandsFromUsers,CustomerRegistration,Student,
# Specification Path: 

