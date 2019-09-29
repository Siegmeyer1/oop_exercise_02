cmake_minimum_required(VERSION 3.5)

project(oop_exercise_02)

add_executable(oop_exercise_02 FazzyNumber.cpp main.cpp)
set_target_properties(oop_exercise_02 PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )
