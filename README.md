# Colossal Cave Adventure

## What is Colossal Cave Adventure
Colossal Cave Adventure is a text based adventure game.  Originally
written in Fortran running on a DEC PDP-10.

[Colossal Cave Adventure](https://en.wikipedia.org/wiki/Colossal_Cave_Adventure)


## Origin of This Version 

This version is based on BDS C Adventure.  From 

[David Kinder's guide to Adventure downloads](https://rickadams.org/adventure/e_downloads.html)

> From the Jay R. Jaegar converted the original Adventure to BDS C, and
> added separate values for treasures, survival and score. Available is
> Bob Wither's DOS version, as a DOS executable and MS C source
> code. The BDS code was converted to Unix by Jerry D. Pohl. This latter
> version is available as Unixsource code, OS/2 source code, a DOS
> executable and an OS/2 executable.

The source code from Jay R. Jaegar was pre-ANSI C.  It has been
modified to compile with more modern C compilers.  It is know to
compile for MacOS and Ubuntu.  It will likely compile for any recent
Unix-like operating system.

## Build
### Example of building with Linux or MacOS command line
```sh
mkdir build 
cd build
cmake -G 'Unix Makefiles' ../.
make 
```

### MacOS XCode
```sh
mkdir xcbuild 
cd xcbuild
cmake -D CMAKE_C_COMPILER=$(xcrun -find cc) -D CMAKE_CXX_COMPILER=$(xcrun -find c++) -G Xcode ../.
open advent.xcodeproj/
```
