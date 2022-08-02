game:main.o TextImage.o RiddleText.o
	gcc main.o TextImage.o RiddleText.o -g -o game -lSDL -lSDL_image -lSDL_ttf 
main.o:main.c 
	gcc -c main.c -g
TextImage.o:TextImage.c 
	gcc -c TextImage.c  -g
RiddleText.o: RiddleText.c
	gcc -c RiddleText.c -g
