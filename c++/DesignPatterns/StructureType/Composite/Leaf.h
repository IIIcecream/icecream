#pragma once

/*!
*@brief        叶子节点
*@author       tangwei  2019/03/15  11:15
*@remarks      无
*/

#include "Component.h"

class Leaf : public Component
{
public:
    virtual void operation() override;
};