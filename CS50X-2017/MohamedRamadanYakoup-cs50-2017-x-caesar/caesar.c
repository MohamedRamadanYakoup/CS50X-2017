#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    int i = 0;
    int key;
    
    //get the key
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }
        
    string k = argv[1];
    key = atoi(k);
    
    if (k < 0)
    {
        printf("Nope\n");
        return 1;
    }
    
    
    
    //get the string
    printf("plaintext:");
    string pt = get_string();
    
    
    if(isalpha(pt[i]))
    {
        int n;
        printf("ciphertext:");
        for(i = 0, n = strlen(pt); i < n ; i++)
        {
            
            if(isupper(pt[i]))
            {
                toupper(pt[i]);
                pt[i] = pt[i] - 65;
                printf("%c", ((pt[i] + key) % 26) + 65);
            }
            else if(islower(pt[i]))
            {
                tolower(pt[i]);
                pt[i] = pt[i] - 97;
                printf("%c", ((pt[i] + key) % 26) + 97);
            }
            else
            {
                printf("%c", pt[i]);
            }
        }
       printf("\n");
    }
}