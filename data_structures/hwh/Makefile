out: 
	mkdir out

out/app: main.c hash_map.c out
	gcc -Wall main.c hash_map.c -o out/app

debug: main.c hash_map.c out
	gcc -Wall main.c hash_map.c -g -o out/app

check_leaks: debug
	valgrind --leak-check=full ./out/app

build: out/app

clean:
	rm -rf out