#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

string initials(string name);

int main (void)
{
    string name = get_string();
    initials(name);
    printf("\n");
}

string initials(string name)
{
    int i = 0;
    if(name != NULL)
    {
        if(name[0] == ' ')
        {
            printf("%c", toupper(name[0] - ' '));
        }
        else
        {
            printf("%c", toupper(name[0]));
        }
        for(int n = strlen(name); i < n; i++)
        {
            if(name[i] == ' ' && name[i+1] != '\0')
            {
                if(name[i + 1] == ' ')
                {
                    printf("%c", toupper(name[i+1] - ' '));
                }
                else
                {
                    printf("%c", toupper(name[i+1]));
                }
            }
        }
    }
    return 0;
}