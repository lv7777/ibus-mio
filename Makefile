
# -Wall is display all warning and also Wextra.
build: gtktes.c
	gcc -O2 -Wall -Wextra gtktes.c `pkg-config --cflags --libs gtk+-2.0`  -o release
