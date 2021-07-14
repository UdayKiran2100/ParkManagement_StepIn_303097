#include "unity.h"
#include "parkdef.h"
#include "default_Libraries.h"



/* Modify these two lines according to the project */
#define PROJECT_NAME  "ParkManagement"

/* Prototypes for all the test functions */
void test_parkadd(void);
void test_parkdelete_beginning(void);
void test_parkdelete(void);
void test_print_toFile(void);
void test_print(void);
void test_pushtoken(void);
void test_poptoken(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_parkadd);
  RUN_TEST(test_parkdelete_beginning);
  RUN_TEST(test_parkdelete);
  RUN_TEST(test_print_toFile);
  RUN_TEST(test_print);
  RUN_TEST(test_pushtoken);
  RUN_TEST(test_poptoken);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 

/**
 * @brief Used to test the working of the function addIndividual.
 * 
 */
void test_parkadd(void)
{
    char name[20]="Uday"; 
    int token,time;
    parkList *head = (parkList*)malloc(sizeof(parkList));
    time=10002;
    token=1;
    head->in_time = time;
    head->token_number=token;
    strcpy(head->name,name);

    TEST_ASSERT_EQUAL(head, addIndividual(head,name,2,10005));   
}


/**
 * @brief Used to check the working of the function delete from beginning
 * 
 */
void test_parkdelete_beginning(void)
{
  parkList *temp1 = (parkList*)malloc(sizeof(parkList));
  parkList *temp2 = (parkList*)malloc(sizeof(parkList));
  temp1->next=temp2;

  TEST_ASSERT_EQUAL(temp2, deleteIndividual_beginning(temp1));

}

/**
 * @brief Used to check the working of the function delete from anywhere in list.
 * 
 */
void test_parkdelete(void)
{
  parkList *temp1 = NULL;
  
  TEST_ASSERT_EQUAL(temp1, deleteIndividual(temp1,1));

  temp1=(parkList*)malloc(sizeof(parkList));
  temp1->token_number=2;
  
  TEST_ASSERT_EQUAL(temp1, deleteIndividual(temp1,1));

  TEST_ASSERT_EQUAL(NULL, deleteIndividual(temp1,2));

  parkList *temp2 = (parkList*)malloc(sizeof(parkList));
  temp2->token_number=1;

  TEST_ASSERT_EQUAL(temp1, deleteIndividual(temp1,1));

}


/**
 * @brief Used to test the printing of the data to a file
 * 
 */
void test_print_toFile(void)
{
  parkList *temp1 = NULL;
  
  TEST_ASSERT_EQUAL(0, print_parkdetails_toFile(temp1));

  temp1=(parkList*)malloc(sizeof(parkList));
  temp1->token_number=2;
  temp1->in_time=1001;
  strcpy(temp1->name , "Uday");

  TEST_ASSERT_EQUAL(1, print_parkdetails_toFile(temp1));
  
}

/**
 * @brief Used to test the printing of the data to the terminal
 * 
 */
void test_print(void)
{
  parkList *temp1 = NULL;
  
  TEST_ASSERT_EQUAL(0, print_parkdetails(temp1));

  temp1=(parkList*)malloc(sizeof(parkList));
  temp1->token_number=2;
  temp1->in_time=1001;
  strcpy(temp1->name , "Uday");

  TEST_ASSERT_EQUAL(1, print_parkdetails(temp1));
  
}

/**
 * @brief Used to test the working of the push to stack operation on token values.
 * 
 */
void test_pushtoken(void)
{
  tokenStack stack;
  stack.tokenno[0]=1;
  stack.tokenno[1]=2;
  stack.tokenno[2]=3;
  stack.top=2;

  TEST_ASSERT_EQUAL(3, push_token(&stack,4));
  
  stack.top=99;
  TEST_ASSERT_EQUAL(0, push_token(&stack,5));

}


/**
 * @brief Used to test the working of the pop out of stack operations.
 * 
 */
void test_poptoken(void)
{
  tokenStack stack;
  stack.tokenno[0]=1;
  stack.tokenno[1]=2;
  stack.tokenno[2]=3;
  stack.top=2;

  TEST_ASSERT_EQUAL(3, pop_token(&stack));
  
  stack.top=-1;
  TEST_ASSERT_EQUAL(-1, pop_token(&stack));
  
}

