#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H
#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual void Pay(double amount) = 0;
};

class ShoppingCart
{
private:
    PaymentStrategy* m_payStrategy;
public:
    ShoppingCart(PaymentStrategy* strategy=nullptr):m_payStrategy(strategy)
    {

    }

    void SetPaymentStrategy(PaymentStrategy* strategy)
    {
        m_payStrategy = strategy;
    }

    void Checkout(int amount)
    {
        m_payStrategy->Pay(amount);
    }
};

class CreditCardPayment:public PaymentStrategy
{
public:
    virtual void Pay(double amount)
    {
        cout << "Pay " << amount << " by credit card." << endl;
    }
};

class CashPayment:public PaymentStrategy
{
public:
    virtual void Pay(double amount)
    {
        cout << "Pay " << amount << " by Cash." << endl;
    }
};


#endif // PAYMENTSTRATEGY_H
