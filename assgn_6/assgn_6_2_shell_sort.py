def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def main():
    n = int(input("Enter the number of students: "))
    percentages = []

    print("Enter the percentages of students:")
    for i in range(n):
        percentage = float(input(f"Percentage of student {i + 1}: "))
        percentages.append(percentage)

    shell_sort(percentages)

    print("\nPercentages in ascending order (Shell Sort):")
    print(" ".join(f"{p:.2f}" for p in percentages))

    print("\nTop five scores:")
    print(" ".join(f"{p:.2f}" for p in percentages[-1:-6:-1]))

if __name__ == "__main__":
    main()
