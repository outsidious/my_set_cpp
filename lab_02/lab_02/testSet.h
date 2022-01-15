#ifndef TEST_SMART_H
#define TEST_SMART_H

#include <QObject>

class Test_Set_Constructors : public QObject
{
    Q_OBJECT
public:
    explicit Test_Set_Constructors(QObject *parent = 0);

private slots:
    void createEmptySetTest();
    void createSetFromIitializerListTest();
    void createSetFromArrayTest();
    void createSetFromSetTest();
    void createSetFromIteratorsTest();
};


class Test_Set_Methods : public QObject
{
    Q_OBJECT
public:
    explicit Test_Set_Methods(QObject *parent = 0);

private slots:
    void getSetBeginTest();
    void getSetEndTest();
    void hasSetElemTrueTest();
    void hasSetElemFalseTest();
    void addNewElemToSetTest();
    void addOldElemToSetTest();
    void unionSetWithSetTest();
    void unionSetWithNewElemTest();
    void unionSetWithOldElemTest();
    void deleteOldElemFromSetTest();
    void deleteNewElemFromSetTest();
    void differenceSetWithSetTest();
    void differenceSetWithNewElemTest();
    void differenceSetWithOldElemTest();
    void intersectionSetWithSetTest();
    void symDifferenceSetWithSetTest();
    void isSubsetOfTrueTest();
    void isSubsetOfFalseTest();
    void containTrueTest();
    void containFalseTest();
};


class Test_Iterator_Constructors : public QObject
{
    Q_OBJECT
public:
    explicit Test_Iterator_Constructors(QObject *parent = 0);

private slots:
    void createEmptyIteratorTest();
    void createIteratorFromSetTest();
};


class Test_Iterator_Operators : public QObject
{
    Q_OBJECT
public:
    explicit Test_Iterator_Operators(QObject *parent = 0);

private slots:
    void getValueTest();
    void setIteratorEqualSetTest();
    void setIteratorEqualIteratorTest();
    void IteratorPlusNumTest();
    void IteratorMinusNumTest();
};

#endif // TEST_SMART_H
