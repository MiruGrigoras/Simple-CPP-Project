cmake_minimum_required(VERSION 3.0)
project(ArtGallery)

include_directories(libs)


add_executable(artGallery 
    src/main.cpp
    src/surface.cpp
    libs/surface.hpp
    src/paint.cpp
    libs/paint.hpp
    src/painting.cpp
    libs/painting.hpp
    src/painter.cpp
    libs/painter.hpp)
