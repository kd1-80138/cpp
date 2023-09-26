// Q1. Write a menu driven program to calculate volume of the box(length * width * height).
// Provide necessary constructors.


#include<iostream>
using namespace std ;

 class Box
 {
    private :
        float length ;
        float width;
        float height;
    public:
      
      Box()
      {
        this->height=1;
        this->length=1;
        this->width=1;
      }
      Box(int length,int height, int width=1)
      {
        this->length= length ;
        this-> width=width;
        this->height=height;
      }

     
      
    void set_parameters()
    {
        cout<<"enter length"<<endl;
        cin>>this->length;
        cout<<"enter width"<<endl;
        cin>>this->width;
        cout<<"enter height"<<endl;
        cin>>this->height;
    }


        int cal_volume()
        {
            int volume =  this->length*this->width*this->height;
            return volume ;

        }

 };

 enum x{Exit,accept,calculate,invol};

 x menu()
 {int ch;
    cout<<endl;
    cout<< "enter choice "<<endl;
    cout<< "0 - Exit "<<endl;
    cout<< "1-  INSERT"<<endl;
    cout<< "2 -calculate volume"<<endl;
    cout<<"3- to calculate volume of the object set by parameters while initilization"<<endl;
    cin>>ch;
      return x(ch);
 }

 int main ()
 {
    Box b;                      // b object created //default paramater called;
    Box b1(10,12,10);            //n b1 object created //parameterrized constructor called;
     x choice ;
    while((choice=menu())!= Exit)
    {
        switch(choice)
        {
            case accept:                // accepts and stores for the object b
                  b.set_parameters();  
                  break;
            

            case calculate :
                                              //calculates volume for the object b;
                 int vol;
                 vol=b.cal_volume();
                 cout<<"volume is ="<<vol;
                 break;

            case invol:
               float v1;
                  v1=b1.cal_volume();
                  cout<<"volume of b1 is "<<v1<<endl;
                  break;


            default :
             cout<<"invalid choice "<<endl;
             break;            
        }
    }
 }