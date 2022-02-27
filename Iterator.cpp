//Iterator design pattern

#include <iostream>

template<typename T>
class AbstractList{
public:
    T x;
    AbstractList(T x): x(x){}
    AbstractList<T>* next_ = nullptr;
public:
    virtual void push_back(T y) = 0;
    virtual T get() = 0;
};

template<typename T>
class Iterator{
    AbstractList<T>* list = nullptr;
public:
    Iterator(AbstractList<T>* list): list(list){}
    void Next(){
        list = list->next_;
    }
    bool IsDone(){
        return !list->next_;
    }
    T get(){
        return list->get();
    }
};

template<typename T>
class List: public AbstractList<T>{
    friend Iterator<T>;
public:
    List(T x): AbstractList<T>(x){}
    void push_back(T y) override{
        if(this->next_){
            this->next_->push_back(y);
        }
        else{
            this->next_ = new List<T>(y);
        }
    }
    T get() override{
        return this->x;
    }
    Iterator<T>* CreateIterator(){
        return new Iterator<T>(this);
    }
};

int main(){
    List<int> alist(8);
    alist.push_back(5);
    alist.push_back(7);
    Iterator<int>* it = alist.CreateIterator();
    std::cout<<it->get()<<" ";
    while(!it->IsDone()){
        it->Next();
        std::cout<<it->get()<<" ";
    }
}