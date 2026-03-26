CXX = g++
CXXFLAGS = -I./include -Wall -Wextra
SRCDIR = src
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/fun.cpp $(SRCDIR)/methods_solutions.cpp
TARGET = main.exe

.PHONY: all clean run rebuild runandrun

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET)

rebuildandrun: clean $(TARGET)
	./$(TARGET)

clean:
	del /Q $(TARGET) 2>nul || true
