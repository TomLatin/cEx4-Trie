
#include "Trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates a new node so that all of its fields are initialized except the signal field - letter, that we initialize
// with the word insert.
node* getNode()
{
    node *pNode = NULL;
    pNode=(node*)malloc(sizeof(node));
    if(pNode)  //pNode!=NULL i.e the malloc Succeeded
    {
        int i=0;
        pNode->isEndOfWord=FALSE;
        pNode->count=0;
        for (i;  i< NUM_LETTERS; i++) {
            pNode >children[i]=NULL;
        }


    return pNode;
}

/**
 * The function receives the tree root and a const string that cannot be changed that represent a word.
 * The function inserts the string that symbolizes a word into the Trie correctly.
 * @param root
 * @param key
 */
void insert(node **root, const char *key)
{
    int level=0;
    int len=strlen(key);
    int index;
    node *pCurrent= *root;

    for(level ; level<len ; level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!(pCurrent->children[index])) //Checks the location in array children - if a node already exists.If no initialize the location with node
        {
            pCurrent->children[index]=getNode(); //insert pointer to node in the array children
            pCurrent->children[index]->letter=key[level]; //insert to the node in the array children the right letter
        }
        pCurrent=pCurrent->children[index]; // node promotion
    }

    //end of word
    pCurrent->isEndOfWord=TRUE;
    pCurrent->count++;

}
/**
 * This function is designed to free all the node we have assigned by the malloc function
 */
void freeAllTrie(node ** root)
{
    node *pCurrent= *root;
    int i=0;
    for (i;i<NUM_LETTERS;i++)
    {
        if(pCurrent->children[i]!=null)
        {
            freeAllTrie(&(pCurrent->children[i]))  //The recursion
        }
    }

    free(pCurrent);
}

/**
 * print all the words in the trie and the amount of times they enter the tree Fine dictionary from low to high
 */
void print (npde** root , const char* key,int level)
{
    node *pCurrent= *root;
    int i=0;

    //Stop conditions
    if(pCurrent==null)
    {
        return;
    }

    if(pCurrent->isEndOfWord)
    {
        key[level]='\0';
        printf("%s\t%ld",key,pCurrent->count);
    }

    //The recursion
    for(i;i<NUM_LETTERS ; i++)
    {
        if(pCurrent-> children[i]!=null)
        {
            key[level]=pCurrent-> children[i]->letter;
            printf(&(pCurrent->children[i]),key,level+1) //node promotion,same string,level down in the tree
        }
    }
}

/**
 * print all the words in the trie and the amount of times they enter the tree Fine dictionary from high to low
 */
    void printReverse (npde** root , const char* key,int level)
    {
        node *pCurrent= *root;
        int i=NUM_LETTERS-1;

        //Stop conditions
        if(pCurrent==null)
        {
            return;
        }

        //The recursion
        for(i; i>=0 ; i--)
        {
            if(pCurrent-> children[i]!=null)
            {
                key[level]=pCurrent-> children[i]->letter;
                printf(&(pCurrent->children[i]),key,level+1) //node promotion,same string,level down in the tree
            }
        }

        if(pCurrent->isEndOfWord)
        {
            key[level]='\0';
            printf("%s\t%ld",key,pCurrent->count);
        }
    }

}



