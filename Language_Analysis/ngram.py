from collections import Counter

def ngram_counter(input_string: str,n_gram: int)->Counter:
    window = []
    counter = Counter()
    words = input_string.split()
    for word in words:
        window.append(word)
        if(len(window) >= n_gram):
            counter[tuple(window)] += 1
            window.pop(0)
    return counter

def ngram_successor_map(sentence:str, n_gram:int)->dict:
    window = []
    map = {}
    words = input_string.split()
    for word in words:
        window.append(word)
        if(len(window) >= n_gram):
            kry = tuple(window[:-1])
            if key not in map:
                dict[key] = window[-1]
            else:
                dict[key].append(window[-1])
            window.pop(0)
    return map


