from math import sqrt
from math import ceil

"""
WARMUP
LESSER OF TWO EVENS: Write a function that returns the lesser of two given numbers if both numbers are even,
but returns the greater if one or both numbers are odd

lesser_of_two_evens(2,4) --> 2
lesser_of_two_evens(2,5) --> 5
"""


def lesser_of_two_evens(a, b):
    if a%2 == 0 and b%2 == 0:
        # both numbers are even
        return min(a, b)
    else:
        # one or both numbers are odd
        return max(a, b)


# print(lesser_of_two_evens(4, 9))
# print(lesser_of_two_evens(7, 91))
# print(lesser_of_two_evens(16, 26))


"""
ANIMAL CRACKERS: Write a function takes a two-word string and returns True if both words begin with same letter

animal_crackers('Levelheaded Llama') --> True
animal_crackers('Crazy Kangaroo') --> False
"""


def animal_crackers(text):
    first_word = text.split()[0]
    second_word = text.split()[1]

    return first_word[0].lower() == second_word[0].lower()


# print(animal_crackers('Levelheaded Llama'))
# print(animal_crackers('Crazy Kangaroo'))
# print(animal_crackers('Six Swans'))


"""
MAKES TWENTY: Given two integers, return True if the sum of the integers is 20 or if one of the integers is 20. 
If not, return False

makes_twenty(20,10) --> True
makes_twenty(12,8) --> True
makes_twenty(2,3) --> False
"""


def makes_twenty(n1, n2):
    return n1+n2 == 20 or n1 == 20 or n2 == 20


# print(makes_twenty(20, 10))
# print(makes_twenty(12, 8))
# print(makes_twenty(2, 3))


"""
LEVEL 1
OLD MACDONALD: Write a function that capitalizes the first and fourth letters of a name

old_macdonald('macdonald') --> MacDonald
"""


def old_macdonald(name):
    return name[:3].capitalize() + name[3:].capitalize()


# print(old_macdonald('macdonald'))
# print(old_macdonald('macarthur'))


"""
MASTER YODA: Given a sentence, return a sentence with the words reversed

master_yoda('I am home') --> 'home am I'
master_yoda('We are ready') --> 'ready are We'
"""


def master_yoda(text):
    reversed_list = text.split()[::-1]
    return ' '.join(reversed_list)


# print(master_yoda('I am home'))
# print(master_yoda('We are ready'))


"""
ALMOST THERE: Given an integer n, return True if n is within 10 of either 100 or 200

almost_there(90) --> True
almost_there(104) --> True
almost_there(150) --> False
almost_there(209) --> True
"""


def almost_there(n):
    distance_from_100 = abs(100 - n)
    distance_from_200 = abs(200 - n)

    return distance_from_100 <= 10 or distance_from_200 <= 10


# print(almost_there(90))
# print(almost_there(104))
# print(almost_there(150))
# print(almost_there(209))

"""
FIND 33:
Given a list of ints, return True if the array contains a 3 next to a 3 somewhere.

has_33([1, 3, 3]) → True
has_33([1, 3, 1, 3]) → False
has_33([3, 1, 3]) → False
"""


def has_33(nums):
    for index, num in enumerate(nums[1:]):
        if num == 3 and nums[index] == 3:
            return True
    return False


# print(has_33([1, 3, 3]))
# print(has_33([1, 3, 1, 3]))
# print(has_33([3, 1, 3]))


"""
PAPER DOLL: Given a string, return a string where for every character in the original there are three characters

paper_doll('Hello') --> 'HHHeeellllllooo'
paper_doll('Mississippi') --> 'MMMiiissssssiiippppppiii'
"""


def paper_doll(text):
    result = ''
    for char in text:
        result += char * 3
    return result


# print(paper_doll('Hello'))
# print(paper_doll('Mississippi'))


"""
BLACKJACK: Given three integers between 1 and 11, if their sum is less than or equal to 21, return their sum.
If their sum exceeds 21 and there's an eleven, reduce the total sum by 10. 
Finally, if the sum (even after adjustment) exceeds 21, return 'BUST'

blackjack(5,6,7) --> 18
blackjack(9,9,9) --> 'BUST'
blackjack(9,9,11) --> 19
"""


def blackjack(a, b, c):
    total = a + b + c
    if total <= 21:
        return total
    if a == 11 or b == 11 or c == 11:
        total -= 10
    if total > 21:
        return 'BUST'
    return total


# print(blackjack(5, 6, 7))
# print(blackjack(9, 9, 9))
# print(blackjack(9, 9, 11))


"""
SUMMER OF '69: Return the sum of the list of numbers, except ignore sections of numbers starting with a 6 
and extending to the next 9 (every 6 will be followed by at least one 9). Return 0 for no numbers.

summer_69([1, 3, 5]) --> 9
summer_69([4, 5, 6, 7, 8, 9]) --> 9
summer_69([2, 1, 6, 9, 11]) --> 14
"""


def summer_69(arr):
    add = True
    total = 0
    for num in arr:
        if num == 6:
            add = False
        if add:
            total += num
        if num == 9:
            add = True
    return total


# print(summer_69([1, 3, 5]))
# print(summer_69([4, 5, 6, 7, 8, 9]))
# print(summer_69([2, 1, 6, 9, 11]))


"""
SPY GAME: Write a function that takes in a list of integers and returns True if it contains 007 in order
 spy_game([1,2,4,0,0,7,5]) --> True
 spy_game([1,0,2,4,0,5,7]) --> True
 spy_game([1,7,2,0,4,5,0]) --> False
"""


def spy_game(nums):
    code = [0, 0, 7]

    for num in nums:
        if num == code[0]:
            code.pop(0)
            if not code:
                return True

    return False


print(spy_game([1, 2, 4, 0, 0, 7, 5]))
print(spy_game([1, 0, 2, 4, 0, 5, 7]))
print(spy_game([1, 7, 2, 0, 4, 5, 0]))

"""
COUNT PRIMES: Write a function that returns the number of prime numbers that exist up to and including a given number
count_primes(100) --> 25
"""


def count_primes(num):
    prime_count = 0
    if num >= 2:
        prime_count = 1
    for a in range(3, num):
        for number in range(2, ceil(sqrt(a)) + 1):
            if a % number == 0:
                break
        else:
            prime_count += 1

    return prime_count

# print(count_primes(100000))
