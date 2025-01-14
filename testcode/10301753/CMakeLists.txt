project(10301753)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CustomerLoginAndAuthentication.cpp src/CustomerRegistration.cpp src/ReceiveCommandsFromUsers.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:ReceiveCommandsFromUsers, CustomerRegistration, CustomerLoginAndAuthentication, ReceiveCommandsFromUsers, CustomerRegistration, CustomerLoginAndAuthentication, 
# Specification Path: 

