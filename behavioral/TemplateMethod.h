#pragma once

namespace paterns {

class TemplateMathod {
public:
	virtual void templateMethod() const final {
		stepOne();
		stepTwo();
		stepThree();
	}

	virtual ~TemplateMathod() = default;

protected:
	virtual void stepOne() const {
		// Some equal actions.
	}

	virtual void stepTwo() const = 0;
	virtual void stepThree() const = 0;
};

class ConcreteAlgorithmA : public TemplateMathod {
private:

	void stepTwo() const override {
		// Actions for Algorithm A.
	}

	void stepThree() const override {
		// Actions for Algorithm A.
	}
};

class ConcreteAlgorithmB : public TemplateMathod {
private:

	void stepTwo() const override {
		// Actions for Algorithm B.
	}

	void stepThree() const override {
		// Actions for Algorithm B.
	}
};

}
