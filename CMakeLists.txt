cmake_minimum_required(VERSION 3.6)
project(Grupo2_C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/Class1_Introduction/Car.c
        src/Class1_Introduction/Car.h
        src/Class1_Introduction/Main.c
        src/Class1_Introduction/Parking.c
        src/Class1_Introduction/Parking.h
        src/TAD/ComplexNumber.c
        src/TAD/ComplexNumber.h
        src/TAD/Tester.c
        )
add_executable(Grupo2_C ${SOURCE_FILES})