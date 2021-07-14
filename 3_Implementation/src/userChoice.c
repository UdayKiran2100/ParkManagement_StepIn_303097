#include "default_Libraries.h"
#include "parkdef.h"
#include "linuxconio.h"

parkList* multithread(parkList *phead)
{
    
        clock_t t=clock();
        if(phead==NULL)
            return NULL;
        parkList *h=phead;
        int diff=(int)(t-(h->in_time))/CLOCKS_PER_SEC;
        if(diff>=100)
        {
            printf("%s with token %d needs to exit the park(Time is UP) ",h->name,h->token_number);
            h=deleteIndividual_beginning(h);
            phead=h;
            printf("delete\n");
        }
        print_parkdetails_toFile(phead);
        return phead;
        //usleep(60);
}


parkList* chooseInput(parkList *phead, tokenStack *stack, int *f)
{
    FILE *fptr;
    //while(f==1)
    //{
        
        char choice='0';
        printf("Enter \t'A' for new entry.\n\t'B' for exiting person.\n\t'C' for printing park details\n\t'D' for application exit and clear park.\n\t'E' for logout\n");
        //scanf("%c",&choice);
        while(1)
        {
            if(!kbhit())
            {
                phead=multithread(phead);
                continue;
            }
            else{
                choice=fgetc(stdin);
                fflush(stdin);
                break;
            }
        }
            
       // printf("%d",choice);
        //usleep(1000);
        switch(choice)
        {
            case 'A':
                printf("\nEnter name\n");
                
                char name[20];
                int token1;
                while(1)
                {
                    if(!kbhit())
                    {
                        phead=multithread(phead);
                        continue;
                    }
                    else{
                        fgets(name,20,stdin);
                        fflush(stdin);
                        break;
                    }
                }

                
                char *tok=strtok(name,"\n");
                strcpy(name,tok);
                //fflush(stdin);
                token1=pop_token(stack);
                clock_t time=clock();
                int time1=(int)time;
                if(token1>0)
                    phead=addIndividual(phead,name,token1,time1);
                    
                break;
            
            case 'B':
                printf("\nEnter token number who wants to exit\n");
                int token2;
                scanf("%d",&token2);
                fflush(stdin);
                push_token(stack,token2);
                phead=deleteIndividual(phead,token2);
                
                break;

            case 'C':
                print_parkdetails(phead);
                break;

            case 'D':
                fptr=fopen("park_details.txt","w");
                fclose(fptr);
                free(phead);
                *f=0;
                break;

            case 'E':
                print_parkdetails_toFile(phead);
                free(phead);
                *f=0;
                break;
            
            case '0':
                return NULL;

            default:
                printf("\nInvalid Choice,Error\n");
                //return NULL;
        }
    //}
    return phead;
}