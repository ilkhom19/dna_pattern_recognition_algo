#include <bits/stdc++.h>
using namespace std;

int numberOfQueries,queryLength,baseStringLength;
int decimal = 256;
int primeNumber = 1117;
string baseString, query;
vector <int> hashes;
vector <string> queries;



void hashFunction(string text)
{
    // generates the hashes of length 'queryLength' from the 'text'
    int i;
    int totalHash = 0;
    int hash = 1;

    for (i = 0; i < queryLength - 1; i++)
        hash = (hash * decimal) % primeNumber;

    for (i = 0; i < queryLength; i++)
        totalHash = (decimal * totalHash + text[i]) % primeNumber;

    hashes.push_back(totalHash);

    for (i = 0; i <= baseStringLength - queryLength; i++) {
        totalHash = (decimal * (totalHash - text[i] * hash) + text[i + queryLength]) % primeNumber;

        if (totalHash < 0)
            totalHash += primeNumber;

        hashes.push_back(totalHash);
    }
}



int doesDatasetHave(string query)
{
    int i, j, localHash = 0;

    // get the hash of the query
    for (i = 0; i < queryLength; i++)
        localHash = (decimal * localHash + query[i]) % primeNumber;


    for(i = 0; i < hashes.size(); i++){
        if( localHash == hashes[i] ){

            // verify the match
            for (j = 0; j < queryLength; j++){
                if ( baseString[i+j] != query[j] )
                    break;
            }
            if (j == queryLength)
                return i;
        }
    }

    return -1;
}



int main()
{

    clock_t start, end;
    start = clock();
    // getting the input
    cin >> baseString;
    cin >> numberOfQueries >> queryLength;
    baseStringLength =  (int)baseString.size();

    for(int i = 0; i < numberOfQueries; i++){
        cin >> query ;
        queries.push_back(query);
    }

    // generate hashes for the dataset
    hashFunction(baseString);

    // look for a query in the dataset
    for(int i=0; i<numberOfQueries; i++){
        query = queries[i];
        int index = doesDatasetHave(query);
        if( index != -1)
            cout << "The sequence: '" << query  << "' found at the position: " << index+1<< "\n";
        else
            cout << "The sequence: '" << query  << "' not found"<< "\n";
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(0);
    cout << " ms " << endl;
}
