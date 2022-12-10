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



bool doesDatasetHave(string query)
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
                return true;

        }
    }

    return false;
}



int main()
{

    // getting the input
    getline(cin, baseString);
    cin >> numberOfQueries >> queryLength;
    baseStringLength =  (int)baseString.size();

    for(int i = 0; i <= numberOfQueries; i++){
        getline(cin, query);
        queries.push_back(query);
    }

    // generate hashes for the dataset
    hashFunction(baseString);

    // look for a query in the dataset
    for(int i=1; i<=numberOfQueries; i++){
        query = queries[i];
        if(doesDatasetHave(query))
            cout << "The sequence: '" << query  << "' is present in the dataset ! "<< "\n";
        else
            cout << "The sequence: '" << query  << "' not found! "<< "\n";
    }
}
