all: image2array

image2array: image2array.cpp
	g++ -lgd -o image2array image2array.cpp

test: image2array
	./image2array ../../Images/Puzzle/probe1-2.png

.PHONY: probe1
probe1: image2array
	./image2array ../../Images/Puzzle/probe1-1.png  > images.h
	./image2array ../../Images/Puzzle/probe1-2.png >> images.h
	./image2array ../../Images/Puzzle/probe1-3.png >> images.h
	./image2array ../../Images/Puzzle/probe1-4.png >> images.h

.PHONY: clean
clean:
	rm -f image2array

