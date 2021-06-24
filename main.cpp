#include <iostream>
#include <algorithm>
#include "trie.h"
using namespace std;


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
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            add_book(root, s);
            cout<<s<<" added to library!"<<endl;
        }
        else if(ch==2)
        {
            string s;
            cout<<"Enter Book's Name"<<endl;
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
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