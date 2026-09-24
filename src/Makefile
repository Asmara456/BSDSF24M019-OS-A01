# src/Makefile: compiles all .c files and links them into one executable
CC      = gcc
CFLAGS  = -Wall -Wextra -I../include
OBJDIR  = ../obj
BINDIR  = ../bin
TARGET  = $(BINDIR)/client
SRCS    = main.c mystrfunctions.c myfilefunctions.c
OBJECTS = $(SRCS:%.c=$(OBJDIR)/%.o)
HEADERS = $(wildcard ../include/*.h)

all: $(TARGET)

# Linking rule: build the executable from all object files
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Pattern rule: build each .o in obj/ from the matching .c in src/
$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
