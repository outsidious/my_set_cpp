#ifndef TESTSETOPERATIONS_H
#define TESTSETOPERATIONS_H

#include <QObject>

class Test_Set_Operations : public QObject
{
    Q_OBJECT
public:
    explicit Test_Set_Operations(QObject *parent = 0);

private slots:
    void test();
};


#endif // TESTSETOPERATIONS_H
