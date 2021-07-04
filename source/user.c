#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXPARKSIZE 100

int park_population=0;

typedef struct parklist{
    char name[20];
    int token_number;
    struct parklist *next;
}parkList;


typedef struct tokenstack
{
    int tokenno[MAXPARKSIZE];
    int top;
}tokenStack;



parkList* addIndividual( parkList *head, char *name, int token )
{
    parkList *new=(parkList*)malloc(sizeof(parkList));
    strcpy(new->name,name);
    new->token_number=token;
    new->next=NULL;

    if(head==NULL)
    {
        head=new;
        return head;
    }
    else
    {
        parkList *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
    return head;
}

parkList* deleteIndividual_beginning(parkList *head)
{
    if(head==NULL)
    {
        printf("The park is empty\n");
        return head;
    }
    else
    {
        parkList *temp=head;
        head=head->next;
        //free(temp);
    }
    return head;
}

parkList* deleteIndividual(parkList *head, int token)
{
    if(head==NULL)
    {
        printf("Park is Empty\n");
        return head;
    }
    else
    {
        parkList *temp=head;
        parkList *prev=head;
        while(temp->next!=NULL && temp->token_number!=token)
        {   
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            printf("The individual with given token number is not present in park\n");
        }
        else
        {
            prev->next=temp->next;
        }
    }
    return head;
}

void push_token(tokenStack *st,int data)
{
    if( st->top== ( MAXPARKSIZE-1) )
    {
        printf("Park is FULL\n");
    }
    else
    {
        st->top++;
        st->tokenno[st->top]=data;
    }
}

int pop_token(tokenStack *st)
{
    if( st->top==-1 )
    {
        printf("Park is Empty\n");
        return 0;
    }
    else
    {
        return st->tokenno[st->top--];
    }
}

void print_parkdetails_toFile(parkList *head)
{
    FILE *fptr=fopen("park_details.txt","w");
    parkList *temp=head;
    while(temp!=NULL)
    {
        fprintf(fptr,"%s:%d \n",temp->name,temp->token_number);
        temp=temp->next;
    }
}

void print_parkdetails(parkList *head)
{
    
    parkList *temp=head;
    while(temp!=NULL)
    {
        printf("%s:%d\n",temp->name,temp->token_number);
        temp=temp->next;
    }
}

void main()
{
    tokenStack stack;
    stack.top=-1;

    int *t=(int*)calloc(MAXPARKSIZE,sizeof(int));

    parkList *phead=NULL;
    FILE *fptr;

    fptr=fopen("park_details.txt","r");

    if(fptr!=NULL)
    {   
        char temp[40];
        fgets(temp,30,fptr);
        while(!feof(fptr))
        {
            
            char temp_name[20];
            int temp_token;
            char *tok;
            
            
            tok=strtok(temp,":");
            strcpy(temp_name,tok);
            tok=strtok(NULL,"\n");
            temp_token=atoi(tok);
            //tok=strtok(NULL,"\n");
           
            phead = addIndividual(phead,temp_name,temp_token);
            t[temp_token-1]=-1;

            fgets(temp,30,fptr);
            if(strlen(temp)<=1)
                break;
        }
    }
    print_parkdetails(phead);

    for(int i=MAXPARKSIZE-1;i>=0;i--)
    {
        if(t[i]==0)
        {
            push_token(&stack,i+1);
        }
    }
    free(t);
    fclose(fptr);
    char choice;
    
    
    
    
    int f=1;
    while(f==1)
    {
        printf("Enter \t'A' for new entry.\n\t'B' for exiting person.\n\t'C' for printing park details\n\t'D' for application exit and clear park.\n\t'E' for logout\n");
        scanf("%c",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 'A':
                printf("Enter name\n");
                char name[20];
                int token1;
                scanf("%[^\n]",name);
                fflush(stdin);
                token1=pop_token(&stack);
                
                if(token1>0)
                    phead=addIndividual(phead,name,token1);
                
                break;
            
            case 'B':
                printf("Enter token number who wants to exit\n");
                int token2;
                scanf("%d",&token2);
                fflush(stdin);
                push_token(&stack,token2);
                phead=deleteIndividual(phead,token2);
                
                break;

            case 'C':
                print_parkdetails(phead);
                break;

            case 'D':
                fptr=fopen("park_details.txt","w");
                fclose(fptr);
                free(phead);
                f=0;
                break;

            case 'E':
                print_parkdetails_toFile(phead);
                free(phead);
                f=0;
                break;

            default:
                printf("Invalid Choice\n");
        }
    }
}