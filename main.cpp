#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ve vector
#define ll long long

using namespace std;


ll GetChar(ve<string>& unknown, ve<ve<string>>& nums){
    for(int k = 0; k<20; k++){
        ll works = 1;
        for(int i = 0; (i<unknown.size())and works; i++){
            for(int j = 0; (j<unknown[0].size())and works; j++){
                works &= (unknown[i][j] == nums[k][i][j]);
            }
        }
        if(works){
            return k;
        }
    }
}

void OutputNum(ll x, ve<ve<string>>& nums){
    for(int i = 0; i<nums[x].size(); i++){
        cout << nums[x][i] << '\n';
    }
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int l;
    int h;
    cin >> l >> h; cin.ignore();
    ve<ve<string>> nums(20, ve<string>());
    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        for(int j = 0; j<20*l; j+=l){
            nums[j/l].push_back(numeral.substr(j, l));
        }
    }



    int s1;
    cin >> s1; cin.ignore();
    ve<string> currentChar;
    ll num1 = 0;

    for (int i = 0; i < s1; i++) {
        string num_1line;
        cin >> num_1line; cin.ignore();
        currentChar.push_back(num_1line);
        if(currentChar.size() == l){
            num1*=20;
            num1+=GetChar(currentChar, nums);
            currentChar.clear();
        }
    }



    int s2;
    cin >> s2; cin.ignore();
    ll num2 = 0;
    currentChar.clear();

    for (int i = 0; i < s2; i++) {
        string num_2line;
        cin >> num_2line; cin.ignore();
        currentChar.push_back(num_2line);
        if(currentChar.size() == l){
            num2*=20;
            num2+=GetChar(currentChar, nums);
            currentChar.clear();
        }
    }
    string operation;
    cin >> operation; cin.ignore();

    ll finalNum = 0;
    switch (operation[0]){
        case '+':
            finalNum = num1+num2;
            break;
        case '-':
            finalNum = num1-num2;
            break;
        case '*':
            finalNum = num1*num2;
            break;
        case '/':
            finalNum = num1/num2;
            break;
    }

    ve<ll> digits;
    while (finalNum > 0){
        digits.push_back(finalNum%20);
        finalNum/=20;
    }
    for(int i = digits.size()-1; i>=0; i--){
        OutputNum(digits[i], nums);
    }



    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "result" << endl;
}