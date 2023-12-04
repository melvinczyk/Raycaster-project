CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
INCLUDES = -I/Users/nicholasburczyk/Documents/coding/C/sfml/include
LIB_PATH = -L/Users/nicholasburczyk/Documents/Coding/C/build/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
RPATH = -Wl,-rpath,./build/lib

SRCS = src/main.cpp src/Game.cpp src/Map.cpp src/Player.cpp src/RayCasting.cpp src/Settings.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = raycast

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIB_PATH) $(LIBS) $(RPATH)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
