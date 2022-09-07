#include <stdexcept>
#include <iostream>
#include <cstddef>
#include "collection.h"

using namespace std;
 
int main ()
{
    Collection<int> collection;
    cout << "collection created" << endl;
    collection.insert(8);
    collection.insert(6);
    collection.insert(7);
    collection.insert(5);
    collection.insert(3);
    collection.insert(0);
    collection.insert(9);
    cout << "8, 6, 7, 5, 3, 0, 9 inserted" << endl;
    cout << "contains(0) (expected 1): " << collection.contains(0) << endl;
    cout << "contains(1) (expected 0): " << collection.contains(1) << endl;
    cout << "contains(2) (expected 0): " << collection.contains(2) << endl;
    cout << "contains(3) (expected 1): " << collection.contains(3) << endl;
    cout << "contains(4) (expected 0): " << collection.contains(4) << endl;
    cout << "contains(5) (expected 1): " << collection.contains(5) << endl;
    cout << "contains(6) (expected 1): " << collection.contains(6) << endl;
    cout << "contains(7) (expected 1): " << collection.contains(7) << endl;
    cout << "contains(8) (expected 1): " << collection.contains(8) << endl;
    cout << "contains(9) (expected 1): " << collection.contains(9) << endl;
    collection.remove(8);
    cout << "8 removed" << endl;
    cout << "contains(0) (expected 1): " << collection.contains(0) << endl;
    cout << "contains(1) (expected 0): " << collection.contains(1) << endl;
    cout << "contains(2) (expected 0): " << collection.contains(2) << endl;
    cout << "contains(3) (expected 1): " << collection.contains(3) << endl;
    cout << "contains(4) (expected 0): " << collection.contains(4) << endl;
    cout << "contains(5) (expected 1): " << collection.contains(5) << endl;
    cout << "contains(6) (expected 1): " << collection.contains(6) << endl;
    cout << "contains(7) (expected 1): " << collection.contains(7) << endl;
    cout << "contains(8) (expected 0): " << collection.contains(8) << endl;
    cout << "contains(9) (expected 1): " << collection.contains(9) << endl;
    cout << "size() on collection (expected 6): " << collection.size() << endl;
    cout << "is_empty() tested on collection (expected 0): " << collection.is_empty() << endl;
    collection.make_empty();
    cout << "make_empty() done on collection. is_empty() tested (expected 1): " << collection.is_empty() << endl;
    
    Collection<int> collection2 = collection;
    cout << "collection2 made with copy constructor" << endl;
    cout << "is_empty() tested on collection2 (expected 1): " << collection2.is_empty() << endl;
    
    collection.insert(2);
    collection.insert(5);
    collection.insert(7);
    collection2 = collection;
    cout << "2, 5, 7 added to collection, then copied to collection2 via assignment operator" << endl;
    cout << "contains(0) (expected 0): " << collection2.contains(0) << endl;
    cout << "contains(1) (expected 0): " << collection2.contains(1) << endl;
    cout << "contains(2) (expected 1): " << collection2.contains(2) << endl;
    cout << "contains(3) (expected 0): " << collection2.contains(3) << endl;
    cout << "contains(4) (expected 0): " << collection2.contains(4) << endl;
    cout << "contains(5) (expected 1): " << collection2.contains(5) << endl;
    cout << "contains(6) (expected 0): " << collection2.contains(6) << endl;
    cout << "contains(7) (expected 1): " << collection2.contains(7) << endl;
    
    collection.~Collection();
    collection2.~Collection();
    cout << "collection and collection2 deleted" << endl;
    return 0;
}


