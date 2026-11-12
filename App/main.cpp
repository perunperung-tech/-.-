#include <iostream>
#include <vector>
#include "input.h"
#include "calculation.h"
#include "output.h"

int main()
{
    std::vector<int> grades = readGrades();

    if (grades.empty())
    {
        std::cout << "No grades entered" << std::endl;
        return 0;
    }

    double avg = average(grades);
    int maxGrade = maxValue(grades);

    std::cout << formatAverage(avg) << std::endl;
    std::cout << formatMax(maxGrade) << std::endl;

    return 0;
}
