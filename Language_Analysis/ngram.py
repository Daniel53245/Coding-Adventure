from collections import Counter

punctuation = '.;,-“’”:?—‘!()_'

def ngram_counter(input_string: str,n_gram: int)->Counter:
    window = []
    counter = Counter()
    words = input_string.split()
    for word in words:
        word = word.lower.strip(punctuation)
    for word in words:
        window.append(word)
        if(len(window) >= n_gram):
            counter[tuple(window)] += 1
            window.pop(0)
    return counter

def ngram_successor_map(sentence:str, n_gram:int)->dict:
    window = []
    map = {}
    words = sentence.split()
    for word in words:
        word = word.lower().strip(punctuation)

    for word in words:
        window.append(word)
        if(len(window) >= n_gram + 1):
            key = tuple(window[:n_gram])
            if key not in map:
                map[key] = window[-1]
            else:
                map[key].append(window[-1])
            window.pop(0)
    return map



if __name__ == "__main__":
    sentence = "Nice to meet you Dai !"
    print(ngram_successor_map(sentence,2))
