#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    //Number of command line arg
    if (argc != 2)
    {
        printf("Nope\n");                    //(A)
        return 1;
    }
    
    //Be sure that argv is alphabetic
    string k;
    k = argv[1];
    for(int i = 0, n = strlen(k); i < n; i++)
    {
        if (isalpha(k[i]) == 0)
        {
            printf("Nope\n");
            return 1;                              //(B) 
        }
        
    }
    
    
    
    printf("plaintext:");
    string pt = get_string();
    
    
    int j=0, m = strlen(k);
    
    printf("ciphertext:");
    for(int i = 0, n = strlen(pt); i < n; i++)
    {
        j = j % m;        //wrap around the key
        
        if(isalpha(pt[i]))
        {
            if (islower(pt[i]) && islower(k[j]))
            {
                printf("%c", (((pt[i] - 97) + (k[j] - 97)) % 26) + 97);
            }
            else if (isupper(pt[i]) && islower(k[j]))
            {
                printf("%c", (((pt[i] - 65) + (k[j] - 97)) % 26) + 65);
            }
            else if (islower(pt[i]) && isupper(k[j]))
            {
                printf("%c", (((pt[i] - 97) + (k[j] - 65)) % 26) + 97);
            }
            else if (isupper(pt[i]) && isupper(k[j]))
            {
                printf("%c", (((pt[i] - 65) + (k[j] - 65)) % 26) + 65);
            }
                    
            j++;
        }
        else
        {
            printf("%c", pt[i]);
        }
            
    }
        printf("\n");
}