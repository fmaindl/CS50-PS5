// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

//define the struc 'node'
typedef struct node
    {
        bool is_word;
        struct node *children[27];
    }
    node;

    node *root = malloc(sizeof(char)(27));
    root->is_word = false;
    for (int i = 0, i < 27, i++)
    {
        root->children[i] == NULL;
    }

    int word_count;
    word_count = 0;

// Returns true if word is in dictionary else false (self-note strcasecmp to compare,
bool check(const char *word)
{
    node *trav = root;

    //iterate through selected word
    for (int i = 0; i < strlen(word); i++)
    {
        //if capital letter
        if (word[i] > 64 && word[i] < 91)
        {
            int index = word[i] - 'A';
        }
        //if apostrophe
        else if (word[i] == 39)
        {
            int index = 26;
        }
        // if lower case letter
        else
        {
            int index = word[i] - 'a';
        }
        // if no pointers lead to that letter
        if (!trav->children[index])
        {
            return false;
        }
        //set the pointer to the next children pointer
        trav = trav->children[index];
    }
    //if after all the iteration the trav pointer is pointing to is_word == true, then return true
    if (trav->is_word == true && trav != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open up the dictionary file
    FILE *fp = fopen(dictionary, "rb");
    if (fp == NULL)
    {
        return false;
    }


    // iterate through each word of the dictionary one word at a time
    while (fscanf(fp, "%s", word) != EOF)
    {
        //set up a pointer called *trav to root
        node *trav = root;

        // iterate through each character of the word
        for (int i = 0; i < strlen(word); i++)
        {
            //set up the is_word to be false (since we haven't reached the end of the word yet) and implement the index function
            node is_word = false;
            int index = word[i] - 'a';
            if (index == -58)
            {
                index = 26;
            }

            // condition: if the link between the trav pointer does not exist
            if (!trav->children[index])
            {
                //then create a new node called 'new_children' that is always the same size (26+1)
                node *new_children = malloc(sizeof(char)*27);
                new_children->is_word = false;

                //set all pointers of the new children array pointing to NULL
                for (int i = 0, i < 27, i++)
                {
                    new_children->children[i] == NULL;
                }
                // there is now a new pointer at children[index]
                trav->children[index] = new_children;

            //trav is now pointing at children[index]
            trav = trav->children[index];
        }
        trav->is_word = true;
        word_count++;
    }

    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (load(dictionary) == true)
    {
        return word_count;
    }
    else
    {
        return 0;
    }

}

//function to free a node
void free_function(node* trav)
{

    for (int i = 0; i < 27; i++)
    {
        if (trav->children[i] != NULL)
        {
            free_function(trav->children[i]);
        }
    }
    free(trav);
    return true;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i = 0; i < 27; i++)
    {
        if (root->children[i] != NULL)
        {
            free_function(root->children[i]);
        }
    return true;
    }



    fclose(dictionary);




    return false;
}
