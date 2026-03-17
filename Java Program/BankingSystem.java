import java.util.Scanner;

// Custom exception for insufficient balance (Checked Exception)
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

// BankAccount class with deposit and withdraw methods
class BankAccount {
    private String accountHolder;
    private double balance;

    // Constructor
    public BankAccount(String name, double initialBalance) {
        this.accountHolder = name;
        this.balance = initialBalance;
    }

    // Method to deposit money
    public void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: ₹" + amount);
    }

    // Method to withdraw money
    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException("Not enough balance. Current balance: ₹" + balance);
        }
        balance -= amount;
        System.out.println("Withdrawn: ₹" + amount);
    }

    // Method to display balance
    public void showBalance() {
        System.out.println("Current balance: ₹" + balance);
    }
}

// Main class to run the program
public class BankingSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BankAccount account = new BankAccount("Vikash", 5000.0);

        while (true) {
            System.out.println("\n--- Bank Menu ---");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Show Balance");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            try {
                int choice = Integer.parseInt(scanner.nextLine());

                switch (choice) {
                    case 1:
                        System.out.print("Enter amount to deposit: ");
                        double depositAmount = Double.parseDouble(scanner.nextLine());
                        account.deposit(depositAmount);
                        break;

                    case 2:
                        System.out.print("Enter amount to withdraw: ");
                        double withdrawAmount = Double.parseDouble(scanner.nextLine());
                        account.withdraw(withdrawAmount);
                        break;

                    case 3:
                        account.showBalance();
                        break;

                    case 4:
                        System.out.println("Exiting the program. Thank you!");
                        return;

                    default:
                        System.out.println("Invalid option. Please enter a number from 1 to 4.");
                }

            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter numbers only.");
            } catch (InsufficientFundsException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
