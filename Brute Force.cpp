#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;


void arrayPrinting(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " -> ";
    }

}

int calculateCost(int adjacencyArray[][11], int traversingArray[], int size) {

    int shortestDistance = 9999999;

    do {

        int currentDistance = 0;

        for(int i = 0; i < size - 1; i++){

            currentDistance += adjacencyArray[traversingArray[i]][traversingArray[i+1]];

        }

        currentDistance += adjacencyArray[traversingArray[size-1]][traversingArray[0]];

        if(shortestDistance > currentDistance){

            shortestDistance = currentDistance;
            arrayPrinting(traversingArray, size);
            cout << traversingArray[0];
            cout << " Current Path: " << currentDistance; 
            cout << endl;

        }

    } while(next_permutation(traversingArray, traversingArray + size));

    return shortestDistance;
}

int main() {

    int size = 11;

    int traversingArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int adjacencyMatrix[11][11] = { {0, 2, 5, 7, 1, 3, 5, 13, 50, 47, 56}, 
                                    {6, 0, 3, 8, 2, 4, 6, 15, 78, 78, 48}, 
                                    {8, 7, 0, 4, 7, 5, 9, 17, 56, 93, 74},
                                    {12, 4, 6, 0, 5, 7, 1, 19, 24, 61, 44},
                                    {1, 3, 2, 8, 0, 7, 8, 26, 47, 87, 36},
                                    {3, 4, 5, 7, 7, 0, 5, 27, 68, 12, 22},
                                    {5, 6, 9, 1, 8, 5, 0, 11, 78, 33, 56},
                                    {13, 15, 17, 19, 26, 27, 11, 0, 36, 45, 55},
                                    {50, 78, 56, 24, 47, 68, 78, 36, 0, 88, 56},
                                    {47, 78, 93, 61, 87, 12, 33, 45, 88, 0, 75},
                                    {56, 48, 74, 44, 36, 22, 56, 55, 56, 75, 0}
                                    };
	
	auto start = high_resolution_clock::now();
	
    int cost = calculateCost(adjacencyMatrix, traversingArray, size);
    
    auto stop = high_resolution_clock::now();
    
    cout << "Shortest path possible: " << cost<< endl;
    
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
    return 0;
    
}
