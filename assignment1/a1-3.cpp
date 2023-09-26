#include <iostream>
#include<cstring>
class Student
{
    int rollno;
    char name[50];
    int marks;

public:
    void initStudent()
    {
        this->rollno = 0;
        strcpy(this->name,"Rahul");
        this->marks = 0;
    }
    void printstudent()
    {
        printf("name = %s", this->name);
        printf("\n rollno= %d", this->rollno);
        printf("\n marks = %d", this->marks);
    }

    void acceptStudent()
    {
        printf("\n enter roll no ");
        scanf("%d", &rollno);
        printf("\n enter name ");
        scanf("%s", &name);
        printf("enter marks ");
        scanf("%d", &marks);
    }
};
int main()
{
    Student s1;
    int x;
    while (x)
    {
        printf("\n 0-Exit");
        printf("\n1-to initialize default data ");
        printf("\n 2-to insert  student value");
        printf("\n 3-Display student data only");
        scanf("%d", &x);

        if (x >= 0 && x <= 3)
        {
            switch (x)
            {
            case 1:
                s1.initStudent();
                break;

            case 2:
                s1.acceptStudent();
                s1.printstudent();
                break;

            case 3:
                s1.printstudent();
                break;
            }
        }
        else
        {
            printf("\n enter invalid data \n");
        }
    }
}