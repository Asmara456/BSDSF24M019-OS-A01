# src/Makefile: builds a static library, then links main against it
CC         = gcc
AR         = ar
CFLAGS     = -Wall -Wextra -I../include
OBJDIR     = ../obj
BINDIR     = ../bin
LIBDIR     = ../lib
LIBNAME    = myutils
STATIC_LIB = $(LIBDIR)/lib$(LIBNAME).a
TARGET     = $(BINDIR)/client_static
LIB_SRCS   = mystrfunctions.c myfilefunctions.c
LIB_OBJS   = $(LIB_SRCS:%.c=$(OBJDIR)/%.o)
MAIN_OBJ   = $(OBJDIR)/main.o
HEADERS    = $(wildcard ../include/*.h)

all: $(TARGET)

# Link: main.o + static library -> executable
$(TARGET): $(MAIN_OBJ) $(STATIC_LIB)
	$(CC) $(MAIN_OBJ) -L$(LIBDIR) -l$(LIBNAME) -o $@

# Archive: library objects -> libmyutils.a
$(STATIC_LIB): $(LIB_OBJS)
	$(AR) rc $@ $(LIB_OBJS)
	ranlib $@

# Pattern rule: each .c in src/ -> .o in obj/
$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(STATIC_LIB) $(TARGET)

.PHONY: all clean
