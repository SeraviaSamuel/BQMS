#ifndef TELLER_H
#define TELLER_H
#include"customer.h"
#include<iostream>
using namespace std;
class teller
{
    bool isAvailable;
    int ServingTime;
    int numberOfServedCustomers=0;
    int totalServingTime = 0;
    //customer currentCustomer;

public:
    teller()
    {
        isAvailable = true;
        ServingTime = 0;
    }
    void setTotalServingTime(int serviceTime)
    {
        totalServingTime += serviceTime;
    }
    void SetisAvailable(bool value)
    {
        isAvailable = value;
    }
    void setServingTime(int servingtime)
    {
        ServingTime = servingtime;
    }
    void setNumberOfServedCustomers()
    {
        numberOfServedCustomers++;
    }
    int getTotalServingTime() const
    {
        return totalServingTime;
    }
    int getNumberOfServedCustomers()
    {
        return numberOfServedCustomers;
    }
    int getServingTime()
    {
        return ServingTime;
    }
    bool getisAvailable()
    {
        return isAvailable;
    }
    void serveCustomer(customer& customer, int tellerid)
    {
        isAvailable = false;
        cout << "The customer : " << customer.getID() << " Served by Teller : " << tellerid + 1 <<endl;
        customer.setLeavingTime(customer.getArrivalTime() + customer.getServiceTime()+customer.getWaitingTime());
        isAvailable = true;
    }
    /*void assignCustomerToTeller (Customer &customer)
    {
        this->currentCustomer = customer;
        this->isAvailable = false;
        //cout << "Customer assigned to teller , Teller is now busy." <<endl;
    }*/

};

#endif // TELLER_H
