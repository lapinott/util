cmake_minimum_required(VERSION 3.10)

#util
project(util)

#c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#debug name
set (CMAKE_DEBUG_POSTFIX "d")

find_path(BOOST_DIR "boost dir")

add_subdirectory("util")