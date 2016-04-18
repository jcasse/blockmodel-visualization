DIR     = .
TARGET  = main

C       = g++
WFLAGS  = -W -Wall -Wextra -Wsign-promo -Werror
LFLAGS  = 
CFLAGS  = -c -O2 -ansi -pedantic-errors $(WFLAGS)
LIBS	  = -lGL -lglut -lGLU

HDRS    = $(shell find $(DIR) -name '*.h')
SRCS    = main.cpp
OBJS    = $(SRCS:.cpp=.o)

.PHONY: all clean tar build rebuild

all: build

$(TARGET): $(OBJS)
	$(C) $^ $(LIBS) -o $@

%.o: %.cpp
	$(C) $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(TARGET) *.gz .??* *.tgz *.zip

tar:
	tar -czf $(LOGNAME).tar.gz

build: $(TARGET)

rebuild: clean build
