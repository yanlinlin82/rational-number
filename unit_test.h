#pragma once
#include <cstdlib>
#include <iostream>

class unit_test
{
public:
	static unit_test& instance()
	{
		static unit_test instance;
		return instance;
	}
	size_t fail_, pass_;

	class unit
	{
	public:
		explicit unit(const char* s) { std::cerr << "[UnitTest] " << s << ": " << std::flush; }
		~unit() { std::cerr << std::endl; }
	};
private:
	unit_test(): fail_(0), pass_(0) { }
	~unit_test()
	{
		std::cerr << "[UnitTest] All " << (pass_ + fail_) << " test(s), "
			<< pass_ << " passed and "
			<< fail_ << " failed." << std::endl;
		exit(fail_ > 0 ? 1 : 0);
	}
	unit_test(const unit_test&) = delete;
	void operator = (const unit_test&) = delete;
};

#define unit(name) \
	unit_test::unit unit_##name(#name)

#define unit_assert(exp) \
	std::cerr << '.' << std::flush; \
	if (!(exp)) { \
		++unit_test::instance().fail_; \
		std::cerr << '\n' << __FILE__ << ':' << __LINE__ \
			<< ":unit_assert failed: " << #exp << std::endl; \
	} else \
		++unit_test::instance().pass_
