//#include<iostream>
//#include<stack>
//#include<string>
//#include<vector>
//#include <algorithm>
//#include<unordered_map>
//using namespace std;
//
//bool isLeapYear(int y) {
//    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
//}
//bool isP(string& date) {
//    string rd = date;
//    reverse(rd.begin(), rd.end());
//    return date == rd;
//}
//int main() {
//    string date;
//    int k;
//    cin >> date >>k;
//    //string date = d;
//    int count = 0, dif = 0;
//    while (count < k) {
//        int year = stoi(date.substr(0, date.size() - 4));
//        int month = stoi(date.substr(date.size() - 4, 2));
//        int day =stoi(date.substr(date.size()-2, 2));
//        day++;
//        dif++;
//        if (day > 31 || (month == 2 && ((day > 28 && !isLeapYear(year)) || (day > 29 && isLeapYear(year)))) ||
//            ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
//            day = 1;
//            month++;
//            if (month > 12) {
//                month = 1;
//                year++;
//            }
//        }
//        date = to_string(year);
//        if (month < 10) date += "0";
//        date += to_string(month);
//        if (day < 10) date += "0";
//        date +=to_string(day);
//
//        if (isP(date))
//            count++;
//    }
//    cout << date << endl;
//    cout << dif << endl;
//}
//
