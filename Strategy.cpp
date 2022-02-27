//Strategy design pattern

#include <iostream>

class Strategy {
public:
	virtual void Operate() = 0;
};

class StrategyA: public Strategy {
public:
	void Operate() override {
		std::cout << "Strategy A operated\n";
	}
};

class StrategyB : public Strategy {
public:
	void Operate() override {
		std::cout << "Strategy B operated\n";
	}
};

class StrategyC : public Strategy {
public:
	void Operate() override {
		std::cout << "Strategy C operated\n";
	}
};

template<class AStrategy>
class Context {
	AStrategy* strategy_;
public:
	Context() {
		strategy_ = new AStrategy();
	}
	void Operate() {
		strategy_->Operate();
	}
};

int main()
{
	Context<StrategyA>* contexta = new Context<StrategyA>();
	contexta->Operate();
	Context<StrategyC>* contextc = new Context<StrategyC>();
	contextc->Operate();
}

