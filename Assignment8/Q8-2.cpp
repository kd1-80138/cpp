// Q2. Modify Stack class from previous assignment to implement copy constructor and overload =
// operator.


#include<iostream>
using namespace std;

class stack
{
    private:
      int top;
      int size ;
      int *a;
    public:
        //parameterless constructor 
        stack()
        {
            this->a=new int[5];
            this->top=-1;
            this->size= 5;
        }

        //parameterized constructor called
        stack(int size)
        {
            this->a=new int[size];
            this->top=-1;
            this->size=size;
        }

        //copy constructor
        stack(stack &s)
        {
            this->a=new int[5];
            this->top=s.top;
            this->size=s.size;

        }


       //enters value in the stack
       void push()
       {
           
          if(this->isfull())
          { 
              cout<<"stack is full"<<endl;
          }
          else
          {
            top++;
            cout<<"enter value to enter in stack"<<endl;
            cin>>a[top];
          }
   

       }
       //deletes topmost element 
       void pop()
       {  if(this->isempty()){
           cout<<"stack is empty"<<endl;
          }
          else
          {
            top--;
          }
       }
       //peek shows last element
      
       void peek()
       {
        cout<<"topmost element is "<<a[top]<<endl;

       }
       //to check stack is empty or not 
       
       bool isempty()
       {
        if(top==-1)
        {
            //cout<<"stack is empty"<<endl;
            return true;
        }
        //cout<<"stack is not empty"<<endl;
        return false;

       }
       //to check stack is full or not 
        bool isfull()
       {
        if(top==size-1)
           return true;

        return false;
        
       }
      //prints stack
       void print_stack()
       {
        cout <<"stack = ";
        for(int i=0;i<=top;i++ )
        {
            cout<<a[i]<<" ";
        }

       }

       bool operator==(stack  &d2)
    {
        if (this->size=d2.size &&this->top==d2.top)
           return true ;
           

           return false;

    }


       ~stack()
       {
        delete[] a;
       }


};

int main ()
{
    int choice=1;
    cout<<"enter values in stack 1st "<<endl;
    stack s; //stack 1
     s.push();
    s.push();
    s.push();

     cout<<"enter values in stack 2nd "<<endl;
   stack s1;//stack 2
    s1.push();
    s1.push();
    s1.push();
    s1.push();

   /* while(choice)
    {

    cout<<endl;
    cout<<"************************************"<<endl;
    cout<<"0-Exit "<<endl;
    cout<<"2-push"<<endl;
    cout<<"3-pop"<<endl;
    cout<<"4- peek"<<endl;
    cout<<"5-to check empty"<<endl;
    cout<<"6-to check full "<<endl;
    cout<<"7-to print stack"<<endl;
    cout<<"8-to copy stack 1 into stack 2"<<endl;
    cout<<"9-to check weather both stacks are same  or not "<<endl;
    cin>>choice;
    cout<<"******************************************"<<endl;

    switch (choice )
    {
        case 2:
              s.push();
              break;

       case 3:
               s.pop();
               break;


         case  4:
                s.peek();
                break;


         case  5:
                if(s.isempty())
                   cout<<"stack is empty"<<endl;
                else
                   cout<<"stack is not empty"<<endl;

                break;


         case 6: 
                 if(s.isfull())
                 {
                    cout<<"stack is full"<<endl;
                 }
                else 
                    cout<<"stack is not full"<<endl;

                break;
         case  7:
                 s.print_stack();
                 break;

        case 8:
                s1=s;
                cout<<"copy done successfully"<<endl;
                break;
        case 9:
        if(s==s1)
        {
            cout<<"both stacks are equal"<<endl;
        }
        else {
            cout<<"both stacks are not same "<<endl;
        }
        break;

              
        default:
              cout<<"invalid operation selected"<<endl;
    
    }
    }*/

        if(s==s1)
        {
            cout<<"both stacks are equal"<<endl;
        }
        else {
            cout<<"both stacks are not same "<<endl;
        }

return 0;
}