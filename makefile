#################################################
# MAKEFILE
#################################################

CXX		 := g++
CXXFLAGS := -std=c++11

BIN     := bin
SRC     := src
BUILD		:= build
INCLUDE := include
LIB     := lib
LIBRARIES := 
EXECUTABLE  := $(notdir $(CURDIR))

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJS	:= $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cpp
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src

run:
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*