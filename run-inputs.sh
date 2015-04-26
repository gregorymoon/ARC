#!/bin/bash/

DIR=sample-input

for entry in "$DIR"/*
do
	printf "\n$entry\n--------------\n\n"
	printf "cache-size = 1024\n"
	./LRU 1024 "$entry"

	printf "\ncache-size = 2048\n"
	./LRU 2048 "$entry"

	printf "\ncache-size = 4096\n"
	./LRU 4096 "$entry"

	printf "\ncache-size = 8192\n"
	./LRU 8192 "$entry"

	printf "\ncache-size = 16384\n"
	./LRU 16384 "$entry"

	printf "\ncache-size = 32768\n"
	./LRU 32768 "$entry"

	printf "\ncache-size = 65536\n"
	./LRU 65536 "$entry"

	printf "\ncache-size = 131072\n"
	./LRU 131072 "$entry"

	printf "\ncache-size = 262144\n"
	./LRU 262144 "$entry"

	printf "\ncache-size = 524288\n"
	./LRU 524288 "$entry"
done

wait
