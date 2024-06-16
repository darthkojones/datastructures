CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = selection_sort
OBJS = main.o selection_sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp selection_sort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

selection_sort.o: selection_sort.cpp selection_sort.h
	$(CXX) $(CXXFLAGS) -c selection_sort.cpp

clean:
	rm -f $(TARGET) $(OBJS)
