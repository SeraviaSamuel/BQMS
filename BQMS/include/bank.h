#ifndef BANK_H
#define BANK_H
#include <queue>
#include"teller.h"
#include"customer.h"
struct CompareCustomer
{
    bool operator()(const customer& c1, const customer& c2)
    {
        return c1.getArrivalTime() > c2.getArrivalTime();

    }
};

class bank
{
    priority_queue<customer, vector<customer>, CompareCustomer> customerPriorityQueue; // Combined customer queue
    teller* ListOfTellers;
    int NumberOfTellers;
    int currentTellerIndex;
    int totalWaitingTime=0;
    int totalServiceTime=0;
public:
    bank(int TellersNumber)
    {
        NumberOfTellers = TellersNumber;
        ListOfTellers = new teller[NumberOfTellers];
        currentTellerIndex = 0;
    }
    void settotalWaitingTime(int num)
    {
        totalWaitingTime+=num;
    }
    void settotalServiceTime(int num)
    {
        totalServiceTime+=num;
    }
    int gettotalWaitingTime()
    {
        return totalWaitingTime;
    }
    int gettotalServiceTime()
    {
        return totalServiceTime;
    }
    void EnqueueCustomer(customer c)
    {
        customerPriorityQueue.push(c);
        //cout << "Customer " << c.getID()<< " arrived and added to the queue." << endl;
    }
    void DequeueCustomers()
    {
        while (!customerPriorityQueue.empty())
        {
            customer servedCustomer = customerPriorityQueue.top();
            customerPriorityQueue.pop();

            if (currentTellerIndex >= NumberOfTellers)
            {
                currentTellerIndex = 0;
            }
            if (ListOfTellers[currentTellerIndex].getisAvailable())
                if (ListOfTellers[currentTellerIndex].getServingTime() == 0)
                {
                    servedCustomer.setWaitingTime(0);
                    ListOfTellers[currentTellerIndex].setServingTime(servedCustomer.getLeavingTime());
                    ListOfTellers[currentTellerIndex].setNumberOfServedCustomers();
                    ListOfTellers[currentTellerIndex].serveCustomer(servedCustomer, currentTellerIndex);
                    cout <<"The Waiting Time of the Customer is : " << servedCustomer.getWaitingTime() << endl;
                    this->settotalWaitingTime(servedCustomer.getWaitingTime());
                    this->settotalServiceTime(ListOfTellers[currentTellerIndex].getServingTime());
                    ListOfTellers[currentTellerIndex].setTotalServingTime(ListOfTellers[currentTellerIndex].getServingTime());
                }
                else
                {
                    int index = GetAvilableTeller(NumberOfTellers, ListOfTellers, servedCustomer.getArrivalTime());
                    ListOfTellers[index].setNumberOfServedCustomers();
                    ListOfTellers[index].serveCustomer(servedCustomer, index);
                    servedCustomer.setWaitingTime(ListOfTellers[index].getServingTime()- servedCustomer.getArrivalTime());
                    ListOfTellers[index].setServingTime(servedCustomer.getLeavingTime()+ servedCustomer.getWaitingTime());
                    cout <<"The Waiting Time of the Customer is : " << servedCustomer.getWaitingTime() << endl;
                    this->settotalWaitingTime(servedCustomer.getWaitingTime());
                    this->settotalServiceTime(ListOfTellers[index].getServingTime());
                    ListOfTellers[index].setTotalServingTime(ListOfTellers[index].getServingTime());
                }

            currentTellerIndex++;
        }
    }
    void DisplayUtilization()
    {
        cout<<"Utilization Rate : "<<endl;
        if (totalServiceTime == 0)
        {
            cout << "No customers served yet." << endl;
            return;
        }
        for(int i = 0; i < NumberOfTellers; i++)
        {
            float utilization = (float)ListOfTellers[i].getTotalServingTime() / gettotalServiceTime() * 100.0f;
            //cout<<"Teller "<< i + 1 <<" Total Serving Time : "<<ListOfTellers[i].getTotalServingTime()<<endl;
            //cout<<"bank total serving time : "<<totalServiceTime<<endl;
            cout << " Teller " << i + 1 << " Utilization Rate : " << utilization << "%" << endl;
        }
    }
    void DisplayAverageWaitingTime()
    {
        cout<<"Average Waiting Time in The Bank : "<<endl;
        float avg=this->gettotalWaitingTime()/9.0;
        cout<<" Average Waiting Time : "<<avg<<endl;
    }
    void DisplayAverageServingTime()
    {
        cout<<"Average Serving Time in The Bank : "<<endl;
        float avg=this->gettotalServiceTime()/9.0;
        cout<<" Average Serving Time : "<<avg<<endl;
    }
    void DisplayNumberOfCustomersServedByTellers()
    {
        cout<<"Number Of Customers Served By Each Teller : "<<endl;
        for(int i = 0; i < NumberOfTellers; i++)
        {
            cout << " Teller " << i + 1 << " Serve : " << ListOfTellers[i].getNumberOfServedCustomers() <<" Customers"<<endl;
        }
    }
    int GetAvilableTeller(int NumberOfTellers, teller*teller,int arrivaltime)
    {
        int minindex = 0;
        int waitingTime=0;
        int minwaitingTime = INT_MAX;
        for (int i = 0; i < NumberOfTellers; i++)
        {
            waitingTime = teller[i].getServingTime() - arrivaltime;
            if (minwaitingTime > waitingTime)
            {
                minwaitingTime = waitingTime;
                minindex = i;
            }
        }
        return minindex;
    }

    void displayQueueStatus()
    {
        cout << "Current queue status :" << endl;
        if(customerPriorityQueue.empty())
        {
            cout << " The queue is empty , No customer to be served ." << endl;
        }
        else
        {
            priority_queue<customer, vector<customer>, CompareCustomer> displayQueue = customerPriorityQueue; // Create a copy of the priority queue
            int position = 1;
            while(!displayQueue.empty())
            {
                customer displayCustomer = displayQueue.top(); //front
                cout << " Position : " << position << " Customer ID : " << displayCustomer.getID()<<endl;
                displayQueue.pop();
                position++;
            }
        }
    }



};

#endif // BANK_H
