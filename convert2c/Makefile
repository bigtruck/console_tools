TARGET=b2c
CC=gcc
CXX=g++
CXXFLAGS =-std=c++0x
OBJ=b2c.o
SRC=b2c.cpp

HEADER_PATH = -I/usr/local/include
LIB_PATH = -L/usr/local/lib

$(TARGET):$(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LIB_PATH) $(LIBS)

$(OBJ):$(SRC)
	$(CXX) -c $(SRC) $(HEADER_PATH) $(CXXFLAGS)

clean:
	rm $(OBJ) $(TARGET)
