#include "HashTable2D.h"
#include <iostream>

HashTable2D::HashTable2D() : rows(100), cols(5)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            table[i][j] = -1; // Initialize all slots as empty
}

int HashTable2D::insert(int value)
{
    int hash = value % rows;
    int spotsChecked = 0;
    for (int j = 0; j < cols; j++)
    {
        spotsChecked++;
        if (table[hash][j] == -1)
        {
            table[hash][j] = value;
            return spotsChecked;
        }
    }
    std::cout << "The value " << value << " cannot be inserted.\n";
    return spotsChecked;
}

int HashTable2D::search(int value)
{
    int hash = value % rows;
    int spotsChecked = 0;
    for (int j = 0; j < cols; j++)
    {
        spotsChecked++;
        if (table[hash][j] == value)
        {
            std::cout << "The value " << value << " can be found.\n";
            return spotsChecked;
        }
    }
    std::cout << "The value " << value << " cannot be found.\n";
    return spotsChecked;
}

int HashTable2D::remove(int value)
{
    int hash = value % rows;
    int spotsChecked = 0;
    for (int j = 0; j < cols; j++)
    {
        spotsChecked++;
        if (table[hash][j] == value)
        {
            table[hash][j] = -1;
            std::cout << "The value " << value << " was removed.\n";
            return spotsChecked;
        }
    }
    std::cout << "The value " << value << " cannot be removed.\n";
    return spotsChecked;
}

void HashTable2D::print()
{
    for (int i = 0; i < rows; i++)
    {
        std::cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++)
        {
            if (table[i][j] != -1)
                std::cout << table[i][j] << " ";
            else
                std::cout << "Empty ";
        }
        std::cout << "\n";
    }
}
