#pragma once

/*!
*@brief        ����ģʽ
*@author       tangw-b  2019/03/14  16:35
*/

class Singleton
{
public:
    static Singleton* getInstanse();

private:
    Singleton() {}
    ~Singleton();

private:
    static Singleton *m_pInstance;
};
