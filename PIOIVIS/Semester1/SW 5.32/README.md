# Представление и обработка информации в интеллектуальных системах: расчетная работа

**Задача**: поиск подграфов в графе, изоморфных графу-образцу (5.32)<br>
**Важно**: Исполняемый файл скомпилирован для GNU/Linux и требует GLIBC 2.34

## Структура
- В папке tasks хранятся текстовые файлы, содержащие в себе матрицы связности для исходного графа и графа-образца
- В папке orig после запуска программы будут хранится текстовые файлы с записью исходного графа и графа-образца на языке DOT
- В папке results после запуска программы будут хранится текстовые файлы с записью исходного графа на языке DOT, в котором вершины, принадлежащие обнаруженному изоморфному подграфу будут окрашены.

## Принцип работы
#### Алгоритм поиска изоморфных подграфов
Программа ищет все возможные соответствия между вершинами исходного графа и графа-образца при помощи алгоритма поиска размещений. Количество вариантов соответствий рассчитывается по формуле n!/(n-m)!, где n - количество вершин исходного графа, а m - количество вершин графа-образца. После программа строит матрицы связности для всех найденных подграфов с количеством вершин m и сравнивает их с матрицей связности графа-образца. Все подграфы, идентичные графу-образцу хранятся в памяти в виде соответствий между вершинами графа-образца и исходного графа.<br><br>
#### Вывод программы
Программа выводит найденные подграфы в виде исходного графа, записанного на языке DOT, вершины, принадлежащие подграфу окрашиваются в синий цвет.
