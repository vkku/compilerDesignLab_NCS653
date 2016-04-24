#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SPACE ' '
#define SIZE 50

struct tokens
{
    char *token;
    int freq;
};

int getEnd(char *str, int i);
void printLog(struct tokens *tok, char *str);


int main()
{
    int i;
    char *str;
    int save = 0;
    int j,k;
    //int function = 0, operator = 0, keyword = 0, identifier = 0, constant = 0, punctuation = 0;
    char logChoice;
    struct tokens tok[SIZE];
    tok -> token = malloc(sizeof(char) * 20);
    str = (char *)malloc(sizeof(char) * 200);
    for(i = 0 ; i < 6 ; i++)
    {
        switch(i)
        {
            case    0   :   //malloc(sizeof(char) * 20);
                            tok[i].token = "Function";
                            tok[i].freq = 0;
                            break;

            case    1   :   //malloc(sizeof(char) * 20);
                            tok[i].token = "Operator";
                            tok[i].freq = 0;
                            break;

            case    2   :   //malloc(sizeof(char) * 20);
                            tok[i].token = "Keyword";
                            tok[i].freq = 0;
                            break;

            case    3   :   //malloc(sizeof(char) * 20);
                            tok[i].token = "Identifier";
                            tok[i].freq = 0;
                            break;

            case    4   :   //malloc(sizeof(char) * 20);
                            tok[i].token = "Constant";
                            tok[i].freq = 0;
                            break;

            case    5   :   //malloc(sizeof(char) * 20);
                            tok[i].token = "Punctuation";
                            tok[i].freq = 0;
                            break;
            default     :   printf("\nSerious Internal Error\nReport Bug with id = SW_STR");
                            break;
        }
    }
    str = (char *)malloc(sizeof(char)* SIZE);
    printf("****************************** LEXICAL ANALYSER ******************************\n");
    printf("Enter your question string [space delimited]\n");
    fgets(str,200,stdin);
    //printf("%s",str);
    printf("\nTOKENS :\n");
    printf("--------");
    for(i = 0 ; str[i] != '\0' ; )
    {
        //printf("\nLoop + 1\n");
        save = i;
        i = getEnd(str,i+1);    //The updated i will point to the space

        for(j = i ; j >= save ; j--)
        {
            //Check for function
            if(str[j] == ')' && str[j - 1] == '(' || str[j] == ')' && str[j - 2] == '(')
            {
                printf("\nFunction : ");
                for(k = save ; k < i ; k++ )
                    printf("%c",str[k]);
                tok[0].freq++;
                break;
            }
            //Check for operator
            else if(str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/' || str[j] == '^' || str[j] == '%' || str[j] == '.' || str[j] == '=')
            {
                printf("\nOperator : ");
                for(k = save ; k < i ; k++ )
                    printf("%c",str[k]);
                tok[1].freq++;
                break;
            }
            //Check for keyword
            else if(    (str[j] == 'f' && str[j - 1] == 'i')    ||  (str[j] == 'o' && str[j - 1] == 'd')    )
            {
                printf("\nKeyword : ");
                for(k = save ; k < i ; k++ )
                    printf("%c",str[k]);
                tok[2].freq++;
                break;
            }
            //Check for identifier
            else if( isalpha(str[j]) )
            {
                printf("\nIdentifier : ");
                for(k = save ; k < i ; k++ )
                    printf("%c",str[k]);
                tok[3].freq++;
                break;
            }
            //Check for constant
            else if( isdigit(str[j]) )
            {
                printf("\nConstant : ");
                for(k = save ; k < i ; k++ )
                    printf("%c",str[k]);
                tok[4].freq++;
                break;
            }
            //Check for punctuation
            else if(str[j] == ',' || str[j] == '('  || str[j] == ')'  || str[j] == ';'  || str[j] == ';' )
            {
                printf("\nPunctuation : ");
                for(k = save ; k < i ; k++ )
                    printf("%c",str[k]);
                tok[5].freq++;
                break;
            }

        }
    }

    printf("\n**********************************************************************\n");
    printf("The expression contains : \n\n");
    printf("Functions       : %3d\n",tok[0].freq);
    printf("Operators       : %3d\n",tok[1].freq);
    printf("Keywords        : %3d\n",tok[2].freq);
    printf("Identifiers     : %3d\n",tok[3].freq);
    printf("Constants       : %3d\n",tok[4].freq);
    printf("Punctuations    : %3d\n",tok[5].freq);
    printf("\n**********************************************************************\n");

    //Write Log - Input stream is clear no flush needed
    printf("\nWrite in log file ? [Y / N]\n");
    fflush(stdin);
    scanf("%c",&logChoice);
    if(tolower(logChoice) == 'y')
    {
        printLog(tok, str);
    }
    else
    {
        printf("\nThanks for using token generator program\n");
    }

    return 0;
}


int getEnd(char *str, int i)
{
    int j;
    for(j = i ; str[j] != SPACE && str[j] != '\0' ; j++)
    {
        // printf("%3c",str[j]);
        i++;

    }

    return i;
}


void printLog(struct tokens *tok, char *str)
{
    int fd;
    int i;
    char temp[20];
    int count  = 0;
    char cnt = str[0];
    do
    {
        cnt = str[count++];
    }while(cnt != '\0');
    //last = (char *)malloc(sizeof(char) * 20);
    fd = creat("tokensLog.txt", 0644);
    write(fd, "Question String : \n", strlen("Question String : \n") );
    write(fd, str, count );
    write(fd, "\n", strlen("\n") );

    for(i = 0 ; i < 6 ; i++)
    {

        //strcpy(temp, itoa(j, buffer, tok[i].freq) );
        itoa(tok[i].freq, temp, 20);
        write(fd, tok[i].token, strlen(tok[i].token) );
        write(fd, " : ", strlen(" : ") );
        write(fd, temp, strlen(temp) );
        write(fd, "\n", strlen("\n") );

    //itoa((tok[i].freq), temp, 10);
    //strcpy(temp, last);
    //printf("\nHere : %s",temp);
        //printf("%s", tok[i].token);
        //printf("%s",temp);
        //printf(" : %d\n", tok[i].freq);
        //printf("\nActually : %s", (tok[i].token) );

    }
    printf("\nReport successfully saved to tokensLog.txt\n");
}
