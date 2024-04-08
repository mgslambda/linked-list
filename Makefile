build: main.c src/list.c
	mkdir -p bin
	gcc -o bin/main src/list.c main.c

debug: main.c src/list.c
	mkdir -p debug
	gcc -g -o debug/main src/list.c main.c

ll_insert_test: test/ll_insert_test.c src/list.c
	mkdir -p bin
	gcc -o bin/ll_insert_test test/ll_insert_test.c src/list.c
