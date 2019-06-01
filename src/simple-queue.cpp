#include <stddef.h>

using namespace std;

class Node
{
private:

    // Value stored in the node
    int _value;

    // Pointer to the next node
    Node *_next;

    // Pointer to the previous node
    Node *_prev;

public:

    // Returns the value of the node
    const int value(){ return this->_value; }

    // Returns a pointer to the next node
    Node* next(){ return this->_next; }

    // Returns a pointer to the previous node
    Node* prev(){ return this->_prev; }

    // Set the pointer to the next node
    void setNext(Node *next){ this->_next = next; }

    // Set the pointer to the previous node
    void setPrev(Node *prev){ this->_prev = prev; }

    Node(int value, Node *next, Node *prev)
    {
        this->_value = value;
        this->_next = next;
        this->_prev = prev;
    }
    ~Node();
};

int main(){}
