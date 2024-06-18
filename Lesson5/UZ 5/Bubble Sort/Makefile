CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = bubble_sort
OBJS = main.o bubble_sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp bubble_sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

bubble_sort.o: bubble_sort.cpp bubble_sort.h
	$(CXX) $(CXXFLAGS) -c bubble_sort.cpp

clean:
	rm -f $(TARGET) $(OBJS)
