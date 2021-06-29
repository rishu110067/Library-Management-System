#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include "struct.h"
#include "trie.h"
#include "fenwick.h"

int main()
{
    int size=100;
    Library L(size);
    Fenwick F(size);
    struct trienode* root = new trienode;

    cout<<endl<<"Library of size "<<size<<" created!"<<endl;

    int ch=0;
    do
    {
        cout<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Add a book"<<endl;
        cout<<"2. Search a book"<<endl;
        cout<<"3. Find number of books between 2 Shelf No."<<endl;
        cin>>ch;

        if(ch==1)
        {
            string s; 
            cout<<"Enter Book's Name: "<<endl;
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            
            int x;
            cout<<"Enter Shelf No. to place the book: "<<endl;
            cin>>x;
            
            if(x<0 || x>=size)
            {
                cout<<"Invalid Shelf No.!"<<endl;
            }
            else if(L.shelf[x]==1)
            {
                cout<<"Another Book is already at this place!"<<endl;
            }
            else
            {
                add_book(root, s, x);
                L.shelf[x]=1;
                F.update(x,1);
                cout<<s<<" added to library at Shelf No. "<<x<<" !"<<endl;
            }
        }
        else if(ch==2)
        {
            string s;
            cout<<"Enter Book's Name"<<endl;
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            int x = search_book(root, s);
            if(x!=-1)
            {
                cout<<s<<" found in library at Shelf No. "<<x<<" !"<<endl;
            }
            else 
            {
                cout<<s<<" not found in library!"<<endl;
            }
        }
        else if(ch==3)
        {
            int l,r; 
            cout<<"Enter left and right Shelf No."<<endl;
            cin>>l>>r;

            if(r<l || l<0 || r>=size)
            {
                cout<<"Invalid Shelf No.!"<<endl;
            }
            else
            {
                cout<<F.sum(l,r)<<" books between Shelf No. "<<l<<" and "<<r<<" !"<<endl;
            }
        }
        else break;
        
    } while(ch);
    
}