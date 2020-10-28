CC = clang++ -std=c++11

#The Target Binary Program
TARGET      	:= p2pFileSharing

#The Directories - Source, Objects and Binary
SRC_DIR			:= ./src
INC_DIR 		:= -I./include
OBJ_DIR 		:= ./obj
TARGET_DIR 		:= ./bin

SRC_FILES 		:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES		:= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET_FILES	:= $(TARGET_DIR)/$(TARGET)

$(TARGET_FILES): $(OBJ_FILES)
	$(CC) -o $@ $^

$(OBJ_FILES): | $(OBJ_DIR)

$(TARGET_FILES): | $(TARGET_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(INC_DIR) -c -o $@ $<

$(TARGET_DIR): 
	mkdir -p $(TARGET_DIR)

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(TARGET_DIR)