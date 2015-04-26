CC = gcc
PROJ = m

SRCS = \
    alg_lin.c

CDEPS =
LDEPS =

OBJS = ${SRCS:.c=.o}
HEADS = ${OBJS:.o=.h}

LFLAG = -Wall -g -O3 -std=c11 -pedantic
LIBS = -lm

all: alert main

main: main.c $(OBJS) $(LDEPS)
	$(Ltag) $(PROJ) $(Rtag)
	@$(CC) $(LFLAG) main.c $(LDEPS) $(OBJS) $(LIBS) -o $(PROJ)

%.o : %.c %.h
	$(Ctag) $< $(Rtag)
	@$(CC) -c $(LFLAG) $< $(LIBS) -o $@

alert:
	$(ALERTTAG) $(Rtag)

rm: clean
clean:
	$(REDTAG)"rm $(OBJS) "$(PURPLETAG)"$(PROJ)"$(Rtag)
	@rm $(OBJS) $(PROJ)

#
#
#
#
#
#
#
#
#color tags
Ctag= @echo -e "\e[92m    COMPILING OBJECT:"
Ltag= @echo -e "\e[95m    LINKING:"
REDTAG= @echo -e "\e[91m"
GREENTAG= "\e[92m"
PURPLETAG= "\e[95m"
ALERTTAG= @echo -e "\e[91m    making..."
COLORTAG= @echo -e "\e[91m"
Rtag= "\e[0m"
