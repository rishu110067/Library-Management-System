#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#include "struct.h"
#include "trie.h"
#include "fenwick.h"
#include "hopcroftKarp.h"

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
        cout<<"4. Swap books kept at two shelf positions"<<endl;
        cout<<"5. Remove a book"<<endl;
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
            else if(L.shelf[x]!="#")
            {
                cout<<"Another Book is already at this place!"<<endl;
            }
            else
            {
                add_book(root, s, x);
                L.shelf[x]=s;
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
        else if(ch==4)
        {
            int x,y; 
            cout<<"Enter the two Shelf No."<<endl;
            cin>>x>>y;
            
            if(x<0 || x>=size || y<0 || y>=size)
            {
                cout<<"Invalid Shelf No.!"<<endl;
            }
            else
            {
                swap(L.shelf[x], L.shelf[y]);
                if(L.shelf[x]!="#") 
                {
                    add_book(root, L.shelf[x], x);
                    F.update(x,1);
                    F.update(y,-1);
                }
                if(L.shelf[y]!="#") 
                {
                    add_book(root, L.shelf[y], y);
                    F.update(x,-1);
                    F.update(y,1);
                }
                cout<<"Books at Shelf No. "<<x<<" and "<<y<<" Swapped!"<<endl;
            }
        }
        else if(ch==5)
        {
            string s;
            cout<<"Enter Book's Name"<<endl;
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            int x = search_book(root, s);
            if(x==-1)
            {
                cout<<s<<" not present in the library!"<<endl;
            }
            else
            {
                L.shelf[x]="#";
                F.update(x,-1);
                add_book(root, s, -1);
                cout<<s<<" removed from shelf no. "<<x<<" !"<<endl;
            }

        }
        else break;
        
    } while(ch);
    
}