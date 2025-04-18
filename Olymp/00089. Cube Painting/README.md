# Фарбування кубиків
> [e-olymp](https://www.eolymp.com/uk/problems/89)

## Постановка задачі
Сара познайомилась з новою грою, що була подібною до Іграшки-конструктора, яку їй було подаровано на день народження. Ця гра називається Безмежна Уява (БУ). Вона містить силу-силенну однакових кубиків таких, що кожна їхня грань має площу 1 см^2. Дана гра (БУ) має спеціальну властивість таку, що можна з'єднати два кубики разом грань до грані за допомогою спеціального клею, якщо ці грані точно підігнані одна до одної. Старший брат Сари Даріус вирішив розробити задачу для Сари з використанням БУ. Він побудував тривимірний об'єкт, використовуючи ці кубики і хоче, щоб Сара пофарбувала усі грані кубиків, які не є зв'язаними. Вважається, що грань є не зв'язаною, якщо вона не з'єднується з іншим кубиком. Наприклад, уявіть об'єкт подібний до зображеного на малюнку.

У наведеному прикладі, кількість всіх не зв'язаних граней складає 16. Проблема в наступному - знайти число, що показує площу, яку повинна пофарбувати Сара.
### Вхідні дані
Перший рядок містить кількість тестів. Кожен тест починається з рядка, що містить кількість кубиків n (1 ≤ n ≤ 200). Кубики пронумеровані числами від 1 до n.

Наступні n рядків описують утворення нових об'єктів: дані про зв'язування кожного кубика надаються в одному рядку. Кожен з цих рядків починається з цілого числа І, яке є номером кубика, після чого йде символ двокрапки ":" і пропуск, за якими слідують декілька цілих чисел (не більше шести), які є номерами кубиків, з'єднаних з кубиком І, і завершується єдиним нульовим символом "0", що вказує на кінець цієї множини.

Гарантується, що дані для кожного теста можуть реалізувати дійсний об'єкт в просторі. Важливим є також те, що кубики можуть сконструювати будь-який складний об'єкт або навіть декілька малих відокремлених об'єктів.
### Вихідні дані
Для кожного темту вивести в окремому рядку кількість незв'язаних граней для усіх кубиків.
## Приклад

### Вхідні дані #1
```
3
4
1: 2 3 0
2: 1 4 0
3: 4 1 0
4: 2 3 0
3
1: 2 0
2: 3 1 0
3: 2 0
4
1: 2 0
2: 1 0
3: 4 0
4: 3 0
```
### Вихідні дані#1
```
16
14
20
```