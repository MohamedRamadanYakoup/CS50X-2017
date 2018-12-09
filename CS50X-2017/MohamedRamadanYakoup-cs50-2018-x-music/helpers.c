// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int size = strlen(fraction);

    //Getting the numerator and the denominator
    float numerator = fraction[size - 3] - '0';
    float denominator = fraction[size - 1] - '0';

    //returning the number of eighths
    return (int)((numerator / denominator) * 8);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter[3];
    letter[0] = note[0];
    int octave = 4;
    float freq = 0;

    //detecting whether there is a semitnote(accidentals) or not
    if (note[1] == '#' || note[1] == 'b')
    {
        letter[1] = note[1];
        octave = note[2] - '0';
        letter[2] = '\0';
    }
    else
    {
        octave = note[1] - '0';
        letter[1] = '\0';
    }

    //calculating the frequency with the frequency of A4 as we taking it as a standard
    //freq of A4 = 440Hz
    //The frequency, f, of some note is 2n/12 × 440, where n is the number of semitones from that note to A4.
    switch (letter[0])
    {
        case 'A':
            freq = 440 * pow(2, 0);
            break;
        case 'B':
            freq = 440 * pow(2, ((double)2) / 12);
            break;
        case 'C':
            freq = 440 * pow(2, ((double) - 9) / 12);
            break;
        case 'D':
            freq = 440 * pow(2, ((double) - 7) / 12);
            break;
        case 'E':
            freq = 440 * pow(2, ((double) - 5) / 12);
            break;
        case 'F':
            freq = 440 * pow(2, ((double) - 4) / 12);
            break;
        case 'G':
            freq = 440 * pow(2, ((double) - 2) / 12);
            break;
    }

    if (letter[1] == '#')
    {
        freq *=   pow(2, ((double)1) / 12);
    }
    else if (letter[1] == 'b')
    {
        freq *= pow(2, ((double) - 1) / 12);
    }

    freq *= pow(2, octave - 4);

    return (int)round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //detecting whether the text is a blank line
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
