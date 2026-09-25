cmake_minimum_required(VERSION 4.3)
project(cascii)

set(CMAKE_CXX_STANDARD 17)

add_executable(cascii main.cpp
        Classes/Command.h
        Headers/Commands.h
        Sources/Commands.cpp
        Headers/OutColour.h
        Sources/OutColour.cpp
        Headers/Terminal.h
        Sources/Terminal.cpp
        Headers/CommandHandler.h
        Sources/CommandHandler.cpp
        Headers/Utilities.h
        Sources/Utilities.cpp
)
