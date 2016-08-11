#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 10
//void findFirst(char find, char *first, char *prod, int filled);

char findFirst(char find, char prod[][SIZE], int num);
int main()
{
    char prod[10][10];
    int num;
    char find;
    char first[10];
    int filled = 0;
    int i,j,k;
    //first[0] = '$';
    printf("\nEnter the number of production : \n");
    scanf("%d",&num);
    printf("\nEnter the productions (Format : A -> +b)\n");
    for(i= 0 ; i < num ; i++)
    {
        printf("\nEnter Production %d : ",i + 1);
        fflush(stdin);
        gets(prod[i]);
    }

    printf("\nNumber of productions : %d\n",num);
    /*
    for(i = 0 ; i < num ; i++)
    {
        printf("%s",prod[i]);
        printf("\n");
    }
    */
    printf("\nEnter literal to find FIRST\n");
    //fflush(stdin);
    scanf("%c",&find);
    //printf("\n%c",find);
    //findFirst(find, first, prod, filled);
    if(islower(find))
    {
        printf("\nFIRST(%c) = { %c }",find,find);
        exit(0);
    }
    else
    {
        for(i = 0 ; i < num ; i++)
        {
            for(j = 0 ; j < 1 ; j++)      //previously j < strlen(prod[i][j])
            {
                //printf("\nHere : %c\n",prod[i][j]);
                if(prod[i][j] == find)
                {
                    if(islower(prod[i][j+5]))
                    {
                        first[filled++] = prod[i][j+5];
                        //printf("\nHere : %c\n",prod[i][j+5]);
                    }
                    else if(prod[i][j+5] == '+' ||  prod[i][j+5] == '-' ||  prod[i][j+5] == '*' ||  prod[i][j+5] == '/')
                    {
                        first[filled++] = prod[i][j+5];
                        //printf("\nHere : %c\n",prod[i][j+5]);
                    }
                    else if(prod[i][j+5] == '$' && prod[i][j+6] == '\0')
                    {
                        first[filled++] = prod[i][j+5];
                    }
                    else if(isupper(prod[i][j+5]))
                    {
                        //findFirst(prod[i][j+5], first, prod, filled);
                        //printf("\nCase left for implementation with %c\n",prod[i][j+5]);
                        first[filled++] = findFirst(prod[i][j+5], prod, num);
                        //printf("\nReceived : %c",first[filled-1]);
                    }
                }
            }
        }
    }
    printf("\nFIRST( %c ) = { ",find);
    for(k = 0 ; k < filled ; k++)
    {
        printf("%c, ",first[k]);
    }
    printf("\b\b");
    printf(" }\n");


    return 0;
}


char findFirst(char find, char prod[][SIZE], int num)
{
    int i = 0,j = 0;
    /*
    if(islower(find))
    {
        return find;
    }
    */
    //printf("\nHere : %c", (**(*prod + 1) + 3) );
    //char print = **(*(prod+1))+5;
    //printf("\n6th Element : %c", **(*(prod+1)+5)  );
    //printf("\nElement : %c\n",print);
        for(i = 0 ; i < num ; i++)
        {
            //char temp = prod[i][j];
                    //printf("\nFinding : %c\n",temp);
                if( prod[i][j]  == find)          //**((prod+i*j))
                {
                    if(islower( prod[i][j+5] ) )
                    {
                        //printf("\nI'am responsible here\n");
                        return prod[i][j+5];
                    }
                    else if( prod[i][j+5] == '$' && prod[i][j+6] == '\0')
                    {
                        return prod[i][j+5];
                    }
                    else if(prod[i][j+5] == '+' ||  prod[i][j+5] == '-' ||  prod[i][j+5] == '*' ||  prod[i][j+5] == '/')
                    {
                        return prod[i][j+5];
                    }
                    else if( isupper(prod[i][j+5]) )
                    {
                        return findFirst( prod[i][j+5], prod, num);
                    }
                }
            }

    /*
    printf("\nFIRST( %c ) = { ");
    for(k = 0 ; k < filled ; k++)
    {
        printf("%c",first[k]);
    }
    printf(" }\n");
    */
    //printf("\nReached end at iter : %d",i);
    return '$';

}
