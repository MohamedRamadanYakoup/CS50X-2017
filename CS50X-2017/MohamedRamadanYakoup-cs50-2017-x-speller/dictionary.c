/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define HASH_MAX 2000

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashTable[HASH_MAX];

int nWords = 0;

unsigned int hash(char *str);


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int wLength = strlen(word);
    char lWord[LENGTH + 1];

    for(int i = 0; i < wLength; i++)
    {
        lWord[i] = tolower(word[i]);
    }

    lWord[wLength] = '\0';

    int key = hash(lWord);

    node *cursor = hashTable[key];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lWord) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    for (int i = 0; i < HASH_MAX; i++)
    {
        hashTable[i] = NULL;
    }

    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        printf("Couldn't open the file\n");
        return 1;
    }

    while(true)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }

        fscanf(dic, "%s", new_node->word);
        new_node->next = NULL;

        if (feof(dic))
        {
            // hit end of file
            free(new_node);
            break;
        }

        nWords++;

        int key = hash(new_node->word);
        node *head = hashTable[key];

        if (head == NULL)
        {
            hashTable[key] = new_node;
        }
        else
        {
            new_node->next = hashTable[key];
            hashTable[key] = new_node;
        }
    }

    fclose(dic);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return nWords;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASH_MAX; i++)
    {
        node *cursor = hashTable[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

unsigned int hash(char *str)
{
    int sum =0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        sum += str[i];
    }

    int key = sum % HASH_MAX;

    return key;
}