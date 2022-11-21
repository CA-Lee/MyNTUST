import java.util.*;

/*
 * Derived class: CDAccount
 *
 * Description:
 * monthly interest; fixed amount and duration (e.g., you can open
 * 1 12-month CD for $5000; for the next 12 months you can’t deposit
 * anything and withdrawals cost a $250 fee); at the end of the
 * duration the interest payments stop and you can withdraw w/o fee.
 */

public class CDAccount extends Account implements WithdrawableAccount, InterestableAccount {
    protected int accountDurationDays;

    CDAccount(String accountName_, double firstDeposit) throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;
        accountDurationDays = 365;
    }

    CDAccount(String accountName_, double firstDeposit, double interestRate, Date firstDate, int durationDays)
            throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = firstDate;
        lastInterestDate = openDate;
        accountDurationDays = durationDays;
    }

    public double deposit(double amount) throws BankingException {
        throw new BankingException("Not allowed");
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        if (withdrawDate.getTime() - openDate.getTime() < (long) 1000 * 60 * 60 * 24 * accountDurationDays) {
            // cost 250 fee
            if ((accountBalance - amount - 250) < 0) {
                throw new BankingException("Underfraft from CD account name:" +
                        accountName);
            } else {
                accountBalance -= amount + 250;
                return (accountBalance);
            }
        } else {
            // fee free
            if ((accountBalance - amount) < 0) {
                throw new BankingException("Underfraft from CD account name:" +
                        accountName);
            } else {
                accountBalance -= amount;
                return (accountBalance);
            }
        }
    }

    public double computeInterest(Date interestDate) throws BankingException {
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException("Invalid date to compute interest for account name: " +
                    accountName);
        }

        int numberOfMounths = (int) ((Math.min(interestDate.getTime(),
                openDate.getTime() + (long) 1000 * 60 * 60 * 24 * accountDurationDays // payment due
        ) - lastInterestDate.getTime()) / (86400000.0 * 30));
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