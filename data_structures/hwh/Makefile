out: 
	mkdir $@

out/app: main.c hash_map.c hash_map_tests.c out
	gcc -Wall main.c hash_map.c -o $@

debug: main.c hash_map.c hash_map_tests.c out
	gcc -Wall main.c hash_map.c hash_map_tests.c -g -o out/app

check_leaks: debug
	valgrind --leak-check=full ./out/app

build: out/app

clean:
	rm -rf out