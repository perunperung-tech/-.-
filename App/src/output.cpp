#include "output.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

std::string formatAverage(double value)
{
    if (value < 0)
        throw std::invalid_argument("value is negative");

    std::ostringstream out;
    out << "Average: " << std::fixed << std::setprecision(2) << value;
    return out.str();
}

std::string formatMax(int value)
{
    if (value < 0)
        throw std::invalid_argument("value is negative");

    return "Max grade: " + std::to_string(value);
}
