OBJECTS = file.c filename.c templating.c bstrlib/bstrlib.c
MOD_SOURCE = mod_miniplate.c
APXS = apxs -n miniplate -i -a -c $(MOD_SOURCE) $(OBJECTS)
CC = gcc
CC_FLAGS = -c

.PHONY: default
default:
	$(CC) $(CC_FLAGS) $(OBJECTS)
	$(APXS)

