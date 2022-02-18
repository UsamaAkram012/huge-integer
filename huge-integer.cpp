/*
            Name:			Usama Akram
            Roll Number:	bitf19m514
            Task 1 (Home Work Number 2)
            Function:       HugeInteger
*/
#include<iostream>
#include<string.h>
#include<iomanip>
#define SIZE 40
using namespace std;

class HugeInteger {
    char* arr;
    int currentSize;
public:
    HugeInteger() {
        currentSize = 0;
        arr = new char[SIZE];
        for (int i = 0; i < SIZE; i++)
            arr[i] = '0';
    }

    HugeInteger(const HugeInteger& n) {
        arr = new char[SIZE];
        currentSize = n.currentSize;
        for (int i = 0; i < SIZE; i++)
            this->arr[i] = n.arr[i];
    }

    ~HugeInteger() {
        if (arr != NULL) {
            delete[] arr;
            arr = nullptr;
        }
    }

    char getValue(int index) {
        return arr[index];
    }

    // ---------------------------------------------

    string convertToString(char* a) {
        int i;
        string s = "";
        for (i = 0; i < SIZE; i++) {
            s = s + a[i];
        }
        return s;
    }

    // ---------------------------------------------

    string findSum(string str1, string str2) {
        if (str1.length() > str2.length())
            swap(str1, str2);
        string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;
        int carry = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            int sum = ((str1[i] - '0') +
                (str2[i + diff] - '0') +
                carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            str.push_back(carry + '0');
        reverse(str.begin(), str.end());
        return str;
        string ans = "";
        int sz;
        for (sz = SIZE - 1; str[sz] != '0'; sz--);
        int index = sz;
        for (int i = SIZE - 1, j = index + 1; j < SIZE; i--, j++) {
            ans += str[j];
        }
        return ans;
    }

    // ---------------------------------------------

    bool isSmaller(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;
        for (int i = 0; i < n1; i++) {
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;
        }
        return false;
    }

    // ---------------------------------------------

    string findDiff(string str1, string str2) {
        if (isSmaller(str1, str2)) {
            cout << ">>>Seocnd Number is smaller than first therefore numbers are being swap and result is  ";
            swap(str1, str2);
        }
        string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;
        int carry = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }
        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1[i] == '0' && carry) {
                str.push_back('9');
                continue;
            }
            int sub = ((str1[i] - '0') - carry);
            if (i > 0 || sub > 0)
                str.push_back(sub + '0');
            carry = 0;
        }
        reverse(str.begin(), str.end());
        return str;
        string ans = "";
        int sz;
        for (sz = SIZE - 1; str[sz] != '0'; sz--);
        int index = sz;
        for (int i = SIZE - 1, j = index + 1; j < SIZE; i--, j++) {
            ans += str[j];
        }
        return ans;
    }

    // ---------------------------------------------

    HugeInteger operator + (const HugeInteger& n2) {
        HugeInteger n;
        string sum, one, two;
        int index;
        one = convertToString(arr);
        two = convertToString(n2.arr);
        sum = findSum(one, two);

        string ans = "";
        int sz;
        for (sz = 0; sum[sz] == '0'; sz++);
        index = sz;
        for (int j = index; j < SIZE; j++) {
            ans += sum[j];
        }

        n.currentSize = ans.size();
        index = SIZE - n.currentSize;
        for (int j = 0; j < n.currentSize; j++) {
            n.arr[index++] = ans[j];
        }
        return n;
    }

    // ---------------------------------------------

    HugeInteger operator - (const HugeInteger& n2) {
        HugeInteger n;
        string diff, one, two;
        int index;
        one = convertToString(arr);
        two = convertToString(n2.arr);
        diff = findDiff(one, two);
        string ans = "";
        int sz;
        for (sz = 0; diff[sz] == '0'; sz++);
        index = sz;
        for (int j = index; j < SIZE; j++) {
            ans += diff[j];
        }
        n.currentSize = ans.size();
        index = SIZE - n.currentSize;
        for (int j = 0; j < n.currentSize; j++) {
            n.arr[index++] = ans[j];
        }
        return n;
    }

    // ---------------------------------------------

    void operator = (const HugeInteger& n2) {
        this->~HugeInteger();
        arr = new char[SIZE];
        currentSize = n2.currentSize;
        for (int i = 0; i < SIZE; i++)
            this->arr[i] = n2.arr[i];
    }

    // ---------------------------------------------

    bool operator == (const HugeInteger& n2) {
        if (currentSize != n2.currentSize) return false;
        for (int i = 0; i < SIZE; i++)
            if (arr[i] != n2.arr[i])
                return false;
        return true;
    }

    // ---------------------------------------------

    bool operator != (const HugeInteger& n2) {
        return !(*this == n2);
    }

    // ---------------------------------------------

    bool operator > (const HugeInteger& n2) {
        if (currentSize < n2.currentSize) return false;
        return !(*this == n2);
        for (int i = 0; i < SIZE; i++)
            if (arr[i] < n2.arr[i])
                return false;
            else
                continue;
        return true;
    }

    // ---------------------------------------------

    bool operator < (const HugeInteger& n2) {
        return !(*this == n2 or *this > n2);
    }

    // ---------------------------------------------

    bool operator <= (const HugeInteger& n2) {
        return !(*this > n2);
    }

    // ---------------------------------------------

    bool operator >= (const HugeInteger& n2) {
        return !(*this < n2);
    }

    // ---------------------------------------------

    char& operator [] (const int index) {
        if (index >= SIZE) {
            cout << "Segmentation Fault.\n";
            exit(0);
        }
        int start;
        start = SIZE - this->currentSize;
        return arr[start+index];
    }

    // ---------------------------------------------

    HugeInteger operator ()(int a,int b) {
        HugeInteger ans;
        int start;
        start = SIZE - this->currentSize;
        for (int i = a + start; i <= b + start; i++) {
            ans.arr[i] = this->arr[i];
        }
        print(a, b);
        return ans;
    }

    // ---------------------------------------------

    void print(int a,int b) {
        int st;
        st = SIZE - this->currentSize;
        cout << "Sub_array is ";
        for (int i = a + st; i <= b + st; i++) {
            cout << this->arr[i];
        }
        cout << "\n";
    }
    //Friends prototype
    friend istream& operator >> (istream&, HugeInteger&);
    friend ostream& operator<<(ostream&, HugeInteger&);
};
ostream& operator<<(ostream& output, HugeInteger& n) {
    if (n.currentSize == 0) output << "0";
    else {
        int index;
        index = SIZE - n.currentSize;
        for (int i = index; i < SIZE; i++)
            output << n.arr[i];
    }
    output << '\n';
    return output;
}

// ---------------------------------------------

istream& operator >> (istream& input, HugeInteger& n) {
    string temp; int index, sz;
    input >> temp;
    n.currentSize = temp.size();
    index = SIZE - n.currentSize;
    for (int i = SIZE - 1, j = 0; j < n.currentSize; i--, j++) {
        n.arr[index++] = temp[j];
    }
    return input;
}

// -----------------Main Menu---------------------------

void menu() {
    cout << setw(70) << "=============================" << endl;
    cout << setw(60) << "Main Menu" << endl;
    cout << setw(70) << "=============================" << endl;
    int choice_num[13] = { 01,02,03,04,05,06,7,8,9,10,11,12,13};
    string choice_name[13] = { "Input Numbers","Display Numbers","Sum","Difference","Is equal","Is Not equal","Find Less",
        "Find greater","Find less or equal","Find greater or equal","Get or Set Array","Find Sub-Array","Quit" };
    for (int i = 0; i < 13; i++) {
        cout << setw(45) << choice_num[i] << "  " << choice_name[i] << endl;
    }
}

int main() {
    HugeInteger obj1, obj2,temp;
    int index, val, n1, n2, choice, want, array_choice;
    menu();

    while (1) {
        cout << "Enter your choice: ";
        xyz:
        cin >> choice;
        switch (choice) {
        case 1:
            cout << setw(15) << "1st array\n";
            cout << "Enter elements: ";
            cin >> obj1;
            cout << setw(15) << "2nd array\n";
            cout << "Enter elements: ";
            cin >> obj2;
            system("Pause");
            system("CLS");
            menu();
            break;
        case 2:
            cout << setw(10) << "1st array is  ";
            cout << obj1;
            cout << setw(10) << "2nd array is  ";
            cout << obj2;
            system("Pause");
            system("CLS");
            menu();
            break;
        case 3:
            cout << "Sum of array is ";
            temp = obj1 + obj2;
            cout << temp;
            system("Pause");
            system("CLS");
            menu();
            break;
        case 4:
            cout << "Difference of array is ";
            temp = obj1 - obj2;
            cout << temp;
            system("Pause");
            system("CLS");
            menu();
            break;
        case 5:
            if (obj1 == obj2)  cout << "Numbers are equal.\n";
            else cout << "Numbers are not equal.\n";
            system("Pause");
            system("CLS");
            menu();
            break;
        case 6:
            if (obj1 != obj2)  cout << "Numbers are not equal.\n";
            system("Pause");
            system("CLS");
            menu();
            break;
        case 7:
            if (obj1 < obj2)  cout << "First number is less than second number.\n";
            else cout << "Second number is less than first number.\n";
            system("Pause");
            system("CLS");
            menu();
            break;
        case 8:
            if (obj1 > obj2)  cout << "First number is greater than second number.\n";
            else cout << "Second number is greater than first number.\n";
            system("Pause");
            system("CLS");
            menu();
            break;
        case 9:
            if (obj1 <= obj2)  cout << "First number is less than or equal to second number.\n";
            else cout << "First number is not less than or equal to second number.\n";
            system("Pause");
            system("CLS");
            menu();
            break;
        case 10:
            if (obj1 >= obj2)  cout << "First number is greater than or equal to second number.\n";
            else cout << "First number is not greater than or equal to second number.\n";
            system("Pause");
            system("CLS");
            menu();
            break;
        case 11:
            cout << "You want to continue with array 1 Or 2: ";
            cin >> array_choice;
            if (array_choice == 1) {
                cout << "1. Set Value\n2. Get value\nEnter your choice: ";
                cin >> want;
                if (want == 1) {
                    cout << "Enter Index of array: ";
                    cin >> index;
                    cout << "Enter value you want to update:";
                    cin >> val;
                    obj1[index] = val+'0';
                    cout << "\n";
                }
                else {
                    cout << "Enter Index of array you want to get: ";
                    cin >> index;
                    cout << "Value is " << obj1[index];
                    cout << "\n";
                }
            }
            else if (array_choice == 2) {
                cout << "1. Set Value\n2. Get value\nEnter your choice: ";
                cin >> want;
                if (want == 1) {
                    cout << "Enter Index of array: ";
                    cin >> index;
                    cout << "Enter value you want to update:";
                    cin >> val;
                    obj2[index] = val+'0';
                    cout << "\n";
                }
                else {
                    cout << "Enter Index of array you want to get: ";
                    cin >> index;
                    cout << "Value is " << obj2[index];
                    cout << "\n";
                }
            }
            system("Pause");
            system("CLS");
            menu();
            break;
        case 12:
            cout << "You want to continue with array 1 or 2:  ";
            cin >> array_choice;
            if (array_choice == 1) {
                cout << "Enter Starting Index: ";
                cin >> n1;
                cout << "Enter Last Index: ";
                cin >> n2;
                temp=obj1(n1, n2);
            }
            else if (array_choice == 2) {
                cout << "Enter Starting Index: ";
                cin >> n1;
                cout << "Enter Last Index: ";
                cin >> n2;
                temp=obj2(n1, n2);
            }
            system("Pause");
            system("CLS");
            menu();
            break;
        case 13:
            return 0;
        default:
            cout << "Wrong choice....Enter valid choice: ";
            goto xyz;
        }
    }
    return 0;
}