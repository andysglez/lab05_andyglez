CXXFLAGS: -std=c++11 -Wall

eval: evalfull.o
	g++ $(CXXFLAGS) evalfull.o -o eval
stack: usestack.o
	g++ $(CXXFLAGS) usestack.o -o stack
usestack.o: usestack.cpp intstack.h
	g++ -c usestack.cpp
evalfull.o: evalfull.cpp 
	g++ -c evalfull.cpp
clean:
	rm -f *.o eval stack
