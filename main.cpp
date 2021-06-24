#include<iostream>
#include<string.h>
using namespace std;

const int ALPHA_SIZE = 26;
struct trienode
{
    trienode* children[ALPHA_SIZE];
    bool end_of_word;
    trienode()
    {
        end_of_word = false;
        for(int i=0; i<ALPHA_SIZE; i++)
            children[i]=NULL;
    }
};

void add_book(trienode* root, string key)
{
    trienode* pcrawl = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if(!pcrawl->children[index])
            pcrawl->children[index] = new trienode; 
        pcrawl = pcrawl->children[index];
    }
    pcrawl -> end_of_word = true;
}

bool search_book(trienode* root, string key)
{
    trienode* pcrawl = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i]-'a';
        if(!pcrawl->children[index])
            return false;
        pcrawl = pcrawl->children[index];
    }
    return pcrawl->end_of_word;
}

int main()
{
    struct trienode* root = new trienode;

    int ch=0;
    do
    {
        cout<<"0. Exit"<<endl;
        cout<<"1. Add a book"<<endl;
        cout<<"2. Search a book"<<endl;
        cin>>ch;

        if(ch==1)
        {
            string s; 
            cout<<"Enter Book's Name: "<<endl;
            cin>>s;
            add_book(root, s);
            cout<<s<<" added to library!"<<endl;
        }
        else if(ch==2)
        {
            string s;
            cout<<"Enter Book's Name"<<endl;
            cin>>s;
            if(search_book(root, s))
            {
                cout<<s<<" found in library!"<<endl;
            }
            else 
            {
                cout<<s<<" not found in library!"<<endl;
            }
        }
        else break;
        
    } while(ch);
    
    
}