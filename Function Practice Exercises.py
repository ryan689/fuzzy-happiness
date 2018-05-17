"""
WARMUP
LESSER OF TWO EVENS: Write a function that returns the lesser of two given numbers if both numbers are even,
but returns the greater if one or both numbers are odd

lesser_of_two_evens(2,4) --> 2
lesser_of_two_evens(2,5) --> 5
"""


def lesser_of_two_evens(a, b):
    if a%2 == 0 and b%2 == 0:
        return min(a, b)
    else:
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


print(paper_doll('Hello'))
print(paper_doll('Mississippi'))

"""
BLACKJACK: Given three integers between 1 and 11, if their sum is less than or equal to 21, return their sum.
If their sum exceeds 21 and there's an eleven, reduce the total sum by 10. 
Finally, if the sum (even after adjustment) exceeds 21, return 'BUST'

blackjack(5,6,7) --> 18
blackjack(9,9,9) --> 'BUST'
blackjack(9,9,11) --> 19
"""
