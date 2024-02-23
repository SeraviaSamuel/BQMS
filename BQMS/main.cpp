#include <iostream>
#include"bank.h"
using namespace std;

int main()
{
    bank b(3);
    b.EnqueueCustomer(customer(1, 62, 35));
    b.EnqueueCustomer(customer(2, 57, 39));
    b.EnqueueCustomer(customer(3,124,78));
    b.EnqueueCustomer(customer(4, 50, 80));
    b.EnqueueCustomer(customer(5, 55, 82));
    b.EnqueueCustomer(customer(6, 60, 85));
    b.EnqueueCustomer(customer(7, 50, 88));
    b.EnqueueCustomer(customer(8, 59, 89));
    b.EnqueueCustomer(customer(9, 63, 95));

    b.displayQueueStatus();
    cout<<"---------------------------------------------"<<endl;
    b.DequeueCustomers();
    cout<<"---------------------------------------------"<<endl;
    b.displayQueueStatus();
    cout<<"---------------------------------------------"<<endl;
    b.DisplayNumberOfCustomersServedByTellers();
    cout<<"---------------------------------------------"<<endl;
    b.DisplayAverageWaitingTime();
    cout<<"---------------------------------------------"<<endl;
    b.DisplayAverageServingTime();
    cout<<"---------------------------------------------"<<endl;
    b.DisplayUtilization();
    cout<<"---------------------------------------------"<<endl;
    return 0;
}
