#pragma once
#include "Component.h"
#include <vector>

class Composite : public Component
{
public:
    virtual ~Composite();

protected:
    virtual void add(IComponent *pItem) override;
    virtual void remove(IComponent *pItem) override;
    virtual void operation() override;

private:
    std::vector<IComponent *> m_vec;
};