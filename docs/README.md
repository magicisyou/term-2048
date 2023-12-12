# Term 2048

2048 game for the linux terminal.

![Term 2048](/docs/screenshot.webp)

## Usage

The game can be played using the arrow keys

Press **q** or **Q** to quit and **r** to reset the game

## Build

If libncurses-dev is not installed install it. In debian based system install using apt. Use appropriate package manager in other distros.

```
sudo apt install libncurses-dev
```

Clone the repository

```
git clone https://github.com/magicisyou/term-2048
```

Change directory

```
cd term-2048
```

Compile

```
g++ -I include src/*.cpp -o term-2048 -lncurses -std=c++17
```

Run
```
./term-2048
```
