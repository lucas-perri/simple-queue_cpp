#include <stddef.h>
#include <stdexcept>

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

    // Allow interaction between nodes
    friend Node;

public:

    // Returns the value of the node
    const int value(){ return this->_value; }

    // Returns a pointer to the next node
    Node* next(){ return this->_next; }

    // Returns a pointer to the previous node
    Node* prev(){ return this->_prev; }

    // Construct and bind to next and previous nodes
    Node(int value, Node *prev=nullptr, Node *next=nullptr)
    {
        this->_value = value;
        this->_next = next;
        this->_prev = prev;
        if(this->_next != nullptr) this->_next->_prev = this;
        if(this->_prev != nullptr) this->_prev->_next = this;
    }

    // Destroy and unbind from next or previous node (or bind them together)
    ~Node()
    {
        if(this->_next != nullptr && this->_prev != nullptr)
        {
            this->_next->_prev = this->_prev;
            this->_prev->_next = this->_next;
        }
        else if (this->_next != nullptr)
        {
            this->_next->_prev = nullptr;
        }
        else if (this->_prev != nullptr)
        {
            this->_prev->_next = nullptr;
        }
    }
};

class Queue
{
private:

    // Pointer to the first node on the queue
    Node *_front = nullptr;

    // Pointer to the last node on the queue
    Node *_back = nullptr;

    size_t _size = 0;

public:

    // Returns the current size of the queue
    const size_t size(){ return this->_size; }

    // Returns whether the queue is empty or not
    const bool empty(){ return this->_size == 0; }

    // Returns the value of the element at the front of the queue
    const int front()
    {
        if(this->empty()) throw underflow_error("Queue is empty!");
        return this->_front->value();
    }

    // Returns the value of the element at the back of the queue
    const int back()
    {
        if(this->empty()) throw underflow_error("Queue is empty!");
        return this->_back->value();
    }

    // Add an element to the back of the queue
    void push(int value)
    {
        Node *new_node;
        try{ new_node = new Node(value, this->_back); }
        catch(bad_alloc){ throw; }
        if(this->_size == 0) this->_front = new_node;
        this->_back = new_node;
        this->_size++;
        if(this->_size == 0) throw overflow_error("Queue is full!");
    }

    // Remove the element at the front of the queue and return its value
    int pop()
    {
        if(this->empty()) throw underflow_error("Queue is empty!");
        Node *old_node = this->_front;
        this->_front = this->_front->next();
        int value = old_node->value();
        delete old_node;
        this->_size--;
        return value;
    }

    Queue();
    ~Queue(){ while(!this->empty()) this->pop(); }
};

int main(){}
