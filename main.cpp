#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

#include "struct.h"
#include "trie.h"
#include "fenwick.h"
#include "hopcroftKarp.h"

void MaxBipMatch(vector<string> v[], int n);

int siz=100;   
Library L(siz);
Fenwick F(siz);
struct trienode* root = new trienode;

int main()
{

    cout<<endl<<"Library of size "<<siz<<" created!"<<endl;

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
        cout<<"6. Match people with books they want"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
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

            if(x<0 || x>=siz)
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

            if(r<l || l<0 || r>=siz)
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
            
            if(x<0 || x>=siz || y<0 || y>=siz)
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
        else if(ch==6)
        {
            int n;
            cout<<"Enter number of people: ";
            cin>>n;
            vector<string> v[n+1];
            for(int i=1; i<=n; i++)
            {
                cout<<"Person "<<i<<endl;
                
                cout<<"Enter number of Books: ";
                int k; cin>>k;

                cout<<"Enter "<<k<<" Book Names: ";
                for(int j=1; j<=k; j++)
                {
                    string s; cin>>s;
                    transform(s.begin(), s.end(), s.begin(), ::tolower);
                    v[i].push_back(s);
                }
            }

            MaxBipMatch(v,n);
        }
        else break;
        
    } while(ch);

    cout<<"Library Management Program Ended!"<<endl;
    return 0;
}


void MaxBipMatch(vector<string> v[], int n)
{
    map<string, int> m;
    int k=0;
	for(int i=1; i<=n; i++)
    {
        for(auto x:v[i])
        {
            if(m.find(x)==m.end())
            {
                k++;
                m[x]=k;
            }
        }
    }

    vector<string> book(k+1);
    vector<string> np;
    int fl=0;
    for(auto x:m)
    {
        book[x.second]=x.first;
        if(search_book(root, x.first)==-1) 
        {
            np.push_back(x.first);
            m[x.first]=0;
            fl=1;
        }
    }

    if(fl)
    {
        cout<<endl;
        cout<<"These books are not present in the library: ";
        for(auto x:np) cout<<x<<" "; 
        cout<<endl;
    }

    BipGraph g(n, k);
    for(int i=1; i<=n; i++)
    {
        for(auto x:v[i])
        {
            if(m[x]) g.addEdge(i,m[x]);
        }
    }

    int mbm = g.hopcroftKarp();
    cout<<endl;
    cout<<mbm<<" Matchings possible! "<<endl;
    for(int i=1; i<=n; i++)
	{
		if(g.pairU[i]) 
            cout<<"Person "<<i<<" -> "<<book[g.pairU[i]]<<endl;
	}
}
