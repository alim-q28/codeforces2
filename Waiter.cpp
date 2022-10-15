#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */
vector<int> getPrime (){
    vector<int> prime;
    int lower = 2;
    int upper = 10000;
    for (int i=lower; i<upper; i++){
        bool isPrime = 0;
        for(int j=lower; j<=sqrt(i); j++){
            if (i%j == 0)
                isPrime = 1;
        }
        if (isPrime == 0)
            prime.push_back(i);
    }
    return prime;
}
vector<int> waiter(vector<int> number, int q) {
    vector<int> result, strA, strB;   
    int num;
    vector<int> prime = getPrime(); // assign all the prime number to array
    
    for (int i=0; i<q; i++){
        int size = number.size();
        
        for (int j=0; j<size; j++){
            num = number.back();
            
            // if the number is divisible by the prime number, store it to stack strB
            // if not, store it to stack strB
            if( num % prime[i] == 0 ){
                strB.push_back(num);
                number.pop_back();
            }
            else{
                strA.push_back(num);    
                number.pop_back();
            }
        }
        number = strA;  // do the iteration with number in the strA
        strA.clear();
        
        // move the strB stack value to the result stack
        while (!strB.empty()){
            result.push_back(strB.back());
            strB.pop_back();
        }
    }
    
    // if the strA stack not empty until all iteration, move it to result stack
    while (!number.empty()){
        result.push_back(number.back());
        number.pop_back();
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
