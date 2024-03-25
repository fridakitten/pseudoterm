#Makefile

all:
	@clang -lreadline -framework Foundation main.c libhost/libhost.c libinfo/libinfo.c libconv/libconv.c libexec/libexec.m -o pterm
