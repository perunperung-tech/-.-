# План тестирования

Приложение: подсчёт среднего балла и максимальной оценки.
Тесты написаны в проекте `App.Tests` (Microsoft Unit Tests). Каждый тест готовит свои данные сам, порядок запуска не важен. Имя теста: Модуль_Функция_Сценарий_Результат.

## Модуль input

| № | Функция | Сценарий | Входные данные | Ожидаемый результат | Тип | Тест |
|---|---------|----------|----------------|---------------------|-----|------|
| 1 | parseNumber | Корректный ввод | "42" | 42 | Позитивный | Input_ParseNumber_CorrectNumber_ReturnsNumber |
| 2 | parseNumber | Отрицательное число | "-7" | -7 | Позитивный | Input_ParseNumber_NegativeNumber_ReturnsNegative |
| 3 | parseNumber | Ноль | "0" | 0 | Граничный | Input_ParseNumber_Zero_ReturnsZero |
| 4 | parseNumber | Максимальный int | "2147483647" | 2147483647 | Граничный | Input_ParseNumber_MaxInt_ReturnsMaxInt |
| 5 | parseNumber | Пустая строка | "" | исключение invalid_argument | Граничный | Input_ParseNumber_EmptyString_Throws |
| 6 | parseNumber | Ошибочный ввод (буквы) | "abc" | исключение invalid_argument | Негативный | Input_ParseNumber_Letters_Throws |
| 7 | parseNumber | Число с буквами | "12abc" | исключение invalid_argument | Негативный | Input_ParseNumber_NumberWithLetters_Throws |
| 8 | parseNumber | Слишком большое число | "99999999999" | исключение invalid_argument | Негативный | Input_ParseNumber_TooBigNumber_Throws |
| 9 | parseNumber | Только минус | "-" | исключение invalid_argument | Негативный | Input_ParseNumber_OnlyMinus_Throws |
| 10 | isValidGrade | Корректная оценка | 4 | true | Позитивный | Input_IsValidGrade_Four_ReturnsTrue |
| 11 | isValidGrade | Нижняя граница | 2 | true | Граничный | Input_IsValidGrade_Two_ReturnsTrue |
| 12 | isValidGrade | Верхняя граница | 5 | true | Граничный | Input_IsValidGrade_Five_ReturnsTrue |
| 13 | isValidGrade | Меньше допустимого | 1 | false | Негативный | Input_IsValidGrade_One_ReturnsFalse |
| 14 | isValidGrade | Больше допустимого | 6 | false | Негативный | Input_IsValidGrade_Six_ReturnsFalse |

Функция readGrades читает данные с клавиатуры, поэтому модульными тестами не покрывается, её проверяют запуском приложения вручную. Внутри она использует parseNumber и isValidGrade, которые покрыты тестами.

## Модуль calculation

| № | Функция | Сценарий | Входные данные | Ожидаемый результат | Тип | Тест |
|---|---------|----------|----------------|---------------------|-----|------|
| 15 | sum | Корректный ввод | {2, 3, 4} | 9 | Позитивный | Calculation_Sum_ThreeNumbers_ReturnsSum |
| 16 | sum | Пустой вектор | {} | 0 | Граничный | Calculation_Sum_EmptyVector_ReturnsZero |
| 17 | sum | Один элемент | {5} | 5 | Граничный | Calculation_Sum_OneElement_ReturnsElement |
| 18 | average | Корректный ввод | {4, 5, 4, 5} | 4.5 | Позитивный | Calculation_Average_FourGrades_ReturnsAverage |
| 19 | average | Один элемент | {3} | 3.0 | Граничный | Calculation_Average_OneElement_ReturnsElement |
| 20 | average | Пустой вектор | {} | исключение invalid_argument | Негативный | Calculation_Average_EmptyVector_Throws |
| 21 | maxValue | Корректный ввод | {3, 5, 4} | 5 | Позитивный | Calculation_MaxValue_ThreeGrades_ReturnsMax |
| 22 | maxValue | Один элемент | {2} | 2 | Граничный | Calculation_MaxValue_OneElement_ReturnsElement |
| 23 | maxValue | Все элементы равны | {4, 4, 4} | 4 | Граничный | Calculation_MaxValue_AllSame_ReturnsThatValue |
| 24 | maxValue | Пустой вектор | {} | исключение invalid_argument | Негативный | Calculation_MaxValue_EmptyVector_Throws |

Для sum негативного теста нет, потому что у функции нет ошибочных условий (пустой вектор для неё нормальный случай, результат 0).

## Модуль output

| № | Функция | Сценарий | Входные данные | Ожидаемый результат | Тип | Тест |
|---|---------|----------|----------------|---------------------|-----|------|
| 25 | formatAverage | Корректный ввод | 4.5 | "Average: 4.50" | Позитивный | Output_FormatAverage_NormalValue_ReturnsText |
| 26 | formatAverage | Нужно округление | 4.666 | "Average: 4.67" | Позитивный | Output_FormatAverage_NeedsRounding_ReturnsRounded |
| 27 | formatAverage | Ноль | 0 | "Average: 0.00" | Граничный | Output_FormatAverage_Zero_ReturnsZeroText |
| 28 | formatAverage | Отрицательное значение | -1 | исключение invalid_argument | Негативный | Output_FormatAverage_NegativeValue_Throws |
| 29 | formatMax | Корректный ввод | 5 | "Max grade: 5" | Позитивный | Output_FormatMax_NormalValue_ReturnsText |
| 30 | formatMax | Ноль | 0 | "Max grade: 0" | Граничный | Output_FormatMax_Zero_ReturnsZeroText |
| 31 | formatMax | Отрицательное значение | -1 | исключение invalid_argument | Негативный | Output_FormatMax_NegativeValue_Throws |

Всего 31 сценарий, на каждый есть тест.
