#pragma once

class IProduct
{
public:
    virtual ~IProduct() {}
    virtual void operation() = 0;
};

class Product : public IProduct
{
public:
    virtual void operation() override;
};

// productAÓÉproductA1,A2...×é³É

// Product1
class Product1 : public Product
{
public:
    virtual void operation() override;
};

class ProductA1 : public Product1
{
public:
    virtual void operation() override;
};

class ProductA2 : public Product1
{
public:
    virtual void operation() override;
};

// Product2
class Product2 : public Product
{
public:
    virtual void operation() override;
};

class ProductA2 : public Product2
{
public:
    virtual void operation() override;
};

class ProductB2 : public Product2
{
public:
    virtual void operation() override;
};

// Product3
class Product3 : public Product
{
public:
    virtual void operation() override;
};