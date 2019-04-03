#pragma once

/*!
*@brief        �򵥹�������̬�����������ǲ��������ģʽ�еģ���Ϊ�����������������󹤳���ǰ��
*@author       tangwei  2019/03/19  11:10
*@remarks      ��
*/

#include "IFactory.h"

class StaticFactory : public IFactory
{
public:
    virtual IProduct* createProduct() override;
    void setProductType(int n) { m_nType = n; }

private:
    int m_nType = 0;
};
