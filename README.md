В этом файле описаны все программы репозитория

---Лабораторная работа №1---
~~~Вариант 23~~~

Реализована функция для игры в города.
На вход функции передаётся массив названных ранее городов (в порядке их использования в игре). В
качестве результата возвращается город, начинающийся на последнюю букву последнего названного города и
которого ещё нет в массиве. Если городов на последнюю букву не бывает — используется
предпоследняя буква. Если подходящих городов больше не осталось, переданные названия городов
содержат недопустимый символ или массив городов пустой, возвращается ошибка. Список всех известных
городов размещён во внешнем файле.
Для успешного запуска приложения необходимо собрать файлы исходного кода с помощью CMake. Необходимые настройки CMake прописаны в соответствующем файле. Далее требуется запустить файл main.exe.
Минимальная версия CMake 3.16
Стандарт языка: C++20

Лабораторная работа №2 