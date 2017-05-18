#compile
CC = gcc
CFLAG = -Wall -Werror -std=gnu99
#folder define
SRC = src
BIN = bin
BUILD = build/src
DIRGUARD=@mkdir -p $(@D)
#target
TARGET   = prog_lab5
#sources
SOURCES  := $(wildcard $(SRC)/*.c)
#INCLUDES := $(wildcard $(SRC)/*.h)
#objects
OBJECTS  := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)

rm       = rm -f

$(BIN)/$(TARGET): $(OBJECTS)
	@$(DIRGUARD)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(BUILD)/%.o : $(SRC)/%.c
	@$(DIRGUARD)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(OBJECTSTEST)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BIN)/*
	@echo "Executable removed!"