cmake_minimum_required(VERSION 3.9)
project(fish_shoal)

set(CMAKE_CXX_STANDARD 11)

add_executable(fish_shoal
        classes/BigFish.cpp
        classes/Fish.cpp
        classes/LittleFish.cpp
        classes/Ocean.cpp
        classes/VariableFish.cpp
        headers/BigFish.h
        headers/config.hpp
        headers/Fish.h
        headers/LittleFish.h
        headers/Ocean.h
        headers/VariableFish.h
        main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(fish_shoal ${SFML_LIBRARIES})
endif()