all:
	gcc toralizer.c -o toralizer.so -fPIC -shared -ldl -D_GNU_SOURCE