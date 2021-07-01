# Library-Managememt-System
Using various data structures and algorithms to ease the process of managing a library.

## Features:
### 1. Add a book 
It takes the book name and shelf no. as input.
Then, it adds the book in the library and keeps it at the shelf no. in the input. 

### 2. Search a book 
It takes the book name as input and tells if the book is present in the library or not. 
If present, it tells the shelf no. where the book is kept.

### 3. Find number of books between 2 shelf positions  
It takes two shelf no.'s l and r as input.
Then, it finds the number of books kept between the two shelf positions in the Library.

### 4. Swap books kept at 2 shelf positions  
It takes two shelf no.'s x and y as input.
Then, it swaps the books that were kept at those positions.

### 5. Remove a book 
It takes the book name as input and removes the book from library. 
It also tells the shelf no. from which the book was removed.

### 5. Match people with books they want 
It first takes a number as input i.e. number of people who wants book from library. 
Then, for every person, it takes a number _k_ and a set of books of size _k_ as input out of which one book will be allocated to this person.
Then it allocates one book to every person in such a way that maximum number of people can get a book that they want.   

## Data Structures and Algorithms used:
### 1. Trie: 
For searching a book in the library.

### 2. Fenwick Tree
For finding number of books between two shelf positions in the Library.

### 3. Hopcroft Karp Algorithm
For Maximum Bipartite Matching of people and books. 
It matches people with books they want.  
