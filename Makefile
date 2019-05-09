movie.gif: eq.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: eq.cpp
	g++ eq.cpp

clean:
	rm -rf a.out eq.dat *.png~
