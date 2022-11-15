
/*****************************************************************
    CS4001301 Programming Languages                   
    
    Programming Assignment #1
    
    Java programming using subtype, subclass, and exception handling
    
    To compile: %> javac Application.java
    
    To execute: %> java Application

******************************************************************/

import java.util.*;

public class Application {

    public static void main(String args[]) {
        final double YEARLY_INTEREST_RATE = 0.12;
        Account checkingAccount;
        // Date d;
        double ret;
        boolean testPassed = true;
        try {

            checkingAccount = new CheckingAccount("John Smith", 1500.0);

            try {
                ret = checkingAccount.withdraw(100.00);
                System.out.println("Account <" + checkingAccount.name() + "> now has $" + ret + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, checkingAccount.balance());
                testPassed = false;
            }

            checkingAccount = new CheckingAccount("John Smith", 1500.0);

            // should throw
            try {
                ret = checkingAccount.withdraw(600.00);
                System.out.println("Account <" + checkingAccount.name() + "> now has $" + ret + " balance\n");
                testPassed = false;
            } catch (Exception e) {
                stdExceptionPrinting(e, checkingAccount.balance());
            }

            /* put your own tests here ....... */

            // comprehensive test of CheckingAccount

            // test minimum balance
            try {
                CheckingAccount checkingAccountFewDeposit = new CheckingAccount(
                        "checkingAccountFewDeposit", 100,
                        YEARLY_INTEREST_RATE);
                testPassed = false;
                checkingAccountFewDeposit.balance();
            } catch (Exception e) {
            }

            CheckingAccount checkingAccount2 = new CheckingAccount(
                    "checkingAccount2", 1000, YEARLY_INTEREST_RATE);

            // name
            if (checkingAccount2.name() != "checkingAccount2") {
                testPassed = false;
            }

            // balance
            if (checkingAccount2.balance() != 1000) {
                testPassed = false;
            }

            // deposit
            checkingAccount2.deposit(100);
            if (checkingAccount2.balance() != 1100) {
                testPassed = false;
            }

            // withdraw
            try {
                ret = checkingAccount2.withdraw(100.00);
            } catch (Exception e) {
                testPassed = false;
            }

            // should throw
            try {
                ret = checkingAccount2.withdraw(600.00);
                testPassed = false;
            } catch (Exception e) {
            }

            // compute_interest

            Date interestDate = new Date();
            interestDate.setTime(interestDate.getTime() + 1000 * 60 * 60 * 24); // add one day

            // test w/ default openDate
            double beforeBalance = checkingAccount2.balance();
            if (beforeBalance != checkingAccount2.computeInterest()) {
                testPassed = false;
            }

            if (checkingAccount2.computeInterest(interestDate) != beforeBalance
                    * (1 + YEARLY_INTEREST_RATE / 365)) {
                testPassed = false;
            }

            // test w/ specified openDate
            Date firstDate = ((Date) interestDate.clone());
            firstDate.setTime(interestDate.getTime() - 1000 * 60 * 60 * 24 * 2);

            CheckingAccount checkingAccount3 = new CheckingAccount("checkingAccount3", 1000, YEARLY_INTEREST_RATE,
                    firstDate);
            double beforeBalance3 = checkingAccount3.balance();
            if (checkingAccount3.computeInterest() != beforeBalance3 * (1 + YEARLY_INTEREST_RATE / 365)) {
                testPassed = false;
            }

            if (checkingAccount3.computeInterest(interestDate) != beforeBalance3
                    * (1 + YEARLY_INTEREST_RATE / 365) * (1 + YEARLY_INTEREST_RATE / 365)) {
                testPassed = false;
            }

            /**********************/
            // comprehensive test of ...

            // name
            // balance
            // deposit
            // withdraw
            // compute_interest
            // test w/ default openDate
            // test w/ specified openDate

            // compute_interest
            /**********************/

            /*
             * if your implementaion is correct, you can do the following with polymorphic
             * array accountList
             */
            // Account[] accountList;

            // accountList = new Account[4];

            // // buid 4 different accounts in the same array
            // accountList[0] = new CheckingAccount("John Smith", 1500.0);
            // accountList[1] = new SavingAccount("William Hurt", 1200.0);
            // accountList[2] = new CDAccount("Woody Allison", 1000.0);
            // accountList[3] = new LoanAccount("Judi Foster", -1500.0);

            // // compute interest for all accounts
            // for (int count = 0; count < accountList.length; count++) {
            // double newBalance = accountList[count].computeInterest();
            // System.out.println("Account <" + accountList[count].name() + "> now has $" +
            // newBalance + " balance\n");
            // }

        } catch (Exception e) {
            stdExceptionPrinting(e, 0);
            testPassed = false;
        } finally {
            // simple final result
            System.out.println((testPassed ? "Test passed." : "Test failed.") + "\n");
        }
    }

    static void stdExceptionPrinting(Exception e, double balance) {
        System.out.println("EXCEPTION: Banking system throws a " + e.getClass() +
                " with message: \n\t" +
                "MESSAGE: " + e.getMessage());
        System.out.println("\tAccount balance remains $" + balance + "\n");
    }
}