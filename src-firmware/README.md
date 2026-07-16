# UWMTR Thruster Control Board Firmware

## Developer Instructions
For initial setup and installation instructions, follow the steps outlined in 
[uwmtr-fw-template-v1](https://github.com/UWMedTechRobotics/uwmtr-fw-template-v1).

### Implementing New Drivers
Use drivers for the following:
- Hardware abstractions for sensors and other peripherals on the board.

1. Create the files:
- Create source files in `./Src/Drivers/UWMTR/Src/`.
- Create header files in `./Src/Drivers/UWMTR/Inc/`.
- In `CMakeList.txt`, update `target_sources(${CMAKE_PROJECT_NAME} PRIVATE)` to
include the file paths to any source files.
- In `CmakeList.txt`, update `target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE)`
to include the directory of any header files. Note that you shouldn't have to 
modify 