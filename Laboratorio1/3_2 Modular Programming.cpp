#include <iostream>
#include <cstdlib>
using namespace std;
int* gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0; // Counter to know the number of used elements int
int gnMax = 0; // Variable containing the size of the allocated
// memory

struct Vector
{
    int* m_pVect, // Pointer to the buffer
        m_nCount=0, // Control how many elements are actually used
        m_nMax=10, // Control how many are allocated as maximum
        m_nDelta=5; // To control the growing
    Vector(int _m_nMax, int _m_nCount, int _m_nDelta) {
        m_nCount = _m_nCount;
        m_nMax = _m_nMax;
        m_nDelta = _m_nDelta;
        m_pVect = new int[m_nMax];
    }
};

void Resize(Vector* pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int)*(pThis->m_nMax + pThis->m_nDelta));
    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}


void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
    Vector v(10, 0, 5);
    for (int i = 1; i < 500; i++) {
        Insert(&v, i);
        cout << v.m_pVect[i-1]<<" ";
    }
}
