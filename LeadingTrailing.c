#include<stdio.h>
#include<ctype.h>

#define WORD_LEN 50
#define MAX_PRODS 27

int main()
{
    char prod[MAX_PRODS][WORD_LEN] = {'0'};
    char leading[MAX_PRODS][WORD_LEN] = {0};
    char trailing[MAX_PRODS][WORD_LEN] = {0};
    char head[MAX_PRODS] = {0};
    char tail[MAX_PRODS] = {0};
    static int numProd;
    int i = 0;
    int j = 0, k = 0; //l = 0;
    //int empty = 1;
    int save;
    int flag = 0;
    //Handling first insertion in leading array
    for(i = 0 ; i < MAX_PRODS ; i++)
    {
        leading[i][-1] = '1';
    }
    printf("\nEnter the number of productions : \n");
    scanf("%d",&numProd);
    printf("\nProductions must be entered strictly in Format : E -> X\n");
    save = numProd;
    for(i = 0 ; i < numProd ; i++)
    {
        printf("\nEnter production %d : \t",i+1);
        fflush(stdin);
        fgets(prod[i], sizeof(prod[i]), stdin);
    }
    printf("\nProductions : \n");
    for(i = 0 ; i < numProd ; i++)
        printf("%s",prod[i]);

    /*

    **************************************************************************************************************************
                                        LEADING COMPUTATION
    **************************************************************************************************************************
    */
    for(i = 0 ; i < numProd ; i++)
    {
        if(islower(prod[i][0]) )
            break;
        for(j = 5 ; j < WORD_LEN ; j++)
        {
            if(isupper(prod[i][j]) || prod[i][j] == ' ' || isdigit(prod[i][j]))
            {
                // It's a non - terminal -> way to skip
            }
            else
            {
                //printf("\nCurrently Held in leading : %c\n",prod[i][j]);
                //printf("\nBound Calculated i : %d, j : %d for %c\n",prod[i][0] - 65 ,head[ prod[i][0] - 65 ],  prod[i][0]);
                if(leading[ prod[i][0] - 65 ][ prod[i][j] - 33 ] != prod[i][j])
                {
                    head[ prod[i][0] - 65 ]++;
                    leading[ prod[i][0] - 65 ][ prod[i][j] - 33 ] = prod[i][j];      //leading indexes :
                    //printf("\nHead : %d and leading : %d\n",head[prod[i][0] - 65],leading[ prod[i][0] - 65 ][ head[ prod[i][0] - 65 ] ]);
                    //printf("\nElement : %c ENTERED AT : [%d,%d]", prod[i][j], prod[i][0] - 65, prod[i][j] - 33);
                    //head[ prod[i][0] - 65 ]++;    //Increase offset by 1                     // i : index from A -> 0 corresponding to alphabet.
                                         // j : offset from 0 to place leading into
                }

                /*
                //Before ACII approach
                leading[i][0] = prod[i][0];
                //leading[i][1] = prod[i][j];
                k = 0;
                while(leading[i][k] != 0)
                    k++;
                leading[i][k] = prod[i][j];
                //printf("\nArray Contents : %c",leading[i][empty]);
                //flag = 1;
                */
                //printf("\nArray Contents : %c and k : %d",leading[i][k],k);
                break;
            }
            /*
            //To make empty delimiter to -1
            if(flag == 1)
            {
                leading[i][empty] = -1;
                flag = 0;
            }
            */
            //printf("\nnumProd : %d",numProd);
        }
    }



/*
    **************************************************************************************************************************
                                        TRAILING COMPUTATION
    **************************************************************************************************************************
*/

    for(i = 0 ; i < numProd ; i++)
    {
        for(j = WORD_LEN - 1 ; j >= 5 ; j--)
        {
                //printf("\nCurrently Held : %d\n",prod[i][j]);
            if(isupper(prod[i][j]) || prod[i][j] == ' ' || isdigit(prod[i][j]) || prod[i][j] - '0' == 0 || prod[i][j] == 0 || prod[i][j] == 10)
            {
                // 10 -> ASCII for \n, filled by fgets
                //printf("\nSkipped\n");
                // It's a non - terminal -> way to skip
            }
            else
            {
                //printf("\nExecuted for %d\n",prod[i][j]);
                tail[ prod[i][0] - 65 ]++;
                trailing[ prod[i][0] - 65 ][ prod[i][j] - 33 ] = prod[i][j];
                //printf("\nBound Calculated i : %d, j : %d for %c\n",prod[i][0] - 65 ,tail[ prod[i][0] - 65 ],  prod[i][0]);
                //trailing[ prod[i][0] - 65 ][ tail[ prod[i][0] - 65 ] ] = prod[i][j];      //leading indexes :
                //printf("\nHead : %d and trailing : %d\n",tail[prod[i][0] - 65],trailing[ prod[i][0] - 65 ][prod[i][0] - 33]);
                //tail[ prod[i][0] - 65 ]++;    //Increase offset by 1                     // i : index from A -> 0 corresponding to alphabet.
                                         // j : offset from 0 to place leading into
                /*
                //Before ACII approach
                leading[i][0] = prod[i][0];
                //leading[i][1] = prod[i][j];
                k = 0;
                while(leading[i][k] != 0)
                    k++;
                leading[i][k] = prod[i][j];
                //printf("\nArray Contents : %c",leading[i][empty]);
                //flag = 1;
                /*
                //printf("\nArray Contents : %c and k : %d",leading[i][k],k);
                break;
            }
            /*
            //To make empty delimiter to -1
            if(flag == 1)
            {
                leading[i][empty] = -1;
                flag = 0;
            }
            */
            //printf("\nnumProd : %d",numProd);
            break;
        }
    }
  }











    // *********************************** PRINT ******************************************
    printf("\n** LEADING **");
    /*
    //printf("\nnumProd : %d",numProd);
    j = 0;  // for checking bound on empty variable
       for(i = 0 ; i < MAX_PRODS ; i++)
        {
            printf("\nLEADING(%c) = {",leading[i][0]);
            j = 0;      //do 1 if not ASCII approach
            while(leading[i][j++] != 0)
            printf(" %c ",leading[i][j]);
        }

    //print last }
    printf("}");
    */
    //i = 0;
/*
    for(i = 0 ; i < MAX_PRODS ; i++)
    {
        printf("\t%d",head[i]);
    }
*/
    //printf("\nExplicit Test : %c",leading[4][11]);
    for(i = 0 ; i < MAX_PRODS ; i++)
    {
        //printf("\nProcessing\n");
        if(head[i] == 0)
        {
            //The corresponding non-terminal isn't used
        }
        else
        {
            printf("\nLEADING(%c) = { ",65 + i);
            k = 0;
            while(k < WORD_LEN - 1)
            {
                if(leading[i][k] != 0)
                    printf("%c ",leading[i][k]);
                k++;
                //printf("here**");
            }
            flag = 1;
        }
        if(flag == 1)
        {
            printf("}");
            flag = 0;
        }
        //i++;
    }
    printf("\n\n\n** TRAILING **");
    for(i = MAX_PRODS - 1 ; i >= 0 ; i--)
    {
        //printf("\nProcessing\n");
        if(tail[i] == 0)
        {
            //The corresponding non-terminal isn't used
        }
        else
        {
            printf("\nTRAILING(%c) = { ",65 + i);
            k = 0;
            while(k < WORD_LEN - 1)
            {
                if(trailing[i][k] != 0)
                    printf("%c ",trailing[i][k]);
                k++;
                //printf("here**");
            }
            flag = 1;
        }
        if(flag == 1)
        {
            printf("}");
            flag = 0;
        }
        //i++;
    }
    return 0;
}
