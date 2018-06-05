from random import randint


# Create a generator that generates the squares of some number up to n
def gen_squares(n):
    for i in range(n+1):
        yield i*i


# Create a generator that yields 'n' random numbers between a low and high number
def gen_random(low, high, n):
    for _ in range(n):
        yield randint(low, high)


# Use the iter function to convert a string to an iterator
iterator = iter('hello')

