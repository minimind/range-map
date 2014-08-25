CC     = g++
CFLAGS = -Wall -O2
SRC    = unittest/main.cpp
TARGET = test_rangemap

OBJ = $(SRC:.cpp=.o)

all:	$(TARGET)

$(TARGET):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
