#include <QTest>
#include "testSetOperations.h"
#include "set.hpp"
#include <cmath>
using namespace std;

Test_Set_Operations::Test_Set_Operations(QObject *parent) :
    QObject(parent)
{}

void Test_Set_Operations::test()
{
    //arrange

    //act
    Set<int> s = Set<int>();

    //assert
    QCOMPARE(0, 0);
}
