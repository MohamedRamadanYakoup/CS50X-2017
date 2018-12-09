#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n, row, c, space;
    //get the input
    do
    {
        printf("Height: ");
        n = get_int();
    }
    while(n < 0 || n > 23);
    
    space = n;
    //build the pyramid
    for(row=1;row<=n;row++)
    {
        for(c=0;c<space-1;c++)
        {
            printf(" ");
        }
        
        space--;
        
        for(c=0;c<row;c++)
        {
            printf("#");
        }
        
        for(c=0;c<2;c++)
            printf(" ");
        
        for(c=0;c<row;c++)
        {
            printf("#");
        }

        printf("\n");
    }
    
}