#ifndef TEST_ITERATOR_BUILDER_H
#define TEST_ITERATOR_BUILDER_H

class _Test_Iterator_Builder
{
public:
    Iterator_Builder() {
        int arr[] = {1, 2};
        ptr = arr;
        index = 0;
        size = 2;
    }

    friend Iterator<int> getBegin()  {
       Iterator<int> res = Iterator<int>();
       res.ptr = ptr;
    }

    Iterator<int> getEnd() {

    }
private:
    int* ptr;
    size_t index = 0;
    size_t size;
};

#endif // TEST_ITERATOR_BUILDER_H
