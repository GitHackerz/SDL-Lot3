game:main.o TextImage.o RiddleText.o RiddleImage.o MiniGame.o MainFN.o
	gcc main.o TextImage.o RiddleText.o RiddleImage.o MiniGame.o MainFN.o -g -o game -lSDL -lSDL_image -lSDL_ttf 
main.o:main.c 
	gcc -c main.c -g
TextImage.o:TextImage.c 
	gcc -c TextImage.c  -g
RiddleText.o: RiddleText.c
	gcc -c RiddleText.c -g
RiddleImage.o: RiddleImage.c
	gcc -c RiddleImage.c -g
MiniGame.o: MiniGame.c
	gcc -c MiniGame.c -g
MainFN.o: MainFN.c
	gcc -c MainFN.c -g
	
