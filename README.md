
# Work Report
My name is BingHongNi, and this is my final project for my Data Structures and Analysis course at Pasadena City College, where I will be creating and simulating a SQL using C++.
## Name: <ins> </ins>


## Features:

- Not Implemented:
  - Due to the grader, I did not implement the cases to prevent my program from crashing when there are invalid file's names.

<br><br>

- Implemented:
  - Implemented a SQL database using most of the projects I have done in this class, including Stack and Queue (double linked list), RPN, Shunting Yard, Tokenizer, B+Tree, Map, Multimap, Binary Files, Parser, and Table.

<br><br>

- Partly implemented:
  - Due to the grader, I partly implemented the cases to prevent my program from crashing when there are invalid commands.

<br><br>

- Bugs
  - Known bugs.

<br><br>

# Reflections:

- The hardest part of this project was B+Tree and Table. B+Tree was difficult due to its complex algorithm, so it took me some time to actually understand it. Table was easier but I spent the most time on it than any other projects I have done in this class. Its implementation was pretty straight forward but I could not figure out why I crashed on the grader. I spent hours and hours to debug it. Once I finally figured out, it was due to the Queue's Copy CTOR that I did in CS3A. Don't ever disrespect pointer! It will kill you in your sleep!

# basic_test.cpp output:
<pre>
<br/><br/><br/><br/>


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from SQL_BASIC
[ RUN      ] SQL_BASIC.SQLBasic
>make table employee fields  last,       first,         dep,      salary, year
basic_test: table created.

>make table employee fields  last,       first,         dep,      salary, year
>insert into employee values Blow,       Joe,           CS,       100000, 2018
>insert into employee values Blow,       JoAnn,         Physics,  200000, 2016
>insert into employee values Johnson,    Jack,          HR,       150000, 2014
>insert into employee values Johnson,    "Jimmy",     Chemistry,140000, 2018
>make table student fields  fname,          lname,    major,    age
>insert into student values Flo,            Yao,        Art,    20
>insert into student values Bo,                      Yang,      CS,             28
>insert into student values "Sammuel L.", Jackson,      CS,             40
>insert into student values "Billy",         Jackson,   Math,   27
>insert into student values "Mary Ann",   Davis,        Math,   30



>select * from employee
Table name: employee, records: 4
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018

basic_test: records selected: 0 1 2 3 

>select last, first, age from employee
Table name: _select_table_1, records: 4
                   record                     last                    first                      age
                        0                     Blow                      Joe                     Blow
                        1                     Blow                    JoAnn                     Blow
                        2                  Johnson                     Jack                  Johnson
                        3                  Johnson                    Jimmy                  Johnson

basic_test: records selected: 0 1 2 3 

>select last from employee
Table name: _select_table_2, records: 4
                   record                     last
                        0                     Blow
                        1                     Blow
                        2                  Johnson
                        3                  Johnson

basic_test: records selected: 0 1 2 3 

>select * from employee where last = Johnson
Table name: _select_table_3, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                     Jack                       HR                   150000                     2014
                        1                  Johnson                    Jimmy                Chemistry                   140000                     2018

basic_test: records selected: 2 3 

>select * from employee where last=Blow and major="JoAnn"
Table name: _select_table_4, records: 1
                   record                     last                    first                      dep                   salary                     year

basic_test: records selected: 

>select * from student
Table name: student, records: 5
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                      Art                       20
                        1                       Bo                     Yang                       CS                       28
                        2               Sammuel L.                  Jackson                       CS                       40
                        3                    Billy                  Jackson                     Math                       27
                        4                 Mary Ann                    Davis                     Math                       30

basic_test: records selected: 0 1 2 3 4 

>select * from student where (major=CS or major=Art)
Table name: _select_table_1, records: 3
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                      Art                       20
                        1                       Bo                     Yang                       CS                       28
                        2               Sammuel L.                  Jackson                       CS                       40

basic_test: records selected: 0 1 2 

>select * from student where lname>J
Table name: _select_table_2, records: 4
                   record                    fname                    lname                    major                      age
                        0               Sammuel L.                  Jackson                       CS                       40
                        1                    Billy                  Jackson                     Math                       27
                        2                       Bo                     Yang                       CS                       28
                        3                      Flo                      Yao                      Art                       20

basic_test: records selected: 2 3 1 0 

>select * from student where lname>J and (major=CS or major=Art)
Table name: _select_table_3, records: 3
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                      Art                       20
                        1                       Bo                     Yang                       CS                       28
                        2               Sammuel L.                  Jackson                       CS                       40

basic_test: records selected: 0 1 2 
----- END TEST ----------
[       OK ] SQL_BASIC.SQLBasic (22 ms)
[----------] 1 test from SQL_BASIC (22 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (22 ms total)
[  PASSED  ] 1 test.
</pre>

# batch.txt output:
<pre>
<br/><br/><br/><br/>

>batch: batch.txt

//****************************************************************************
//              CREATE TABLES AND INSERT RECORDS
//****************************************************************************

>Command [0]: make table employee fields  last,                 first,                  dep,            salary,         year
Table name: employee, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [1]: insert into employee values Blow,                 Joe,                    CS,                     100000,         2018
Table name: employee, records: 1
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018

records selected: 0 
>SQL: DONE.



>Command [2]: insert into employee values Blow,                 JoAnn,                  Physics,        200000,         2016
Table name: employee, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016

records selected: 0 1 
>SQL: DONE.



>Command [3]: insert into employee values Johnson,      Jack,                   HR,             150000,         2014
Table name: employee, records: 3
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014

records selected: 0 1 2 
>SQL: DONE.



>Command [4]: insert into employee values Johnson,      "Jimmy",                Chemistry,      140000,         2018
Table name: employee, records: 4
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018

records selected: 0 1 2 3 
>SQL: DONE.



>Command [5]: insert into employee values Yao,          Jimmy,                  Math,           145000,         2014
Table name: employee, records: 5
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014

records selected: 0 1 2 3 4 
>SQL: DONE.



>Command [6]: insert into employee values "Yao",                Flo,                    CS,                     147000,         2012
Table name: employee, records: 6
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012

records selected: 0 1 2 3 4 5 
>SQL: DONE.



>Command [7]: insert into employee values Yang,                 Bo,                     CS,                     160000,         2013
Table name: employee, records: 7
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013

records selected: 0 1 2 3 4 5 6 
>SQL: DONE.



>Command [8]: insert into employee values Jackson,      "Flo",                  Math,           165000,         2017
Table name: employee, records: 8
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017

records selected: 0 1 2 3 4 5 6 7 
>SQL: DONE.



>Command [9]: insert into employee values Jackson,      Bo,                             Chemistry,      130000,         2011
Table name: employee, records: 9
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011

records selected: 0 1 2 3 4 5 6 7 8 
>SQL: DONE.



>Command [10]: insert into employee values "Jackson",   Billy,                  Math,           170000,         2017
Table name: employee, records: 10
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017

records selected: 0 1 2 3 4 5 6 7 8 9 
>SQL: DONE.



>Command [11]: insert into employee values Johnson,     "Mary Ann",     Math,           165000,         2014
Table name: employee, records: 11
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014

records selected: 0 1 2 3 4 5 6 7 8 9 10 
>SQL: DONE.



>Command [12]: insert into employee values Johnson,     "Billy Bob",    Physics,        142000,         2014
Table name: employee, records: 12
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Johnson                Billy Bob                  Physics                   142000                     2014

records selected: 0 1 2 3 4 5 6 7 8 9 10 11 
>SQL: DONE.



>Command [13]: insert into employee values Johnson,     Billy,                  "Phys Ed",      102000,         2014
Table name: employee, records: 13
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Johnson                Billy Bob                  Physics                   142000                     2014
                       12                  Johnson                    Billy                  Phys Ed                   102000                     2014

records selected: 0 1 2 3 4 5 6 7 8 9 10 11 12 
>SQL: DONE.



>Command [14]: insert into employee values "Van Gogh",  Vincent,                Art,            240000,         2015
Table name: employee, records: 14
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Johnson                Billy Bob                  Physics                   142000                     2014
                       12                  Johnson                    Billy                  Phys Ed                   102000                     2014
                       13                 Van Gogh                  Vincent                      Art                   240000                     2015

records selected: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 
>SQL: DONE.



>Command [15]: insert into employee values "Van Gogh",  Vincent,                CS,                     245000,         2015
Table name: employee, records: 15
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Johnson                Billy Bob                  Physics                   142000                     2014
                       12                  Johnson                    Billy                  Phys Ed                   102000                     2014
                       13                 Van Gogh                  Vincent                      Art                   240000                     2015
                       14                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
>SQL: DONE.



>Command [16]: insert into employee values "Van Gogh",  "Jim Bob",              "Phys Ed",      230000,         2010
Table name: employee, records: 16
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Johnson                Billy Bob                  Physics                   142000                     2014
                       12                  Johnson                    Billy                  Phys Ed                   102000                     2014
                       13                 Van Gogh                  Vincent                      Art                   240000                     2015
                       14                 Van Gogh                  Vincent                       CS                   245000                     2015
                       15                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010

records selected: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
>SQL: DONE.



>Command [17]: select * from employee 
Table name: employee, records: 16
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                      Yao                    Jimmy                     Math                   145000                     2014
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                     Yang                       Bo                       CS                   160000                     2013
                        7                  Jackson                      Flo                     Math                   165000                     2017
                        8                  Jackson                       Bo                Chemistry                   130000                     2011
                        9                  Jackson                    Billy                     Math                   170000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Johnson                Billy Bob                  Physics                   142000                     2014
                       12                  Johnson                    Billy                  Phys Ed                   102000                     2014
                       13                 Van Gogh                  Vincent                      Art                   240000                     2015
                       14                 Van Gogh                  Vincent                       CS                   245000                     2015
                       15                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010

records selected: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
>SQL: DONE.



>Command [18]: make table student fields fname, lname, major, age, company
Table name: student, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [19]: insert into student values Flo,                  Yao,            CS,                             20,     Google
Table name: student, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google

records selected: 0 
>SQL: DONE.



>Command [20]: insert into student values Bo,                           Yang,           CS,                             28,             Microsoft
Table name: student, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft

records selected: 0 1 
>SQL: DONE.



>Command [21]: insert into student values "Sammuel L.",         Jackson,        CS,                             40,             Uber
Table name: student, records: 3
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber

records selected: 0 1 2 
>SQL: DONE.



>Command [22]: insert into student values "Flo",                        "Jackson",      Math,                           21,             Google
Table name: student, records: 4
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google

records selected: 0 1 2 3 
>SQL: DONE.



>Command [23]: insert into student values "Greg",                       "Pearson",      Physics,                        20,             Amazon
Table name: student, records: 5
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon

records selected: 0 1 2 3 4 
>SQL: DONE.



>Command [24]: insert into student values "Jim Bob",            Smith,          Math,                           23,             Verizon
Table name: student, records: 6
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon

records selected: 0 1 2 3 4 5 
>SQL: DONE.



>Command [25]: insert into student values Calvin,                       Woo,            Physics,                        22,             Uber
Table name: student, records: 7
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                   Calvin                      Woo                  Physics                       22                     Uber

records selected: 0 1 2 3 4 5 6 
>SQL: DONE.



>Command [26]: insert into student values "Anna Grace",         "Del Rio",      CS,                                     22,             USAF
Table name: student, records: 8
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                   Calvin                      Woo                  Physics                       22                     Uber
                        7               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 0 1 2 3 4 5 6 7 
>SQL: DONE.



>Command [27]: insert into student values "Teresa Mae",         Gowers,         Chemistry,                      22,             Verizon
Table name: student, records: 9
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                   Calvin                      Woo                  Physics                       22                     Uber
                        7               Anna Grace                  Del Rio                       CS                       22                     USAF
                        8               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 0 1 2 3 4 5 6 7 8 
>SQL: DONE.



>Command [28]: insert into student values Alex,                 Smith,          "Gender Studies",       53,             Amazon
Table name: student, records: 10
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                   Calvin                      Woo                  Physics                       22                     Uber
                        7               Anna Grace                  Del Rio                       CS                       22                     USAF
                        8               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        9                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 0 1 2 3 4 5 6 7 8 9 
>SQL: DONE.



>Command [29]: select * from student
Table name: student, records: 10
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                   Calvin                      Woo                  Physics                       22                     Uber
                        7               Anna Grace                  Del Rio                       CS                       22                     USAF
                        8               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        9                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 0 1 2 3 4 5 6 7 8 9 
>SQL: DONE.


//****************************************************************************
//              SIMPLE SELECT:
//****************************************************************************

>Command [30]: select * from student
Table name: student, records: 10
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                   Calvin                      Woo                  Physics                       22                     Uber
                        7               Anna Grace                  Del Rio                       CS                       22                     USAF
                        8               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        9                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 0 1 2 3 4 5 6 7 8 9 
>SQL: DONE.


//------- simple strings -------------------

>Command [31]: select * from student where lname = Jackson
Table name: _select_table_1, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                      Flo                  Jackson                     Math                       21                   Google

records selected: 2 3 
>SQL: DONE.



>Command [32]: select * from student where major = CS
Table name: _select_table_2, records: 4
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 0 1 2 7 
>SQL: DONE.



>Command [33]: select * from student where company = Uber
Table name: _select_table_3, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                   Calvin                      Woo                  Physics                       22                     Uber

records selected: 2 6 
>SQL: DONE.


//----- quoted strings ---------------------

>Command [34]: select * from student where lname = "Del Rio"
Table name: _select_table_4, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 7 
>SQL: DONE.



>Command [35]: select * from student where fname = "Jim Bob"
Table name: _select_table_5, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0                  Jim Bob                    Smith                     Math                       23                  Verizon

records selected: 5 
>SQL: DONE.



>Command [36]: select * from student where fname = "Anna Grace"
Table name: _select_table_6, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 7 
>SQL: DONE.



>Command [37]: select * from student where fname = "Teresa Mae"
Table name: _select_table_7, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 8 
>SQL: DONE.


//-------- non-existing string ------------------

>Command [38]: select * from student where lname = "Does Not Exist"
Table name: _select_table_8, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.


//****************************************************************************
//              RELATIONAL OPERATORS:
//****************************************************************************
//.................
//:Greater Than   :
//.................

>Command [39]: select * from student where lname > Yang
Table name: _select_table_9, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google

records selected: 0 
>SQL: DONE.



>Command [40]: select * from student where major > Math
Table name: _select_table_10, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0                     Greg                  Pearson                  Physics                       20                   Amazon
                        1                   Calvin                      Woo                  Physics                       22                     Uber

records selected: 4 6 
>SQL: DONE.



>Command [41]: select * from student where fname > "Sammuel L."
Table name: _select_table_11, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 8 
>SQL: DONE.



>Command [42]: select * from employee where salary > 200000
Table name: _select_table_12, records: 3
                   record                     last                    first                      dep                   salary                     year
                        0                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                        1                 Van Gogh                  Vincent                      Art                   240000                     2015
                        2                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 15 13 14 
>SQL: DONE.



>Command [43]: select * from employee where dep > Chemistry
Table name: _select_table_13, records: 9
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                     Jack                       HR                   150000                     2014
                        1                      Yao                    Jimmy                     Math                   145000                     2014
                        2                  Jackson                      Flo                     Math                   165000                     2017
                        3                  Jackson                    Billy                     Math                   170000                     2017
                        4                  Johnson                 Mary Ann                     Math                   165000                     2014
                        5                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        6                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                        7                     Blow                    JoAnn                  Physics                   200000                     2016
                        8                  Johnson                Billy Bob                  Physics                   142000                     2014

records selected: 2 4 7 9 10 12 15 1 11 
>SQL: DONE.



>Command [44]: select * from employee where last > Jackson
Table name: _select_table_14, records: 11
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                     Jack                       HR                   150000                     2014
                        1                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        2                  Johnson                 Mary Ann                     Math                   165000                     2014
                        3                  Johnson                Billy Bob                  Physics                   142000                     2014
                        4                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        5                 Van Gogh                  Vincent                      Art                   240000                     2015
                        6                 Van Gogh                  Vincent                       CS                   245000                     2015
                        7                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                        8                     Yang                       Bo                       CS                   160000                     2013
                        9                      Yao                    Jimmy                     Math                   145000                     2014
                       10                      Yao                      Flo                       CS                   147000                     2012

records selected: 2 3 10 11 12 13 14 15 6 4 5 
>SQL: DONE.



>Command [45]: select * from employee where first > "Billy Bob"
Table name: _select_table_15, records: 13
                   record                     last                    first                      dep                   salary                     year
                        0                     Yang                       Bo                       CS                   160000                     2013
                        1                  Jackson                       Bo                Chemistry                   130000                     2011
                        2                      Yao                      Flo                       CS                   147000                     2012
                        3                  Jackson                      Flo                     Math                   165000                     2017
                        4                  Johnson                     Jack                       HR                   150000                     2014
                        5                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                        6                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        7                      Yao                    Jimmy                     Math                   145000                     2014
                        8                     Blow                    JoAnn                  Physics                   200000                     2016
                        9                     Blow                      Joe                       CS                   100000                     2018
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                 Van Gogh                  Vincent                      Art                   240000                     2015
                       12                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 6 8 5 7 2 15 3 4 1 0 10 13 14 
>SQL: DONE.


//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . . 

>Command [46]: select * from student where age > 50
Table name: _select_table_16, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 9 
>SQL: DONE.



>Command [47]: select * from student where age > 35
Table name: _select_table_17, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 2 9 
>SQL: DONE.



>Command [48]: select * from student where fname > T
Table name: _select_table_18, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 8 
>SQL: DONE.



>Command [49]: select * from employee where salary > 130000
Table name: _select_table_19, records: 13
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        1                  Johnson                Billy Bob                  Physics                   142000                     2014
                        2                      Yao                    Jimmy                     Math                   145000                     2014
                        3                      Yao                      Flo                       CS                   147000                     2012
                        4                  Johnson                     Jack                       HR                   150000                     2014
                        5                     Yang                       Bo                       CS                   160000                     2013
                        6                  Jackson                      Flo                     Math                   165000                     2017
                        7                  Johnson                 Mary Ann                     Math                   165000                     2014
                        8                  Jackson                    Billy                     Math                   170000                     2017
                        9                     Blow                    JoAnn                  Physics                   200000                     2016
                       10                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                       11                 Van Gogh                  Vincent                      Art                   240000                     2015
                       12                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 3 11 4 5 2 6 7 10 9 1 15 13 14 
>SQL: DONE.



>Command [50]: select * from employee where  year > 2009
Table name: _select_table_20, records: 16
                   record                     last                    first                      dep                   salary                     year
                        0                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                        1                  Jackson                       Bo                Chemistry                   130000                     2011
                        2                      Yao                      Flo                       CS                   147000                     2012
                        3                     Yang                       Bo                       CS                   160000                     2013
                        4                  Johnson                     Jack                       HR                   150000                     2014
                        5                      Yao                    Jimmy                     Math                   145000                     2014
                        6                  Johnson                 Mary Ann                     Math                   165000                     2014
                        7                  Johnson                Billy Bob                  Physics                   142000                     2014
                        8                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        9                 Van Gogh                  Vincent                      Art                   240000                     2015
                       10                 Van Gogh                  Vincent                       CS                   245000                     2015
                       11                     Blow                    JoAnn                  Physics                   200000                     2016
                       12                  Jackson                      Flo                     Math                   165000                     2017
                       13                  Jackson                    Billy                     Math                   170000                     2017
                       14                     Blow                      Joe                       CS                   100000                     2018
                       15                  Johnson                    Jimmy                Chemistry                   140000                     2018

records selected: 15 8 5 6 2 4 10 11 12 13 14 1 7 9 0 3 
>SQL: DONE.


//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .

>Command [51]: select * from student where age  > 53
Table name: _select_table_21, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [52]: select * from student where lname > Yao
Table name: _select_table_22, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [53]: select * from student where fname > "Teresa Mae"
Table name: _select_table_23, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [54]: select * from employee where last > "Van Gogh"
Table name: _select_table_24, records: 3
                   record                     last                    first                      dep                   salary                     year
                        0                     Yang                       Bo                       CS                   160000                     2013
                        1                      Yao                    Jimmy                     Math                   145000                     2014
                        2                      Yao                      Flo                       CS                   147000                     2012

records selected: 6 4 5 
>SQL: DONE.



>Command [55]: select * from employee where first > Vincent
Table name: _select_table_25, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [56]: select * from employee where salary > 260000
Table name: _select_table_26, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.


//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . . 

>Command [57]: select * from student where age > 54
Table name: _select_table_27, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [58]: select * from student where lname > Zoolander
Table name: _select_table_28, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [59]: select * from employee where last > Zoolaner
Table name: _select_table_29, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [60]: select * from employee where first > Xu
Table name: _select_table_30, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.


//.................
//:Greater Equal  :
//.................

>Command [61]: select * from student where lname >= Yang
Table name: _select_table_31, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0                       Bo                     Yang                       CS                       28                Microsoft
                        1                      Flo                      Yao                       CS                       20                   Google

records selected: 1 0 
>SQL: DONE.



>Command [62]: select * from student where fname >= "Sammuel L."
Table name: _select_table_32, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 2 8 
>SQL: DONE.



>Command [63]: select * from student where age >= 40
Table name: _select_table_33, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 2 9 
>SQL: DONE.


//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . . 

>Command [64]: select * from employee where last >= Jack
Table name: _select_table_34, records: 14
                   record                     last                    first                      dep                   salary                     year
                        0                  Jackson                      Flo                     Math                   165000                     2017
                        1                  Jackson                       Bo                Chemistry                   130000                     2011
                        2                  Jackson                    Billy                     Math                   170000                     2017
                        3                  Johnson                     Jack                       HR                   150000                     2014
                        4                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        5                  Johnson                 Mary Ann                     Math                   165000                     2014
                        6                  Johnson                Billy Bob                  Physics                   142000                     2014
                        7                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        8                 Van Gogh                  Vincent                      Art                   240000                     2015
                        9                 Van Gogh                  Vincent                       CS                   245000                     2015
                       10                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                       11                     Yang                       Bo                       CS                   160000                     2013
                       12                      Yao                    Jimmy                     Math                   145000                     2014
                       13                      Yao                      Flo                       CS                   147000                     2012

records selected: 7 8 9 2 3 10 11 12 13 14 15 6 4 5 
>SQL: DONE.



>Command [65]: select * from employee where first >= Bill
Table name: _select_table_35, records: 16
                   record                     last                    first                      dep                   salary                     year
                        0                  Jackson                    Billy                     Math                   170000                     2017
                        1                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        2                  Johnson                Billy Bob                  Physics                   142000                     2014
                        3                     Yang                       Bo                       CS                   160000                     2013
                        4                  Jackson                       Bo                Chemistry                   130000                     2011
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                  Jackson                      Flo                     Math                   165000                     2017
                        7                  Johnson                     Jack                       HR                   150000                     2014
                        8                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
                        9                  Johnson                    Jimmy                Chemistry                   140000                     2018
                       10                      Yao                    Jimmy                     Math                   145000                     2014
                       11                     Blow                    JoAnn                  Physics                   200000                     2016
                       12                     Blow                      Joe                       CS                   100000                     2018
                       13                  Johnson                 Mary Ann                     Math                   165000                     2014
                       14                 Van Gogh                  Vincent                      Art                   240000                     2015
                       15                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 9 12 11 6 8 5 7 2 15 3 4 1 0 10 13 14 
>SQL: DONE.



>Command [66]: select * from employee where salary >= 235000
Table name: _select_table_36, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                 Van Gogh                  Vincent                      Art                   240000                     2015
                        1                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 13 14 
>SQL: DONE.


//.................
//:Less Than      :
//.................
//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . . 

>Command [67]: select * from student where lname < Jackson
Table name: _select_table_37, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0               Anna Grace                  Del Rio                       CS                       22                     USAF
                        1               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 7 8 
>SQL: DONE.



>Command [68]: select * from student where major < Math
Table name: _select_table_38, records: 6
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3               Anna Grace                  Del Rio                       CS                       22                     USAF
                        4               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        5                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 0 1 2 7 8 9 
>SQL: DONE.



>Command [69]: select * from student where fname < "Jim Bob"
Table name: _select_table_39, records: 7
                   record                    fname                    lname                    major                      age                  company
                        0                     Alex                    Smith           Gender Studies                       53                   Amazon
                        1               Anna Grace                  Del Rio                       CS                       22                     USAF
                        2                       Bo                     Yang                       CS                       28                Microsoft
                        3                   Calvin                      Woo                  Physics                       22                     Uber
                        4                      Flo                      Yao                       CS                       20                   Google
                        5                      Flo                  Jackson                     Math                       21                   Google
                        6                     Greg                  Pearson                  Physics                       20                   Amazon

records selected: 9 7 1 6 0 3 4 
>SQL: DONE.



>Command [70]: select * from employee where salary < 200000
Table name: _select_table_40, records: 12
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        2                  Jackson                       Bo                Chemistry                   130000                     2011
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                  Johnson                Billy Bob                  Physics                   142000                     2014
                        5                      Yao                    Jimmy                     Math                   145000                     2014
                        6                      Yao                      Flo                       CS                   147000                     2012
                        7                  Johnson                     Jack                       HR                   150000                     2014
                        8                     Yang                       Bo                       CS                   160000                     2013
                        9                  Jackson                      Flo                     Math                   165000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Jackson                    Billy                     Math                   170000                     2017

records selected: 0 12 8 3 11 4 5 2 6 7 10 9 
>SQL: DONE.



>Command [71]: select * from employee where dep < CS
Table name: _select_table_41, records: 1
                   record                     last                    first                      dep                   salary                     year
                        0                 Van Gogh                  Vincent                      Art                   240000                     2015

records selected: 13 
>SQL: DONE.



>Command [72]: select * from employee where last < Jackson
Table name: _select_table_42, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016

records selected: 0 1 
>SQL: DONE.



>Command [73]: select * from employee where first < "Billy Bob"
Table name: _select_table_43, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                  Jackson                    Billy                     Math                   170000                     2017
                        1                  Johnson                    Billy                  Phys Ed                   102000                     2014

records selected: 9 12 
>SQL: DONE.


//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .

>Command [74]: select * from student where age  < 20
Table name: _select_table_44, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [75]: select * from student where lname < "Del Rio"
Table name: _select_table_45, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [76]: select * from student where fname < Alex
Table name: _select_table_46, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [77]: select * from employee where last < Blow
Table name: _select_table_47, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [78]: select * from employee where first < Billy
Table name: _select_table_48, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [79]: select * from employee where salary < 100000
Table name: _select_table_49, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.


//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . . 

>Command [80]: select * from student where age  < 19
Table name: _select_table_50, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [81]: select * from student where lname < Adams
Table name: _select_table_51, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [82]: select * from student where fname < Adam
Table name: _select_table_52, records: 0
                   record                    fname                    lname                    major                      age                  company

records selected: 
>SQL: DONE.



>Command [83]: select * from employee where last < Alex
Table name: _select_table_53, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [84]: select * from employee where first < Avory
Table name: _select_table_54, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.



>Command [85]: select * from employee where dep < Alchemy
Table name: _select_table_55, records: 0
                   record                     last                    first                      dep                   salary                     year

records selected: 
>SQL: DONE.


//.................
//:Less Equal     :
//.................

>Command [86]: select * from student where lname <= Smith
Table name: _select_table_56, records: 7
                   record                    fname                    lname                    major                      age                  company
                        0               Anna Grace                  Del Rio                       CS                       22                     USAF
                        1               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        2               Sammuel L.                  Jackson                       CS                       40                     Uber
                        3                      Flo                  Jackson                     Math                       21                   Google
                        4                     Greg                  Pearson                  Physics                       20                   Amazon
                        5                  Jim Bob                    Smith                     Math                       23                  Verizon
                        6                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 7 8 2 3 4 5 9 
>SQL: DONE.



>Command [87]: select * from student where fname <= Greg
Table name: _select_table_57, records: 7
                   record                    fname                    lname                    major                      age                  company
                        0                     Alex                    Smith           Gender Studies                       53                   Amazon
                        1               Anna Grace                  Del Rio                       CS                       22                     USAF
                        2                       Bo                     Yang                       CS                       28                Microsoft
                        3                   Calvin                      Woo                  Physics                       22                     Uber
                        4                      Flo                      Yao                       CS                       20                   Google
                        5                      Flo                  Jackson                     Math                       21                   Google
                        6                     Greg                  Pearson                  Physics                       20                   Amazon

records selected: 9 7 1 6 0 3 4 
>SQL: DONE.



>Command [88]: select * from student where age <= 40
Table name: _select_table_58, records: 9
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                     Greg                  Pearson                  Physics                       20                   Amazon
                        2                      Flo                  Jackson                     Math                       21                   Google
                        3                   Calvin                      Woo                  Physics                       22                     Uber
                        4               Anna Grace                  Del Rio                       CS                       22                     USAF
                        5               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        6                  Jim Bob                    Smith                     Math                       23                  Verizon
                        7                       Bo                     Yang                       CS                       28                Microsoft
                        8               Sammuel L.                  Jackson                       CS                       40                     Uber

records selected: 0 4 3 6 7 8 5 1 2 
>SQL: DONE.


//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . . 

>Command [89]: select * from employee where last <= Peach
Table name: _select_table_59, records: 10
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Jackson                      Flo                     Math                   165000                     2017
                        3                  Jackson                       Bo                Chemistry                   130000                     2011
                        4                  Jackson                    Billy                     Math                   170000                     2017
                        5                  Johnson                     Jack                       HR                   150000                     2014
                        6                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        7                  Johnson                 Mary Ann                     Math                   165000                     2014
                        8                  Johnson                Billy Bob                  Physics                   142000                     2014
                        9                  Johnson                    Billy                  Phys Ed                   102000                     2014

records selected: 0 1 7 8 9 2 3 10 11 12 
>SQL: DONE.



>Command [90]: select * from employee where first <= Gary
Table name: _select_table_60, records: 7
                   record                     last                    first                      dep                   salary                     year
                        0                  Jackson                    Billy                     Math                   170000                     2017
                        1                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        2                  Johnson                Billy Bob                  Physics                   142000                     2014
                        3                     Yang                       Bo                       CS                   160000                     2013
                        4                  Jackson                       Bo                Chemistry                   130000                     2011
                        5                      Yao                      Flo                       CS                   147000                     2012
                        6                  Jackson                      Flo                     Math                   165000                     2017

records selected: 9 12 11 6 8 5 7 
>SQL: DONE.



>Command [91]: select * from employee where salary <= 23500
Table name: _select_table_61, records: 14
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                  Johnson                    Billy                  Phys Ed                   102000                     2014
                        2                  Jackson                       Bo                Chemistry                   130000                     2011
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        4                  Johnson                Billy Bob                  Physics                   142000                     2014
                        5                      Yao                    Jimmy                     Math                   145000                     2014
                        6                      Yao                      Flo                       CS                   147000                     2012
                        7                  Johnson                     Jack                       HR                   150000                     2014
                        8                     Yang                       Bo                       CS                   160000                     2013
                        9                  Jackson                      Flo                     Math                   165000                     2017
                       10                  Johnson                 Mary Ann                     Math                   165000                     2014
                       11                  Jackson                    Billy                     Math                   170000                     2017
                       12                     Blow                    JoAnn                  Physics                   200000                     2016
                       13                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010

records selected: 0 12 8 3 11 4 5 2 6 7 10 9 1 15 
>SQL: DONE.


//****************************************************************************
//              LOGICAL OPERATORS
//****************************************************************************
//.................
//:AND            :
//.................

>Command [92]: select * from student where fname = "Flo" and lname = "Yao"
Table name: _select_table_62, records: 1
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google

records selected: 0 
>SQL: DONE.



>Command [93]: select * from student where major = "CS" and age < 25
Table name: _select_table_63, records: 2
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 0 7 
>SQL: DONE.



>Command [94]: select * from student where major < Math and age > 25
Table name: _select_table_64, records: 3
                   record                    fname                    lname                    major                      age                  company
                        0                       Bo                     Yang                       CS                       28                Microsoft
                        1               Sammuel L.                  Jackson                       CS                       40                     Uber
                        2                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 1 2 9 
>SQL: DONE.



>Command [95]: select * from employee where dep = CS and salary > 150000
Table name: _select_table_65, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                     Yang                       Bo                       CS                   160000                     2013
                        1                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 6 14 
>SQL: DONE.



>Command [96]: select * from employee where last = Jackson and year < 2015
Table name: _select_table_66, records: 1
                   record                     last                    first                      dep                   salary                     year
                        0                  Jackson                       Bo                Chemistry                   130000                     2011

records selected: 8 
>SQL: DONE.



>Command [97]: select * from employee where last = Johnson and year >=2014
Table name: _select_table_67, records: 5
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                     Jack                       HR                   150000                     2014
                        1                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        2                  Johnson                 Mary Ann                     Math                   165000                     2014
                        3                  Johnson                Billy Bob                  Physics                   142000                     2014
                        4                  Johnson                    Billy                  Phys Ed                   102000                     2014

records selected: 2 3 10 11 12 
>SQL: DONE.


//.................
//:OR            :
//.................

>Command [98]: select * from student where fname = Flo or lname = Jackson
Table name: _select_table_68, records: 3
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1               Sammuel L.                  Jackson                       CS                       40                     Uber
                        2                      Flo                  Jackson                     Math                       21                   Google

records selected: 0 2 3 
>SQL: DONE.



>Command [99]: select * from student where age >=40  or company = Verizon
Table name: _select_table_69, records: 4
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                  Jim Bob                    Smith                     Math                       23                  Verizon
                        2               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
                        3                     Alex                    Smith           Gender Studies                       53                   Amazon

records selected: 2 5 8 9 
>SQL: DONE.



>Command [100]: select * from employee where first = Bo or last = Johnson
Table name: _select_table_70, records: 7
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                     Jack                       HR                   150000                     2014
                        1                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        2                     Yang                       Bo                       CS                   160000                     2013
                        3                  Jackson                       Bo                Chemistry                   130000                     2011
                        4                  Johnson                 Mary Ann                     Math                   165000                     2014
                        5                  Johnson                Billy Bob                  Physics                   142000                     2014
                        6                  Johnson                    Billy                  Phys Ed                   102000                     2014

records selected: 2 3 6 8 10 11 12 
>SQL: DONE.



>Command [101]: select * from employee where year >= 2015 or dep = CS
Table name: _select_table_71, records: 9
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                    Jimmy                Chemistry                   140000                     2018
                        3                      Yao                      Flo                       CS                   147000                     2012
                        4                     Yang                       Bo                       CS                   160000                     2013
                        5                  Jackson                      Flo                     Math                   165000                     2017
                        6                  Jackson                    Billy                     Math                   170000                     2017
                        7                 Van Gogh                  Vincent                      Art                   240000                     2015
                        8                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 0 1 3 5 6 7 9 13 14 
>SQL: DONE.


//.................
//:OR AND         :
//.................

>Command [102]: select * from student where fname = Flo or major = CS and age <= 23
Table name: _select_table_72, records: 3
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                      Flo                  Jackson                     Math                       21                   Google
                        2               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 0 3 7 
>SQL: DONE.



>Command [103]: select * from student where lname = Jackson or age < 23 and company > Uber
Table name: _select_table_73, records: 3
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                      Flo                  Jackson                     Math                       21                   Google
                        2               Teresa Mae                   Gowers                Chemistry                       22                  Verizon

records selected: 2 3 8 
>SQL: DONE.



>Command [104]: select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000
Table name: _select_table_74, records: 5
                   record                     last                    first                      dep                   salary                     year
                        0                  Jackson                      Flo                     Math                   165000                     2017
                        1                  Jackson                    Billy                     Math                   170000                     2017
                        2                 Van Gogh                  Vincent                      Art                   240000                     2015
                        3                 Van Gogh                  Vincent                       CS                   245000                     2015
                        4                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010

records selected: 7 9 13 14 15 
>SQL: DONE.


//.................
//:AND OR AND     :
//.................

>Command [105]: select * from student where age <30 and major=CS or major = Physics and company = Amazon
Table name: _select_table_75, records: 4
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2                     Greg                  Pearson                  Physics                       20                   Amazon
                        3               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 0 1 4 7 
>SQL: DONE.



>Command [106]: select * from student where age <=40 and company=Uber or major = CS and company = Google
Table name: _select_table_76, records: 3
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1               Sammuel L.                  Jackson                       CS                       40                     Uber
                        2                   Calvin                      Woo                  Physics                       22                     Uber

records selected: 0 2 6 
>SQL: DONE.



>Command [107]: select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"
Table name: _select_table_77, records: 3
                   record                     last                    first                      dep                   salary                     year
                        0                     Yang                       Bo                       CS                   160000                     2013
                        1                 Van Gogh                  Vincent                      Art                   240000                     2015
                        2                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 6 13 14 
>SQL: DONE.


//.................
//:OR AND OR      :
//.................

>Command [108]: select * from student where lname = Yang or major = CS and age < 23 or company = Google 
Table name: _select_table_78, records: 4
                   record                    fname                    lname                    major                      age                  company
                        0                      Flo                      Yao                       CS                       20                   Google
                        1                       Bo                     Yang                       CS                       28                Microsoft
                        2                      Flo                  Jackson                     Math                       21                   Google
                        3               Anna Grace                  Del Rio                       CS                       22                     USAF

records selected: 0 1 3 7 
>SQL: DONE.



>Command [109]: select * from student where major = Physics or major = Math and company = Google or lname = Jackson
Table name: _select_table_79, records: 4
                   record                    fname                    lname                    major                      age                  company
                        0               Sammuel L.                  Jackson                       CS                       40                     Uber
                        1                      Flo                  Jackson                     Math                       21                   Google
                        2                     Greg                  Pearson                  Physics                       20                   Amazon
                        3                   Calvin                      Woo                  Physics                       22                     Uber

records selected: 2 3 4 6 
>SQL: DONE.



>Command [110]: select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000
Table name: _select_table_80, records: 8
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                      Yao                      Flo                       CS                   147000                     2012
                        3                     Yang                       Bo                       CS                   160000                     2013
                        4                  Jackson                      Flo                     Math                   165000                     2017
                        5                  Jackson                    Billy                     Math                   170000                     2017
                        6                 Van Gogh                  Vincent                      Art                   240000                     2015
                        7                 Van Gogh                  Vincent                       CS                   245000                     2015

records selected: 0 1 5 6 7 9 13 14 
>SQL: DONE.


---------- END OF BATCH PROCESS ----------

</pre>
