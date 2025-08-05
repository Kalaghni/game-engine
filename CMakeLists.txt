cmake_minimum_required(VERSION 3.15)
project(TitanEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(engine)
add_subdirectory(platform)
add_subdirectory(game)

enable_testing()
add_subdirectory(tests)
