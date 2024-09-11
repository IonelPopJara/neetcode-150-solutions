"""
Problem description:

Given two strings, write a method to decide if one is a permutation of the other.

My idea:

The easiest way I can think of doing this is by creating a hashmap that stores the
count for each character in the first string. Then, when checking a character in the
second string, we can subtract 1 from the respective counter. However, if the counter
is already 0 we can't subtract anymore which means it's not a permutation.
"""

"""
This first solution is not pretty, however its runtime is not that bad.
If we assume that n, and m are the length of the strings.
The the complexity of this algorithm is O(n + m).
If n == m, then it is O(n), and so it's its space complexity.
"""
def solution(str_1, str_2):

    #-----O(n + m)-----
    # If the strings are empty or are equal,
    # they are permutations
    if not str_1 and not str_2:
        return True
    elif str_1 == str_2:
        return True
    # However, if the strings have different lengths,
    # they can't be permutations of each other
    elif len(str_1) != len(str_2):
        return False
    
    # Here n == m
    
    #-----O(1)-----
    counters = {}

    #-----O(n)-----
    # Count the characters in the str_1
    for char in str_1:
        if char not in counters:
            counters[char] = 1
        else:
            counters[char] += 1
    
    #-----O(n)-----
    # Check if the characters of str_2
    # match the ones in str_1
    for char in str_2:
        if char not in counters:
            return False
        elif counters[char] == 0:
            return False
        else:
            counters[char] -= 1;

    return True
        
assert solution("abc", "bca") == True, "Result should be true"
print("Test 1 passed :)")

assert solution("", "") == True, "Result should be true"
print("Test 2 passed :)")

assert solution("abc", "bcad") == False, "Result should be false"
print("Test 3 passed :)")

assert solution("abc", "abc") == True, "Result should be true"
print("Test 4 passed :)")

assert solution("abcdefg", "qwerty") == False, "Result should be false"
print("Test 5 passed :)")

assert solution("abc", "") == False, "Result should be false"
print("Test 6 passed :)")

assert solution("abc", "abb") == False, "Result should be false"
print("Test 7 passed :)")

print("All tests passed!")
