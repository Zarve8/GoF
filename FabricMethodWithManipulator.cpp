//Fabric method with manipulator

#include <iostream>

class Manipulator{
public:
    virtual void add() = 0;
};

class Character{
public:
    virtual void voice() = 0;
    virtual Manipulator* FabricMethod() = 0;
};

class String_Manipulator: public Manipulator{
    Character* character;
public:
    String_Manipulator(Character* ch): character(ch){}
    void add() override;
};

class Integer_Manipulator: public Manipulator{
    Character* character;
public:
    Integer_Manipulator(Character* ch): character(ch){}
    void add() override;
};

class String: public Character{
    std::string s;
    friend String_Manipulator;
public:
    String(std::string s): s(s){}
    void voice() override{
        std::cout<<s<<"\n";
    }
    Manipulator* FabricMethod() override{
        return new String_Manipulator(this);
    }
};

class Integer: public Character{
    int x;
    friend Integer_Manipulator;
public:
    Integer(int x): x(x){}
    void voice() override{
        std::cout<<x<<"\n";
    }
    Manipulator* FabricMethod() override{
        return new Integer_Manipulator(this);
    }
};

void String_Manipulator::add() {
    std::string string  = static_cast<String*>(this->character)->s;
    string = string + "\n" + string;
    static_cast<String*>(this->character)->s = string;
}

void Integer_Manipulator::add() {
    int y  = static_cast<Integer*>(this->character)->x;
    y++;
    static_cast<Integer*>(this->character)->x = y;
}

int main(){
    Character* acharacter = new String("###");
    Manipulator* amanipulator = acharacter->FabricMethod();
    amanipulator->add();
    acharacter->voice();
    acharacter = new Integer(6);
    amanipulator = acharacter->FabricMethod();
    amanipulator->add();
    acharacter->voice();
}