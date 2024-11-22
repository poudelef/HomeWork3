#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H

class HashTable1D
{
private:
    int *table;
    int size;

public:
    HashTable1D(int tableSize);
    ~HashTable1D();

    int insert(int value);
    int search(int value);
    int remove(int value);
    void print();
};

#endif
