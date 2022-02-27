// Command design pattern

#include <iostream>
#include <vector>

class Command{
public:
    virtual void Execute(std::string s) = 0;
    virtual void Undo() = 0;
    virtual Command* Copy() = 0;
};

class AppState{
    static AppState* instance_;
    AppState(std::string s): state_(s){}
    std::vector<Command*> commandSequence_;
public:
    std::string state_;
    static AppState* GetInstance(std::string s){
        if(!instance_) instance_ = new AppState(s);
        return instance_;
    }
    void Print(){
        std::cout<<state_<<"\n";
    }
    void AddCommand(Command* command){
        commandSequence_.push_back(command->Copy());
    }
    void Undo(){
        if(commandSequence_.size() > 0){
            commandSequence_[commandSequence_.size()-1]->Undo();
            commandSequence_.pop_back();
        }
    }
};
AppState* AppState::instance_ = nullptr;

class CommandAdd: public Command{
    int n = 0;
public:
    void Execute(std::string s) override{
        AppState::GetInstance("")->state_+=s;
        n = s.size();
        AppState::GetInstance("")->AddCommand(this);
    }
    void Undo() override{
        int l = AppState::GetInstance("")->state_.size();
        AppState::GetInstance("")->state_.erase(l-n, n);
    }
    Command* Copy() override{
        CommandAdd* commandAdd = new CommandAdd();
        commandAdd->n = this->n;
        return commandAdd;
    }
};

class Invoker{
    Command* action_;
public:
    Invoker(Command* command): action_(command){}
    void Execute(){
        action_->Execute("World");
    }
};


int main(){
    AppState::GetInstance("Hello ");
    Invoker* invoker = new Invoker(new CommandAdd());
    invoker->Execute();
    invoker->Execute();
    AppState::GetInstance("")->Print();
    AppState::GetInstance("")->Undo();
    AppState::GetInstance("")->Print();
}

