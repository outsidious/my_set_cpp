#include <QTest>
#include "testSet.h"
#include "set.hpp"
#include <cmath>
using namespace std;

//Constructors
Test_Set_Constructors::Test_Set_Constructors(QObject *parent) :
    QObject(parent)
{}

void Test_Set_Constructors::createEmptySetTest()
{
    //arrange

    //act
    Set<int> s = Set<int>();

    //assert
    QCOMPARE(s.GetCountElement(), 0);
}

void Test_Set_Constructors::createSetFromIitializerListTest()
{
    //arrange

    //act
    Set<int> s = Set<int>({1, 2, 3});

    //assert
    QCOMPARE(s.GetCountElement(), 3);
    QCOMPARE(s.Has(1), true);
    QCOMPARE(s.Has(2), true);
    QCOMPARE(s.Has(3), true);
    QCOMPARE(s.Has(4), false);
}

void Test_Set_Constructors::createSetFromArrayTest()
{
    //arrange
    int arr[3] = {1, 2, 3};

    //act
    Set<int> s = Set<int>(3, arr);

    //assert
    QCOMPARE(s.GetCountElement(), 3);
    QCOMPARE(s.Has(1), true);
    QCOMPARE(s.Has(2), true);
    QCOMPARE(s.Has(3), true);
    QCOMPARE(s.Has(4), false);
}

void Test_Set_Constructors::createSetFromSetTest()
{
    //arrange
    Set<int> s1 = Set<int>({1, 2, 3});

    //act
    Set<int> s2 = Set<int>(s1);

    //assert
    QCOMPARE(s2.GetCountElement(), 3);
    QCOMPARE(s2.Has(1), true);
    QCOMPARE(s2.Has(2), true);
    QCOMPARE(s2.Has(3), true);
    QCOMPARE(s2.Has(4), false);
}

void Test_Set_Constructors::createSetFromIteratorsTest()
{
    //arrange
    Set<int> s1 = Set<int>({1, 2, 3});
    _Test_Iterator_Builder builder = _Test_Iterator_Builder();
    Iterator<int> i = builder.getBegin();

    //act
    Set<int> s2 = Set<int>(i, i + 1);

    //assert
    QCOMPARE(s2.GetCountElement(), 1);
    QCOMPARE(s2.Has(1), true);
    QCOMPARE(s2.Has(2), false);
}


//Methods
Test_Set_Methods::Test_Set_Methods(QObject *parent) :
    QObject(parent)
{}

void Test_Set_Methods::getSetBeginTest()
{
    //arrange
    Set<int> s1 = Set<int>({1, 2, 3});

    //act
    Iterator<int> i = s1.begin();

    //assert
    QCOMPARE(*i, 1);
}

void Test_Set_Methods::getSetEndTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    Iterator<int> i = s1.end();

    //assert
    QCOMPARE(*(--i), 3);
}

void Test_Set_Methods::hasSetElemTrueTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    bool check = s1.Has(1) && s1.Has(2) && s1.Has(3);

    //assert
    QCOMPARE(check, true);
}

void Test_Set_Methods::hasSetElemFalseTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    bool check = s1.Has(0) || s1.Has(4);

    //assert
    QCOMPARE(check, false);
}

void Test_Set_Methods::addNewElemToSetTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    bool check = s1.Add(4);

    //assert
    QCOMPARE(s1.Has(4), true);
    QCOMPARE(s1.GetCountElement(), 4);
    QCOMPARE(check, true);
}

void Test_Set_Methods::addOldElemToSetTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    bool check = s1.Add(1);

    //assert
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.GetCountElement(), 3);
    QCOMPARE(check, false);
}

void Test_Set_Methods::unionSetWithSetTest()
{
    //arrange
    _Test_Set_Builder builder1 = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder1.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({3, 4, 5});
    Set<int> s2 = builder2.getSet();

    //act
    s1.Union(s2);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), true);
    QCOMPARE(s1.Has(4), true);
    QCOMPARE(s1.Has(5), true);
    QCOMPARE(s1.Has(6), false);
    QCOMPARE(s1.GetCountElement(), 5);
}

void Test_Set_Methods::unionSetWithNewElemTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    s1.Union(4);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), true);
    QCOMPARE(s1.Has(4), true);
    QCOMPARE(s1.Has(5), false);
    QCOMPARE(s1.GetCountElement(), 4);
}

void Test_Set_Methods::unionSetWithOldElemTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    s1.Union(3);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), true);
    QCOMPARE(s1.Has(4), false);
    QCOMPARE(s1.GetCountElement(), 3);
}

void Test_Set_Methods::deleteOldElemFromSetTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    bool check = s1.Delete(3);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), false);
    QCOMPARE(check, true);
    QCOMPARE(s1.GetCountElement(), 2);
}

void Test_Set_Methods::deleteNewElemFromSetTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    bool check = s1.Delete(0);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), true);
    QCOMPARE(check, false);
    QCOMPARE(s1.GetCountElement(), 3);
}

void Test_Set_Methods::differenceSetWithSetTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({3, 4, 5});
    Set<int> s2 = builder2.getSet();

    //act
    s1.Difference(s2);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), false);
    QCOMPARE(s1.GetCountElement(), 2);
}

void Test_Set_Methods::differenceSetWithOldElemTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    s1.Difference(3);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), false);
    QCOMPARE(s1.GetCountElement(), 2);
}

void Test_Set_Methods::differenceSetWithNewElemTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();

    //act
    s1.Difference(0);

    //assert
    QCOMPARE(s1.Has(0), false);
    QCOMPARE(s1.Has(1), true);
    QCOMPARE(s1.Has(2), true);
    QCOMPARE(s1.Has(3), true);
    QCOMPARE(s1.GetCountElement(), 3);
}

void Test_Set_Methods::intersectionSetWithSetTest()
{
    //arrange
    _Test_Set_Builder builder1 = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder1.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({3, 4, 5});
    Set<int> s2 = builder2.getSet();
    Set<int> s3;

    //act
    s3 = s1.Intersection(s2);

    //assert
    QCOMPARE(s3.Has(1), false);
    QCOMPARE(s3.Has(2), false);
    QCOMPARE(s3.Has(3), true);
    QCOMPARE(s3.Has(4), false);
    QCOMPARE(s3.Has(5), false);
    QCOMPARE(s3.GetCountElement(), 1);
}

void Test_Set_Methods::symDifferenceSetWithSetTest()
{
    //arrange
    _Test_Set_Builder builder1 = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder1.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({3, 4, 5});
    Set<int> s2 = builder2.getSet();
    Set<int> s3;

    //act
    s3 = s1.SymDifference(s2);

    //assert
    QCOMPARE(s3.Has(1), true);
    QCOMPARE(s3.Has(2), true);
    QCOMPARE(s3.Has(3), false);
    QCOMPARE(s3.Has(4), false);
    QCOMPARE(s3.Has(5), false);
    QCOMPARE(s3.GetCountElement(), 2);
}

void Test_Set_Methods::isSubsetOfTrueTest()
{
    //arrange
    _Test_Set_Builder builder1 = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder1.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({1, 2, 3, 4, 5});
    Set<int> s2 = builder2.getSet();

    //act
    bool check = s1.IsSubsetOf(s2);

    //assert
    QCOMPARE(check, true);
}

void Test_Set_Methods::isSubsetOfFalseTest()
{
    //arrange
    _Test_Set_Builder builder1 = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder1.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({3, 4, 5});
    Set<int> s2 = builder2.getSet();

    //act
    bool check = s1.IsSubsetOf(s2);

    //assert
    QCOMPARE(check, false);
}

void Test_Set_Methods::containTrueTest()
{
    //arrange
    _Test_Set_Builder builder1 = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder1.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({1, 2, 3, 4, 5});
    Set<int> s2 = builder2.getSet();

    //act
    bool check = s2.Contain(s1);

    //assert
    QCOMPARE(check, true);
}

void Test_Set_Methods::containFalseTest()
{
    //arrange
    _Test_Set_Builder builder = _Test_Set_Builder({1, 2, 3});
    Set<int> s1 = builder.getSet();
    _Test_Set_Builder builder2 = _Test_Set_Builder({3, 4, 5});
    Set<int> s2 = builder2.getSet();

    //act
    bool check = s2.Contain(s1);

    //assert
    QCOMPARE(check, false);
}


//Iterator Constructors
Test_Iterator_Constructors::Test_Iterator_Constructors(QObject *parent) :
    QObject(parent)
{}

void Test_Iterator_Constructors::createEmptyIteratorTest()
{
    //arrange

    //act
    Iterator<int> it = Iterator<int>();

    //assert
    _Test_Iterator test = _Test_Iterator(it);
    QCOMPARE(test.getIndex(), 0);
    QCOMPARE(test.getSize(), 0);
}

void Test_Iterator_Constructors::createIteratorFromSetTest()
{
    //arrange
    Set<int> s = _Test_Set_Builder({1, 2, 3}).getSet();

    //act
    Iterator<int> it = Iterator<int>(s);
    _Test_Iterator test = _Test_Iterator(it);

    //assert
    QCOMPARE(test.getIndex(), 0);
    QCOMPARE(test.getSize(), 3);
    QCOMPARE(*it, 1);
    QCOMPARE(*(it + 1), 2);
    QCOMPARE(*(it + 2), 3);
}


//iterator operators
Test_Iterator_Operators::Test_Iterator_Operators(QObject *parent) :
    QObject(parent)
{}

void Test_Iterator_Operators::getValueTest()
{
    //arrange
    Iterator<int> it = _Test_Iterator_Builder().getBegin();

    //act
    int val = *it;

    //assert
    QCOMPARE(val, 1);
}


void Test_Iterator_Operators::setIteratorEqualSetTest()
{
    //arrange
    Set<int> s = _Test_Set_Builder({1, 2, 3}).getSet();

    //act
    Iterator<int> it = s;

    //assert
    _Test_Iterator test = _Test_Iterator(it);
    QCOMPARE(test.getSize(), 3);
    QCOMPARE(test.getIndex(), 0);
    QCOMPARE(*it, 1);
    QCOMPARE(*(it + 1), 2);
    QCOMPARE(*(it + 2), 3);
}

void Test_Iterator_Operators::setIteratorEqualIteratorTest()
{
    //arrange
    Iterator<int> it = _Test_Iterator_Builder().getBegin();

    //act
    Iterator<int> it2 = it;

    //assert
    _Test_Iterator test = _Test_Iterator(it2);
    QCOMPARE(test.getSize(), 3);
    QCOMPARE(test.getIndex(), 0);
    QCOMPARE(*it, 1);
    QCOMPARE(*(it + 1), 2);
    QCOMPARE(*(it + 2), 3);
}

void Test_Iterator_Operators::IteratorPlusNumTest()
{
    //arrange
    Iterator<int> it = _Test_Iterator_Builder().getBegin();

    //act
    Iterator<int> it2 = it + 2;

    //assert
    _Test_Iterator test = _Test_Iterator(it2);
    QCOMPARE(test.getSize(), 3);
    QCOMPARE(test.getIndex(), 2);
    QCOMPARE(*it2, 3);
}

void Test_Iterator_Operators::IteratorMinusNumTest()
{
    //arrange
    Iterator<int> it = _Test_Iterator_Builder().getEnd();

    //act
    Iterator<int> it2 = it - 2;

    //assert
    _Test_Iterator test = _Test_Iterator(it2);
    QCOMPARE(test.getSize(), 3);
    QCOMPARE(test.getIndex(), 0);
    QCOMPARE(*it2, 1);
}

