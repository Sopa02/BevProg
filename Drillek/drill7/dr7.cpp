/*
	The first working version of Stroustrup's calculator.
	Written by Renátó Besenczi based on the book BS, "Programming: Principles and Practice using C++, Second Edition"
	See chapter 6 and chapter 7 of book: https://stroustrup.com/programming.html
	© 2020 Renátó Besenczi, according to CC0. Questions: renato.besenczi@gmail.com

	Input from cin; output to cout. Input comes from cin through the Token_stream called ts.

	Grammar:
	
	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Print:
		;
	Quit:
		q
	Statement:
		Declaration
		Expression
	Declaration:
		"let" Name "=" Expression
	Name:
		string literal
	Expression:
		Term
		Expression + Term
		Expression – Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
		( Expression )
		– Primary
		+ Primary
	Number:
		floating-point-literal

*/

#include "../std_lib_facilities.h" //Include usual header

// Some symbolic constants for clarity
constexpr char number = '8';
constexpr char print = '=';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char result = '=';
constexpr char thousand = 'k';
constexpr char squareroot = 's';
constexpr char power='p';
constexpr char quit='q';
const char declkey = '#'; //constexpr string since C++20 only
const string quitKey = "exit";
const string sqrtKey="sqrt";
const string powKey="pow";

//function declarations
double expression();
double primary();
double term();
double declaration();
double statement();

// Variable ///////////////////////
class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s)
{
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}
// Variable end ///////////////////////

// Token ///////////////////////
class Token {
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};
// Token end ///////////////////////

// Token_stream ///////////////////////
class Token_stream {
public:
	Token_stream();
	void putback(Token t);
	Token get();
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
		case print:
		case 'e':
		{
			string s;
    		s += ch;
    		while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    		cin.putback(ch);
			if (s==quitKey) return Token{quit};
		}
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ',':
		//case '=':
			return Token(ch);
		case '#':
			return Token{let};
		case 's':
		{
			string s;
    		s += ch;
    		while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    		cin.putback(ch);
			if (s==sqrtKey) return Token{squareroot};
		}
		case 'p':
		{
			string s;
    		s += ch;
    		while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    		cin.putback(ch);
			if (s==powKey) return Token{power};
		}
		case thousand:
			return Token{number,1000};
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default: 
    	{
    		if (isalpha(ch))
    		{
    			string s;
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    			cin.putback(ch);
    			// if (s == declkey) return Token{let};
    			// else
				if (is_declared(s))
    				return Token(number, get_value(s));
    			return Token{name,s};
    		}
    		error("Bad token");
    	}
    	return 0;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}
// Token_stream end ///////////////////////
Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

// Logically separate calculate() from the usual "boiler plate" of main 
void calculate()
{
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() 
try {
	cout<<"Welcome to our simple calculator.\nPlease enter"<<
	"expressions using floating-point numbers.\n"<<
	"\nAvailable operators are: + - / * %\n"<<
	"Remember to write '='(print) after each calculation.\n"<<
	"You can quit by typeing 'exit' in a new line.\n";

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	
	calculate();

	return 0;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}

//Functions mapping grammar rules //////////////////////////
double _pow(){
	Token t = ts.get();
	if (t.kind!='(')
	{
		error("missing '('! \tpow(x,i)");
	}
	double x = expression();
	t = ts.get();
	if(t.kind!=',')
	{
		error("missing ',' \tpow(x,i)");
	}
	int i = narrow_cast<int>(expression());
	return pow(x,i);
}
double square()
{
	Token t = ts.get();
	if (t.kind != '(') error("correct use of the sqrt function: \t sqrt(expression)");
	double d = expression();
	if (d<0)
	{
		error("The result of the expression inside the sqrt function must be a positive number!");
	}
	return sqrt(d);
}

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case 's':
		{
			double d = square();
			t=ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case 'p':
		{
			double d = _pow();
			t=ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		default:
			error("primary expected");
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
				/* //or you can use narrow cast check
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) error ("%: Zero oszto");
				left = i1 % i2;
				t = ts.get();
				break;
				*/
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}



double statement()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}
//Functions mapping grammar rules end //////////////////////////

// Program end!