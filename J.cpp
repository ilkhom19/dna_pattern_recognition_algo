#include <bits/stdc++.h>
using namespace std;

int numberOfQueries,queryLength,baseStringLength;
int decimal = 256;
int primeNumber = 1117;
string baseString, query;
vector <int> hashes;
vector <string> queries;




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

    // look for a query in the dataset
    for(int i=0; i<numberOfQueries; i++){
        query = queries[i];
        bool flag = false;
        for(int j=0; j<baseStringLength-queryLength; j++){
            string tmp = baseString.substr(j,queryLength);
            if(tmp == query){
                cout << "The sequence: '" << query  << "' found at the position: " << j+1 << "\n";
                flag = true;
            }
        }
        if( !flag)
            cout << "The sequence: '" << query  << "' not found"<< "\n";
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken*1000 << setprecision(0);
    cout << " ms " << endl;
}