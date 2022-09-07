#include <stdexcept>
#include <iostream>
#include "selection.h"

using namespace std;

int select(size_t k, const int* list, size_t N);

int main(){
    size_t N = 3, k = 2;
    int arr[] = {5, 6, 9};
    const int* A = &arr[0];
    cout << "select(2, {5, 6, 9}, 3): " << select(k, A, N) << endl;
    k = 4;
    N = 4;
    int arr2[] = {6, 3, 4, 9};
    A = &arr2[0];
    cout << "select(4, {6, 3, 4, 9}, 4): " << select(k, A, N) << endl;
    int arr3[] = {7, 6, 1, 3, 11};
    k = 3;
    N = 5;
    A = &arr3[0];
    cout << "select(3, {7, 6, 1, 3, 11}, 5): " << select(k, A, N) << endl;
    int arr4[] = {3, 11};
    k = 1;
    N = 2;
    A = &arr4[0];
    cout << "select(1, {3, 11}, 2): " << select(k, A, N) << endl;
    int arr5[] = {9, 6, 3, 12};
    k = 2;
    N = 4;
    A = &arr5[0];
    cout << "select(2, {9, 6, 3, 12}, 4): " << select(k, A, N) << endl;
    int arr6[] = {5, 6, 3, 2, 1};
    k = 3;
    N = 5;
    A = &arr6[0];
    cout << "select(3, {5, 6, 3, 2, 1}, 5): " << select(k, A, N) << endl;
	int arr7[] = {8, 6, 3, 125, 4};
    k = 2;
    N = 5;
    A = &arr7[0];
    cout << "select(2, {8, 6, 3, 125, 4}, 5): " << select(k, A, N) << endl;
    int arr8[] = {55, 34, 6, 3, 2, 1, 15};
    k = 3;
    N = 7;
    A = &arr8[0];
    cout << "select(3, {55, 34, 6, 3, 2, 1, 15}, 7): " << select(k, A, N) << endl;
	int arr9[] = {7, 25, 63, 2, 74, 5};
    k = 4;
    N = 5;
    A = &arr9[0];
    cout << "select(4, {7, 25, 63, 2, 74, 5}, 5): " << select(k, A, N) << endl;
    return 0;
}