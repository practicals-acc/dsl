def char_freq(s, char):
    freq = 0
    for c in s:
        if c == char:
            freq += 1
    return freq

# Example usage
string = "hello world"
target_char = 'o'
result = char_freq(string, target_char)
print(f"Frequency of '{target_char}':", result)
