def is_palindrome(s):
    s = s.lower()
    return s == s[::-1]

# Example usage
string = "Racecar"
result = is_palindrome(string)
print(f"Is '{string}' a palindrome?:", result)
