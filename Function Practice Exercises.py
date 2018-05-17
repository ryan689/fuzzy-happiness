"""
LESSER OF TWO EVENS: Write a function that returns the lesser of two given numbers if both numbers are even, but returns the greater if one or both numbers are odd
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
MAKES TWENTY: Given two integers, return True if the sum of the integers is 20 or if one of the integers is 20. If not, return False
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


print(master_yoda('I am home'))
print(master_yoda('We are ready'))
