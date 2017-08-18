#pragma once
#include "ADT.h"
#include <exception>
#include <stdexcpt.h>

class Queue : ADT
{
public:
    Queue();
    ~Queue() override;
    void push(int) override;
    int pop() override;
    int get() override;
    bool isEmpty() override;
    std::string toString() override;
    void reverse();


    class queueIsEmpty:std::runtime_error
    {
    public:
        queueIsEmpty (const char* what_arg);
        queueIsEmpty (const std::string& what_arg);
    };


protected:
    /*
    * Structure that represent a single element of Queue.
    */
    struct  Element
    {
        int value = 0;
        Element* next = nullptr;
        Element(int, Element*);
    };
    Element* root = nullptr;     // root element for queue.
    Element* current = nullptr;

    
};