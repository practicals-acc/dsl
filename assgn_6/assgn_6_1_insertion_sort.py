def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def main():
    n = int(input("Enter the number of students: "))
    percentages = []

    print("Enter the percentages of students:")
    for i in range(n):
        percentage = float(input(f"Percentage of student {i + 1}: "))
        percentages.append(percentage)

    insertion_sort(percentages)

    print("\nPercentages in ascending order (Insertion Sort):")
    print(" ".join(f"{p:.2f}" for p in percentages))

    print("\nTop five scores:")
    print(" ".join(f"{p:.2f}" for p in percentages[-1:-6:-1]))

if __name__ == "__main__":
    main()
