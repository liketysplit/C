SRC_DIR = ./src_files
INC_DIR = ./inc_files
OBJ_DIR = ./obj_files
BIN_DIR = ./bin_files

CC = gcc
_OBJS = main.o rcards.o sort.o
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(_OBJS))
_SRCS = $(patsubst %.o, %.c, $(_OBJS))
SRCS = $(patsubst %, $(SRC_DIR)/%, $(_SRCS))
CFLAGS = -g -I$(INC_DIR) -w
LDFLAGS = -lm 

all: $(BIN_DIR)/CardGen

$(BIN_DIR)/CardGen: $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

dependencies:  $(SRCS)
	$(CC) -I$(INC_DIR) -MM $^ | sed '/^.*.o:/ s#^#$(OBJ_DIR)/#' > $@

include dependencies