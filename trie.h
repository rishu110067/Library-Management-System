#ifndef TRIE_H
#define TRIE_H

const int ALPHA_SIZE = 26;
struct trienode
{
    trienode* children[ALPHA_SIZE];
    int end_of_word;
    trienode()
    {
        end_of_word = -1;
        for(int i=0; i<ALPHA_SIZE; i++)
            children[i]=NULL;
    }
};

void add_book(trienode* root, string key, int x)
{
    trienode* pcrawl = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if(!pcrawl->children[index])
            pcrawl->children[index] = new trienode; 
        pcrawl = pcrawl->children[index];
    }
    pcrawl -> end_of_word = x;
}

int search_book(trienode* root, string key)
{
    trienode* pcrawl = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if(!pcrawl->children[index])
            return -1;
        pcrawl = pcrawl->children[index];
    }
    return pcrawl->end_of_word;
}

#endif