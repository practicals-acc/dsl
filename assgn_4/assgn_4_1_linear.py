def input_student_details():
    n = int(input("Enter the number of students: "))
    print("Enter the roll numbers of students who attended the training program:")
    roll_numbers = [int(input(f"Roll number {i + 1}: ")) for i in range(n)]
    return roll_numbers

roll_numbers = input_student_details()

key = int(input("Enter the roll number to search using Linear Search: "))

found = False
for i in range(len(roll_numbers)):
    if roll_numbers[i] == key:
        print(f"Roll number {key} found at position {i + 1} using Linear Search.")
        found = True
        break

if not found:
    print(f"Roll number {key} not found.")
