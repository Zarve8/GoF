//Memento design pattern

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
class Originator;

class Memento{
    friend Originator;
    std::string state_;
public:
    Memento(std::string s): state_(s){}
};

class Originator{
    std::string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string state_;
    std::string GetRandomState(){
        int n = rand()%19 + 1;
        std::string s = "";
        for(int i = 0; i<n; i++){
            int ind = rand() % 32;
            s += alphanum[ind];
        }
        return s;
    }
public:
    Originator(){
        srand (time(NULL));
        state_ = GetRandomState();
        std::cout<<"Originated with state "<<state_<<"\n";
    }
    void Do(){
        state_ = GetRandomState();
        std::cout<<"did something and state changet to "<<state_<<"\n";
    }
    Memento* Save(){
        return new Memento(state_);
    }
    void Restore(Memento* memento){
        state_ = memento->state_;
        std::cout<<"state restored to "<<state_<<"\n";
    }
};

class Caretaker{
    Originator* originator_;
    std::vector<Memento*> mementos{};
public:
    Caretaker(Originator* originator): originator_(originator){}
    void BackUp(){
        mementos.push_back(originator_->Save());
    }
    void Undo(){
        if(mementos.size()){
            originator_->Restore(mementos[mementos.size()-1]);
            mementos.pop_back();
        }
    }
};

int main(){
    Originator* originator = new Originator;
    Caretaker* caretaker = new Caretaker(originator);
    caretaker->BackUp();
    originator->Do();
    originator->Do();
    caretaker->BackUp();
    originator->Do();
    caretaker->BackUp();
    caretaker->Undo();
    caretaker->Undo();
    caretaker->Undo();
}