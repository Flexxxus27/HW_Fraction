#include <iostream>
#include <exception>

class Fraction {
public:

	Fraction(long num, long denum) {
		try
		{
			if (denum == 0) {
				throw std::exception("Ошибка denum = 0\n");
			}
			num_ = num;
			denum_ = denum;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Denum = 0\n" << ex.what();
		}
	}

	void Print_Fr() {
		std::cout << num_ << '/' << denum_ << std::endl;
	}

	void True_Fr() {
		if (num_ > denum_) {
			std::cout << "Дробь не правильная !\n";
		}
		else
			std::cout << "Дробь правильная!\n";
	}

	double RealNum_Fr() {
		return num_ / denum_;
	}

	friend Fraction Sum(Fraction a, Fraction b) {
		long sum_num = a.num_ * b.denum_ + b.num_ * a.denum_;
		long sum_denum = a.denum_ * b.denum_;
		return Fraction(sum_num, sum_denum);
	}
	friend Fraction Sum(Fraction a, long num) {
		num *= a.denum_;
		return Fraction(a.num_ + num, a.denum_);
	}

	friend Fraction dif(Fraction a, Fraction b) {
		long sum_num = a.num_ * b.denum_ - b.num_ * a.denum_;
		long sum_denum = a.denum_ * b.denum_;
		return Fraction(sum_num, sum_denum);
	}
	friend Fraction dif(Fraction a, long num) {
		a.num_ -= num * a.denum_;
		return a;
	}

	friend Fraction div(Fraction a, Fraction b) {
		long sum_num = a.num_ * b.denum_;
		long sum_denum = a.denum_ * b.num_;
		return Fraction(sum_num, sum_denum);
	}
	friend Fraction div(Fraction a, long num) {
		long div_num = a.denum_ * num;
		return Fraction(a.num_, div_num);
	}
	friend Fraction Multy(Fraction a, Fraction b) {
		long sum_num = a.num_ * b.num_;
		long sum_denum = a.denum_ * b.denum_;
		return Fraction(sum_num, sum_denum);
	}
	friend Fraction Multy(Fraction a, long num) {
		long multy_num = a.num_ * num;
		return Fraction(multy_num, a.denum_);
	}



private:
	long num_;
	long denum_;
};






int main() {
	setlocale(0, "");
	
	Fraction F0(0, 0);
	Fraction F1(2, 3);
	Fraction F2(3, 1);

	F1.Print_Fr();
	F2.Print_Fr();

	std::cout << F2.RealNum_Fr() << std::endl;
	std::cout << F1.RealNum_Fr() << std::endl;

	F1.True_Fr();
	F2.True_Fr();

	Fraction F3 = Sum(F1, F2);
	F3.Print_Fr();

	Fraction F4 = Multy(F1, F2);
	F4.Print_Fr();

	Fraction F5 = div(F2, 3);
	F5.Print_Fr();


	return 0;
}