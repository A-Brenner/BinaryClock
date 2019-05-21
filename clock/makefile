

all: main.c display.c
		gcc -c main.c display.c
		gcc -o clock main.o display.o framebuffer.o
clean:
		rm main.o
		rm display.o
		rm clock
run:
	./clock.sh | ./clock
	



