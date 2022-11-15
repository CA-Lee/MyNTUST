import java.util.*;

/*
 * Derived class: SavingAccount
 *
 * Description:
 *      monthly interest; fee of $1 for every transaction, except
 *      the first three per month are free; no minimum balance.
 */

public class SavingAccount extends Account implements FullFunctionalAccount {
    protected Date lastTransactionDate;
    protected int freeTransQuota;

    SavingAccount(String accountName_, double firstDeposit, double interestRate) throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = new Date();
        lastInterestDate = openDate;
        lastTransactionDate = openDate;
        freeTransQuota = 3;
    }

    SavingAccount(String accountName_, double firstDeposit, double interestRate, Date firstDate)
            throws BankingException {
        accountName = accountName_;
        accountBalance = firstDeposit;
        accountInterestRate = interestRate;
        openDate = firstDate;
        lastInterestDate = openDate;
        lastTransactionDate = openDate;
        freeTransQuota = 3;
    }

    private double getTransFee(Date transDate) {
        if (freeTransQuota > 0)
            return 0;
        else
            return 1;
    }

    private void updateFreeTransQuota(Date transDate) {
        if (transDate.getTime() - lastTransactionDate.getTime() > (long) 1000 * 60 * 60 * 24 * 30) {
            freeTransQuota = 3;
        }
        freeTransQuota--;
        lastTransactionDate = transDate;
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        if ((accountBalance - amount - getTransFee(withdrawDate)) < 0) {
            throw new BankingException("Underfraft from checking account name:" +
                    accountName);
        } else {
            accountBalance -= amount + getTransFee(withdrawDate);
            updateFreeTransQuota(withdrawDate);
            return (accountBalance);
        }
    }

    public double deposit(double amount) throws BankingException {
        Date depositDate = new Date();
        accountBalance += amount - getTransFee(depositDate);
        updateFreeTransQuota(depositDate);
        return (accountBalance);
    }

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
