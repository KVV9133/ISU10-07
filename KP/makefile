all: d_p

d_p: main.o temp_api.o 
	gcc -o d_p main.o temp_api.o 

main.o: main.c
	gcc -c -o main.o main.c

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c



clean:
	del *.o
	del prog.exe