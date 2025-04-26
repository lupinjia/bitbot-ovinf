cmake_minimum_required(VERSION 3.14)

project(bitbot)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Release)
set(BITBOT_DEPENDENCY_USE_PROXY TRUE)
set(BITBOT_DEPENDENCY_USE_LOCAL_FILE TRUE)
set(BITBOT_DEPENDENCY_LOCAL_FILE_PATH ${CMAKE_SOURCE_DIR}/dependencies)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/home/dknt/Library/openvino_u24_2025.1.0/runtime/cmake")

include(bitbot.cmake)
include_directories("/usr/include/eigen3")

BitbotAddDependency(
  NAME           bitbot_mujoco
  FILE_NAME      "bitbot_mujoco-main.zip"
  FILE_PATH      ${BITBOT_DEPENDENCY_LOCAL_FILE_PATH}
  USE_LOCAL_FILE TRUE
)

include(FetchContent)
FetchContent_Declare(
  ovinf
  GIT_REPOSITORY git@github.com:Dknt0/ovinf.git
  GIT_TAG main
)
FetchContent_MakeAvailable(ovinf)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

find_package(OpenVINO REQUIRED)
find_package(yaml-cpp REQUIRED)

add_executable(main_app 
  main.cc
)

target_include_directories(main_app PUBLIC ${OVINF_INCLUDED}
  ${OpenVINO_INCLUDE_DIRS}
  "/usr/include/eigen3/"
  ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(main_app
  BitbotMujoco
  ovinf
)
target_compile_options(main_app PUBLIC)
target_compile_features(main_app PUBLIC cxx_std_20)

