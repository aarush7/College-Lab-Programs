package com.company;

import java.util.Scanner;

class DemonetizationException extends Exception
{
    void display(double num)
    {
        System.out.println("Deposit of Old Currency of Rs. "+num+" crosses Rs. 5,000 and cannot be Deposited");
    }
}
class Account {
    private double balance;
    void deposit(double amount, String currencyType)
    {

        if(currencyType.equals("NEW"))
            balance+=amount;
        else
        {
            if(amount<=5000)
                balance+=amount;
            else
            {
                try
                {
                    throw new DemonetizationException();
                }
                catch(DemonetizationException d)
                {
                    d.display(amount);
                }
            }
        }
    }
    void withdraw(double amount)
    {
        if(balance-amount<500)
        {
            System.out.println("Balance should not go under Rs. 500. Error");
        }
        else
            balance-=amount;
    }
    void currBalance()
    {
        System.out.println("The current balance is Rs "+balance);
    }
    Account()
    {
        balance=500;
    }
}
class Customer
{
    public static void main(String args[])
    {
        Account a=new Account();
        Scanner in= new Scanner (System.in);
        while(true)
        {
            int choice;
            System.out.println("Enter");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Check Balance");
            choice = in.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the amount and Currency Type");
                    double am;
                    String cur;
                    am = in.nextDouble();
                    cur = in.next();
                    a.deposit(am, cur);
                    break;
                case 2:
                    System.out.println("Enter the amount");
                    am = in.nextDouble();
                    a.withdraw(am);
                    break;
                case 3:
                    a.currBalance();
                    break;
            }
        }
    }
}
