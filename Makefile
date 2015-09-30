

CXX = g++

LIBS = -lcurl

OBJ_DIR = ./.obj

HDRS = $(wildcard *.hpp)
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = ./neo

LOG_FILES = log.txt
OTHER_FILES = 

TOUCH = touch
RM = rm -f

.PHONY: all run clean touch

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	
	$(TARGET)

clean:
	echo "hi"
	$(RM) $(OBJS)
	$(RM) $(TARGET)
	$(RM) $(LOG_FILES)
#	$(RM) $(OTHER_FILES)

touch:
	$(TOUCH) $(wildcard *)

