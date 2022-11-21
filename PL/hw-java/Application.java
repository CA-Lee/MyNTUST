
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
        Date today = new Date();
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
                Account checkingAccountFewDeposit = new CheckingAccount(
                        "checkingAccountFewDeposit", 100,
                        YEARLY_INTEREST_RATE);
                testPassed = false;
                checkingAccountFewDeposit.balance();
            } catch (Exception e) {
            }

            Account checkingAccount2 = new CheckingAccount(
                    "checkingAccount2", 1000, YEARLY_INTEREST_RATE);

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
            interestDate.setTime(today.getTime() + 1000 * 60 * 60 * 25); // add one day

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
            Date firstDate = new Date();
            firstDate.setTime(today.getTime() - 1000 * 60 * 60 * 25);

            Account checkingAccount3 = new CheckingAccount("checkingAccount3", 1000, YEARLY_INTEREST_RATE,
                    firstDate);
            double beforeBalance3 = checkingAccount3.balance();
            if (checkingAccount3.computeInterest() != beforeBalance3 * (1 + YEARLY_INTEREST_RATE / 365)) {
                testPassed = false;
            }

            if (checkingAccount3.computeInterest(interestDate) != beforeBalance3
                    * (1 + YEARLY_INTEREST_RATE / 365) * (1 + YEARLY_INTEREST_RATE / 365)) {
                testPassed = false;
            }

            // comprehensive test of SavingAccount
            Account savingAccount = new SavingAccount("savingAccount", 1000, YEARLY_INTEREST_RATE, today);

            // deposit
            savingAccount.deposit(100);
            if (savingAccount.balance() != 1100) {
                testPassed = false;
            }

            // withdraw
            savingAccount.withdraw(100);
            if (savingAccount.balance() != 1000) {
                testPassed = false;
            }
            savingAccount.withdraw(100);
            savingAccount.withdraw(100);
            if (savingAccount.balance() != 799) {
                testPassed = false;
            }

            try {
                savingAccount.withdraw(99999);
                testPassed = false;
            } catch (Exception e) {
            }

            // compute_interest
            interestDate.setTime(today.getTime() + (long) (1000 * 60 * 60 * 24) * 31);

            // test w/ default openDate
            beforeBalance = savingAccount.balance();

            if (beforeBalance != savingAccount.computeInterest()) {
                testPassed = false;
            }

            if (savingAccount.computeInterest(interestDate) != beforeBalance
                    * (1 + YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            // test w/ specified openDate
            firstDate.setTime(today.getTime() - (long) 1000 * 60 * 60 * 24 * 31);
            Account savingAccount2 = new SavingAccount("savingAccount2", 1000,
                    YEARLY_INTEREST_RATE,
                    firstDate);
            beforeBalance = savingAccount2.balance();
            if (savingAccount2.computeInterest() != beforeBalance * (1 +
                    YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            if (savingAccount2.computeInterest(interestDate) != beforeBalance
                    * (1 + YEARLY_INTEREST_RATE / 12) * (1 + YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            // comprehensive test of CDAccount
            Account cDAccount = new CDAccount("cDAccount", 1000, YEARLY_INTEREST_RATE, today, 360);

            // deposit
            try {
                cDAccount.deposit(100);
                testPassed = false;
            } catch (Exception e) {
            }

            // withdraw
            cDAccount.withdraw(100);
            if (cDAccount.balance() != 650) {
                testPassed = false;
            }

            try {
                cDAccount.withdraw(99999);
                testPassed = false;
            } catch (Exception e) {
            }

            ((CDAccount) cDAccount).withdraw(100, new Date(today.getTime() + (long) 1000
                    * 60 * 60 * 24 * 400));
            if (cDAccount.balance() != 550) {
                testPassed = false;
            }

            // compute_interest
            interestDate.setTime(today.getTime() + (long) (1000 * 60 * 60 * 24) * 31);

            // test w/ default openDate
            beforeBalance = cDAccount.balance();

            if (beforeBalance != cDAccount.computeInterest()) {
                testPassed = false;
            }

            if (cDAccount.computeInterest(interestDate) != beforeBalance * (1 + YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            // test w/ specified openDate
            firstDate.setTime(today.getTime() - (long) 1000 * 60 * 60 * 24 * 31);
            Account cdAccount2 = new CDAccount("cdAccount2", 1000,
                    YEARLY_INTEREST_RATE,
                    firstDate, 360);
            beforeBalance = cdAccount2.balance();
            if (cdAccount2.computeInterest() != beforeBalance * (1 +
                    YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            if (cdAccount2.computeInterest(interestDate) != beforeBalance * (1 + YEARLY_INTEREST_RATE / 12)
                    * (1 + YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            Account cdAccount3 = new CDAccount("cdAccount3", 1000,
                    YEARLY_INTEREST_RATE,
                    today, 360);
            interestDate.setTime(today.getTime() + (long) (1000 * 60 * 60 * 24) * 400);
            beforeBalance = cdAccount3.balance();

            if (cdAccount3.computeInterest(interestDate) != beforeBalance * (1 + YEARLY_INTEREST_RATE / 12 * 12)) {
                testPassed = false;
            }

            // comprehensive test of LoanAccount
            Account loanAccount = new LoanAccount("loanAccount", -1000, YEARLY_INTEREST_RATE, today);

            // deposit
            loanAccount.deposit(100);
            if (loanAccount.balance() != -900) {
                testPassed = false;
            }

            // withdraw
            try {
                loanAccount.withdraw(100);
                testPassed = false;
            } catch (Exception e) {
            }

            // compute_interest
            interestDate.setTime(today.getTime() + (long) (1000 * 60 * 60 * 24) * 31);

            // test w/ default openDate
            beforeBalance = loanAccount.balance();

            if (beforeBalance != loanAccount.computeInterest()) {
                testPassed = false;
            }

            if (loanAccount.computeInterest(interestDate) != beforeBalance
                    * (1 + YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            // test w/ specified openDate
            firstDate.setTime(today.getTime() - (long) 1000 * 60 * 60 * 24 * 31);
            Account loanAccount2 = new LoanAccount("loanAccount2", -1000,
                    YEARLY_INTEREST_RATE,
                    firstDate);
            beforeBalance = loanAccount2.balance();
            if (loanAccount2.computeInterest() != beforeBalance * (1 +
                    YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            if (loanAccount2.computeInterest(interestDate) != beforeBalance
                    * (1 + YEARLY_INTEREST_RATE / 12) * (1 + YEARLY_INTEREST_RATE / 12)) {
                testPassed = false;
            }

            ArrayList<Class<? extends Account>> accountClassList = new ArrayList<Class<? extends Account>>();
            accountClassList.add(CheckingAccount.class);
            accountClassList.add(SavingAccount.class);
            accountClassList.add(CDAccount.class);
            // accountClassList.add(LoanAccount.class);

            for (Class<? extends Account> cls : accountClassList) {
                try {
                    Account account = cls.getDeclaredConstructor(String.class, double.class)
                            .newInstance("account", 10000);
                    // name
                    if (account.name() != "account") {
                        testPassed = false;
                    }

                    // balance
                    if (account.balance() != 10000) {
                        testPassed = false;
                    }

                } catch (Exception e) {
                    stdExceptionPrinting(e, 167);
                    testPassed = false;
                    continue;
                }
            }

            /*
             * if your implementaion is correct, you can do the following with polymorphic
             * array accountList
             */
            Account[] accountList;

            accountList = new Account[4];

            // buid 4 different accounts in the same array
            accountList[0] = new CheckingAccount("John Smith", 1500.0);
            accountList[1] = new SavingAccount("William Hurt", 1200.0);
            accountList[2] = new CDAccount("Woody Allison", 1000.0);
            accountList[3] = new LoanAccount("Judi Foster", -1500.0);

            // compute interest for all accounts
            for (int count = 0; count < accountList.length; count++) {
                double newBalance = accountList[count].computeInterest();
                System.out.println("Account <" + accountList[count].name() + "> now has $" +
                        newBalance + " balance\n");
            }

        } catch (

        Exception e) {
            stdExceptionPrinting(e, 195);
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