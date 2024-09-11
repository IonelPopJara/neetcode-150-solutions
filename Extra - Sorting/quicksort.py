def quicksortBad(inputArray, left, right):
    if left >= right:
        return

    pivot = left + right // 2

    i = left
    j = right - 1

    while i < j:
        while inputArray[i] < inputArray[pivot]:
            i += 1
        while inputArray[j] > inputArray[pivot]:
            j -= 1

        if i < j:
            # Swap
            tmp = inputArray[i]
            inputArray[i] = inputArray[j]
            inputArray[j] = tmp

    # Swap with pivot
    tmp = inputArray[pivot]
    inputArray[i] = inputArray[pivot]
    inputArray[pivot] = inputArray[i]

    quicksort(inputArray, left, pivot)  # Call quicksort left
    quicksort(inputArray, pivot + 1, right)  # Call quicksort right

    return inputArray


def partition(inputArray, left, right):
    i = left
    j = right - 1

    pivotIdx = right
    pivot = inputArray[pivotIdx]

    while i < j:
        while i < right and inputArray[i] < pivot:
            i += 1
        while j > left and inputArray[j] >= pivot:
            j -= 1

        if i < j:
            # Swap
            inputArray[i], inputArray[j] = inputArray[j], inputArray[i]

    if inputArray[i] > pivot:
        inputArray[i], inputArray[pivotIdx] = inputArray[pivotIdx], inputArray[i]

    return i

def partitionMiddle(inputArray, left, right):
    i = left
    j = right - 1

    pivotIdx = left + right // 2
    pivot = inputArray[pivotIdx]
    
    # Swap the pivot with the last element
    inputArray[pivotIdx], inputArray[right - 1] = inputArray[right - 1], inputArray[pivotIdx]

    while i < j:
        while i < right and inputArray[i] < pivot:
            i += 1
        while j > left and inputArray[j] >= pivot:
            j -= 1

        if i < j:
            # Swap
            inputArray[i], inputArray[j] = inputArray[j], inputArray[i]

    if inputArray[i] > pivot:
        # Swap the pivot back
        inputArray[i], inputArray[right - 1] = inputArray[right - 1], inputArray[i]

    return i


def quicksort(inputArray, left, right):
    if left >= right:
        return
    partition_pos = partitionMiddle(inputArray, left, right)
    quicksort(inputArray, left, partition_pos - 1)
    quicksort(inputArray, partition_pos + 1, right)

    return inputArray


arr = [3, 2, 12, 5, 15, 8]
res = quicksort(arr, 0, len(arr))
print(res)

arr = [2, 1, 1, 1, 1, 1]
res = quicksort(arr, 0, len(arr) - 1)

print(res)

"""
GENERAL ALGORITHM

[3, 2, 12, 5, 15, 8] -> Choose 5 as a pivot
[3, 2, 12] 5 [15, 8] -> Rearrange
[3, 2] 5 [15, 8, 12] -> Rearrange
[3, 2] 5 [15, 8, 12] -> Call quicksort left
    [3, 2] -> Choose 2 as a pivot
    2 [3] -> Rearrange
    2 [3] -> Call quicksort left
        [NONE] -> 0 element, return
    [2] [3] -> call quicksort right
        [3] -> 1 element, return
[2, 3] 5 [15, 8, 12] -> Call quicksort right
    [15, 8, 12] -> Choose 18 as a pivot
    [15] 8 [12] -> Rearrange
    8 [12, 15] -> Call quicksort left
        [NONE] -> 0 element, return
    8 [12, 15] -> Call quicksort right
        [12, 15] -> Choose 15 as a pivot
        [12] 15 -> Rearrange
        [12] 15 -> Call quicksort left
            [12] -> 1 element, return
        [12] 15 -> Call quicksort right
            [NONE] -> 0 element, return
    8 [12, 15]
[2, 3] 5 [8, 12, 15]
[2, 3, 5, 8, 12, 15]
"""

"""
REARRANGE
[3, 2, 12] 5 [15, 8]
left              right
"""
