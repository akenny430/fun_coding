# Prime tester

Basic implementation of Miller-Rabin prime tester in C++.

Main functionality is written in `miller_rabin.cpp`.

## Building

Need to have [CMake](https://cliutils.gitlab.io/modern-cmake/chapters/intro/installing.html)
and a C++ compiler installed.

Run the following:

```{zsh}
$ CXX=clang++ cmake -S . -B build
$ cd build
$ make
```

## Running

After building, run the following:

```{zsh}
$ .prime
```

This activates the driver program.
You enter a number and it prints whether or not the number is prime.