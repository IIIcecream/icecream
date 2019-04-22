#include <initializer_list>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "functional"
//////////////////////////////////////////////////////////////////////////
//  Ä£°åÊ¹ÓÃ
//////////////////////////////////////////////////////////////////////////
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
};


template <typename T> class myVec
{
public:
    myVec();
    myVec(std::initializer_list<T> il);

    void push_back(T &&t) { data->push_back(t); }

private:
    std::shared_ptr<std::vector<T>> data;
};


map<std::string, std::function<bool(int a, int b)>> myMap;
template <typename T>
bool funcManager(string s, std::function<T(T a, T b)> func)
{
    myMap[s] = func;
};

#define My_Register_CustomFunc(functionName)\
class My##functionName\
{\
public:\
My##functionName(){\
funcManager(#functionName, functionName);\
}\
};\
static My##functionName s_##My##functionName;

int min(int a, int b) { return a < b ? a : b; };

bool callTemplateFunc()
{
    compare(1, 0);
    compare(1.1, 2.3);

    //myVec<int> vec;
   // My_Register_CustomFunc(min);

    return true;
};
