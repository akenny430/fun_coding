cmake_minimum_required(VERSION 3.19)

project(
    prime_tester
    LANGUAGES CXX
)

# dependencies
add_library(
    miller_rabin
    messages.cpp
    messages.hpp
    miller_rabin.cpp
    miller_rabin.hpp
)
target_compile_features(
    miller_rabin
    PUBLIC
        cxx_std_20
)

# executable
add_executable(
    prime
    main.cpp
    messages.hpp
    miller_rabin.hpp
)

# linking
target_link_libraries(
    prime
    PRIVATE
        miller_rabin
)
