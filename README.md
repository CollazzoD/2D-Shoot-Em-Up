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

## Appearance
### Highscore Screen
When started, the game will prompt the "Highscore Screen" like the following image:

![Highscore_Screen_Image](https://github.com/CollazzoD/2d-Shoot-Em-Up/blob/master/Highscore_screen.png)

To start playing, just press <kbd>Space</kbd>. To close the application, just close the window.

### Playing
While playing, use the <kbd>Arrows</kbd> to move the Spaceship and the <kbd>Space</kbd> to Fire.
Pressing the <kbd>Esc</kbd> button will prompt the "Highscore Screen". To resume playing, just press <kbd>Space</kbd>.
The Player dies when gets hit by an Enemy's bullet. When this happen, the game will resum after a short period.
To close the application, just close the window.

![Game_Screen_Image](https://github.com/CollazzoD/2d-Shoot-Em-Up/blob/master/Game_screen.png)


## Commands
* While in Highscore Screen:
  * <kbd>Space</kbd> : Start/Resume playing

* While playing:
  * <kbd>Arrows</kbd> : move Spaceship
  * <kbd>Space</kbd> : Fire
  * <kbd>Esc</kbd> : Show highscore screen
  
## Folder Structure
* cmake : contains CMake find utilities
* gfx : contains all the png images used as texture
* src : contains all the project code

## Class Structure
Project's class structure is depicted with the following image
![UML Class Image](https://github.com/CollazzoD/2d-Shoot-Em-Up/blob/master/UML%20Class.png)

## Rubric Points Addressed
This section indicates which rubric points are addressed for the CppND Capstone Project.
The file is indicated with the extension. If one has to refer to both .h and .cpp, the file extension is replaced with .\*
The lines of code, if present, are indicated with an interval notation, that indicates from which line to which line one can find the relative rubric point (e.g. example.cpp [1:5] indicates from line 1 to line 5 of example.cpp's file).

Rubric Point  | File
:-------------:|:-------------:
The project reads data from a file and process the data,<br> or the program writes data to a file | highscore.cpp [4:24]
The project accepts user input and processes the input.| controller.cpp [5:67] <br> (using the SDL library as interface for user's input)
The project uses Object Oriented Programming techniques. | entity.\*, alienBullet.\*, bullet.\*, debris.\*,<br> enemy.\*, explosion.\*, player.\*
Classes use appropriate access specifiers for class members.| alienBullet.h, bullet.h, controller.h, debris.h, enemy.h,<br> entity.h, explosion.h, game.h, highscore.h, player.h, renderer.h, star.h, texture.h
Class constructors utilize member initialization lists. | alienBullet.cpp, bullet.cpp, debris.cpp, enemy.cpp, entity.cpp, <br> explosion.cpp, player.cpp, texture.cpp
Derived class functions override virtual base class functions. | alienBullet.cpp [8:14], bullet.cpp [7:15], debris.cpp[8:13], enemy.cpp [11:21], explosion.cpp [8:15], player.cpp [18:53]
The project makes use of references in function declarations. | game.cpp [79]

