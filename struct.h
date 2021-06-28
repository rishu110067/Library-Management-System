#ifndef BOOK_H
#define BOOK_H

struct Book
{
    string name;
    string author;
    int price;
    int id;
};

struct Library
{
    int size;
    vector<int> shelf;
    vector<struct Book> book_id; 
    Library(int size)
    {
        shelf.resize(size);
        book_id.resize(size);
    }
};

#endif