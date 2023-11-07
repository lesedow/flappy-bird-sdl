#!/bin/zsh
g++ -c src/*.cpp -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main
exit 0
