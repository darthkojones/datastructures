CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = merge_sort
OBJS = main.o merge_sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

merge_sort.o: merge_sort.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) -c merge_sort.cpp

clean:
	rm -f $(TARGET) $(OBJS)
