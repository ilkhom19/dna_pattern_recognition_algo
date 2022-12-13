import time
# constant
decimal = 256
prime_number = 1117
hashes, queries = [],[]


def main():


    # inputs
    base_string = input()
    number_of_queries , query_length = list(map(int, input().split()))
    base_string_length = len(base_string)

    queries = [input() for i in range(number_of_queries)]


    hash_function(base_string,query_length, base_string_length)
    # print(hashes[3])

    for i in range (number_of_queries):
        query = queries[i]
        index = does_dataset_have(query,query_length,base_string)
        if (index != -1):
            print(f"The sequence: {query} found at the position: {index + 1}")

        else:
            print(f"The sequence: {query} not found !")


def hash_function(text: str,query_length, base_string_length) -> None:
    total_hash = 0
    hash1 = 1
    for i in range(query_length - 1):
        hash1 = (hash1 * decimal) % prime_number

    for i in range(query_length):
        total_hash = (decimal * total_hash + ord(text[i])) % prime_number

    hashes.append(total_hash)

    for i in range((base_string_length - query_length)):
        total_hash = (decimal * (total_hash - ord(text[i]) * hash1) + ord(text[i + query_length])) % prime_number

        if (total_hash < 0):
            total_hash += prime_number
        hashes.append(total_hash)


def does_dataset_have(query: str, query_length,base_string) -> int:
    local_hash = 0
    for i in range(query_length):
        local_hash = (decimal * local_hash + ord(query[i])) % prime_number

    for i in range(len(hashes)):
        if (local_hash == hashes[i]):
            j = 0
            while j < query_length:
                if (base_string[i + j] != query[j]):
                    break
                j+=1
            if (j == query_length):
                return i
    return -1


if __name__ == "__main__":
    start_time = time.time()
    main()
    print( "The program execution time in ms: " + str(int((time.time() - start_time) * 1000)))
