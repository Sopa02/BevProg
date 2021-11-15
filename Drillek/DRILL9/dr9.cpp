#include "../std_lib_facilities.h"

namespace UDChrono {

	class Year {
		static constexpr int min = 1800;
		static constexpr int max = 2200;
	public:
		class Invalid{};
		Year (int x): y{x} { if (x<min || x>max) throw Invalid{}; }
		int year(){ return y; }
		void increment() { y++; }
	private:
		int y;
	};

	Year operator++(Year& year)
	{
		year.increment();
	}


	enum class Month {
		jan, feb, mar, apr, may, june, july, aug, sept, oct, nov, dec
	};

	
	const vector<string> months = 
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	ostream& operator<<(ostream& os, Month m){
		return os << months[int(m)];
	}
	
	ostream& operator<<(ostream& os, Year y){
		return os << y.year();
	}

	Month operator++(Month& m)
	{
		m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
		return m;
	}

	
	class Date {
		Year year;
		Month month;
		int day;
	public:
		class Invalid {};
		Date(): year(Year{2001}), month(Month::jan), day(1) {}
		Date(Year y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }
		bool is_valid();
		void add_day(int n);
		Year get_year() const { return year; }
		Month get_month() const { return month; }
		int get_day() const { return day; }
	};

	bool Date::is_valid()
	{
		if (day < 1 || day > 31) return false;
		return true;
	}

	void Date::add_day(int n)
	{
		day += n;
		if (day > 31) 
		{
			++month;
			day -= 31;
			if (month == Month::jan)
			{
				++year;
			}
		}
	}
} // End namespace

ostream& operator<<(ostream& os, const UDChrono::Date& d){
		return os << d.get_year()<<". "<<d.get_month()<<" "<<d.get_day()<<".";
	}

int main()
try {
	
	using namespace UDChrono;

	Date today {Year{1978}, Month::june, 25};
    Date tomorrow = today;
    tomorrow.add_day(1);

	cout << "Date: " <<today<< "\n";

	cout << "Date: " <<tomorrow<< "\n";

	return 0;

} catch (UDChrono::Date::Invalid) {
	cout << "Error: Invalid date\n";
	return 1; 
} catch (UDChrono::Year::Invalid) {
	cout << "Error: Invalid year\n";
	return 2; 
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 3;
}