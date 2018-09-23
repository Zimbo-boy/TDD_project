project(chapterFirstExample)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/googlemock/include $ENV{GMOCK_HOME}/googletest/include)
link_directories(/usr/src/googletest/googlemock/mybuild /usr/src/googletest/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   main.cpp 
   SoundexTest.cpp Soundex.h Playground.h)
add_executable(test ${sources})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)

