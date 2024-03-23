#Makefile

all:
	@clang -lreadline main.c libhost/libhost.c libinfo/libinfo.c libconv/libconv.c -o pterm
