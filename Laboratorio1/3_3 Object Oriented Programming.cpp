#include <iostream>
#include <cstdlib>
using namespace std;

// Class CVector definition
class CVector
{
private:
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta = 10); // Constructor
    void Insert(int elem); // Insert a new element
    void print();
};
CVector::CVector(int delta) {
    Init(delta);
}
void CVector::print() {
    for (int i = 0; i < m_nMax; i++) {
        cout << m_pVect[i]<<" ";
    }
}
void CVector::Init(int delta) {
    m_nDelta = delta;
    
    m_nCount = 0; // Counter to know the number of used elements int
    m_nMax = 0;
    m_pVect = new int[m_nMax]; // Dynamic buffer to save the elements int
}

void CVector::Resize() {
    m_nDelta = 10; // Used to increase the vector size
    m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
    m_nMax += m_nDelta; // The Max has to be increased by delta
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}


int main() {
    CVector v;
    for (int i = 1; i < 500; i++) {
        v.Insert(i);
    }
    v.print();
}
