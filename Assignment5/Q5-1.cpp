/*
Q1. Write a menu driven program for Student management.
In main(), create Array of Objects and provide facility for accept, print, search and sort.
For student accept name, gender, rollNumber and marks of three subjects from user and print name,
rollNumber, gender and percentage.
Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
sorting and searching array.
Search function returns index of found Student, otherwise returns -1.
*/

#include <iostream>
#define size 5
using namespace std;

class Student
{
private:
    int rollno;
    string name;
    string gender;
    float *marks;
public:
    Student()
    {
        this->rollno = 0;
        this->name = "";
        this->gender = "";
        this->marks = new float[3];
    }

    Student(int rollno, string name, string gender)
    {
        this->rollno = rollno;
        this->name = name;
        this->gender = gender;
        this->marks = new float[3];
        float marks;
    }

    void Acceptdata()
    {
        cout << "enter rollno=" ;
        cin >> this->rollno;
        cout << "enter name=" ;
        cin >> this->name;
        cout << "enter gender=";
        cin >> this->gender;
        for (int i = 0; i < 3; i++)
        {
            float marks;
            cout << "enter marks=";
            cin >> marks;
            this->marks[i] = marks;
        }
    }

    void printData()
    {
        cout << "rollno=" << this->rollno << endl;
        cout << "name=" << this->name << endl;
        cout << "gender=" << this->gender << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "marks=" << this->marks[i] << endl;
        }
    }

    int getRollno()
    {
        return this->rollno;
    }

    friend void searchRecords();
    friend void sortRecords();
};
void searchRecords(Student s[])
{
    int key;
    cout << "enter rollno for searching: " << endl;
    cin >> key;
    for (int i = 0; i < 3; i++)
    {
        if (s[i].getRollno() == key)
            cout << "index=" << i << endl;
        else
            cout<<"rollno not found"<<endl;
    }
}
void sortRecords(Student s[])
{
    Student temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (s[i].getRollno() > s[j].getRollno())
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
enum Emenu
{
    EXIT,
    ACCEPT_DATA,
    RECORDS_SEARCHING,
    RECORDS_SORTING,
    PRINT_DATA
};
Emenu menu()
{
    int choice;
    cout << "******************************************"<< endl;
    cout << "select any choice" << endl;
    cout << "0.exit" << endl;
    cout << "1. for accepting records" << endl;
    cout << "2.for searching records" << endl;
    cout << "3.for sorting records" << endl;
    cout << "4.printing records" << endl;
    cin >> choice;
    cout<<"***********************************************"<<endl;
    return Emenu(choice);
}

int main()
{
    Emenu choice;
    Student s[size];
    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case ACCEPT_DATA: 
            for (int i = 1; i < size; i++)
            {
             s[i].Acceptdata();
            }
            break;

        case RECORDS_SEARCHING: 
            searchRecords(s);
            break;

        case RECORDS_SORTING:
            sortRecords(s); 
            break;

        case PRINT_DATA:
            for (int i = 1; i < size; i++)
            {
                s[i].printData();
            } 
            break;

        default:
            cout<<"enter valid choice"<<endl;
            break;
        }
    }
    return 0;
}