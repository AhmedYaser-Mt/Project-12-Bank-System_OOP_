#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include "clsString.h"
#include<ctime>
#include<vector>
#include<string>
using namespace std;

class clsDate
{
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);

		_Day = Now->tm_mday;
		_Month = Now->tm_mon + 1;
		_Year = Now->tm_year + 1900;
	}

	clsDate(string DateString)
	{
		vector <string> vDate = clsString::Split(DateString, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short day, short month, short year)
	{
		_Day = day;
		_Month = month;
		_Year = year;
	}

	clsDate(short DaysFrombeginingOfYear, short year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DaysFrombeginingOfYear, year);

		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
	}

	void SetDay(short day)
	{
		_Day = day;
	}

	void SetMonth(short month)
	{
		_Month = month;
	}

	void SetYear(short year)
	{
		_Year = year;
	}

	short GetDay()
	{
		return _Day;
	}

	short GetMonth()
	{
		return _Month;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetDay, put = SetDay)) short _Day;
	__declspec(property(get = GetMonth, put = SetMonth)) short _Month;
	__declspec(property(get = GetYear, put = SetYear)) short _Year;

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);
		short Day, Month, Year;

		Day = Now->tm_mday;
		Month = Now->tm_mon + 1;
		Year = Now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}

	static clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate = clsString::Split(DateString, "/");

		Date._Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);

		return Date;
	}

	static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{
		clsDate Date;

		short RemainnigDays = DayOrderInYear;
		short MonthDays = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Year, Date._Month);

			if (RemainnigDays > MonthDays)
			{
				RemainnigDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainnigDays;
				break;
			}
		}

		return Date;
	}

	clsDate GetDateFromDayOrderInYear(short DayOrderInYear)
	{
		return GetDateFromDayOrderInYear(DayOrderInYear, _Year);
	}

	static short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (NumberOfDays[Month - 1]);
	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}

	static bool IsLeapYear(short Year)
	{
		return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + '/' + to_string(Date._Month) + '/' + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	void Print()
	{
		cout << DateToString() << "\n";
	}

	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}

	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}

	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}

	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}

	static short ReadYear()
	{
		short Year;
		cout << "Please Enter a Year ? ";
		cin >> Year;
		return Year;
	}

	static short ReadMonth()
	{
		short Month;
		cout << "\nPlease Enter a Month ? ";
		cin >> Month;
		return Month;
	}

	static short ReadDay()
	{
		short Day;
		cout << "\nPlease Enter a Day ? ";
		cin >> Day;
		return Day;
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short A = (14 - Month) / 12;

		short Y = Year - A;

		short M = Month + 12 * A - 2;

		return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", };

		return arrDayNames[DayOfWeekOrder];
	}

	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return Months[MonthNumber - 1];
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Year, short Month)
	{
		short NumberOfDays = NumberOfDaysInAMonth(Year, Month);

		short Current = DayOfWeekOrder(1, Month, Year);

		printf("\n  _______________%s________________\n", MonthShortName(Month).c_str());
		printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;

		for (i = 0;i < Current;i++)
			printf("     ");

		for (short j = 1;j <= NumberOfDays;j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  __________________________________\n");
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Year, _Month);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n  __________________________________\n");
		printf("\n          Calendar - %d", Year);
		printf("\n  __________________________________\n");

		for (short i = 1;i <= 12;i++)
		{
			PrintMonthCalendar(Year, i);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1;i < Month;i++)
		{
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}

		TotalDays += Day;

		return TotalDays;
	}

	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}

	static clsDate AddDaysToDate(short Days, clsDate Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._Month, Date._Year);
		short MonthDays = 0;

		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	clsDate AddDays(short Days)
	{
		return AddDaysToDate(Days, *this);
	}

	static clsDate ReadFullDate()
	{
		clsDate Date;

		Date._Day = ReadDay();
		Date._Month = ReadMonth();
		Date._Year = ReadYear();

		return Date;
	}

	static bool IsDate1BeforeDate2(clsDate& Date1, clsDate& Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? ((Date1._Month < Date2._Month) ? true : (Date1._Month == Date2._Month) ? (Date1._Day < Date2._Day) : false) : false);
	}

	bool IsDateBeforeDate2(clsDate& Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualToDate2(clsDate& Date1, clsDate& Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDateEqualToDate2(clsDate& Date2)
	{
		return IsDate1EqualToDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate& Date1)
	{
		return (Date1._Day == NumberOfDaysInAMonth(Date1._Year, Date1._Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Year);
	}

	static clsDate IncreaseDateByOneDay(clsDate & Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	void AddOneDay()
	{
		IncreaseDateByOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	void SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}


		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static clsDate IncreaseDateByXDays(clsDate &Date, short NumberOfDays)
	{
		for (short i = 1;i <= NumberOfDays;i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByXDays(short NumberOfDays)
	{
		 IncreaseDateByXDays(*this, NumberOfDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate &Date)
	{
		Date = IncreaseDateByXDays(Date, 7);

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		 IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate &Date, short NumberOfWeeks)
	{
		for (short i = 1;i <= NumberOfWeeks;i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByXWeeks(short NumberOfWeeks)
	{
		 IncreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate &Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);

		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		 IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate &Date, short NumberOfMonths)
	{
		for (short i = 1;i <= NumberOfMonths;i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByXMonths(short NumberOfMonths)
	{
		 IncreaseDateByXMonths(*this, NumberOfMonths);
	}

	static clsDate IncreaseDateByOneYear(clsDate &Date)
	{
		Date._Year++;

		return Date;
	}

	void IncreaseDateByOneYear()
	{
		 IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate &Date, short NumberOfYears)
	{
		Date._Year += NumberOfYears;

		return Date;
	}

	void IncreaseDateByXYears(short NumberOfYears)
	{
		 IncreaseDateByXYears(*this, NumberOfYears);
	}

	static clsDate IncreaseDateByOneDecade(clsDate &Date)
	{
		Date._Year += 10;

		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		 IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate &Date, short NumberOfDecades)
	{
		Date._Year += (NumberOfDecades * 10);

		return Date;
	}

	void IncreaseDateByXDecades(short NumberOfDecades)
	{
		 IncreaseDateByXDecades(*this, NumberOfDecades);
	}

	static clsDate IncreaseDateByOneCentury(clsDate &Date)
	{
		Date._Year += 100;

		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		 IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate &Date)
	{
		Date._Year += 1000;

		return Date;
	}

	void IncreaseDateByOneMillennium() 
	{
		 IncreaseDateByOneMillennium(*this);
	}

	static bool IsFirstDayInMonth(short Day)
	{
		return (Day == 1);
	}

	bool IsFirstDayInMonth()
	{
		return IsFirstDayInMonth(_Day);
	}

	static bool IsFirstMonthInYear(short Month)
	{
		return (Month == 1);
	}

	bool IsFirstMonthInYear()
	{
		return IsFirstMonthInYear(_Month);
	}

	static clsDate DecreaseDateByOneDay(clsDate &Date)
	{
		if (IsFirstDayInMonth(Date._Day))
		{
			if (IsFirstMonthInYear(Date._Month))
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		 DecreaseDateByOneDay(*this);
	}
	
	static clsDate DecreaseDateByXDays(clsDate &Date, short NumberOfDays)
	{
		for (short i = 1;i <= NumberOfDays;i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDays(short NumberOfDays)
	{
		 DecreaseDateByXDays(*this, NumberOfDays);
	}
	
	static clsDate DecreaseDateByOneWeek(clsDate &Date)
	{
		Date = DecreaseDateByXDays(Date, 7);

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		 DecreaseDateByOneWeek(*this);
	}
	
	static clsDate DecreaseDateByXWeeks(clsDate &Date, short NumberOfWeeks)
	{
		for (short i = 1;i <= NumberOfWeeks;i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByXWeeks(short NumberOfWeeks)
	{
		 DecreaseDateByXWeeks(*this, NumberOfWeeks);
	}
	
	static clsDate DecreaseDateByOneMonth(clsDate &Date)
	{
		if (IsFirstMonthInYear(Date._Month))
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);

		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		 DecreaseDateByOneMonth(*this);
	}
	
	static clsDate DecreaseDateByXMonths(clsDate &Date, short NumberOfMonths)
	{
		for (short i = 1;i <= NumberOfMonths;i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByXMonths(short NumberOfMonths)
	{
		 DecreaseDateByXMonths(*this, NumberOfMonths);
	}
	
	static clsDate DecreaseDateByOneYear(clsDate &Date)
	{
		Date._Year--;

		return Date;
	}

	void DecreaseDateByOneYear()
	{
		 DecreaseDateByOneYear(*this);
	}
	
	static clsDate DecreaseDateByXYears(clsDate &Date, short NumberOfYears)
	{
		Date._Year -= NumberOfYears;

		return Date;
	}

	void DecreaseDateByXYears(short NumberOfYears)
	{
		 DecreaseDateByXYears(*this, NumberOfYears);
	}
	
	static clsDate DecreaseDateByOneDecade(clsDate &Date)
	{
		Date._Year -= 10;

		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		 DecreaseDateByOneDecade(*this);
	}
	
	static clsDate DecreaseDateByXDecades (clsDate &Date, short NumberOfDecades)
	{
		Date._Year -= (NumberOfDecades * 10);

		return Date;
	}

	void DecreaseDateByXDecades(short NumberOfDecades)
	{
		 DecreaseDateByXDecades(*this, NumberOfDecades);
	}
	
	static clsDate DecreaseDateByOneCentury(clsDate &Date)
	{
		Date._Year -= 100;

		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		 DecreaseDateByOneCentury(*this);
	}
	
	static clsDate DecreaseDateByOneMillennium(clsDate &Date)
	{
		Date._Year -= 1000;

		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		 DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOfWeekOrder(Date) == 6);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}
	 
	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}
	 
	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}
	 
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return (6 - DayOfWeekOrder(Date));
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
	 
	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}
	 
	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;

		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return Days;
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		short WeekEndCounter = 0;

		for (short i = 1;i <= VacationDays + WeekEndCounter;i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate& Date1, clsDate& Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
	}

	bool IsDateAfterDate2(clsDate& Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate& Date1, clsDate& Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		else if (IsDate1EqualToDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate& Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date._Day < 1 || Date._Day > 31)
			return false;

		if (Date._Month < 1 || Date._Month > 12)
			return false;

		if (Date._Month == 2)
		{
			if (IsLeapYear(Date._Year))
			{
				if (Date._Day > 29)
					return false;
			}
			else
			{
				if (Date._Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);

		if (Date._Day > DaysInMonth)
			return false;

		return true;
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string ReadDateString(string Message)
	{
		string DateString;
		cout << Message;
		getline(cin >> ws, DateString);
		return DateString;
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, GetSystemDate());
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);

		short Year, Month, Day, Hour, Minute, Second;

		Year = Now->tm_year + 1900;
		Month = Now->tm_mon + 1;
		Day = Now->tm_mday;
		Hour = Now->tm_hour;
		Minute = Now->tm_min;
		Second = Now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
	}
};


