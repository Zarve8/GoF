//State design pattern

#include <iostream>

enum class E_State{A, B, C};

class State {
public:
	virtual void Operate() = 0;
};

class StateA: public State {
public:
	void Operate() override {
		std::cout << "State A operated\n";
	}
};

class StateB : public State {
public:
	void Operate() override {
		std::cout << "State B operated\n";
	}
};

class StateC : public State {
public:
	void Operate() override {
		std::cout << "State C operated\n";
	}
};

class Context {
	State* state_;
	E_State enum_;
public:
	Context(E_State state) {
		ChangeState(state);
	}
	void ChangeState(E_State state) {
		enum_ = state;
		switch (state) {
		case E_State::A:
			state_ = new StateA();
			break;
		case E_State::B:
			state_ = new StateB();
			break;
		case E_State::C:
			state_ = new StateC();
			break;
		}
	}
	void Operate() {
		state_->Operate();
	}
};

int main()
{
	Context* context = new Context(E_State::A);
	context->Operate();
	context->ChangeState(E_State::B);
	context->Operate();
	context->ChangeState(E_State::C);
	context->Operate();
}

