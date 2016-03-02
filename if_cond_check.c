#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define CONDITION_FREQ 4    //number of if cases to check
int main()
{
    char cond[100][6], check[100] = {0};
    char input[100] = {0};
    //int prev = 3;
    int curr = 3;
    int f = 3, term = 0, isValid = 0;    //is if valid
    int validExp = 0, size = 0;
    int id = 0; //for checking long identifier
    int constant = 0;   //for checking long constant
    char inc[20] = {0};  //for checking conditions if(identifier ++) or if(identifier --)
    int incCount = 0;   //for inserting chars into inc[]
    int i = 0;  //for iterations
    int optr = 0, any = 0;  //for checking *o*o*o*o*c combination
    char pcond[20][4] = {0}; //for checking ++ conditions

    // Fill cond array
    strcpy(cond[0],"ioi");  //if(identifier operator identifier)
    strcpy(cond[1],"ioc");  //if(identifier operator constant)
    strcpy(cond[2],"i");    //if(identifier)
    strcpy(cond[3],"c");    //if(constant)
    strcpy(pcond[0],"ip");   //if(identifier ++)
    strcpy(pcond[1],"im");   //if(identifier --)
    //printf("\nCond : %s\n",cond[0]);



    printf("\nEnter Expression : \n");
    fgets(input, sizeof(input), stdin);
    size = strlen(input);
    //printf("\nSize : %d\n",size);
    //Valid if check
    if(input[0] == 'i' && input[size - 2] == ')')       //Remember \n is also added to string before \0
    {
        validExp = 1;
    }
    if(validExp == 0)
    {
        printf("\nErroneous if");
        exit(0);
    }

    //Conditions check
    /*
    if( isalpha(input[prev]) )
    {
        printf("\nSingle Executed");
        check[term++] = 'i';
    }

    else if( isdigit(input[prev]) )
    {
        check[term++] = 'c';
    }
    */



    for(curr = 3 ; input[curr] != '\n' ; )
    {
        //Identifier check
        if( isalpha(input[curr]) )      //Single identifier
        {
            //printf("\nPrevious : %c\n",input[prev]);
            id = 1;
        }
        if(isalpha(input[curr]) && isalpha(input[curr + 1]) )
        {
            //printf("\nPrev : %c\nCurr : %c\n",input[prev],input[curr]);
            //printf("\nLooping Executed");
            id = 1;
            while( isalpha(input[curr]) && isalpha(input[curr + 1]) )
            {
                //printf("\nInside\n");
                //prev++;
                curr++;
            }

        }
        if(id == 1)
        {
            //printf("\nMultiple Executed");
            check[term++] = 'i';
            inc[incCount++] = 'i';
            id = 0;
        }

        //Constant check
        if( isdigit(input[curr]) )      //Single identifier
        {
            //printf("\nPrevious : %c\n",input[prev]);
            constant = 1;
        }
        if(isdigit(input[curr]) && isdigit(input[curr + 1]) )
        {
            //printf("\nPrev : %c\nCurr : %c\n",input[prev],input[curr]);
            //printf("\nLooping Executed");
            constant = 1;
            while( isdigit(input[curr]) && isdigit(input[curr + 1]) )
            {
                //printf("\nInside\n");
                //prev++;
                curr++;
            }

        }
        if(constant == 1)
        {
            //printf("\nMultiple Executed");
            check[term++] = 'c';
            constant = 0;
        }

        //Operator check
        // + , ++
        if(input[curr] == '+' && input[curr + 1] == '+')   //For ++
        {
            check[term++] = 'o';
            inc[incCount++] = 'p';
            /*
            if(prev + 2 < size - 1)
                prev += 2;
            */
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }
        else if(input[curr] == '+')
        {
            check[term++] = 'o';
        }

        // - , --
        if(input[curr] == '-' && input[curr + 1] == '-')   //For --
        {
            check[term++] = 'o';
            inc[incCount++] = 'm';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        else if(input[curr] == '-')
        {
            check[term++] = 'o';
        }

        // !=
        if(input[curr] == '!' && input[curr + 1] == '=')   //For --
        {
            check[term++] = 'o';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        // <=
        if(input[curr] == '<' && input[curr + 1] == '=')   //For --
        {
            check[term++] = 'o';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        // >=
        if(input[curr] == '>' && input[curr + 1] == '=')   //For --
        {
            check[term++] = 'o';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        // ==
        if(input[curr] == '=' && input[curr + 1] == '=')   //For --
        {
            check[term++] = 'o';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        // <
        if(input[curr] == '<')
        {
            check[term++] = 'o';
        }

        // >
        if(input[curr] == '>')
        {
            check[term++] = 'o';
        }
        // *
        if(input[curr] == '*')
        {
            check[term++] = 'o';
        }
        // >
        if(input[curr] == '/')
        {
            check[term++] = 'o';
        }
        // >
        if(input[curr] == '%')
        {
            check[term++] = 'o';
        }

        // ||
        if(input[curr] == '|' && input[curr + 1] == '|')   //For --
        {
            check[term++] = 'o';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        // &&
        if(input[curr] == '&' && input[curr + 1] == '&')   //For --
        {
            check[term++] = 'o';
            //prev += 2;
            if(curr + 2 < size - 1)
                curr++;    //one increment is at end of loop
        }

        //prev++;
        curr++;
    }

    //printf("\nCheck : *%s*\n",check);
    //printf("Sizeof check : %d\n",strlen(check));
    //printf("\nThird : %c\nFourth : %c\n",input[3],input[4]);
    //printf("\n%s\n",input);

    //check for *o*o*o*o combination
    for(i = 0 ; i < strlen(check) ; i++)
    {
        if(i % 2 == 0 && (check[i] == 'i' || check[i] == 'c') )   //even index
        {
            //printf("\nChecking : %c\n",check[i]);
            any++;
        }
        /*
        This idea failed on input : a + b 9 * b --> i o i c o i
        if(i % 2 == 1 && check[i] == 'o' )
        {
            //printf("\nChecking : %c\n",check[i]);
            optr++;
        }
        */
        else if(check[i] == 'o')
        {
            optr++;
        }
    }
    if(any - 1 == optr)
    {
        isValid = 1;
        if(optr == 0)   //for condition if(identifier constant) , if(constant identifier) --> these aren't valid
            isValid = 0;
        //printf("\nisValid : %d\n",isValid);
    }
    // Check for valid if
    if(isValid == 0)
    {

     for(i = 0 ; i < CONDITION_FREQ ; i++)
     {
         //printf("\ncheck at loop start : %s\ninc : %s\n",check,inc);
        //printf("\nisValid : %d\n",isValid);
        if(strcmp(check,cond[i]) == 0 || strcmp(inc,pcond[i]) == 0)
            isValid = 1;
        //printf("\nisValid : %d\n",isValid);
        /*
        if(isValid == 1)
            printf("\nMatching Condition : %d\n",i);
        */
     }


    //printf("\nOptr : %d\n",optr);
    //printf("\nAny : %d\n",any);
    }
        if(isValid == 1)
        {
            printf("\nValid if construct\n");
            isValid = 0;
        }
        else
            printf("\nInvalid if construct\n");

    getch();
    return 0;
}
