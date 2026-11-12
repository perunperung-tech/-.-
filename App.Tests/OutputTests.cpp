#include "CppUnitTest.h"
#include "output.h"
#include <string>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AppTests
{
    TEST_CLASS(OutputTests)
    {
    public:

        // formatAverage

        TEST_METHOD(Output_FormatAverage_NormalValue_ReturnsText)
        {
            Logger::WriteMessage(L"formatAverage: 4.5");
            Assert::AreEqual(std::string("Average: 4.50"), formatAverage(4.5));
        }

        TEST_METHOD(Output_FormatAverage_NeedsRounding_ReturnsRounded)
        {
            Logger::WriteMessage(L"formatAverage: 4.666");
            Assert::AreEqual(std::string("Average: 4.67"), formatAverage(4.666));
        }

        TEST_METHOD(Output_FormatAverage_Zero_ReturnsZeroText)
        {
            Logger::WriteMessage(L"formatAverage: 0");
            Assert::AreEqual(std::string("Average: 0.00"), formatAverage(0));
        }

        TEST_METHOD(Output_FormatAverage_NegativeValue_Throws)
        {
            Logger::WriteMessage(L"formatAverage: -1");
            Assert::ExpectException<std::invalid_argument>([] { formatAverage(-1); });
        }

        // formatMax

        TEST_METHOD(Output_FormatMax_NormalValue_ReturnsText)
        {
            Logger::WriteMessage(L"formatMax: 5");
            Assert::AreEqual(std::string("Max grade: 5"), formatMax(5));
        }

        TEST_METHOD(Output_FormatMax_Zero_ReturnsZeroText)
        {
            Logger::WriteMessage(L"formatMax: 0");
            Assert::AreEqual(std::string("Max grade: 0"), formatMax(0));
        }

        TEST_METHOD(Output_FormatMax_NegativeValue_Throws)
        {
            Logger::WriteMessage(L"formatMax: -1");
            Assert::ExpectException<std::invalid_argument>([] { formatMax(-1); });
        }
    };
}
