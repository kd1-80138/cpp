/*
Q1. Implement a Stack class using C++ templates. Test stack operations on Stack<int>,
Stack<double> and Stack<Box>.*/
#include<iostream>
using namespace std;


template <class T>
class Stack
{
private:
    int size;
    int index;
    T *arr;

public:
    Stack(int size)
    {
        this->size = size;
        this->index = 0;
        this->arr = new T[this->size];
    }

    void push(T element)
    {
        if (!isFull())
        {
            this->arr[this->index] = element;
            this->index++;
        }
        else
            cout << "Queue is Full.. cannot add element.." << endl;
    }

    T pop()
    {
        if (!isEmpty())
          {  
            this->index--;
            return this->arr[index];
            
          }
        else
        {
            
           cout << "Queue is Empty.. cannot pop the element.." << endl;
           return NULL;
        }
    }

    T top()
    {
        return this->arr[index];
    }

    int getLength()
    {
        return this->index;
    }

    bool isEmpty()
    {
        if(this->index==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if(this->index==size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Stack()
    {
        delete[] this->arr;
    }
};

int main()
{
    Stack<int> a1(3);
    a1.push(4);
    a1.push(3);

    a1.push(3);

    int ans=a1.pop();
    cout<<ans;

    Stack<double> a2(3);
    
    a2.push(3.6);
    a2.push(2.7);
    a2.push(4.7);
    a2.push(4.7);
    a2.push(4.7);
    ans=a2.pop();
    cout<<ans;


}