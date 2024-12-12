def word_count(s):
    words = s.split()
    count = {}
    
    for word in words:
        count[word] = count.get(word, 0) + 1

    return count

# Example usage
string = "hello world hello everyone"
result = word_count(string)
print("Word occurrences:", result)
