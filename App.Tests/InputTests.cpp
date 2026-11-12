#include "CppUnitTest.h"
#include "input.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AppTests
{
    TEST_CLASS(InputTests)
    {
    public:

        // parseNumber

        TEST_METHOD(Input_ParseNumber_CorrectNumber_ReturnsNumber)
        {
            Logger::WriteMessage(L"parseNumber: 42");
            int result = parseNumber("42");
            Assert::AreEqual(42, result);
        }

        TEST_METHOD(Input_ParseNumber_NegativeNumber_ReturnsNegative)
        {
            Logger::WriteMessage(L"parseNumber: -7");
            int result = parseNumber("-7");
            Assert::AreEqual(-7, result);
        }

        TEST_METHOD(Input_ParseNumber_Zero_ReturnsZero)
        {
            Logger::WriteMessage(L"parseNumber: 0");
            int result = parseNumber("0");
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Input_ParseNumber_MaxInt_ReturnsMaxInt)
        {
            Logger::WriteMessage(L"parseNumber: 2147483647");
            int result = parseNumber("2147483647");
            Assert::AreEqual(2147483647, result);
        }

        TEST_METHOD(Input_ParseNumber_EmptyString_Throws)
        {
            Logger::WriteMessage(L"parseNumber: пустая строка");
            Assert::ExpectException<std::invalid_argument>([] { parseNumber(""); });
        }

        TEST_METHOD(Input_ParseNumber_Letters_Throws)
        {
            Logger::WriteMessage(L"parseNumber: abc");
            Assert::ExpectException<std::invalid_argument>([] { parseNumber("abc"); });
        }

        TEST_METHOD(Input_ParseNumber_NumberWithLetters_Throws)
        {
            Logger::WriteMessage(L"parseNumber: 12abc");
            Assert::ExpectException<std::invalid_argument>([] { parseNumber("12abc"); });
        }

        TEST_METHOD(Input_ParseNumber_TooBigNumber_Throws)
        {
            Logger::WriteMessage(L"parseNumber: 99999999999");
            Assert::ExpectException<std::invalid_argument>([] { parseNumber("99999999999"); });
        }

        TEST_METHOD(Input_ParseNumber_OnlyMinus_Throws)
        {
            Logger::WriteMessage(L"parseNumber: -");
            Assert::ExpectException<std::invalid_argument>([] { parseNumber("-"); });
        }

        // isValidGrade

        TEST_METHOD(Input_IsValidGrade_Four_ReturnsTrue)
        {
            Logger::WriteMessage(L"isValidGrade: 4");
            Assert::IsTrue(isValidGrade(4));
        }

        TEST_METHOD(Input_IsValidGrade_Two_ReturnsTrue)
        {
            Logger::WriteMessage(L"isValidGrade: 2");
            Assert::IsTrue(isValidGrade(2));
        }

        TEST_METHOD(Input_IsValidGrade_Five_ReturnsTrue)
        {
            Logger::WriteMessage(L"isValidGrade: 5");
            Assert::IsTrue(isValidGrade(5));
        }

        TEST_METHOD(Input_IsValidGrade_One_ReturnsFalse)
        {
            Logger::WriteMessage(L"isValidGrade: 1");
            Assert::IsFalse(isValidGrade(1));
        }

        TEST_METHOD(Input_IsValidGrade_Six_ReturnsFalse)
        {
            Logger::WriteMessage(L"isValidGrade: 6");
            Assert::IsFalse(isValidGrade(6));
        }
    };
}
