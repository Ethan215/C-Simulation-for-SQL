
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../includes/sql/sql.h"
//------------------------------------------------------------------------------------------
using namespace std;

const vector<string> command_list = {
/*00*/     "make table employee fields  last,       first,         dep,      salary, year",
/*01*/     "insert into employee values Blow,       Joe,           CS,       100000, 2018",
/*02*/     "insert into employee values Blow,       JoAnn,         Physics,  200000, 2016",
/*03*/     "insert into employee values Johnson,    Jack,          HR,       150000, 2014",
/*04*/     "insert into employee values Johnson,    \"Jimmy\",     Chemistry,140000, 2018",

/*05*/     "make table student fields  fname,          lname,    major,    age",
/*06*/     "insert into student values Flo,            Yao, 	Art, 	20",
/*07*/     "insert into student values Bo, 		     Yang, 	CS, 		28",
/*08*/     "insert into student values \"Sammuel L.\", Jackson, 	CS, 		40",
/*09*/     "insert into student values \"Billy\",	     Jackson, 	Math,	27",
/*10*/     "insert into student values \"Mary Ann\",   Davis,	Math,	30",

/*11*/     "select * from employee",
/*12*/     "select last, first, age from employee",
/*13*/     "select last from employee",
/*14*/     "select * from employee where last = Johnson",
/*15*/     "select * from employee where last=Blow and major=\"JoAnn\"",

/*16*/     "select * from student",
/*17*/     "select * from student where (major=CS or major=Art)",
/*18*/     "select * from student where lname>J",
/*19*/     "select * from student where lname>J and (major=CS or major=Art)"
};

const int MAKE_TABLE_COMMANDS = 11;
const int SELECT_COMMANDS = 20;

int main(){
       SQL sql;

     // sql.drop_table("student");
     // sql.drop_table("employee");
     cout << "----- END TEST ----------" << endl;
     return 0;
}

/**
------ SQL Tables I Manage: --------
employee
student
---------------------------
>make table employee fields  last,       first,         dep,      salary, year
create table basic_test: table created.
>make table employee fields  last,       first,         dep,      salary, year
create table >insert into employee values Blow,       Joe,           CS,       100000, 2018
>insert into employee values Blow,       JoAnn,         Physics,  200000, 2016
>insert into employee values Johnson,    Jack,          HR,       150000, 2014
>insert into employee values Johnson,    "Jimmy",     Chemistry,140000, 2018
>make table student fields  fname,          lname,    major,    age
create table >insert into student values Flo,            Yao,   Art,    20
>insert into student values Bo,                      Yang,      CS,             28
>insert into student values "Sammuel L.", Jackson,      CS,             40
>insert into student values "Billy",         Jackson,   Math,   27
>insert into student values "Mary Ann",   Davis,        Math,   30
>select * from employee
There is no condition
basic_test: records selected: 0 1 2 3 
>select last, first, age from employee
There is no condition
basic_test: records selected: 0 1 2 3 
>select last from employee
There is no condition
basic_test: records selected: 0 1 2 3 
>select * from employee where last = Johnson
basic_test: records selected: 2 3 
>select * from employee where last=Blow and major="JoAnn"
basic_test: records selected: 
>select * from student
There is no condition
basic_test: records selected: 0 1 2 3 4 
>select * from student where (major=CS or major=Art)
basic_test: records selected: 0 1 2 
>select * from student where lname>J
basic_test: records selected: 2 3 1 0 
>select * from student where lname>J and (major=CS or major=Art)
basic_test: records selected: 0 1 2 
----- END TEST --------
[       OK ] SQL_BASIC.SQLBasic (135 ms)
[----------] 1 test from SQL_BASIC (135 ms total)
[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (137 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 
//==========================================================================
//  debug = on
//==========================================================================
build git:(master) ✗  😊 $> ./bin/basic_test debug
----------running basic_test.cpp---------
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from SQL_BASIC
[ RUN      ] SQL_BASIC.SQLBasic
------ SQL Tables I Manage: --------
employee
student
---------------------------
>make table employee fields  last,       first,         dep,      salary, year
create table basic_test: table created.
>make table employee fields  last,       first,         dep,      salary, year
create table >insert into employee values Blow,       Joe,           CS,       100000, 2018
>insert into employee values Blow,       JoAnn,         Physics,  200000, 2016
>insert into employee values Johnson,    Jack,          HR,       150000, 2014
>insert into employee values Johnson,    "Jimmy",     Chemistry,140000, 2018
>make table student fields  fname,          lname,    major,    age
create table >insert into student values Flo,            Yao,   Art,    20
>insert into student values Bo,                      Yang,      CS,             28
>insert into student values "Sammuel L.", Jackson,      CS,             40
>insert into student values "Billy",         Jackson,   Math,   27
>insert into student values "Mary Ann",   Davis,        Math,   30
>select * from employee
There is no condition
Table name: _select_table_34, records: 4
                   record                     last                    first                      dep                   salary                     year
                        0                     Blow                      Joe                       CS                   100000                     2018
                        1                     Blow                    JoAnn                  Physics                   200000                     2016
                        2                  Johnson                     Jack                       HR                   150000                     2014
                        3                  Johnson                    Jimmy                Chemistry                   140000                     2018
basic_test: records selected: 0 1 2 3 
>select last, first, age from employee
There is no condition
Table name: _select_table_38, records: 4
                   record                     last                    first                      age
                        0                     Blow                      Joe                     Blow
                        1                     Blow                    JoAnn                     Blow
                        2                  Johnson                     Jack                  Johnson
                        3                  Johnson                    Jimmy                  Johnson
basic_test: records selected: 0 1 2 3 
>select last from employee
There is no condition
Table name: _select_table_42, records: 4
                   record                     last
                        0                     Blow
                        1                     Blow
                        2                  Johnson
                        3                  Johnson
basic_test: records selected: 0 1 2 3 
>select * from employee where last = Johnson
Table name: _select_table_46, records: 2
                   record                     last                    first                      dep                   salary                     year
                        0                  Johnson                     Jack                       HR                   150000                     2014
                        1                  Johnson                    Jimmy                Chemistry                   140000                     2018
basic_test: records selected: 2 3 
>select * from employee where last=Blow and major="JoAnn"
Table name: _select_table_50, records: 0
                   record                     last                    first                      dep                   salary                     year
basic_test: records selected: 
>select * from student
There is no condition
Table name: _select_table_54, records: 5
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                      Art                       20
                        1                       Bo                     Yang                       CS                       28
                        2              Sammuel L .                  Jackson                       CS                       40
                        3                    Billy                  Jackson                     Math                       27
                        4                 Mary Ann                    Davis                     Math                       30
basic_test: records selected: 0 1 2 3 4 
>select * from student where (major=CS or major=Art)
Table name: _select_table_58, records: 3
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                      Art                       20
                        1                       Bo                     Yang                       CS                       28
                        2              Sammuel L .                  Jackson                       CS                       40
basic_test: records selected: 0 1 2 
>select * from student where lname>J
Table name: _select_table_62, records: 4
                   record                    fname                    lname                    major                      age
                        0              Sammuel L .                  Jackson                       CS                       40
                        1                    Billy                  Jackson                     Math                       27
                        2                       Bo                     Yang                       CS                       28
                        3                      Flo                      Yao                      Art                       20
basic_test: records selected: 2 3 1 0 
>select * from student where lname>J and (major=CS or major=Art)
Table name: _select_table_66, records: 3
                   record                    fname                    lname                    major                      age
                        0                      Flo                      Yao                      Art                       20
                        1                       Bo                     Yang                       CS                       28
                        2              Sammuel L .                  Jackson                       CS                       40
basic_test: records selected: 0 1 2 
----- END TEST --------
[       OK ] SQL_BASIC.SQLBasic (84 ms)
[----------] 1 test from SQL_BASIC (84 ms total)
[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (84 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 
*/