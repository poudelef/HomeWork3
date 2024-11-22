#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H

class HashTable2D
{
private:
    int table[100][5];
    int rows;
    int cols;

public:
    HashTable2D();

    int insert(int value);
    int search(int value);
    int remove(int value);
    void print();
};

#endif
