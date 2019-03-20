SHELL		:= /bin/bash
RM			:= rm -rf
MKDIR		:= mkdir -p
NAME		:= 42sh
BUILD_DIR	:= build
SHRC		:= .42shrc

all: ./build/Makefile
	@ $(MAKE) -C $(BUILD_DIR)
	@ cp $(BUILD_DIR)/$(NAME) .
	@ cp -f $(SHRC) ~

./build/Makefile:
	@ $(MKDIR) $(BUILD_DIR) > /dev/null
	@ cd $(BUILD_DIR) > /dev/null 2>&1 && cmake ..

cclean:
	@ $(MAKE) -C $(BUILD_DIR) clean

clean:
	@ $(RM) $(BUILD_DIR)

fclean: clean
	@ $(RM) $(NAME)
	@ $(RM) $(NAME).dSYM

re: fclean all
