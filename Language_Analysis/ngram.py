from collections import Counter

def bigram_counter(input_string: str,n_gram: int)->Counter:
    window = []
    counter = Counter()
    words = input_string.split()
    for word in words:
        window.append(word)
        if(len(window) >= n_gram):
            counter[tuple(window)] += 1
            window.pop(0)
    return counter

sentence = "hello world tom"
print(bigram_frequency(sentence,2))
