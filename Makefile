OBJECTS = file.c filename.c templating.c heading.c bstrlib/bstrlib.c
MOD_SOURCE = mod_miniplate.c
INCLUDES = -I/usr/include/libxml2
LIBS = -lxml2 -lgumbo
APXS = apxs -n miniplate -i -a -c $(INCLUDES) $(LIBS) $(MOD_SOURCE) $(OBJECTS)
CC = gcc
CC_FLAGS = -c

.PHONY: default
default:
	$(CC) $(INCLUDES) $(LIBS) $(CC_FLAGS) $(OBJECTS)
	$(APXS)

clean:
	rm -f *.o
	rm -f *.la
	rm -f *.lo
	rm -f *.slo

