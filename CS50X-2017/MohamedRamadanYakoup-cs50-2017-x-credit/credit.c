#include <stdio.h>
#include <cs50.h>

int main (void)
{
    long long f, x;
    long long m, i;
    //get inputs
    do
    {
        printf("number: ");
        m = get_long_long();
    }
    while(m < 0);
   
   //other numbers 
    for(i = m, x = 0;i > 0; i /= 100)
    {
        x += i % 10;
    }
    

   
    //secound numbers * 2
    for(i = m / 10, f = 0;i > 0; i /= 100)
    {
        if(2 * (i % 10) > 9)
        {
            f += (2 * (i % 10)) / 10;
            f += (2 * (i % 10)) % 10;
        }
        else
            f += 2 * (i % 10);
    }
    
    int sum = f + x;
    
    // check to see if the CC number is in the appropriate range
if ( sum % 10 == 0 )
    {   
        if ( (m >= 340000000000000 && m < 350000000000000) || (m >= 370000000000000 && m < 380000000000000) )
            printf("AMEX\n");
        else if ( m >= 5100000000000000 && m < 5600000000000000 )
            printf("MASTERCARD\n");
        else if ( (m >= 4000000000000 && m < 5000000000000) || (m >= 4000000000000000 && m < 5000000000000000) )
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
    
}    