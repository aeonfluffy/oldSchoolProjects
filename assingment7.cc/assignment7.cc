/********************************************************************
CSCI 340 SPRING

Progammer: Rachel Bastuk
Section:   Section 1
TA:        Ramesh Vankadaru
Date Due:  3/7/2016

Purpose:   Header File for Binary Search tree
*********************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

/*****
Prototypes
*****/
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
void heapify(vector <int>& v, int heap_size, int r, bool(*compar)(int, int));
bool less_than(int e1, int e2);
bool greater_than(int e1, int e2);
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) );
int extract_heap(vector <int> &v, int& heap_size, bool (*compar)(int, int));

/***************************************************************
Function:        build_heap
Use:             construct a heap with heap_size elements into vector v
Arguments:       vector v, int heap_size, boolean function pointer to compare two integers
Returns:         nothing
***************************************************************/
void build_heap (vector<int>& v, int heap_size, bool (*compar)(int, int) )
{
    for(int i = heap_size; i > 0; i--)
    {
        heapify(v, heap_size, i, compar);
    }
}
/***************************************************************
Function:        heapify
Use:             heapifies a tree at the root position r assuing r's two subtrees are already heaps
Arguments:       vector v, heap_size, boolean function pointers to compare two elements
Returns:         nothing
***************************************************************/
void heapify(vector <int>& v, int heap_size, int r, bool(*compar)(int, int))
{
    int left = 2 * r, right = 2 * r + 1, minMax = r, temp;

        if(left < heap_size && compar(v[left], v[minMax]))
        {
            minMax = left;
        }
        if(right < heap_size && compar(v[right], v[minMax]))
        {
            minMax = right;
        }

        if(r != minMax)
        {
            temp = v[r];
            v[r] = v[minMax];
            v[minMax] = temp;
            heapify(v, heap_size, minMax, compar);
        }
}

/***************************************************************
Function:        less_than
Use:             compare two integers
Arguments:       two integers, e1 and e2
Returns:         true if e1 is less than e2 otherwise it returns false
***************************************************************/
bool less_than(int e1, int e2)
{
    return e1 < e2;
}

/***************************************************************
Function:        greater_than
Use:             compare two integers
Arguments:       two integers, e1 and e2
Returns:         true if e1 is greater than e2 otherwise it returns false
***************************************************************/
bool greater_than(int e1, int e2)
{
    return e1 > e2;
}

/***************************************************************
Function:        heap_sort
Use:             sort a heap depending on the compar that was passed in
Arguments:       vector, size of the heap, and a boolean function pointer to compare two numbers
Returns:         nothing
***************************************************************/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
    for(int i = heap_size - 1; i > 1; i--)
    {
        v[i] = extract_heap(v, i, compar);
    }
    std::reverse(v.begin(), v.end());
}

/***************************************************************
Function:        extract_heap
Use:             extracts root of the heap, fills root with last element of current heap and update heap size
Arguments:       vector, size of the heap, and a boolean function pointer to compar
Returns:         the old root value
***************************************************************/
int extract_heap(vector <int> &v, int& heap_size, bool (*compar)(int, int))
{
    int old_root = v[1];
    v[1] = v[heap_size];
    heapify(v, heap_size, 1, compar);
    return old_root;
}

/***************************************************************
Function:        print_vector
Use:             displays elements in a vector starting at v, showing 8 lines
                    each item occupies 5 spaces
Arguments:       a vector, a position, and a size of the vector
Returns:         nothing
***************************************************************/
void print_vector(vector <int>& v, int pos, int size)
{
    int lnbreak = 0;
    for(int i = pos; i < size; i++)
    {
        if(lnbreak != 0 && lnbreak % 5 == 0)
        {
            cout << endl;
        }
        cout << setw(5) << v[i];
        lnbreak ++;
    }
        cout << endl;
}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );


    return 0;
}

