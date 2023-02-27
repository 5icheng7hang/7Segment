INCLUDES= -I ./include
FLAGS= -g

OBJECTS= ./build/Game.o ./build/GameplayCore.o ./build/Method.o


all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} -L ./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o ./bin/main

./build/Game.o:src/Game.c
	gcc ${FLAGS} ${INCLUDES} ./src/Game.c -c -o ./build/Game.o

./build/GameplayCore.o:src/GameplayCore.c
	gcc ${FLAGS} ${INCLUDES} ./src/GameplayCore.c -c -o ./build/GameplayCore.o

./build/Method.o:src/Method.c
	gcc ${FLAGS} ${INCLUDES} ./src/Method.c -c -o ./build/Method.o

run:
	bin/main

clean:
	del build\*
