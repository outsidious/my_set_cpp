#include <iostream>
#include <string>
//#include "set.hpp"

#include <QApplication>
#include <QTest>
#include <cstdlib>
#include <cstdio>
#include "testSet.h"
//#include "testSetOperations.h"

using namespace std;


int main(int argc, char *argv[])
{
    //freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new Test_Set_Constructors, argc, argv);
    QTest::qExec(new Test_Set_Methods, argc, argv);
    QTest::qExec(new Test_Iterator_Constructors, argc, argv);
    QTest::qExec(new Test_Iterator_Constructors, argc, argv);
    return 0;
}


/*int main(void) {
    try {
        cout << "START\n\n";
        Set<int> s1;
        cout << "s1 = " << s1;
        Set<int> s2{1, 2, 3, 4, 5, 6};
        cout << "s2 = " << s2;
        int arr[7] = {6, 7, 8, 9, 10, 2, 3};
        Set<int> s3 (7, arr);
        cout << "s3 = " << s3;
        Set<int> s4 (s3);
        cout << "s4 = " << s4;
        Set<int> s5;
        s5 = s4;
        cout << "s5 = " << s5;
        Set<int> s6;
        s6 = {1, 2, 3, 4};
        cout << "s6 = " << s6;
        Set<int> s7;
        s7 = s6;

        s2.Add(32);
        cout << "s2.Add(32); s2 = " << s2;
        s2.Add(5);
        cout << "s2.Add(5); s2 = " << s2;

        s2.Delete(18);
        cout << "s2.Delete(18); s2 = " << s2;
        s2.Delete(4);
        cout << "s2.Delete(4); s2 = " << s2;

        bool res = s2.Has(3);
        cout << "s2.Has(3); result = " << res;
        res = s2.Has(100);
        cout << "\ns2.Has(100); result = " << res;

        s1.Add(6);
        cout << "\n\ns1.Add(6); s1 = " << s1;
        s1.Clear();
        cout << "s1.Clear(); s1 = " << s1;

        s4 += s2;
        cout << "\ns4 += s2; s4 = " << s4;

        s2 -= s3;
        cout << "s2 -= s3; s2 = " << s2;

        s2.Add(2);
        cout << "\n\ns2.Add(2); s2 = " << s2;

        cout << "s5 = " << s5;
        cout << "s4 = " << s4;

        s5.Intersection(s2);
        cout << "s5 *= s2; s5 = " << s5;

        s5 /= s4;
        cout << "s5 /= s4; s5 = " << s5;

        s3 %= s5;
        cout << "s3 %= s5; s3 = " << s3;

        res = s3 > s5;
        cout << "\ns3 > s5; res = " << res;

        res = s3 >= s5;
        cout << "\ns3 >= s5; res = " << res;

        res = s3 < s5;
        cout << "\ns3 < s5; res = " << res;

        res = s3 <= s5;
        cout << "\ns3 <= s5; res = " << res;

        res = s3 == s4;
        cout << "\ns3 == s4; res = " << res;

        res = s3 != s4;
        cout << "\ns3 != s4; res = " << res;

        s2 += 16;
        cout << "\n\ns2 += 16; s2 = " << s2;

        s2.Union(18);
        cout << "s.Union(18); s2 = " << s2;

        s2 -= 16;
        cout << "s2 -= 16; s2 = " << s2;

        s2.Difference(18);
        cout << "s2.Differnce(18); s2 = " << s2;


        s5.Union(20);
        cout << "s5.Union(20); s5 = " << s5;

        s5.Union(s3);
        cout << "s5.Union(s3); s5 = " << s5;

        cout << "s2 + 4 =  " << s2 + 4;

        cout << "s2 - 4 =  " << s2 - 4;

        std::cout << "\nEND\n";
    } catch (SetException& error) {
        std::cout << error.what();
    }

    return 0;
}*/
