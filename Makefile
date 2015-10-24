CPP=g++
CFLAGS=-Wall -O2 -g -pthread

ALLCPPEXE=$(patsubst %.cc,%,$(wildcard *.cc))

all: $(ALLCEXE) $(ALLCPPEXE)

$(ALLCPPEXE): %: %.cc
	$(CPP) $(CFLAGS) -o $@ $< $(LIB)

clean:
	rm -rf $(ALLCEXE) $(ALLCPPEXE) $(ALLCPPEXE) *.dSYM
