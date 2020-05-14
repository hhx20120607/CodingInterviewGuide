#include<bits/stdc++.h>
using namespace std;
string num1To9(int num) {
    if (num < 1 || num > 9)
        return "";
    string names[9] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
    return names[num - 1];
}
string num1To99(int num, bool hasBai) {
    if (num < 1 || num > 99)
        return "";
    if (num < 10)
        return num1To9(num);
    int shi = num / 10;
    if (shi == 1 && (!hasBai))
        return "十" + num1To9(num % 10);
    else
        return num1To9(shi) + "十" + num1To9(num % 10);
}

string num1To999(int num) {
    if (num < 1 || num > 999) {
        return "";
    }
    if (num < 100) {
        return num1To99(num, false);
    }
    string res = num1To9(num / 100) + "百";
    int rest = num % 100;
    if (rest == 0) {
        return res;
    } else if (rest >= 10) {
        res += num1To99(rest, true);
    } else {
        res += "零" + num1To9(rest);
    }
    return res;
}

string num1To9999(int num) {
    if (num < 1 || num > 9999) {
        return "";
    }
    if (num < 1000) {
        return num1To999(num);
    }
    string res = num1To9(num / 1000) + "千";
    int rest = num % 1000;
    if (rest == 0) {
        return res;
    } else if (rest >= 100) {
        res += num1To999(rest);
    } else {
        res += "零" + num1To99(rest, false);
    }
    return res;
}

string num1To99999999(int num) {
    if (num < 1 || num > 99999999) {
        return "";
    }
    int wan = num / 10000;
    int rest = num % 10000;
    if (wan == 0) {
        return num1To9999(rest);
    }
    string res = num1To9999(wan) + "万";
    if (rest == 0) {
        return res;
    } else {
        if (rest < 1000) {
            return res + "零" + num1To999(rest);
        } else {
            return res + num1To9999(rest);
        }
    }
}
string getNumChiExp(int num) {
    if (num == 0) {
        return "零";
    }
    string res = num < 0 ? "负" : "";
    int yi = abs(num / 100000000);
    int rest = abs((num % 100000000));
    if (yi == 0) {
        return res + num1To99999999(rest);
    }
    res += num1To9999(yi) + "亿";
    if (rest == 0) {
        return res;
    } else {
        if (rest < 10000000) {
            return res + "零" + num1To99999999(rest);
        } else {
            return res + num1To99999999(rest);
        }
    }
}
string num1To19(int num) {
    if (num < 1 || num > 19) {
        return "";
    }
    string names[19] = { "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
                         "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
                         "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Sixteen ",
                         "Eighteen ", "Nineteen " };
    return names[num - 1];
}

string num1To99(int num) {
    if (num < 1 || num > 99) {
        return "";
    }
    if (num < 20) {
        return num1To19(num);
    }
    int high = num / 10;
    string tyNames[9] = { "Twenty ", "Thirty ", "Forty ", "Fifty ",
                          "Sixty ", "Seventy ", "Eighty ", "Ninety " };
    return tyNames[high - 2] + num1To19(num % 10);
}

string num1ToE999(int num) {
    if (num < 1 || num > 999) {
        return "";
    }
    if (num < 100) {
        return num1To99(num);
    }
    int high = num / 100;
    return num1To19(high) + "Hundred " + num1To99(num % 100);
}
//获得英文的表达式
string getNumEngExp(int num) {
    if (num == 0) {
        return "Zero";
    }
    string res = "";
    if (num < 0) {
        res = "Negative, ";
    }
    if (num == INT_MIN) {
        res += "Two Billion, ";
        num %= -2000000000;
    }
    num = abs(num);
    int high = 1000000000;
    int highIndex = 0;
    string names[4] = { "Billion", "Million", "Thousand", "" };
    while (num != 0) {
        int cur = num / high;
        num %= high;
        if (cur != 0) {
            res += num1ToE999(cur);
            res += names[highIndex] + (num == 0 ? " " : ", ");
        }
        high /= 1000;
        highIndex++;
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    cout<<getNumEngExp(t)<<endl;
    cout<<getNumChiExp(t)<<endl;
    return 0;
}