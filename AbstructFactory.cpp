//Abstract Factory design pattern

#include <iostream>

class A{
protected:
    std::string s;
    A(std::string s): s(s){}
public:
    virtual void voice() = 0;
};

class A1: public A{
public:
    A1(std::string s): A(s){}
    void voice() override{
        std::cout<<this->s+" "+"1\n";
    }
};

class A2: public A{
public:
    A2(std::string s): A(s){}
    void voice() override{
        std::cout<<this->s+" A "+"2\n";
    }
};

class B{
protected:
    std::string s;
    B(std::string s): s(s){}
public:
    virtual void voice() = 0;
};

class B1: public B{
public:
    B1(std::string s): B(s){}
    void voice() override{
        std::cout<<this->s+" B "+"1\n";
    }
};

class B2: public B{
public:
    B2(std::string s): B(s){}
    void voice() override{
        std::cout<<this->s+" B "+"2\n";
    }
};

class AbstructFactiry{
public:
    virtual A* getA(std::string s) = 0;
    virtual B* getB(std::string s) = 0;
};

class Factory1: public AbstructFactiry{
public:
    A* getA(std::string s) override{
        return new A1(s);
    }
    B* getB(std::string s) override{
        return new B1(s);
    }
};

class Factory2: public AbstructFactiry{
public:
    A* getA(std::string s) override{
        return new A2(s);
    }
    B* getB(std::string s) override{
        return new B2(s);
    }
};

int main(){
    Factory1 AFact1;
    A* a1 = AFact1.getA("Hello");
    B* b1 = AFact1.getB("Hi");
    a1->voice();
    b1->voice();
    //another factory
    Factory2 AFact2;
    a1 = AFact2.getA("Hello");
    b1 = AFact2.getB("Hi");
    a1->voice();
    b1->voice();
}