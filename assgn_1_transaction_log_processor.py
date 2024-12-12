def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print("Insufficient balance for withdrawal.")
        return balance

def process_transactions():
    balance = 0
    while True:
        transaction = input("Enter transaction (D for deposit, W for withdrawal, or 'done' to stop): ").strip()
        
        if transaction.lower() == 'done':
            break
        
        transaction_parts = transaction.split()
        if len(transaction_parts) != 2:
            print("Invalid input, try again.")
            continue
        
        action, amount_str = transaction_parts
        try:
            amount = int(amount_str)
        except ValueError:
            print("Invalid amount. Please enter an integer.")
            continue
        
        if action == 'D':
            balance = deposit(balance, amount)
        elif action == 'W':
            balance = withdraw(balance, amount)
        else:
            print("Invalid action. Please use D for deposit or W for withdrawal.")
    
    print("Final balance is:", balance)

process_transactions()
