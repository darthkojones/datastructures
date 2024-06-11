CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = insertion_sort
OBJS = main.o insertion_sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp insertion_sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

insertion_sort.o: insertion_sort.cpp insertion_sort.h
	$(CXX) $(CXXFLAGS) -c insertion_sort.cpp

clean:
	rm -f $(TARGET) $(OBJS)
