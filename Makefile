TARGET = prog
LIBS = -lm
CC = gcc
CPPFLAGS = -g -Wall
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

.PHONY: default all clean test profile

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

CPPUTEST_HOME = /usr/local/Cellar/cpputest/3.8
CPPFLAGS += -I$(CPPUTEST_HOME)/include

%.o: %.c $(HEADERS)
		$(CC) $(CPPFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
		echo $(OBJECTS)
		$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
		-rm -f *.o
		-rm -f $(TARGET)

TEST_FILES = $(wildcard test/*.cpp)
test: $(OBJECTS) 
	g++ $(CPPFLAGS) $(LD_LIBRARIES) mp_arith.c montgomery.c $(TEST_FILES) -o test_runner
	./test_runner -c

profile:
	gcc $(CPPFLAGS) mp_arith.c montgomery.c test/profile.c -o profile -pg
