#include "HashTable1D.h"
#include <iostream>

HashTable1D::HashTable1D(int tableSize) : size(tableSize)
{
    table = new int[size];
    for (int i = 0; i < size; i++)
        table[i] = -1;
}

HashTable1D::~HashTable1D()
{
    delete[] table;
}

int HashTable1D::insert(int value)
{
    int hash = value % size;
    int spotsChecked = 0;
    for (int i = 0; i < size; i++)
    {
        spotsChecked++;
        int idx = (hash + i) % size;
        if (table[idx] == -1)
        {
            table[idx] = value;
            return spotsChecked;
        }
    }
    std::cout << "The value " << value << " cannot be inserted.\n";
    return spotsChecked;
}

int HashTable1D::search(int value)
{
    int hash = value % size;
    int spotsChecked = 0;
    for (int i = 0; i < size; i++)
    {
        spotsChecked++;
        int idx = (hash + i) % size; // Linear probing
        if (table[idx] == value)
        {
            std::cout << "The value " << value << " can be found.\n";
            return spotsChecked;
        }
        if (table[idx] == -1)
            break;
    }
    std::cout << "The value " << value << " cannot be found.\n";
    return spotsChecked;
}

int HashTable1D::remove(int value)
{
    int hash = value % size;
    int spotsChecked = 0;
    for (int i = 0; i < size; i++)
    {
        spotsChecked++;
        int idx = (hash + i) % size;
        if (table[idx] == value)
        {
            table[idx] = -1;
            std::cout << "The value " << value << " was removed.\n";
            return spotsChecked;
        }
        if (table[idx] == -1)
            break;
    }
    std::cout << "The value " << value << " cannot be removed.\n";
    return spotsChecked;
}

void HashTable1D::print()
{
    for (int i = 0; i < size; i++)
    {
        if (table[i] != -1)
            std::cout << "Slot " << i << ": " << table[i] << "\n";
        else
            std::cout << "Slot " << i << ": Empty\n";
    }
}
