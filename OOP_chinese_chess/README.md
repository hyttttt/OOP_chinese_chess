# README
This is the 2nd project from OOP lab.\
Using C++ to make a Chinese chess game with GUI.

## Environment
- Windows 10
- Visual studio 2019
- SDL2
- SDL_image

## Set up SDL
### Step 1：Include SDL and SDL_image directory
1. Open Visual studio 2019
2. Go to project > properties > configuration properties > VC++ directories > include directories > edit
3. Add the include directory from the SDL and SDL_image folder 

    `~\OOP_chinese_chess\SDL2-2.0.22\include`

    `~\OOP_chinese_chess\SDL2_image-2.0.5\include`
    
    (All directories are for example. Please use the real directories.)
    
***
    
### Step 2：Add SDL and SDL_image library
1. Go to project > properties > configuration properties > VC++ directories > library directories > edit
2. Add the library directory from the SDL and SDL_image folder

    `~\OOP_chinese_chess\SDL2-2.0.22\lib\x86`
    
    `~\OOP_chinese_chess\SDL2_image-2.0.5\lib\x86`
    
    (All directories are for example. Please use the real directories.)
***
    
### Step 3：Additional dependencies
1. Go to project > properties > configuration properties > linker > input > additional dependencies > edit
2. Add `SDL2.lib;
SDL2main.lib;
SDL2test.lib;
SDL2_image.lib`

***

### Step 4：Windows environment setting
1. Go into Windows Settings and search for edit the system environment variables
2. Add the library directory from the SDL and SDL_image folder to the **PATH** variable

    `~\OOP_chinese_chess\SDL2-2.0.22\lib\x86`
    
    `~\OOP_chinese_chess\SDL2_image-2.0.5\lib\x86`
    
    (All directories are for example. Please use the real directories.)