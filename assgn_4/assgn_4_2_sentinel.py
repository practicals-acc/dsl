def input_student_details():
    n = int(input("Enter the number of students: "))
    print("Enter the roll numbers of students who attended the training program:")
    roll_numbers = [int(input(f"Roll number {i + 1}: ")) for i in range(n)]
    return roll_numbers

roll_numbers = input_student_details()

key = int(input("Enter the roll number to search using Sentinel Search: "))

last = roll_numbers[-1]
roll_numbers[-1] = key
i = 0
while roll_numbers[i] != key:
    i += 1
roll_numbers[-1] = last

if i < len(roll_numbers) - 1 or roll_numbers[-1] == key:
    print(f"Roll number {key} found at position {i + 1} using Sentinel Search.")
else:
    print(f"Roll number {key} not found.")
