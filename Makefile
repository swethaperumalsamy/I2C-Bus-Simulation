all:
	gcc src/*.c -o output

run:
	./output

clean:
	rm -f output
