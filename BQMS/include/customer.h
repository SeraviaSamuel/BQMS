#ifndef CUSTOMER_H
#define CUSTOMER_H


class customer
{
    int ID;
    //string customerType;
    int ArrivalTime;
    int ServiceTime;
    int WaitingTime;
    int LeavingTime;
public:
    customer(int id, int servicetime, int arrivaltime) //string type
    {
        ID = id;
        //customerType=type;
        ServiceTime = servicetime;
        ArrivalTime = arrivaltime;
        WaitingTime = 0;
        LeavingTime = arrivaltime + servicetime;
    }

    int getID() const
    {
        return ID;
    }

    int getArrivalTime() const
    {
        return ArrivalTime;
    }

    int getServiceTime() const
    {
        return ServiceTime;
    }

    int getWaitingTime() const
    {
        return WaitingTime;
    }

    int getLeavingTime()
    {
        return LeavingTime;
    }
    void setID(int id)
    {
        ID = id;
    }

    void setArrivalTime(int arrivaltime)
    {
        ArrivalTime = arrivaltime;
    }

    void setServiceTime(int servicetime)
    {
        ServiceTime = servicetime;
    }

    void setWaitingTime(int waitingtime)
    {
        WaitingTime = waitingtime;

    }
    void setLeavingTime(int leavingtime)
    {
        LeavingTime = leavingtime;
    }
};

#endif // CUSTOMER_H
