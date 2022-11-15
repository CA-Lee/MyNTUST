import java.util.*;

/*
 * Derived class: SavingAccount
 *
 * Description:
 *      monthly interest; fee of $1 for every transaction, except
 *      the first three per month are free; no minimum balance.
 */

public class SavingAccount extends Account implements FullFunctionalAccount {
    SavingAccount(String accountName_, double firstDeposit) throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;
    }

    SavingAccount(String accountName_, double firstDeposit, double interestRate) throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = new Date();
        lastInterestDate = openDate;
    }

    SavingAccount(String accountName_, double firstDeposit, double interestRate, Date firstDate)
            throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = firstDate;
        lastInterestDate = openDate;
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        // minimum balance is 1000, raise exception if violated
        if ((accountBalance - amount) < 0) {
            throw new BankingException("Underfraft from checking account name:" +
                    accountName);
        } else {
            accountBalance -= amount + 1;
            return (accountBalance);
        }
    }

    // public double deposit(double amount) throws BankingException {
    // accountBalance += amount - 1;
    // return (accountBalance);
    // }

    public double computeInterest(Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException("Invalid date to compute interest for account name: " +
                    accountName);
        }

        int numberOfMounths = (int) ((interestDate.getTime()
                - lastInterestDate.getTime())
                / (86400000.0 * 30));
        System.out.println("Number of months since last interest is " + numberOfMounths);
        double interestEarned = (double) numberOfMounths / 12 *
                accountInterestRate * accountBalance;
        System.out.println("Interest earned is " + interestEarned);
        if (numberOfMounths > 0) {
            lastInterestDate = interestDate;
            accountBalance += interestEarned;
        }
        return (accountBalance);
    }
}
