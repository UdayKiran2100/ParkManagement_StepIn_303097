#include "default_Libraries.h"
#include "parkdef.h"


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