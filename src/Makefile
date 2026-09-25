# src/Makefile: builds static (.a) and dynamic (.so) libraries, links both clients
CC          = gcc
AR          = ar
CFLAGS      = -Wall -Wextra -I../include
FPIC        = -fPIC
OBJDIR      = ../obj
BINDIR      = ../bin
LIBDIR      = ../lib
LIBNAME     = myutils
STATIC_LIB  = $(LIBDIR)/lib$(LIBNAME).a
DYNAMIC_LIB = $(LIBDIR)/lib$(LIBNAME).so
TARGET_STATIC  = $(BINDIR)/client_static
TARGET_DYNAMIC = $(BINDIR)/client_dynamic
LIB_SRCS    = mystrfunctions.c myfilefunctions.c
LIB_OBJS    = $(LIB_SRCS:%.c=$(OBJDIR)/%.o)
LIB_POBJS   = $(LIB_SRCS:%.c=$(OBJDIR)/%.pic.o)
MAIN_OBJ    = $(OBJDIR)/main.o
HEADERS     = $(wildcard ../include/*.h)

all: $(TARGET_STATIC) $(TARGET_DYNAMIC)

# --- Static build ---
$(TARGET_STATIC): $(MAIN_OBJ) $(STATIC_LIB)
	$(CC) $(MAIN_OBJ) -L$(LIBDIR) -l$(LIBNAME) -o $@

$(STATIC_LIB): $(LIB_OBJS)
	$(AR) rc $@ $(LIB_OBJS)
	ranlib $@

$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Dynamic build ---
$(TARGET_DYNAMIC): $(MAIN_OBJ) $(DYNAMIC_LIB)
	$(CC) $(MAIN_OBJ) -L$(LIBDIR) -l$(LIBNAME) -o $@

$(DYNAMIC_LIB): $(LIB_POBJS)
	$(CC) -shared -o $@ $(LIB_POBJS)

$(OBJDIR)/%.pic.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(FPIC) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(STATIC_LIB) $(DYNAMIC_LIB) $(TARGET_STATIC) $(TARGET_DYNAMIC)

.PHONY: all clean
