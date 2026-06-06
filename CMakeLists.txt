#CMAKE version to use
cmake_minimum_required(VERSION 4.3.3)

#define name & version of application
project("SFML_Blueprint" VERSION 1.0 LANGUAGES CXX)

# set language (c++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE-CXX-STANDARD_REQUIRED ON)
set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_BUILD_TYPE Release)

#list all sources files in a SET (HEADERS & SOURCES)

set(HEADERS
    Src/00-HEADERS/Action.h
    Src/00-HEADERS/ActionTarget.h
    Src/00-HEADERS/Game.h
    Src/00-HEADERS/Player.h
)

set(SRCS
    Src/main.cpp
    Src/Action/Action.cpp
    Src/Action/ActionTarget.cpp
    Src/Game/Game.cpp
    Src/Player/Player.cpp
    )

#create application & link all sources files
add_executable(${PROJECT_NAME} ${HEADERS} ${SRCS})

#Link SFML
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/External/SFML/include")
target_link_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/External/SFML/lib")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
      target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics-d sfml-audio-d sfml-network-d sfml-system-d sfml-window-d)         
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
      target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio sfml-network sfml-system sfml-window)         
endif()

#copy resources & SFML include files
file(COPY Res DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
file(COPY Res DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 
file(COPY External DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

#Copy SFML dll in release directories
file(COPY "External/SFML/SFML bin/openal32.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 
file(COPY "External/SFML/SFML bin/sfml-audio-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 
file(COPY "External/SFML/SFML bin/sfml-graphics-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 
file(COPY "External/SFML/SFML bin/sfml-network-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 
file(COPY "External/SFML/SFML bin/sfml-system-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 
file(COPY "External/SFML/SFML bin/sfml-window-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release") 


file(COPY "External/SFML/SFML bin/openal32.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
file(COPY "External/SFML/SFML bin/sfml-audio-d-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
file(COPY "External/SFML/SFML bin/sfml-graphics-d-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
file(COPY "External/SFML/SFML bin/sfml-network-d-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
file(COPY "External/SFML/SFML bin/sfml-system-d-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
file(COPY "External/SFML/SFML bin/sfml-window-d-2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug") 
