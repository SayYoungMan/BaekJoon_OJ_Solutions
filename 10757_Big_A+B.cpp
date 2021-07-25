#include <iostream>
#include <string>
#include <vector>

std::vector<int> convertToArray(std::string str) {
    std::vector <int> arr(str.size());
    int x = str.size(), i = 0;

    while (i != x) {
        arr[i] = str[x-i-1] - '0';
        i++;
    }

    return arr;
}

int main() {
    std::string a, b;
    int tmp;

    std::cin >> a >> b;

    std::vector<int> Aarr = convertToArray(a);
    std::vector<int> Barr = convertToArray(b);
    std::vector<int> ans;

    int smaller = (Aarr.size() < Barr.size()) ? Aarr.size() : Barr.size();
    bool carry = false;

    for (int i=0; i<smaller; i++) {
        if (carry) {
            tmp = Aarr[i] + Barr[i] + 1;
            carry = false;
        } else {
            tmp = Aarr[i] + Barr[i];
        }
        
        if (tmp >= 10) {
            ans.push_back(tmp % 10);
            carry = true;
        } else {
            ans.push_back(tmp);
        }
    }

    if (Aarr.size() > Barr.size()) {
        for (int i=smaller; i < Aarr.size(); i++) {
            if (carry) {
                tmp = Aarr[i] + 1;
                carry = false;
            } else {
                tmp = Aarr[i];
            }
            
            if (tmp >= 10) {
                ans.push_back(tmp % 10);
                carry = true;
            } else {
                ans.push_back(tmp);
            }
        }
    }
    else if (Barr.size() > Aarr.size()) {
        for (int i=smaller; i < Barr.size(); i++) {
            if (carry) {
                tmp = Barr[i] + 1;
                carry = false;
            } else {
                tmp = Barr[i];
            }
            
            if (tmp >= 10) {
                ans.push_back(tmp % 10);
                carry = true;
            } else {
                ans.push_back(tmp);
            }
        }
    }
    
    if (carry) {
        ans.push_back(1);
    }

    for (int i = ans.size()-1; i >= 0; i--) {
        std::cout << ans[i];
    }

    return 0;
}