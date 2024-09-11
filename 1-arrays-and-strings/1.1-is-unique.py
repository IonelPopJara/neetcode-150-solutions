"""
Problem description:

Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?

My idea:

To check weather a string has unique characters, the easiest way we can do is
to have some sort of dictionary/hash table that maps each letter to a counter.
If we find a letter that has already been counted before, we return false,
otherwise we return true.

This idea is showcased in solution_1()

However, the extra point is that we can't use any additional data structures.
To achieve this we can make use of bitwise operations.

While this can be done in python, I decided to do the bitwise implementation in C
since I'm more comfortable working with bits in it.

You can find that implementation alongside my explanation in `1.1-is-unique.c`
"""

def solution_1(input_str):
    # If the input string is empty, is unique
    if not input_str or len(input_str) <= 1:
        return True
    counter = {}
    # Iterate through the input string
    for char in input_str:
        # If the character has already been encountered before
        if char in counter:
            # Return False, a.k.a. not unique
            return False
        # Otherwise, count the character
        counter[char] = 1
    
    # If the loop runs successfully, it is truly unique
    return True

def solution_2(input_str):
    counter = 0
    for char in input_str:
        counter = counter ^ ord(char)
        if (counter == 0):
            return False
    
    return True

#-----TESTS-----#
S = "this should not be unique"
assert solution_1(S) == False, "Result should be False"
print("Test 1 passed :)")

S = "unique"
assert solution_1(S) == False, "Result should be True"
print("Test 2 passed :)")

S = "aaaaa"
assert solution_1(S) == False, "aaaaa is not unique"
print("Test 3 passed :)")

S = ""
assert solution_1(S) == True, "an empty string or no string should be unique"
print("Test 4 passed :)")

print("All tests passed!")
