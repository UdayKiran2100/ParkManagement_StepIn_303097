#include "default_Libraries.h"
#include "parkdef.h"

/**
 * @brief This function is used to push the tokens that have not been in use currently.
 * It further helps in generating unique tokens
 * @param st It is the pointer that holds the stack  address for generating the tokens as required.
 * @param data It is the value of the token that is free.
 * @return int It returns 0 if stack is full. Else the top index value of the stack.
 */
int push_token(tokenStack *st,int data)
{
    if( st->top== ( MAXPARKSIZE-1) )
    {
        printf("Park is FULL\n");
        return 0;
    }
    else
    {
        st->top++;
        st->tokenno[st->top]=data;
    }
    return st->top;
}

/**
 * @brief This function is used to pop the unique tokens.
 * It helps in generating unique tokens
 * @param st It is the pointer that holds the stack  address for generating the tokens as required.
 * @return int It returns 0 if stack is empty. Else the element at top index value of the stack.
 */

int pop_token(tokenStack *st)
{
    if( st->top==-1 )
    {
        printf("\nPark is Empty\n");
        return -1;
    }
    else
    {
        return st->tokenno[st->top--];
    }
}