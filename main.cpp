#include "HashTable1D.h"
#include "HashTable2D.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    std::vector<int> dataset(100);
    for (int i = 0; i < 100; i++)
    {
        dataset[i] = rand() % 1000 + 1;
    }

    HashTable1D hash1D(500);
    HashTable2D hash2D;

    // Initial Insertion
    int spots1D = 0, spots2D = 0;
    for (int i = 0; i < 50; i++)
    {
        spots1D += hash1D.insert(dataset[i]);
        spots2D += hash2D.insert(dataset[i]);
    }
    std::cout << "Initial Insertion - Total Spots Checked:\n";
    std::cout << "1D Hash Table: " << spots1D << "\n";
    std::cout << "2D Hash Table: " << spots2D << "\n";

    // Selective Removal
    for (int i = 0; i < 50; i++)
    {
        if (dataset[i] % 7 == 0)
        {
            spots1D += hash1D.remove(dataset[i]);
            spots2D += hash2D.remove(dataset[i]);
        }
    }

    // Second Insertion
    for (int i = 50; i < 100; i++)
    {
        spots1D += hash1D.insert(dataset[i]);
        spots2D += hash2D.insert(dataset[i]);
    }

    // Search Operation
    for (int i = 0; i < 100; i++)
    {
        if (dataset[i] % 9 == 0)
        {
            spots1D += hash1D.search(dataset[i]);
            spots2D += hash2D.search(dataset[i]);
        }
    }

    // Print Results
    std::cout << "1D Hash Table:\n";
    hash1D.print();
    std::cout << "\n2D Hash Table:\n";
    hash2D.print();

    return 0;
}
