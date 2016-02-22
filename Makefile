MOD_SOURCE = mod_miniplate.c
CC = apxs -i -a -c $(MOD_SOURCE)

.PHONY: default
default:
	$(CC)

