CC = gcc

INCLUDE_PATHS := $(shell cat .vscode/c_cpp_properties.json | jq -r '.configurations[0].includePath[1:] | join(" ")')
INCLUDES=$(INCLUDE_PATHS:%=-I%)

# The CFLAGS variable sets compile flags for gcc:
#  -g          compile with debug information
#  -Wall       give verbose compiler warnings
CFLAGS += -g -Wall $(INCLUDES)

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = firewall_hook
BUILD_TARGET = $(BUILD_DIR)/$(TARGET)

all: $(TARGET)

$(TARGET):
	$(CC) -o $(BUILD_TARGET) $(SOURCES) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILD_TARGET) $(OBJECTS) core