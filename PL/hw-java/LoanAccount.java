import java.util.*;

/*
 * Derived class: LoanAccount
 *
 * Description:
 * like a saving account, but the balance is “negative” (you owe
 * the bank money, so a deposit will reduce the amount of the loan);
 * you can’t withdraw (i.e., loan more money) but of course you can
 * deposit (i.e., pay off part of the loan).
 */

class LoanAccount extends SavingAccount {

    LoanAccount(String accountName_, double firstDeposit) throws BankingException {
        super(accountName_, firstDeposit);
        accountName = accountName_;
        if (firstDeposit > 0) {
            throw new BankingException("First deposit was too much to loan account name:" +
                    accountName);
        }
    }

    LoanAccount(String accountName_, double firstDeposit, double interestRate, Date firstDate)
            throws BankingException {
        super(accountName_, firstDeposit, interestRate, firstDate);
        accountName = accountName_;
        if (firstDeposit > 0) {
            throw new BankingException("First deposit was too much to loan account name:" +
                    accountName);
        }
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        throw new BankingException("Not allowed");
    }

    public double deposit(double amount) throws BankingException {
        if (accountBalance + amount - getTransFee(new Date()) > 0)
            throw new BankingException("Too much amount");
        return super.deposit(amount);
    }
}
