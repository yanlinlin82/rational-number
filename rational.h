#pragma once
#include <iostream>
#include <vector>

namespace math
{
	class rational
	{
	private:
		unsigned int p_, q_;

	public:
		explicit rational(unsigned int p = 0, unsigned int q = 1): p_(p), q_(q) { }

		template <unsigned int base = 10>
		std::string to_string() const {
			static_assert(base >= 2);
			unsigned int n = p_ / q_;
			unsigned int m = p_ % q_;
			std::string s;
			while (n > 0) {
				char c = '0' + (n % base);
				s = c + s;
				n = n / base;
			}
			if (s.empty()) {
				s = "0";
			}
			if (m > 0) {
				s += '.';
				std::vector<std::pair<unsigned int, char>> a;
				for (;;) {
					m *= base;
					size_t j = 0;
					for (; j < a.size(); ++j) {
						if (m == a[j].first) {
							break;
						}
					}
					if (j < a.size()) {
						for (size_t k = 0; k < j; ++k) {
							s += a[k].second;
						}
						s += '(';
						for (size_t k = j; k < a.size(); ++k) {
							s += a[k].second;
						}
						s += ")...";
						break;
					}
					char c = '0' + (m / q_);
					a.push_back(std::make_pair(m, c));
					m %= q_;
					if (m == 0) {
						for (size_t j = 0; j < a.size(); ++j) {
							s += a[j].second;
						}
						break;
					}
				}
			}
			return s;
		}

		friend std::ostream& operator << (std::ostream& os, const rational& r) {
			return (os << r.to_string());
		}
	};
}
