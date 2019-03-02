SHELL		:= /bin/bash
RM			:= rm -rf
MKDIR		:= mkdir -p
NAME		:= 42sh
BUILD_DIR	:= build

all: ./build/Makefile $(NAME)

$(NAME):
	@ $(MAKE) -C $(BUILD_DIR)
	@ cp $(BUILD_DIR)/$(NAME) .

./build/Makefile:
	@ $(MKDIR) $(BUILD_DIR) > /dev/null
	@ cd $(BUILD_DIR) > /dev/null 2>&1 && cmake ..

cclean:
	@ $(MAKE) -C $(BUILD_DIR) clean

clean:
	@ $(RM) $(BUILD_DIR)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all