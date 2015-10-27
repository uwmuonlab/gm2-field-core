# Grab the targets and sources as two batches
SOURCES = $(wildcard src/*.cxx)
TARGETS = $(patsubst src/%.cxx,bin/%,$(SOURCES))

# Debugging/profiling flags
DEBUG = -g -pg

# Figure out the architecture
UNAME_S = $(shell uname -s)

# Clang compiler
ifeq ($(UNAME_S), Darwin)
	CXX = clang++
	CC  = clang
	FLAGS = -std=c++11 $(DEBUG)
endif

# Gnu compiler
ifeq ($(UNAME_S), Linux)
	CXX = g++
	CC  = gcc
	FLAGS = -std=c++0x $(DEBUG)
endif

LIBS = -lm -Lcore/lib -lgm2fieldcore
LIBS  += $(shell root-config --libs)

FLAGS += -Icore/include
FLAGS += $(shell root-config --cflags)

all: $(TARGETS)

bin/%: src/%.cxx 
	$(CXX) $(FLAGS) -o $@ $+ $(LIBS)

clean:
	rm -f $(OBJECTS) $(TARGETS)
