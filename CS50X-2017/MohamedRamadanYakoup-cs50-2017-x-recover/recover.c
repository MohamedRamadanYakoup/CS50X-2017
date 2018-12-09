#include <cs50.h>
#include <stdio.h>

#define s_Buffer 512

int main (int argc, char* argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    char *infile = argv[1];
    unsigned char buf[s_Buffer];    //array to contain bytes
    char arr[8];                    //array for sprintf
    int count = 0;                  //counter for names of imgs
    int f_img = 0;

    FILE *img = NULL;               //img that will contain the imgs

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    while(fread(&buf, s_Buffer, 1, inptr) == 1) //if don't reach the end of file
    {

        //start of jpg
        if (buf[0] == 0xff && buf[1] == 0xd8
        && buf[2] == 0xff && (buf[3] & 0xe0) == 0xe0)

        {
            //close last img
            if (f_img == 1)
            {
                fclose(img);
            }
            else
            {
                f_img = 1;
            }

            //names of imgs
            sprintf(arr, "%03d.jpg", count);
            img = fopen(arr, "a");
            count++;

        }

        //write to file
        if( f_img == 1)
        {
            fwrite(&buf, s_Buffer, 1, img);
        }

    }

    //close files
    fclose(img);
    fclose(inptr);

}