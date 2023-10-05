// Q1. Write a class Distance to hold feet and inches. Overload operator + as member function and ==
// operator as friend function. Also, overload ++ operator (to increment inches) as member function
// and -- operator as friend function. Overload << and >> operators to accept and display distance.
 


 
 #include<iostream>
 using namespace std;
 
 
 
 class Distance
{
    private:
      int feet;
      int inches;

      public:
      Distance()
      {
        this->feet = 0;
        this->inches=0;
      }
      Distance(int feet,int inches)
      {
        this->feet=feet;
        this->inches=inches;
      }
      int get_feet()
      {
        return feet;
      }
     int get_inches()
     {
        return inches;    
     }

     void set_feet(int feet)
     {
        this->feet=feet;

     }
    void set_inches(int inches)
    {
        this->inches=inches;
    }
    void display()
    {
        cout<<this->feet<<", "<<this->inches<<endl;
    }

    

    Distance  operator+(Distance d)
    {
        Distance result;
        result.inches=this->inches + d.inches;
        result.feet=this->feet + d.feet;
        return result;

    }
    void  operator++(int )
    {
    
        cout<<"inside post"<<endl;
        this->feet=this->feet +1;
        this->inches=this->inches+1;
        
        
    }  
   
   friend bool operator==(Distance d1,Distance d2);
    friend void   operator++(Distance &d);
    friend  void operator>>(istream &in, Distance &d);
    friend  void operator<<(ostream &out, Distance &d);





};

    void operator<<(ostream &out, Distance &d)
    {
       out<<"Distance = "<<d.feet<<","<<d.inches<<endl;
    }

     void operator>>(istream &in, Distance &d)
    {
        cout<<"enter feet"<<endl;
        in>>d.feet;
        cout<<"enter inches"<<endl;
        in>>d.inches;
    }

    void  operator++(Distance &d)
    {
        d.set_feet(d.get_feet()+1);
        d.set_inches(d.get_inches()+1);
        
     }


 bool operator==(Distance d1,Distance d2)
    {
        if (d1.get_feet()==d2.get_feet() && d1.get_inches()==d2.get_inches())
           return true ;
           

           return false;

    }



int main()
{
    Distance d1(2,5);
    Distance d2(5,8);
    Distance d3=d1+d2;  //d1.operator+(d2)
    d3.display();

    Distance d4(2,4);
    Distance d5(2,4);
    if(d4==d5)
    {
        cout<<"both are same "<<endl;
    }

     d4++;  // d4.operator++(0)  
    d4.display();
  

  //preincrement of d5;
  cout<<"Before pre increment "<<endl;
   d5.display();
    ++d5;
    
    cout<<"after pre increment"<<endl;
    d5.display();

    //>> overloading
   Distance d6;
    cin>>d6;

    cout<<d6;


}
