import java.util.*;

/*
 *  Derived class: CheckingAccount
 *
 *  Description:
 *      Interest is computed daily; there's no fee for
 *      withdraw; there is a minimum balance of $1000.
 */

class CheckingAccount extends Account implements FullFunctionalAccount {

    CheckingAccount(String accountName_, double firstDeposit) throws BankingException {
        accountName = accountName_;
        if (firstDeposit < 1000) {
            throw new BankingException("First deposit was too few to checking account name:" +
                    accountName);
        }
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;
    }

    CheckingAccount(String accountName_, double firstDeposit, double interestRate) throws BankingException {
        accountName = accountName_;
        if (firstDeposit < 1000) {
            throw new BankingException("First deposit was too few to checking account name:" +
                    accountName);
        }
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = new Date();
        lastInterestDate = openDate;
    }

    CheckingAccount(String accountName_, double firstDeposit, double interestRate, Date firstDate)
            throws BankingException {
        accountName = accountName_;
        if (firstDeposit < 1000) {
            throw new BankingException("First deposit was too few to checking account name:" +
                    accountName);
        }
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = firstDate;
        lastInterestDate = openDate;
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        // minimum balance is 1000, raise exception if violated
        if ((accountBalance - amount) < 1000) {
            throw new BankingException("Underfraft from checking account name:" +
                    accountName);
        } else {
            accountBalance -= amount;
            return (accountBalance);
        }
    }

    public double computeInterest(Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException("Invalid date to compute interest for account name" +
                    accountName);
        }

        int numberOfDays = (int) ((interestDate.getTime()
                - lastInterestDate.getTime())
                / 86400000.0);
        System.out.println("Number of days since last interest is " + numberOfDays);
        double interestEarned = (double) numberOfDays / 365.0 *
                accountInterestRate * accountBalance;
        System.out.println("Interest earned is " + interestEarned);
        lastInterestDate = interestDate;
        accountBalance += interestEarned;
        return (accountBalance);
    }
}