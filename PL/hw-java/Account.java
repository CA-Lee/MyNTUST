
/*****************************************************************
    CS4001301 Programming Languages                   
    
    Programming Assignment #1
    
    Java programming using subtype, subclass, and exception handling
    
    To compile: %> javac Application.java
    
    To execute: %> java Application

******************************************************************/

import java.util.*;

class BankingException extends Exception {
    BankingException () { super(); }
    BankingException (String s) { super(s); }
} 

interface BasicAccount {
    String name();
    double balance();	
}

interface WithdrawableAccount extends BasicAccount {
    double withdraw(double amount) throws BankingException;	
}

interface DepositableAccount extends BasicAccount {
    double deposit(double amount) throws BankingException;	
}

interface InterestableAccount extends BasicAccount {
    double computeInterest() throws BankingException;	
}

interface FullFunctionalAccount extends WithdrawableAccount,
                                        DepositableAccount,
                                        InterestableAccount {
}

public abstract class Account {
	
    // protected variables to store commom attributes for every bank accounts	
    protected String accountName;
    protected double accountBalance;
    protected double accountInterestRate;
    protected Date openDate;
    protected Date lastInterestDate;
    
    // public methods for every bank accounts
    public String name() {
    	return(accountName);	
    }	
    
    public double balance() {
        return(accountBalance);
    }
    
    public double deposit(double amount) throws BankingException{
        accountBalance += amount;
        return(accountBalance);
    } 
    
    abstract double withdraw(double amount, Date withdrawDate) throws BankingException;
    
    public double withdraw(double amount) throws BankingException {
        Date withdrawDate = new Date();
        return(withdraw(amount, withdrawDate));
    }
    
    abstract double computeInterest(Date interestDate) throws BankingException;
    
    public double computeInterest() throws BankingException {
        Date interestDate = new Date();
        return(computeInterest(interestDate));
    }
}
