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
src/parkAdd.c \
src/parkDelete.c \
src/parkPrint.c \
src/tokenHandler.c \
src/userChoice.c \

TEST_SRC = \
test/unity.c\
test/test_main.c\




INC = \
-Iinc\
-Itest\

TEST_INC = \
test\

all: $(SRC) $(BUILD_DIR)
	gcc $(SRC) main.c $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

# test_build: $(TEST_SRC) $(TEST_BUILD_DIR)
# gcc $(SRC) -I$(INC) $(TEST_INC) -o $(call FixPath,$(TEST_BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

test_build: $(SRC) $(TEST_SRC) $(BUILD_DIR)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))



test: test_build
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

#Coverage
coverageCheck:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

# test: test_build
#    $(call FixPath,$(TEST_BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# $(TEST_BUILD_DIR):
# 	mkdir $(TEST_BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)