#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/ram
EJEC :=./ram
RUN :=./bin/ram
OUTPUT := bin/*.out

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall #--debug #-O2 
LIB := #-lsfml-graphics -lsfml-window -lsfml-system #-pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include


$(TARGET): $(OBJECTS)  	
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)  
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS)  -c -o $@ $<

run1:
	$(RUN) ejemplosRAM/test1.ram bin/input_tape.in bin/output_tape.out 1

run2:
	$(RUN) ejemplosRAM/test2.ram bin/input_tape.in bin/output_tape.out 1

run3:
	$(RUN) ejemplosRAM/test3.ram bin/input_tape.in bin/output_tape.out 1

run4:
	$(RUN) ejemplosRAM/test4.ram bin/input_tape.in bin/output_tape.out 1

run5:
	$(RUN) ejemplosRAM/test5.ram bin/input_tape.in bin/output_tape.out 1

run6:
	$(RUN) ejemplosRAM/test6.ram bin/input_tape.in bin/output_tape.out 1

run7:
	$(RUN) ejemplosRAM/test7.ram bin/input_tape.in bin/output_tape.out 1

run8:
	$(RUN) ejemplosRAM/testn.ram bin/input_tape.in bin/output_tape.out 1

run9:
	$(RUN) ejemplosRAM/testlog.ram bin/input_tape.in bin/output_tape.out 1

debug:

	$(CC) $(CFLAGS) *

clean:
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(OUTPUT)"; $(RM) -r $(BUILDDIR) $(TARGET) $(OUTPUT)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean
