# Многофайловый C++ проект и модульное тестирование

Практическая работа по C++. Консольное приложение считает средний балл и максимальную оценку по введённым оценкам (от 2 до 5). Приложение разделено на модули, для них сделан отдельный проект с модульными тестами (Microsoft Unit Tests).

Видео, которые я смотрел перед выполнением:
- Создание многофайловых проектов: https://youtu.be/eRdvAk-Li2c
- Создание проектов тестирования: https://youtu.be/T5xEkLQgZQA

## Требования

- Windows
- Visual Studio 2022 с компонентом "Разработка классических приложений на C++"

## Структура

```
App.sln              решение (два проекта)
App/                 приложение
  main.cpp           только запуск: ввод, вызов модулей, вывод
  include/           заголовочные файлы (объявления)
    input.h
    calculation.h
    output.h
  src/               реализация
    input.cpp
    calculation.cpp
    output.cpp
App.Tests/           проект Microsoft Unit Tests
  InputTests.cpp
  CalculationTests.cpp
  OutputTests.cpp
docs/test-plan.md    план тестирования
```

Модули:
- input - ввод и проверка данных (parseNumber, isValidGrade, readGrades)
- calculation - вычисления (sum, average, maxValue)
- output - форматирование результата (formatAverage, formatMax)

## Как собрать и запустить приложение

1. Открыть файл `App.sln` в Visual Studio.
2. Справа в Solution Explorer нажать правой кнопкой на проект `App` и выбрать "Set as Startup Project".
3. Выбрать конфигурацию Debug и платформу x64.
4. Меню Build - Build Solution (Ctrl+Shift+B).
5. Запустить Ctrl+F5, вводить оценки по одной в строке, пустая строка - конец ввода.

Пример:

```
Enter grades (2-5), one per line. Empty line - finish.
5
4
5

Average: 4.67
Max grade: 5
```

## Как запустить тесты

1. Открыть `App.sln` и собрать решение (Build - Build Solution), платформа x64.
2. Меню Test - Test Explorer.
3. Нажать "Run All Tests".

Тестовый проект `App.Tests` не использует `main.cpp`, он подключает файлы из `App/src` и заголовки из `App/include` и вызывает функции модулей напрямую.

## Результаты запуска тестов

Всего тестов: 31 (InputTests - 14, CalculationTests - 10, OutputTests - 7).

Результат в Test Explorer: пройдено 31 из 31, ошибок сборки и предупреждений нет.

Соответствие тестов сценариям из плана смотри в `docs/test-plan.md`.
