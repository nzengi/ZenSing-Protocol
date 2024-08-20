# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Source and test files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TESTS = $(wildcard $(TEST_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable
TARGET = zensign

# Build rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.PHONY: test
test: $(TARGET)
	@for test in $(TESTS); do \
		$(CXX) $(CXXFLAGS) $$test $(SRCS) -o test_exec && ./test_exec; \
	done

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET) test_exec
