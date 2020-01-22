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
		explicit rational(unsigned int p = 0, unsigned int q = 1)
		{
			set(p, q);
		}

		std::string to_fraction() const
		{
			if (q_ == 0) {
				return (p_ == 0 ? "NA" : "Inf");
			}
			std::string s = std::to_string(p_);
			if (q_ != 1) {
				s += '/' + std::to_string(q_);
			}
			return s;
		}

		template <unsigned int base = 10>
		std::string to_decimal() const
		{
			static_assert(base >= 2);
			if (q_ == 0) {
				return (p_ == 0 ? "NA" : "Inf");
			}
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

		rational operator + (const rational& r)
		{
			unsigned int p = p_ * r.q_ + q_ * r.p_;
			unsigned int q = q_ * r.q_;
			return rational(p, q);
		}

		bool operator == (const rational& r) const
		{
			return (p_ == r.p_) && (q_ == r.q_);
		}

		friend std::ostream& operator << (std::ostream& os, const rational& r)
		{
			return (os << r.to_decimal());
		}

	private:
		void set(unsigned int p, unsigned int q)
		{
			if (p == 0 && q == 0) {
				p_ = p; q_ = q;
			} else if (p == 0) {
				p_ = 0; q_ = 1;
			} else if (q == 0) {
				p_ = 1; q_ = 0;
			} else {
				unsigned int gcd = calculate_gcd(p, q);
				p_ = p / gcd;
				q_ = q / gcd;
			}
		}

		// GCD: greatest common divisor
		static unsigned int calculate_gcd(unsigned int p, unsigned int q)
		{
			while (p && q) {
				if (p > q) {
					p %= q;
				} else {
					q %= p;
				}
			}
			return (p + q);
		}
	};
}
