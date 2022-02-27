//Chain of Responsibility design pattern

#include <iostream>

enum class E_Type{A, B, C};

class Handler {
public:
    virtual Handler* SetNext(Handler *handler) = 0;
    virtual std::string Handle(E_Type request) = 0;
};

class AbstractHandler: public Handler{
    Handler* next_handler_ = nullptr;
public:
    Handler* SetNext(Handler *handler) override{
        next_handler_ = handler;
        return this;
    }
    std::string Handle(E_Type request) override{
        if(next_handler_){
            return next_handler_->Handle(request);
        }
        return nullptr;
    }
};

class Handler_A: public AbstractHandler{
public:
    std::string Handle(E_Type request) override{
        if(request == E_Type::A){
            return "A_Handler picked request";
        }
        else{
            return AbstractHandler::Handle(request);
        }
    }
};

class Handler_B: public AbstractHandler{
public:
    std::string Handle(E_Type request) override{
        if(request == E_Type::B){
            return "B_Handler picked request";
        }
        else{
            return AbstractHandler::Handle(request);
        }
    }
};

class Handler_C: public AbstractHandler{
public:
    std::string Handle(E_Type request) override{
        if(request == E_Type::C){
            return "B_Handler picked request";
        }
        else{
            return AbstractHandler::Handle(request);
        }
    }
};

int main(){
    Handler* ahandler = new Handler_A();
    Handler* bhandler = new Handler_B();
    Handler* chandler = new Handler_C();
    ahandler->SetNext(bhandler->SetNext(chandler));
    std::cout<<ahandler->Handle(E_Type::B);
}