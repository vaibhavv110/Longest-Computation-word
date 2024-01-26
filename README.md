# Longest-Computation-word



# Longest_Compounded_Word
# Steps to Execute the given code:
# a. Open the Python file in any Python IDE.
# b. Paste the contents of Input.txt into the script.
# c. Compile and run the Python script.
# d. The required output will be printed in Output.txt.

# Overview of the above code:
# To solve the problem of finding the longest compounded word, the code utilizes dynamic programming (DP).
# First, it sorts the list of words based on their lengths, and if lengths are equal, it sorts them alphabetically.
# Then, starting from the end of the list, it checks if the current word can be formed using smaller words.
# If yes, it stores the word as the longest compound word (s1), and repeats the process to find the second longest compound word.
# Once both the words are found, the process stops, and the output strings are printed.
# n: number of strings
# k: maximum length of the string

# Time complexity:
# Best Case: O(n log n)
# Average Case: O(nk)
# Worst Case: O(n^2)

# Space complexity: O(k)

def compare_length_lexico(a, b):
    if len(a) != len(b):
        return len(a) < len(b)
    else:
        return a < b

def find_compounded_words():
    words_list = []
    seen_words = set()

    # Read input from the file
    with open("input.txt", "r") as file:
        for line in file:
            words = line.split()
            for word in words:
                words_list.append(word)
                seen_words.add(word)

    words_list.sort(key=lambda x: (len(x), x))

    longest_compound_word = ""
    second_longest_compound_word = ""

    dp = [False] * 1001  # Assuming maximum length of word is 1000

    for current_word in reversed(words_list):
        word_length = len(current_word)

        for i in range(word_length):
            temp = ""
            for j in range(i + 1):
                if current_word[j:i + 1] in seen_words:
                    if j == 0 and i != word_length - 1:
                        dp[i] = True
                        break
                    elif j >= 1 and dp[j - 1]:
                        dp[i] = True
                        break

        if dp[word_length - 1]:
            if not longest_compound_word:
                longest_compound_word = current_word
            elif not second_longest_compound_word:
                second_longest_compound_word = current_word
            else:
                break

    # Write output to file
    with open("output.txt", "w") as file:
        file.write("Longest compound word: {}\n".format(longest_compound_word))
        file.write("Second longest compound word: {}\n".format(second_longest_compound_word))

if __name__ == "__main__":
   
