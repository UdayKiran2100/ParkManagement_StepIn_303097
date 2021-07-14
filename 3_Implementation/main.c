#include "default_Libraries.h"
#include "parkdef.h"



int main()
{
    parkList *phead=NULL;

    tokenStack stack;

    int f=1;
    stack.top=-1;
    
    int *t=(int*)calloc(MAXPARKSIZE,sizeof(int));
    
    //parkList *phead=NULL;
    FILE *fptr;
    
    fptr=fopen("park_details.txt","r");
   
    if(fptr!=NULL)
    {   
        char temp[40];
        fgets(temp,40,fptr);
        while(!feof(fptr))
        {
            
            char temp_name[20];
            int temp_token;
            char *tok;
            int temp_time;
            
            tok=strtok(temp,":");
            strcpy(temp_name,tok);
            
            tok=strtok(NULL,":");
            temp_token=atoi(tok);
            
            tok=strtok(NULL,"\n");
            temp_time=atof(tok);

            phead= addIndividual(phead,temp_name,temp_token,temp_time);
            t[temp_token-1]=-1;

            fgets(temp,40,fptr);
            if(strlen(temp)<=1)
                break;
        }
        
        print_parkdetails(phead);
    }
   

    for(int i=MAXPARKSIZE-1;i>=0;i--)
    {
        if(t[i]==0)
        {
            push_token(&stack,i+1);
        }
    }
    
    free(t);
    
    if(fptr!=NULL)
        fclose(fptr);
        
    
    while(f==1)
    {
        
       phead= chooseInput(phead,&stack,&f);
       //if(phead==NULL)
       // return 0;
    } 
    
}