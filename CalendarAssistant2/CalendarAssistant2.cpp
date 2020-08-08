#include "pch.h"

using namespace System;

int GetYear();
int GetMonth();
int GetDay(int year, int month);
void DisplayDate(int year, int month, int day);

int main(array<System::String ^> ^args)
{
    Console::WriteLine("Welcome to  your calendar assistant");

    int count = 1; // Decalare and initialise the loop counter
    while (count <= 5) // Test the loop counter
    {
        Console::Write("\nPlease enter a date ");

        Console::WriteLine(count);

        int year = GetYear();
        int month = GetMonth();
        int day = GetDay(year, month);
        DisplayDate(year, month, day);

        count++; // Increment the loop counter
    }

    return 0;
}

int GetYear()
{
Console::Write("Year? ");
String^ input = Console::ReadLine();
int year = Convert::ToInt32(input);
return year;
}

int GetMonth()
{
    Console::Write("Month?");
    String^ input = Console::ReadLine();
    int month = Convert::ToInt32(input);
    return month;
}

int GetDay(int year, int month)
{
    int maxDay;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        maxDay = 30;
    }
    else if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear)
        {
            maxDay = 29;
        }
        else 
        {
            maxDay = 28;
        }
            
    }
    else
    {
        maxDay = 31;
    }
    Console::Write("Day [1 to ");
    Console::Write(maxDay);
    Console::Write("]? ");

    String^ input = Console::ReadLine();
    int day = Convert::ToInt32(input);
    return day;
}

void DisplayDate(int year, int month, int day)
{
    Console::WriteLine("\nThis is the date you entered: ");
    Console::Write(year);
    Console::Write("-");
    
    switch (month)
    {
    case 1:
        Console::Write("January");
        break;
    case 2:
        Console::Write("February");
        break;
    case 3:
        Console::Write("March");
        break;
    case 4:
        Console::Write("April");
        break;
    case 5:
        Console::Write("May");
        break;
    case 6:
        Console::Write("June");
        break;
    case 7:
        Console::Write("July");
        break;
    case 8:
        Console::Write("August");
        break;
    case 9:
        Console::Write("September");
        break;
    case 10:
        Console::Write("October");
        break;
    case 11:
        Console::Write("November");
        break;
    case 12:
        Console::Write("December");
        break;
    default:
        Console::Write("Unknown");
        break;

    }

    Console::Write("-");
    Console::Write(day);

    switch (month)
    {
    case 12:
    case 1:
    case 2:
        Console::WriteLine("[Winter]"); break;
    case 3:
    case 4:
    case 5:
        Console::WriteLine("[Spring]"); break;
    case 6:
    case 7:
    case 8:
        Console::WriteLine("[Summer]"); break;
    case 9:
    case 10:
    case 11:
        Console::WriteLine("[fall]"); break;
    }

    Console::WriteLine();
}