#include "input.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

int parseNumber(const std::string& text)
{
    if (text.empty())
        throw std::invalid_argument("empty string");

    size_t start = 0;
    if (text[0] == '-')
        start = 1;

    if (start == text.size())
        throw std::invalid_argument("no digits");

    for (size_t i = start; i < text.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(text[i])))
            throw std::invalid_argument("not a number");
    }

    try
    {
        return std::stoi(text);
    }
    catch (const std::out_of_range&)
    {
        throw std::invalid_argument("number is too big");
    }
}

bool isValidGrade(int grade)
{
    return grade >= 2 && grade <= 5;
}

std::vector<int> readGrades()
{
    std::vector<int> grades;
    std::string line;

    std::cout << "Enter grades (2-5), one per line. Empty line - finish." << std::endl;

    while (true)
    {
        std::getline(std::cin, line);
        if (line.empty())
            break;

        try
        {
            int grade = parseNumber(line);
            if (!isValidGrade(grade))
            {
                std::cout << "Grade must be from 2 to 5" << std::endl;
                continue;
            }
            grades.push_back(grade);
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "This is not a number, try again" << std::endl;
        }
    }

    return grades;
}
