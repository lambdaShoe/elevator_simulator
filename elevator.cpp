#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include<typeinfo>
using namespace std;

class Elevator {
    // Access specifier
public:
    // Data  Members
    int current_floor;
    bool isUsing;
    // Member Functions()
    void display_floor();
    void move(int current,int floor);

} elevator1 , elevator2;


int main() {
    int desired_floor;
    int desired_elevator;
    int customer_curfloor;

    elevator1.current_floor = 1;
    elevator2.current_floor = 1;

    while (true)
    {
        cout << endl
             << "Please choose your elevator: ";
             
        cin >> desired_elevator;
        
        if (desired_elevator != 1 
         && desired_elevator != 2)
        {
            cout << "invalid elevator!"
                 << endl;
            cout << "Try again." 
                 <<endl;

            cin.clear();
            cin.ignore(100, '\n');
        }
        else
        {
            cout << endl 
                 << "Enter Current floor: ";

            if(desired_elevator == 1)
            {
                cin >> customer_curfloor;
                elevator1.isUsing = true;
            }
            else
            {
                cin >> customer_curfloor;
                elevator2.isUsing = true;
            }
            
            
            cout << endl 
                 <<"Enter Desired Floor: ";

            cin >> desired_floor;
            
            //move elevator
            if(desired_elevator == 1)
            {
                elevator1.move(customer_curfloor,desired_floor);
                elevator1.isUsing = false;
            }
            else
            {
                elevator2.move(customer_curfloor,desired_floor);
                elevator2.isUsing = false;
            }
        }

    }

    return 0;
}

void Elevator::display_floor()
{
    if(elevator1.isUsing == true)
    {
        cout << endl
         <<"(1) Current floor: " 
         << elevator1.current_floor 
         << endl;
         
    }
    else 
    {
        cout << endl
         <<"(2) Current floor: " 
         << elevator2.current_floor 
         << endl;
    }
    
}

void Elevator::move(int current,int floor)
{
    //Move from previous floor to client current floor
    if(elevator1.isUsing == true)
    {
        if(elevator1.current_floor >= current) //go down
        {
             while(elevator1.current_floor != current - 1)
            {
                display_floor();
                sleep(1);
                elevator1.current_floor --;
            }
        }
        else //go up
        {
            while(elevator1.current_floor != current + 1) 
            {
                display_floor();
                sleep(1);
                elevator1.current_floor ++;
            }
        }
    }
    else
    {
        if(elevator2.current_floor >= current ) //go down
        {
             while(elevator2.current_floor != current - 1)
            {
                display_floor();
                sleep(1);
                elevator2.current_floor --;
            }
        }
        else //go up
        {
            while(elevator2.current_floor!= current + 1) 
            {
                display_floor();
                sleep(1);
                elevator2.current_floor ++;
            }
        }
    }

    cout << endl
         << "Your elevator has arrived."
         << endl;

    //Move from client current floor to desired floor
    if(current >= floor) //go down
    {
        while(current != floor - 1)
        {
            if(elevator1.isUsing == true) elevator1.current_floor = current;
            else elevator2.current_floor = current;
            display_floor();
            sleep(1);
            current -= 1;
        }
    }
    else //go up
    {
        while(current != floor + 1) 
        {
            if(elevator1.isUsing == true) elevator1.current_floor = current;
            else elevator2.current_floor = current;
            display_floor();
            sleep(1);
            current += 1;
        }
    }

    cout << endl
         << "You have arrived your destination."
         << endl
         << "Thank you for taking the elevator and we hope to see you again." 
         << endl;

}