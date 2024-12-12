def add_matrices(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        return None
    return [[mat1[i][j] + mat2[i][j] for j in range(len(mat1[0]))] for i in range(len(mat1))]

def subtract_matrices(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        return None
    return [[mat1[i][j] - mat2[i][j] for j in range(len(mat1[0]))] for i in range(len(mat1))]

def multiply_matrices(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        return None
    return [[sum(mat1[i][k] * mat2[k][j] for k in range(len(mat2))) for j in range(len(mat2[0]))] for i in range(len(mat1))]

def transpose_matrix(matrix):
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

def display_matrix(matrix):
    for row in matrix:
        print(row)

rows1 = int(input("Enter the number of rows for Matrix A: "))
cols1 = int(input("Enter the number of columns for Matrix A: "))
print("Enter the elements of Matrix A row-wise:")
mat1 = [[int(input(f"Element [{i+1}][{j+1}]: ")) for j in range(cols1)] for i in range(rows1)]

rows2 = int(input("Enter the number of rows for Matrix B: "))
cols2 = int(input("Enter the number of columns for Matrix B: "))
print("Enter the elements of Matrix B row-wise:")
mat2 = [[int(input(f"Element [{i+1}][{j+1}]: ")) for j in range(cols2)] for i in range(rows2)]

print("\nMatrix A:")
display_matrix(mat1)
print("\nMatrix B:")
display_matrix(mat2)

while True:
    print("\nSelect the operation to perform:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Transpose of Matrix A")
    print("5. Transpose of Matrix B")
    print("6. Exit")
    choice = int(input("Enter your choice (1-5): "))

    if choice == 1:
        result = add_matrices(mat1, mat2)
        if result:
            print("\nResult of Addition:")
            display_matrix(result)
        else:
            print("Addition not possible due to dimension mismatch.")
    elif choice == 2:
        result = subtract_matrices(mat1, mat2)
        if result:
            print("\nResult of Subtraction:")
            display_matrix(result)
        else:
            print("Subtraction not possible due to dimension mismatch.")
    elif choice == 3:
        result = multiply_matrices(mat1, mat2)
        if result:
            print("\nResult of Multiplication:")
            display_matrix(result)
        else:
            print("Multiplication not possible due to incompatible dimensions.")
    elif choice == 4:
        print("\nTranspose of Matrix A:")
        display_matrix(transpose_matrix(mat1))
    elif choice == 5:
        print("\nTranspose of Matrix B:")
        display_matrix(transpose_matrix(mat2))
    elif choice == 6:
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please select a valid operation.")
