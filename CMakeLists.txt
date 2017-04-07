cmake_minimum_required(VERSION 3.6)
project(pontoon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Card.h Deck.cpp Deck.h Bank.cpp Bank.h Player.cpp Player.h mainFunctions.cpp mainFunctions.h Log.cpp Log.h)
add_executable(pontoon ${SOURCE_FILES})