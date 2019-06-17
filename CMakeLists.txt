cmake_minimum_required(VERSION 3.11)

project(bomberman)

if (WIN32)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif (WIN32)

if (UNIX)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lsfml-audio")
endif (UNIX)

include_directories(
      includes
      includes/core
      includes/core/generator
      includes/events
      includes/object
      includes/display
      includes/scenes
      includes/object/bomb
      includes/object/button
      includes/object/mur
      includes/object/player
      includes/object/power
      includes/object/sol
      includes/irrlicht
)

FILE(GLOB SRCS
srcs/*.cpp
srcs/core/*cpp
srcs/core/generator/*.cpp
srcs/display/*.cpp
srcs/events/*.cpp
srcs/object/*.cpp
srcs/object/bomb/*.cpp
srcs/object/button/*.cpp
srcs/object/mur/*.cpp
srcs/object/player/*.cpp
srcs/object/power/*.cpp
srcs/object/sol/*.cpp
srcs/scenes/*.cpp)

FILE(GLOB HDRS includes/*.hpp
includes/core/*.hpp
includes/core/generator/*.hpp
includes/display/*.hpp
includes/events/*.hpp
includes/irrlicht/*.hpp
includes/object/*.hpp
includes/object/bomb/*.hpp
includes/object/button/*.hpp
includes/object/mur/*.hpp
includes/object/player/*.hpp
includes/object/power/*.hpp
includes/object/sol/*.hpp
includes/scenes/*.hpp)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)# Enzo remove this line
#SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)# Enzo uncomment this

#Now Enzo is happy. Enzo can sleep.

FIND_PACKAGE(Irrlicht)

INCLUDE_DIRECTORIES(bomberman, ${Irrlicht_INCLUDE_DIRS})

ADD_EXECUTABLE(bomberman
   ${SRCS}
   ${HDRS}
)

install(TARGETS bomberman DESTINATION ${PROJECT_SOURCE_DIR}/..)

if (UNIX)
	target_link_libraries(bomberman ${IRRLICHT_LIBRARY} Irrlicht pthread)
endif(UNIX)

if (WIN32)
	link_directories(${Irrlicht_LIBRARIES})
	target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
endif(WIN32)