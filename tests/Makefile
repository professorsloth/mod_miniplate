CC = gcc
FLAGS = -ggdb
INCLUDES = -I/usr/lib64
LIBS = -lcheck
PROJECT_OBJECTS = ../file.c ../filename.c ../templating.c
LIBRARY_OBJECTS = ../bstrlib/bstrlib.c
TEST_OBJECTS = test.c test_file.c test_filename.c test_templating.c

.PHONY: clean

tests:
	$(CC) $(FLAGS) $(INCLUDES) $(LIBS) $(PROJECT_OBJECTS) $(LIBRARY_OBJECTS) $(TEST_OBJECTS) -o tests

clean:
	rm -rf *.o tests

