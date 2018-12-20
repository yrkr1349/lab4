#pragma once

template <class T>
constexpr auto ToUType(T enumerator) noexcept
{
	return static_cast<std::underlying_type_t<T>>(enumerator);
}

class Calculator
{
private :
	enum class Symbol : char
	{ 
		None = 0,
		LeftParenthesis = '(', RightParenthesis = ')',
		Plus     = '+',  Minus = '-',
		Multiply = '*', Divide = '/',
		Square	 = '^',
		Space    = ' ',
	};

	static const std::string kNumbers;
	static const std::string kSymbols;
	static const std::string kSpecialSymbol;

	static std::stack<char> m_stack;

private :
	static const size_t GetPriority(char cipher);

public :
	Calculator() = delete;

	static const std::tuple<bool, std::string> InfixToPostfix(const std::string& infix);
	static const std::tuple<bool, double, std::string> Calculate(const std::string& equation);
};