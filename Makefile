# Grab the targets and sources as two batches
OBJECTS = $(patsubst src/%.cxx, build/%.o, $(wildcard src/*.cxx))

# Library info.
MAJOR=0
MINOR=0.0
SONAME=libgm2fieldcore.so
ARNAME=libgm2fieldcore.a
LIBNAME=$(SONAME).$(MAJOR).$(MINOR)
PREFIX=/usr/local

# Figure out the architecture
UNAME_S = $(shell uname -s)

# Clang compiler
ifeq ($(UNAME_S), Darwin)
	CXX = clang++
	CC  = clang
	CPPFLAGS = -DOS_DARWIN
	CXXFLAGS = -std=c++11
endif

# Gnu compiler
ifeq ($(UNAME_S), Linux)
	CXX = g++
	CC  = gcc
	CPPFLAGS = -DOS_LINUX
	CXXFLAGS = -std=c++0x
endif

ifdef DEBUG
	FLAGS += -g -pg -fPIC -O3 -pthread
else
	FLAGS += -fPIC -O3 -pthread
endif

# DRS flags
CPPFLAGS += -DHAVE_USB -DHAVE_LIBUSB10 -DUSE_DRS_MUTEX

# ROOT libs and flags
CPPFLAGS += $(shell root-config --cflags)
LIBS = $(shell root-config --libs)

# wxWidgets libs and flags
CXXFLAGS += $(shell wx-config --cxxflags)
LIBS += $(shell wx-config --libs)

CPPFLAGS += -I. -Iinclude -Iinclude/drs
LIBS += -lm -lzmq -ljson_spirit -lCAENDigitizer -lusb-1.0 -lutil -lpthread

all: $(OBJECTS) $(OBJ_VME) $(OBJ_DRS) $(TARGETS) lib/$(ARNAME) $(DATADEF) \
	$(LOGFILE) $(CONFDIR)

$(LOGFILE):
	@mkdir -p $(@D)
	@touch $@

$(CONFDIR):
	@mkdir -p $(@D)
	@cp -r config $(@D)/

build/%.o: src/%.cxx $(DATADEF)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

build/%.o: include/vme/%.c $(DATADEF)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

build/%.o: src/drs/%.cpp $(DATADEF)
	$(CXX)  $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

build/%.o: src/drs/%.c $(DATADEF)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

fe_%: modules/fe_%.cxx $(OBJECTS) $(OBJ_VME) $(OBJ_DRS) $(DATADEF)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@ \
	$(OBJECTS) $(OBJ_VME) $(OBJ_DRS) $(LIBS) $(WXLIBS)

%_daq: modules/%_daq.cxx $(DATADEF)
	$(CXX) $< -o $@  $(CXXFLAGS) $(CPPFLAGS) $(LIBS)

lib/$(ARNAME): $(OBJECTS) $(OBJ_VME) $(OJB_DRS) $(DATADEF)
	$(AR) -rcs $@ $+

clean:
	rm -f $(TARGETS) $(OBJECTS) $(OBJ_VME) $(OBJ_DRS)
