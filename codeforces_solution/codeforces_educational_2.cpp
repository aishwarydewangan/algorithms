#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{

        long long no_lines;
        cin >> no_lines;
        long long integer_i;
        int flag = 1;
        
        string command;
        string integer;
        string original_line;
        long long for_intensity = 1;
        long long num = 0;
        stack<long long> for_last;
        while (no_lines--)
        {
                string line;
                cin >> line;
                //cin.ignore(INT_MAX);
                // original_line = line;
                command = line.substr(0, 3);
                //cout << command << "command" << endl;
                if (command == "add")
                {
                        num += for_intensity ;
                }
                if (command == "for")
                {
                        // cout << "here" << endl;
                        // cout << original_line << endl;

                        cin >> integer;
                        integer_i = stoi(integer);
                        for_intensity *= integer_i;
                        for_last.push(integer_i);
                }
                if (command == "end")
                {

                        integer_i = for_last.top();
                        for_last.pop();
                        for_intensity /= integer_i;
                }
                if (num > 4294967295)
                {
                        flag = 0;
                        cout << "OVERFLOW!!!" << endl;
                        exit(0);
                }
        }

        if (flag)
        {
                cout << num << endl;
        }
        return 0;
}