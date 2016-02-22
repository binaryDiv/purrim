# == PurrIM Makefile ==

# C++ flags
CXXFLAGS := -std=c++11 -O2 -g -Wall -fmessage-length=0
LIBS :=
INCLUDES :=

# Project directories
SRCDIR := src
BUILDDIR := build
BINDIR := bin

# Target variables
TARGET := $(BINDIR)/purrim
SOURCES := $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))
CLEANDELETE :=

HEADERS := $(shell find $(SRCDIR) -type f -name *.h)
SOURCEDEPS := $(HEADERS)

# MAKE TARGETS
# ------------

# Default 'all' target
all: $(TARGET)

# App target
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) -o $(TARGET) $(OBJECTS) $(LIBS)

# Object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

# Clean generated files
clean:
	rm -r $(BUILDDIR)
	rm -f $(TARGET) $(CLEANDELETE)

.PHONY: all clean run todo

