/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, but also resizes it, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames and resize n
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // check n
    if (n < 1 || n > 100)
    {
        printf("n must be in the range [1-100]\n");
        return 1;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER n_bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    n_bf = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    BITMAPINFOHEADER n_bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    n_bi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // set new width and height dimensions
    n_bi.biWidth = bi.biWidth * n;
    n_bi.biHeight = bi.biHeight * n;

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding =  (4 - (n_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // set new file size
    n_bf.bfSize = 54 + (n_bi.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(n_bi.biHeight);
    n_bi.biSizeImage = n_bf.bfSize - 54;


    // write outfile's BITMAPFILEHEADER
    fwrite(&n_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&n_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // each row will be printed out n times
        int row = 0;

        while (row < n)
        {

            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // each pixel will be printed out n times
                int pCounter = 0;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                while (pCounter < n)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    pCounter++;
                }
            }

            // add new padding
            for (int k = 0; k < new_padding; k++)
                fputc(0x00, outptr);

            // seek back to the beginning of row in input file, but not after iteration of printing
            if (row < (n - 1))
                fseek(inptr, -(bi.biWidth * (int)sizeof(RGBTRIPLE)), SEEK_CUR);

            row++;
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}