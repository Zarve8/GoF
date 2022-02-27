//Composite design pattern

#include <iostream>
#include <vector>

class Component{
public:
    virtual void add(Component* component) = 0;
    virtual void remove(Component* component) = 0;
    virtual Component* get_child(int n) = 0;
    virtual std::string execute() = 0;
};

class Composite: public Component{
    std::vector<Component*> child_list{};
public:
    Composite(std::string name){}
    void add(Component* component) override{
        this->child_list.push_back(component);
    }
    void remove(Component* component) override{
        child_list.erase(std::find(child_list.begin(), child_list.end(), component));
    }
    Component* get_child(int n) override{
        return child_list[n];
    }
    std::string execute() override{
        std::string s = "";
        for(int i = 0; i < child_list.size(); i++){
            s += child_list[i]->execute() + " ";
        }
        return "| " + s + "|";
    }
};

class Leaf: public Component{
    std::string name;
public:
    Leaf(std::string name): name(name){}
    std::string execute() override{
        return name;
    }
    void add(Component* component) override{}
    void remove(Component* component) override{}
    Component* get_child(int n) override{return nullptr;}
};

int main(){
    Composite* root  = new Composite("root");
    root->add(new Leaf("aleaf"));
    Composite* acomposite = new Composite("");
    root->add(acomposite);
    acomposite->add(new Leaf("bleaf"));
    acomposite->add(new Leaf("cleaf"));
    std::cout<<root->execute();
}