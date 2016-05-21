################################################################################
## variables
################################################################################

# explicitly defines to avoid confusion if inherited from environment
SHELL         := /bin/sh

# defines the chraracter that deonte the start of a recipie line
.RECIPEPREFIX := \t

PROJECT       := $(shell basename $(CURDIR))
GOAL          := bin/$(PROJECT)

SRCDIR        := src
BLDDIR        := build
DEPDIR        := .d

SRC           := $(wildcard $(SRCDIR)/*.cpp)
OBJ           := $(patsubst $(SRCDIR)/%,$(BLDDIR)/%,$(SRC:.cpp=.o))
DEP           := $(patsubst $(SRCDIR)/%,$(DEPDIR)/%,$(SRC:.cpp=.d))

CPP           := g++

DEPFLAGS       = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
WFLAGS        := -W -Wall -Wextra -Werror -Wfatal-errors
CPPFLAGS      := -O3 -ansi -std=gnu++11
INC           := -I include

Compile        = $(CPP) $(DEPFLAGS) $(CPPFLAGS) $(INC) -c
Link           = $(CPP) $(LDFLAGS) $(LDLIBS)
OUTPUT_OPTION  = -o $@
POSTCOMPILE    = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

################################################################################
## rules
################################################################################

$(GOAL): $(OBJ)
	@echo "Linking..."
	$(Link) $(OUTPUT_OPTION) $^

$(BLDDIR)/%.o: $(SRCDIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	@echo "Compiling..."
	$(Compile) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR):
	@mkdir $@

$(DEPDIR)/%.d: ;

.PRECIOUS: $(DEPDIR)/%.d

-include $(DEP)

.PHONY: clean test info

clean:
	@echo " Cleaning..."
	rm -f $(BLDDIR)/* $(DEPDIR)/* $(GOAL)

tests:
	$(CC) $(CPPFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

info:
	$(CPP) $(CPPFLAGS) -dM -E - < /dev/null
