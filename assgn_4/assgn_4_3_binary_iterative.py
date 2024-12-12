def input_student_details():
    n = int(input("Enter the number of students: "))
    print("Enter the roll numbers of students who attended the training program:")
    roll_numbers = [int(input(f"Roll number {i + 1}: ")) for i in range(n)]
    return roll_numbers

roll_numbers = input_student_details()
roll_numbers.sort()
print("Roll numbers sorted for binary search:", roll_numbers)

key = int(input("Enter the roll number to search using Iterative Binary Search: "))

low, high = 0, len(roll_numbers) - 1
found = False

while low <= high:
    mid = (low + high) // 2
    if roll_numbers[mid] == key:
        print(f"Roll number {key} found at position {mid + 1} using Iterative Binary Search.")
        found = True
        break
    elif roll_numbers[mid] < key:
        low = mid + 1
    else:
        high = mid - 1

if not found:
    print(f"Roll number {key} not found.")
