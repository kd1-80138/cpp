//Q1. Create a namespace NStudent. Create the Student class(created as per assignment-1 Q3) inside
//     namespace. Test the functionalities.



#include<iostream>
using namespace std;


namespace Nstudent
{ 


class Student
{
    int rollno;
    string name ;
    int marks;

public:
    void initStudent()
    {
        this->rollno = 0;
        this->name= "rahul";
        this->marks = 0;
    }
    void printstudent()
    {
        cout<<"name = "<< this->name<<endl;
        cout<<" rollno= "<<this->rollno<<endl;
        cout<<" marks = "<< this->marks<<endl;
    }

    void acceptStudent()
    {
        cout<<"enter roll no";
        cin>>rollno;
        cout<<"\n enter name ";
        cin>>name;
        cout<<"enter marks ";
        cin>> marks;
    }
};

}

using namespace Nstudent;
int main ()

{

    Student s1;
    int x;
    while (x)
    {
        cout<<"1 -acceptStudent "<<endl;
        cout<<"2- printStudent "<<endl;
        cout <<"0- Exit"<<endl;
        cin>>x;

        switch(x)

        {  case 1:
                   s1.acceptStudent();
                   break;
            case 2:
                     s1.printstudent();
                     break;

               default:
                 cout<<"invalid choice"<<endl;     

        }

    }
}