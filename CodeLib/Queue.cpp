#include "stdafx.h"
#include "Queue.h"
Queue::Queue ()
{

}
Queue::Queue (Queue& Ex)
{
    if (!Ex.isEmpty())
    {
        Ex.current = Ex.root;
        while (Ex.current->next != nullptr)
        {
            this->push (Ex.current->value);
            Ex.current = Ex.current->next;
        }
        this->push (Ex.current->value);
    }
}
int Queue::pop ()
{
    if (root != nullptr) 
    {
        int var = root->value;
        Element* temp = root;
        root = root->next;
        delete temp;
        return var;
    }
    throw queueIsEmpty();
    //return 0;
}

void Queue::swap ( Queue* no2)
{
    std::swap (this->root, no2->root);
    std::swap (this->current, no2->current);
}

void Queue::push (int value)
{
    if (root == nullptr) 
    {
        root = new Element(value,nullptr);
        current = root;
    }
    else 
    {
        current->next = new Element (value, nullptr);
        current = current->next;
    }
}

Queue::Element::Element (int value, Element* next)
{
    this->value = value;
    this->next = next;
}

int Queue::get ()
{
    return root->value;
}

bool Queue::isEmpty ()
{
    if (root == nullptr)return true;
    else return false;
}

std::string Queue::toString () noexcept
{
    std::string result="";
    char a[10];
    if (isEmpty ())return result;
    else 
    {
        current = root;
        while (current->next != nullptr) 
        {
            itoa (current->value, a, 10);
            result += a;
            result += " ";
            current = current->next;
        }
        itoa (current->value, a, 10);
        result += a;
        result += " ";
    }
    return result;
}

void Queue::reverse () noexcept
{
    if (isEmpty ())return;
    Element* temp = nullptr;
    Element* temp2 = nullptr;
    bool isLast = false;
    bool first = true;
    while (!isLast)
    {
        if (root == current)isLast = true;
        if (first)
        {
            temp = root;
            root = root->next;
            temp2 = root->next;
            root->next = temp;
            temp->next = nullptr;
            temp = root;
            first = false;
        }
        else
        {
            root = temp2;
            temp2 = temp2->next;
            if (root == current)isLast = true;
            root->next = temp;
            temp = root;
        }
    }    
    current = root;
    while (current->next != nullptr)current = current->next;
}

Queue::~Queue ()
{
    if (root != nullptr)
    {
        while (root->next != nullptr)
        {
            Element* temp = root;
            root = root->next;
            delete temp;
        }
        delete root;
    }
}

Queue::queueIsEmpty::queueIsEmpty (const char* what_arg) : runtime_error (what_arg)
{
    
}
Queue::queueIsEmpty::queueIsEmpty (const std::string& what_arg) : runtime_error (what_arg)
{
    
}
Queue::queueIsEmpty::queueIsEmpty () : runtime_error(queueEmptyExceptMessage)
{
    
}