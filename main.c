#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
char* encrypt(char* t,int k)
{
    int l=strlen(t);    //find the length of input text
    while(*t!=NULL) //to identify end of the input text
    {
        if(isalpha(*t)){    //check if the character is alphabet
                if(isupper(*t)) //check if the character is uppercase
                {
                  *t-=k;
                  if(*t<65) //A=65
                    *t+=26;
                }
                else{   //character is lower case
                   *t-=k;
                   if(*t<97)    //a=97
                   {
                       *t+=26;
                   }
                }
                t++;
           }
        else if(*t==' ')
            t++;
        else
            return "invalid as it contains characters other than alphabets. ";
    }
    t-=l;   //to point to start of the text
    return t;
}
char* decrypt(char* t,int k)
{
    int l=strlen(t);
    while(*t!=NULL)
    {
         if(isalpha(*t)){
                if(isupper(*t))
                {
                  *t+=k;
                  if(*t>90) //Z=90
                    *t-=26;
                }
                else{
                   *t+=k;
                   if(*t>122)   //z=122
                   {
                       *t-=26;
                   }
                }
                t++;
           }
           else if(*t==' ')
            t++;
        else
            return "invalid as it contains characters other than alphabets. ";
    }
    t-=l;   //to point to start of the text
    return t;
}
int main()
{
    char *t;
    int key,ch;
    t=malloc(256);
    printf("Enter the text : ");
    scanf ("%[^\n]%*c", t);
    printf("Enter the key : ");
    scanf("%d",&key);
    printf("Enter 1 to encrypt the text , 2 to decrypt the text and 3 to exit\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
        switch(ch)
    {
    case 1:
        printf("Encrypted text is %s\n",encrypt(t,key));
        break;
    case 2:
        printf("Decrypted text is %s\n",decrypt(t,key));
        break;
    case 3:
        exit(0);
    default:
        printf("entered choice is invalid");
    }
    return 0;
}
