CC=g++
CFLAGS=-I.
DEPS = runperf.h
OBJ = runpred.o runperf.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runpred: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~
