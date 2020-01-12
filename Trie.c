
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

