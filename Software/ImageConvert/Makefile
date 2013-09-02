all: image2array

image2array: image2array.cpp
	g++ -lgd -o image2array image2array.cpp

test: image2array
	./image2array ../../Images/Puzzle/probe1-2.png

.PHONY: probe
probe: image2array
	./image2array ../../Images/Puzzle/probe1-1.png  > images.h
	./image2array ../../Images/Puzzle/probe1-2.png >> images.h
	./image2array ../../Images/Puzzle/probe1-3.png >> images.h
	./image2array ../../Images/Puzzle/probe1-4.png >> images.h
	./image2array ../../Images/Puzzle/probe2-1.png >> images.h
	./image2array ../../Images/Puzzle/probe2-2.png >> images.h
	./image2array ../../Images/Puzzle/probe2-3.png >> images.h
	./image2array ../../Images/Puzzle/probe2-4.png >> images.h
	./image2array ../../Images/Puzzle/probe3-1.png >> images.h
	./image2array ../../Images/Puzzle/probe3-2.png >> images.h
	./image2array ../../Images/Puzzle/probe3-3.png >> images.h
	./image2array ../../Images/Puzzle/probe3-4.png >> images.h
	./image2array ../../Images/Puzzle/probe4-1.png >> images.h
	./image2array ../../Images/Puzzle/probe4-2.png >> images.h
	./image2array ../../Images/Puzzle/probe4-3.png >> images.h
	./image2array ../../Images/Puzzle/probe4-4.png >> images.h
	./image2array ../../Images/Puzzle/probe5-1.png >> images.h
	./image2array ../../Images/Puzzle/probe5-2.png >> images.h
	./image2array ../../Images/Puzzle/probe5-3.png >> images.h
	./image2array ../../Images/Puzzle/probe5-4.png >> images.h

.PHONY: clean
clean:
	rm -f image2array

