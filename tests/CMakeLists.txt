cmake_minimum_required(VERSION 3.11)

project(bomberman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
      ../includes
      ../includes/core
      ../includes/core/generator
      ../includes/events
      ../includes/object
      ../includes/display
      ../includes/scenes
      ../includes/object/bomb
      ../includes/object/button
      ../includes/object/mur
      ../includes/object/player
      ../includes/object/power
      ../includes/object/sol
      ../includes/irrlicht
)

FILE(GLOB SRCS
../srcs/Indie.cpp
../srcs/core/*cpp
../srcs/core/generator/*.cpp
../srcs/display/*.cpp
../srcs/events/*.cpp
../srcs/object/*.cpp
../srcs/object/bomb/*.cpp
../srcs/object/button/*.cpp
../srcs/object/mur/*.cpp
../srcs/object/player/*.cpp
../srcs/object/power/*.cpp
../srcs/object/sol/*.cpp
../srcs/scenes/*.cpp
main_test.cpp)

FILE(GLOB HDRS includes/*.hpp
../includes/core/*.hpp
../includes/core/generator/*.hpp
../includes/display/*.hpp
../includes/events/*.hpp
../includes/irrlicht/*.hpp
../includes/object/*.hpp
../includes/object/bomb/*.hpp
../includes/object/button/*.hpp
../includes/object/mur/*.hpp
../includes/object/player/*.hpp
../includes/object/power/*.hpp
../includes/object/sol/*.hpp
../includes/scenes/*.hpp)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(Irrlicht)

INCLUDE_DIRECTORIES(bomberman, ${IRRLICHT_INCLUDE_DIR})

ADD_EXECUTABLE(bomberman
   ${SRCS}
   ${HDRS}
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

install(TARGETS bomberman DESTINATION ${PROJECT_SOURCE_DIR}/..)

TARGET_LINK_LIBRARIES(bomberman
${IRRLICHT_LIBRARY} Irrlicht pthread)