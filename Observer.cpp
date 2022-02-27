//Observer design pattern

#include <iostream>
#include <list>

class AbstractObserver{
public:
    virtual void Update(std::string message) = 0;
};

class Subject{
    std::list<AbstractObserver*> observers_{};
    std::string message_;
public:
    void Attach(AbstractObserver *observer){
        observers_.push_back(observer);
    }
    void Detach(AbstractObserver *observer){
        observers_.remove(observer);
    }
    void Notify(){
        for(auto it : observers_){
            it->Update(message_);
        }
    }
    void CreateMessage(std::string message){
        this->message_ = message;
        Notify();
    }
};

class Observer: public AbstractObserver{
    Subject* subject_;
    static int number_;
    std::string state_;
    int ind;
public:
    Observer(Subject* subject): subject_(subject){
        ind = number_ + 1;
        number_++;
        subject_->Attach(this);
    }
    void RemoveMySubscription(){
        subject_->Detach(this);
    }
    void Update(std::string message) override{
        state_ = message;
        std::cout<<"state updated in observer:"<<ind<<" with message "<<state_<<"\n";
    }
};
int Observer::number_ = 0;

int main(){
    Subject* subject = new Subject;
    Observer* ob1 = new Observer(subject);
    Observer* ob2 = new Observer(subject);
    Observer* ob3 = new Observer(subject);
    subject->CreateMessage("Hii");
    ob3->RemoveMySubscription();
    subject->CreateMessage("World");
}