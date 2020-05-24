# C++ 2D Shoot'Em Up!
## CPPND: Capstone Project

This is the repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

This project is based on the 2D Shoot'em Up tutorial by Parallel Realities (which can be found [here](https://www.parallelrealities.co.uk/tutorials/#shooter)).

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
  * Make sure to install also SDL2_image (e.g. on Linux run `apt-get install libsdl2-image-dev`)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D-Shoot-Em-Up`.

## Commands
* <kbd>Arrows</kbd> : move Spaceship
* <kbd>Space</kbd> : Fire

## Folder Structure
* cmake : contains CMake find utilities
* gfx : contains all the png images used as texture
* src : contains all the project code

## Class Structure
Project's class structure is depicted with the following image
![UML Class Image](https://github.com/CollazzoD/2d-Shoot-Em-Up/blob/master/UML%20Class.png)
