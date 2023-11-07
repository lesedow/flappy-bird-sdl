#!/bin/zsh
g++ -c src/*.cpp -m64 -O3 -Wall -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/release/main
exit 0
