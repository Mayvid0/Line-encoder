# Specify the compiler
CXX = g++

# Specify compiler flags
CXXFLAGS = -std=c++11

# Specify SFML installation directory
SFML_DIR_MACOS = /opt/homebrew/Cellar/sfml/2.6.1

#dir C:\ /s /b | findstr /i "SFML" can find the directory where sfml is stored at, if u manually can't find it
SFML_DIR_WINDOWS = C:/SFML

#find / -type d -name "SFML-*" 2>/dev/null
SFML_DIR_LINUX = /usr

# Detect the operating system
UNAME_S := $(shell uname -s)

# Set SFML directory based on the operating system
ifeq ($(UNAME_S),Darwin)
    SFML_DIR = $(SFML_DIR_MACOS)
else ifeq ($(UNAME_S),Linux)
    SFML_DIR = $(SFML_DIR_LINUX)
else
    SFML_DIR = $(SFML_DIR_WINDOWS)
endif

# Specify include paths
INCLUDES = -I$(SFML_DIR)/include

# Specify library paths
LDFLAGS = -L$(SFML_DIR)/lib

# Specify libraries to link
LIBS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

# Specify the target executable
TARGET = openWindowApp

# Specify source files
SRCS = $(wildcard src/*.cpp) 

# Specify object files
OBJS = $(SRCS:src/%.cpp=bin/%.o)

# Specify the asset files
ASSETS_DIR = assets
ASSETS = $(wildcard $(ASSETS_DIR)/*)

# Specify the destination for copied assets
ASSETS_DEST_DIR = bin/assets 

all: install_dependencies $(TARGET) copy_assets

install_dependencies:
	# Add installation steps for each platform if needed

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to copy assets to the build directory
copy_assets: $(ASSETS)
	mkdir -p $(ASSETS_DEST_DIR)
	cp $(ASSETS) $(ASSETS_DEST_DIR)

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(ASSETS_DEST_DIR)
