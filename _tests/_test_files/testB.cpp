#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include "../../includes/table/typedefs.h"
#include "../../includes/stl_utils/vector_utilities.h"
#include "../../includes//bplustree/map.h"
#include "../../includes//bplustree/multimap.h"

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/parser/parser.h"

//------------------------------------------------------------------------------------------

using namespace std;

bool parser_basic(bool debug = false){
  cout << "\n\n\n------------------------\n\n\n";
  string str;
  char s[300];

  str = "make table student fields last, first, age, major, class";
  strcpy(s, str.c_str());
  Parser parser(s);
  mmap_ss ptree;
  ptree = parser.parse_tree(); 
  cout << "input: [" << s << "]" << endl << endl;
  ptree.print_lookup();
  cout << endl << endl;

  str = "insert into student values Jones,\"Sue Ellen\", 20, CS, Fr ";
  strcpy(s, str.c_str());
  parser.set_string(s);
  ptree = parser.parse_tree(); 
  cout << "input: [" << s << "]" << endl << endl;
  ptree.print_lookup();
  cout << endl << endl;

  str = "select * from student";
  strcpy(s, str.c_str());
  parser.set_string(s);
  ptree = parser.parse_tree(); 
  cout << "input: [" << s << "]" << endl << endl;
  ptree.print_lookup();
  cout << endl << endl;

  str = "select lname, fname from student where lname = \"Yao\" and fname = \"Flo\"";
  strcpy(s, str.c_str());
  parser.set_string(s);
  ptree = parser.parse_tree(); 
  cout << "input: [" << s << "]" << endl << endl;
  ptree.print_lookup();
  cout << endl << endl;

  str = "select age, lname, fname from student where fname = \"Mary Ann\" and lname = Yao";
  strcpy(s, str.c_str());
  parser.set_string(s);
  ptree = parser.parse_tree(); 
  cout << "input: [" << s << "]" << endl << endl;
  ptree.print_lookup();
  cout << endl << endl;

  str = "select * from student where (age>=25 or lname = Yao) and (fname = \"Teresa Mae\" or Major = CS)";
  strcpy(s, str.c_str());
  parser.set_string(s);
  ptree = parser.parse_tree(); 
  cout << "input: [" << s << "]" << endl << endl;
  ptree.print_lookup();
  cout << endl << endl;

  cout << "\n\n\n----- DONE ----------\n\n" << endl;
  return true;
}

TEST(TEST_TEMPLATE, TestTemplate) {
  bool success = parser_basic();
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*
build git:(master) ✗  😊 $> tree ../includes
../includes
├── binary_files
│   ├── file_record.cpp
│   ├── file_record.h
│   ├── utilities.cpp
│   └── utilities.h
├── bplustree
│   ├── bplustree.h
│   ├── btree_array_funcs.h
│   ├── map.h
│   ├── multimap.h
│   └── set_class.h
├── linked_list_functions
│   └── linkedlistfunctionsTemplated.h
├── node
│   ├── bogus.txt
│   ├── master.txt
│   └── node.h
├── parser
│   ├── parser.cpp
│   ├── parser.h
│   ├── sql_parser_functions.cpp
│   ├── sql_parser_functions.h
│   └── typedefs.h
├── queue
│   ├── MyQueue.h
│   └── queue_composition.h
├── stack
│   ├── MyStack.h
│   └── stack_composition.h
├── stl_utils
│   └── vector_utilities.h
├── table
│   ├── table.cpp
│   ├── table.h
│   └── typedefs.h
├── token
│   ├── child_tokens.h
│   ├── token.cpp
│   └── token.h
└── tokenizer
    ├── constants.h
    ├── ftokenize.cpp
    ├── ftokenize.h
    ├── state_machine_functions.cpp
    ├── state_machine_functions.h
    ├── stokenize.cpp
    └── stokenize.h
11 directories, 36 files
build git:(master) ✗  😊 $> ./bin/basic_test
----------running basic_test.cpp---------
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_TEMPLATE
[ RUN      ] TEST_TEMPLATE.TestTemplate
------------------------
input: [make table student fields last, first, age, major, class]
       col :    last first age major class 
   command :    make 
table_name :    student 
input: [insert into student values Jones,"Sue Ellen", 20, CS, Fr ]
   command :    insert 
table_name :    student 
    values :    Jones Sue Ellen 20 CS Fr 
input: [select * from student]
   command :    select 
    fields :    * 
table_name :    student 
input: [select lname, fname from student where lname = "Yao" and fname = "Flo"]
   command :    select 
 condition :    lname = Yao and fname = Flo 
    fields :    lname fname 
table_name :    student 
     where :    yes 
input: [select age, lname, fname from student where fname = "Mary Ann" and lname = Yao]
   command :    select 
 condition :    fname = Mary Ann and lname = Yao 
    fields :    age lname fname 
table_name :    student 
     where :    yes 
input: [select * from student where (age>=25 or lname = Yao) and (fname = "Teresa Mae" or Major = CS)]
   command :    select 
 condition :    ( age >= 25 or lname = Yao ) and ( fname = Teresa Mae or Major = CS ) 
    fields :    * 
table_name :    student 
     where :    yes 
----- DONE -------------
[       OK ] TEST_TEMPLATE.TestTemplate (3 ms)
[----------] 1 test from TEST_TEMPLATE (3 ms total)
[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (3 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 
*/