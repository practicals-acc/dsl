def find_substring_index(s, substring):
    return s.find(substring)

# Example usage
string = "hello world"
substring = "lo"
index = find_substring_index(string, substring)
print(f"Index of first appearance of '{substring}':", index)
