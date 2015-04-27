#!/bin/bash/

DIR=sample-input

for entry in "$DIR"/*
do
	printf "\n$entry\n--------------\n\n"
	printf "cache-size = 1024\n"
	./main 1024 "$entry"

	printf "\ncache-size = 2048\n"
	./main 2048 "$entry"

	printf "\ncache-size = 4096\n"
	./main 4096 "$entry"

	printf "\ncache-size = 8192\n"
	./main 8192 "$entry"

	printf "\ncache-size = 16384\n"
	./main 16384 "$entry"

	printf "\ncache-size = 32768\n"
	./main 32768 "$entry"

	printf "\ncache-size = 65536\n"
	./main 65536 "$entry"

	printf "\ncache-size = 131072\n"
	./main 131072 "$entry"

	printf "\ncache-size = 262144\n"
	./main 262144 "$entry"

	printf "\ncache-size = 524288\n"
	./main 524288 "$entry"
done

wait
