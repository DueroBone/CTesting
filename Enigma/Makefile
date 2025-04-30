# === Config ===
CC = /usr/bin/gcc
SRC = $(wildcard *.c)
OUT = Enigma

# Default flags
CFLAGS = -O0 -Wall -Werror -fcolor-diagnostics -fansi-escape-codes -Xpreprocessor -fopenmp
INCLUDES = -I/usr/local/Cellar/libomp/20.1.3/include/
LIBS = -L/usr/local/Cellar/libomp/20.1.3/lib/ -lomp

# Check if MEMCHECK=1 is passed
ifeq ($(MEMCHECK),1)
    CFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
    LIBS += -fsanitize=address,undefined
endif

# === Rules ===
all:
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -g $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
