CC = gcc
FLAGS = -ggdb
INCLUDES = -I/usr/lib64
LIBS = -lcheck
PROJECT_OBJECTS = ../file.c ../filename.c ../validation.c
TEST_OBJECTS = test.c test_file.c test_filename.c test_validation.c

.PHONY: clean

tests:
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) $(PROJECT_OBJECTS) $(TEST_OBJECTS) -o tests

clean:
	rm -rf *.o tests

