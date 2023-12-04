CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
INCLUDES = -I/Users/nicholasburczyk/Documents/coding/C/sfml/include
LIB_PATH = -L/Users/nicholasburczyk/Documents/Coding/C/build/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
RPATH = -Wl,-rpath,./build/lib

SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIB_PATH) $(LIBS) $(RPATH)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
