#include <iostream>
#include "PaymentStrategy.h"

int main(int argc, char *argv[])
{
    CreditCardPayment ccPayment;
    CashPayment cashPayment;
    ShoppingCart shoppingCart;

    shoppingCart.SetPaymentStrategy(&cashPayment);
    shoppingCart.Checkout(100);

    shoppingCart.SetPaymentStrategy(&ccPayment);
    shoppingCart.Checkout(200);
    return 0;
}
