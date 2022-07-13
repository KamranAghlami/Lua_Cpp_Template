cmake_minimum_required(VERSION 3.20)

project(lua LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Lua REQUIRED)
find_package(SWIG REQUIRED COMPONENTS lua)

include(UseSWIG)

file(GLOB_RECURSE SWIG_INTERFACE "src/swig/main.i")
file(GLOB_RECURSE SWIG_SOURCES "src/swig/*.h" "src/swig/*.cpp")

set_property(SOURCE ${SWIG_INTERFACE} PROPERTY CPLUSPLUS ON)
set_property(SOURCE ${SWIG_INTERFACE} PROPERTY DEPENDS ${SWIG_SOURCES})

swig_add_library(${PROJECT_NAME}_wrapper
  TYPE MODULE
  LANGUAGE Lua
  SOURCES ${SWIG_INTERFACE} ${SWIG_SOURCES}
)

target_include_directories(${PROJECT_NAME}_wrapper PRIVATE src/swig)
set_property(TARGET ${PROJECT_NAME}_wrapper PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

file(GLOB_RECURSE SOURCES "src/application/*.h" "src/application/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}_wrapper PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}_wrapper PRIVATE ${LUA_LIBRARIES})

target_include_directories(${PROJECT_NAME} PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LUA_LIBRARIES})
