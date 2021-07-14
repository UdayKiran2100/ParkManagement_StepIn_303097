#ifndef _park_lib_
    
    #define _park_lib_

    #define MAXPARKSIZE 100


    /**
     * @brief parklist structure This structure contains 4 elments and is used throughout the program to describe a member entering a  park.
     * 
     * ->name - stores the name of the individual
     * ->token_number- Unique token assigned to each individual
     * ->in_time- The time of entry of an individual into a park
     * ->next- Pointer to the next node of the linked list 
     */
    typedef struct parklist{
        char name[20];
        int token_number;
        int in_time;
        struct parklist *next;
    }parkList;
    /*
        Structure to store the details of the individuals in the park
        This structure can be used to create variables of the given type
    */

   /**
    * @brief tokenstack structure Used to store the token numbers which are avaailable for use.
    * 
    * ->tokennumber- the unique number
    * -> top- the index of the top element in the stack
    * 
    */
    typedef struct tokenstack
    {
        int tokenno[MAXPARKSIZE];
        int top;
    }tokenStack;

    /*
        Structure to store the token numbers which are unused and can be reserved for incoming population. 
    */


    parkList* addIndividual( parkList *head, char *name, int token , int time );



    parkList* deleteIndividual_beginning(parkList *head);


    parkList* deleteIndividual(parkList *head, int token);


    int push_token(tokenStack *st,int data);


    int pop_token(tokenStack *st);


    int print_parkdetails_toFile(parkList *head);


    int print_parkdetails(parkList *head);


    parkList* multithread(parkList *phead);


    parkList* chooseInput(parkList *phead, tokenStack *stack, int *f);

#endif