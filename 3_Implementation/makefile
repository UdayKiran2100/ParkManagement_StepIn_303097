PROJ_NAME = Park_Management
TEST_PROJ_NAME = Test_$(PROJ_NAME)
BUILD_DIR = build


ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif


SRC = \
main.c \
src/parkAdd.c \
src/parkDelete.c \
src/parkPrint.c \
src/tokenHandler.c \
src/userChoice.c \

TEST_SRC = test_factorial.c\
unity/unity.c



INC = \
inc\

TEST_INC = \
unity\

all: $(SRC) $(BUILD_DIR)
	gcc $(SRC) -I$(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)