# Flee2Elephant
Приложение Flee2Elephant решает следующую задачу.

Дано исходное и конечное слово равной длины. Длина исходных слов не ограничена.
Необходимо составить цепочку слов от исходного слова до конечного. Каждое следующее
слово в цепочке может отличаться от предыдущего только одной буквой. Исходное,
конечное и все промежуточные слова должны состоять из одинакового количества букв.
Все используемые слова обязательно должны содержаться в заранее определенном словаре.

На вход в программу подается:

1. Путь к текстовому файлу, в котором указано начальное и конечное слово. На первой
строке указано начальное слово, на второй строке конечное

2. Путь к файлу, который содержит словарь. Слова в словаре указаны по одному на каждой
строке. В словаре слова могут быть разной длины.

На выходе программа выводит в консоль путь от исходного слова к конечному, по одному слову на одной строке.



Сборка:
$make all

Запуск тестов:
$make test

Запуск приложения:
./f2e words dict



Замечания и ограничения:

- для упрощения приложение не использует аллокаторы для узлов дерева и строк слов
- для упрощения приложение работает только с английским алфавитом
- в качестве алгоритма поиска цепочки слов выбрано построение дерева одновременно с обходом его в ширину. В вершине дерева - искомое слово. Каждый последующий уровень дерева поиска заполняется словами, отличающимися на одну букву от слова-предка. Одновременно с построением дерева происходит поиск заданного слова. Если слово найдено, проход от найденного слова до вершины дерева по узлам parent даст искомую цепочку.
- второй вариант решения этой задачи (не реализовано) - строить граф, в вершинах которого слова словаря. Слова соединены дугой графа, если они отличаются на одну букву. После построения графа производится обход графа в ширину от вершины с исходным словом до нахождения вершины искомого. Это решение больше подходит для случаев, когда необходимо производить многократный поиск цепочек, т.к. основная сложность алгоритма - построение графа словаря - O(n*n), где n - количество слов словаря.
