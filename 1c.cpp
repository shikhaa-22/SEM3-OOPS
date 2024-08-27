#include <iostream>
#include <string.h>
using namespace std;
struct stud
{
    int marks[6];
    float sgpa;
    char grade[2];
};
void display(struct stud, int n);
void grade(struct stud *s, int n);
void grade(struct stud *s, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (s[i].marks[j] >= 107)
            {
                sum += 10 * 3;
                strcpy(s[i].grade, "O");
            }
            else if (s[i].marks[j] > 99)
            {
                sum += 9.5 * 3;
                strcpy(s[i].grade, "A+");
            }
            else if (s[i].marks[j] > 94)
            {
                sum += 9 * 3;
                strcpy(s[i].grade, "A");
            }
            else if (s[i].marks[j] > 86)
            {
                sum += 8.5 * 3;
                strcpy(s[i].grade, "B+");
            }
            else if (s[i].marks[j] > 82)
            {
                sum += 8 * 3;
                strcpy(s[i].grade, "B");
            }
            else if (s[i].marks[j] > 69)
            {
                sum += 7 * 3;
                strcpy(s[i].grade, "C");
            }
            else if (s[i].marks[j] > 63)
            {
                sum += 6 * 3;
                strcpy(s[i].grade, "D");
            }
            else if (s[i].marks[j] > 57)
            {
                sum += 5 * 3;
                strcpy(s[i].grade, "E");
            }
            else if (s[i].marks[j] >= 50)
            {
                sum += 4 * 3;
                strcpy(s[i].grade, "P");
            }
            else
            {
                sum += 0;
                strcpy(s[i].grade, "F");
            }
        }
        s[i].sgpa = sum / 18;
    }
}
void display(struct stud *s, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (j != 6)
        {
            cout << "Maths\t" << s[i].marks[j] << "\t" << s[i].grade[2] << endl;
            j++;
            cout << "LD   \t" << s[i].marks[j] << "\t" << s[i].grade[2] << endl;
            j++;
            cout << "DS   \t" << s[i].marks[j] << "\t" << s[i].grade[2] << endl;
            j++;
            cout << "OOPS \t" << s[i].marks[j] << "\t" << s[i].grade[2] << endl;
            j++;
            cout << "TC   \t" << s[i].marks[j] << "\t" << s[i].grade[2] << endl;
            j++;
            cout << "CO   \t" << s[i].marks[j] << "\t" << s[i].grade[2] << endl;
            j++;
        }
        cout << "SGPA:   " << s[i].sgpa << endl;
    }
}
int main()
{
    int i = 0;
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    struct stud s[n];
    for (i = 1; i <= n; i++)
    {
        int j = 0;
        while (j != 6)
        {
            cout << "Details of student with roll number :" << i << endl;
            cout << "Enter maths marks" << endl;
            cin >> s[i].marks[j];
            j++;
            cout << "Enter logic design marks" << endl;
            cin >> s[i].marks[j];
            j++;
            cout << "Enter data structure marks" << endl;
            cin >> s[i].marks[j];
            j++;
            cout << "Enter OOPS marks" << endl;
            cin >> s[i].marks[j];
            j++;
            cout << "Enter Technical Communication marks" << endl;
            cin >> s[i].marks[j];
            j++;
            cout << "Enter Computer organisation marks" << endl;
            cin >> s[i].marks[j];
            j++;
        }
        cout << endl;
        grade(&s[i], n);
    }
    display(&s[i], n);
}
