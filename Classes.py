class Account:

    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if amount < self.balance:
            self.balance -= amount
            return (True, amount)
        else:
            balance = self.balance
            self.balance = 0
            return (False, balance)

    def __str__(self):
        return f'{self.owner}\'s account has ${self.balance} in it'


acct1 = Account('Ryan')
acct1.deposit(100)
print(acct1)
acct1.deposit(50)
print(acct1)
acct1.withdraw(75)
print(acct1)
print(acct1.withdraw(50))
print(acct1)
print(acct1.withdraw(60))
print(acct1)
