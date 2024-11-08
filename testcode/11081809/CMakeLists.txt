project(11081809)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/Student.cpp src/CustomerLoginAndAuthentication.cpp src/ReceiveCommandsFromUsers.cpp src/CustomerRegistration.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:CustomerRegistration,ReceiveCommandsFromUsers,CustomerLoginAndAuthentication,Student,
# Specification Path: 

