#include "CppUnitTest.h"
#include "calculation.h"
#include <vector>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AppTests
{
    TEST_CLASS(CalculationTests)
    {
    public:

        // sum

        TEST_METHOD(Calculation_Sum_ThreeNumbers_ReturnsSum)
        {
            std::vector<int> values = { 2, 3, 4 };
            Logger::WriteMessage(L"sum: 2 3 4");
            Assert::AreEqual(9, sum(values));
        }

        TEST_METHOD(Calculation_Sum_EmptyVector_ReturnsZero)
        {
            std::vector<int> values;
            Logger::WriteMessage(L"sum: пустой вектор");
            Assert::AreEqual(0, sum(values));
        }

        TEST_METHOD(Calculation_Sum_OneElement_ReturnsElement)
        {
            std::vector<int> values = { 5 };
            Logger::WriteMessage(L"sum: 5");
            Assert::AreEqual(5, sum(values));
        }

        // average

        TEST_METHOD(Calculation_Average_FourGrades_ReturnsAverage)
        {
            std::vector<int> values = { 4, 5, 4, 5 };
            Logger::WriteMessage(L"average: 4 5 4 5");
            Assert::AreEqual(4.5, average(values), 0.0001);
        }

        TEST_METHOD(Calculation_Average_OneElement_ReturnsElement)
        {
            std::vector<int> values = { 3 };
            Logger::WriteMessage(L"average: 3");
            Assert::AreEqual(3.0, average(values), 0.0001);
        }

        TEST_METHOD(Calculation_Average_EmptyVector_Throws)
        {
            Logger::WriteMessage(L"average: пустой вектор");
            Assert::ExpectException<std::invalid_argument>([] {
                std::vector<int> values;
                average(values);
            });
        }

        // maxValue

        TEST_METHOD(Calculation_MaxValue_ThreeGrades_ReturnsMax)
        {
            std::vector<int> values = { 3, 5, 4 };
            Logger::WriteMessage(L"maxValue: 3 5 4");
            Assert::AreEqual(5, maxValue(values));
        }

        TEST_METHOD(Calculation_MaxValue_OneElement_ReturnsElement)
        {
            std::vector<int> values = { 2 };
            Logger::WriteMessage(L"maxValue: 2");
            Assert::AreEqual(2, maxValue(values));
        }

        TEST_METHOD(Calculation_MaxValue_AllSame_ReturnsThatValue)
        {
            std::vector<int> values = { 4, 4, 4 };
            Logger::WriteMessage(L"maxValue: 4 4 4");
            Assert::AreEqual(4, maxValue(values));
        }

        TEST_METHOD(Calculation_MaxValue_EmptyVector_Throws)
        {
            Logger::WriteMessage(L"maxValue: пустой вектор");
            Assert::ExpectException<std::invalid_argument>([] {
                std::vector<int> values;
                maxValue(values);
            });
        }
    };
}
