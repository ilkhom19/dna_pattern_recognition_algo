import random


def main():
    with open('refactor.out', 'w') as file:
        baseString = ""
        baseStringLength = 200000
        numberOfQueries = 1000
        queryLength = 100
        letters = "ACGT"

        for i in range(baseStringLength):
            baseString += letters[random.randint(0,3)]

        file.write(baseString+'\n')

        file.write(str(numberOfQueries)+ ' ' + str(queryLength))

        for i in range(numberOfQueries):
            tmp = ''
            for j in range(queryLength):
                tmp += letters[random.randint(0,3)]
            file.write('\n'+tmp)

if __name__ == '__main__':
    main()