def longest_words(words):
    if not words:
        return []

    max_len = 0
    longest = []

    for w in words:
        l = len(w)
        if l > max_len:
            max_len = l
            longest = [w]
        elif l == max_len:
            longest.append(w)

    return longest

# Example usage
words = ["apple", "banana", "cherry", "blueberry", "kiwi", "mango", "pineapple"]
result = longest_words(words)
print("Longest words:", result)
