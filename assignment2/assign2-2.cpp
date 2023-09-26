// Q2. Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
// Instead of char[] use string datatype

#include <iostream>
using namespace std;

class Address
{
private:
    string building;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        cout << "default/parameterless constructor called" << endl;
    }
    Address(string building, string street, string city, int pin)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    void acceptadd()
    {
        cout << "enter building name ";
        cin >> building;
        cout << endl;
        cout << "enter street name ";
        cin >> street;
        cout << endl;
        cout << "enter city name ";
        cin >> city;
        cout << endl;
        cout << "enter pin ";
        cin >> pin;
        cout << endl;
    }
    void displayadd()
    {
        cout << "building: " << this->building << "street:" << this->street << "  city:" << this->city << " pin:" << this->pin;
    }
    string get_building()
    {
        return building; // returns building
    }
    string get_street()
    {
        return street; // returns street
    }

    string get_city()
    {
        return city; // returns city
    }
    int get_pin()
    {
        return pin; // returns pin
    }
    // setters

    void set_building(string building)
    {
        this->building = building;

    } // sets building

    void set_street(string street)
    {
        this->street = street;
        // sets street
    }

    void set_city(string city)
    {
        this->city = city; // sets city
    }

    void set_pin(int pin)
    {
        this->pin = pin;
    } // sets pin
};

int main()
{
    Address a1;
    int x;
    while (x)
    {   cout<<endl;
        cout << "0- exit " << endl;
        cout << "1- accept address" << endl;
        cout << "2-display address" << endl;
        cout << "3- to set building " << endl;
        cout << "4-to  set street " << endl;
        cout << "5- to set city " << endl;
        cout << "6-to  set pin" << endl;
        cout << "7-to view building name" << endl;
        cout << "8- to view street name " << endl;
        cout << "9- to view city " << endl;
        cout << " 10 to view pin" << endl;
        cin >> x;
        string bui, street, city;

        switch (x)
        {

        case 1:
            a1.acceptadd();
            break;
        case 2:
            a1.displayadd();
            break;
        case 3:
            cout << endl;
            cout << "enter building name ";
            cin >> bui;
            a1.set_building(bui);
            break;

        case 4:
            cout << endl;
            cout << "enter street name ";
            cin >> street;
            a1.set_street(street);
            break;

        case 5:
            cout << endl;
            cout << "enter city name";
            cin >> city;
            a1.set_city(city);
            break;
        case 6:
            int pino;
            cout << endl;
            cout << "enter pin no";
            cin >> pino;
            a1.set_pin(pino);
            break;
        case 7:
            cout << "building = " << a1.get_building() <<endl;
            break;

        case 8:
            cout << " street=" << a1.get_street() << endl;
            break;

        case 9:
            cout << " city=" << a1.get_city() << endl;
            break;
        case 10:
            cout << "  pin= " << a1.get_pin() << endl;
            break;

        default:
            cout << "invalid Choice " << endl;
            break;
        }
    }
}