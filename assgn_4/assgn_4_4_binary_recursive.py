def input_student_details():
    n = int(input("Enter the number of students: "))
    print("Enter the roll numbers of students who attended the training program:")
    roll_numbers = [int(input(f"Roll number {i + 1}: ")) for i in range(n)]
    return roll_numbers

def binary_search_recursive(arr, low, high, key):
    if low > high:
        return -1
    mid = (low + high) // 2
    if arr[mid] == key:
        return mid
    elif arr[mid] < key:
        return binary_search_recursive(arr, mid + 1, high, key)
    else:
        return binary_search_recursive(arr, low, mid - 1, key)

roll_numbers = input_student_details()
roll_numbers.sort()
print("Roll numbers sorted for binary search:", roll_numbers)

key = int(input("Enter the roll number to search using Recursive Binary Search: "))

index = binary_search_recursive(roll_numbers, 0, len(roll_numbers) - 1, key)

if index != -1:
    print(f"Roll number {key} found at position {index + 1} using Recursive Binary Search.")
else:
    print(f"Roll number {key} not found.")
