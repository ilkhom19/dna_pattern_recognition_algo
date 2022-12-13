import time

def main():
    base_string = input()
    number_of_queries , query_length = list(map(int, input().split()))
    base_string_length = len(base_string)

    queries = [input() for i in range(number_of_queries)]


    for i in range (number_of_queries):
        query = queries[i]
        flag = False
        for j in range(base_string_length-query_length-1):
            if(base_string[j:j+query_length] == query):
                print(f"The sequence: {query} found at the position: {base_string.find(query) + 1}")
                flag = True

        if(not flag):
            print(f"The sequence: {query} not found !")


if __name__ == "__main__":
    start_time = time.time()
    main()
    print( "The program execution time in ms: " + str(int((time.time() - start_time) * 1000)))
