# snowballGame

Final project of the Udemy course Learn Advanced Modern C++. In the game, the players objective is to hit all bricks with a snowball using arrow keys on the keyboard.

In the game the user interacts with a few button clicks:

- p: pause/start
- r: reset game
- left arrow: move snowboard to the left
- right arrow: move snowboard to the right
- escape: terminate window

The user have 3 lives and wins if all the bricks are gone. Game over happen when the player lose all 3 lives.

## PreRequisite

To compile you have to install the following packages:

```bash
sudo apt update
sudo apt install \
    make \
    cmake \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libdrm-dev \
    libgbm-dev
```

Set up the  SFML library properly using the [tutorials](https://www.sfml-dev.org/tutorials/2.6/) and [cmake-guide](https://www.sfml-dev.org/tutorials/2.6/start-cmake.php)

To be able to see the text in the game, you need** to download fonts

```bash
sudo apt install ttf-mscorefonts-installer
```

and find the root folder to the verdana font and, replace the path in l.55 in the entityManager.cpp

** due to copywrite issues.

## Build

```bash
make
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Run

```bash
./build/Executable
```
