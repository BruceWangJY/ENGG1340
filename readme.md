# ENGG1340 Group Project
## Table Management System
### Problem Statements
This C++ program is aiming at helping a family-owned restaurant to have a table management system to control the status of each table to make up for the waiter shortage.

In reality, family-owned restaurant will have a relatively less table, but due to the waiter shortage, it is not easy for each waiter to remember which table is reserved by different customers. As a consequence, this program could help manage the table and help recommender the most suitable table when customers come. Moreover, considering the situation that customers might occupy a table for a long time to chat so that it might affect other waiting customers, this system could remind the waiter if a table is occupied by a certain group for a long time slot.

### Problem Settings
This program focuses on a deli with a maximum capacity of 50 person. There will be 3 types of table: Table A for 1-2 person, Table B for 3-4 person and Table C for 5-6 person. The total number of table should be less than 10. There will be 3 kinds of possible status of each table: avaliable, occupied or reserved. The system will have the following functions:(to be continued)
 1) To read from file including information such as table type and their number using file I/O, we have provided the data in the file; 
 2) To occupy and release a table, we use a function that gets the table size and number from the input and change the relevant status of table and simultaneously, use the clock() function to record the current time; 
 3) To change the number of tables or type of tables using changeSetting function, user need to input a number and its related size, then the imformation will be changed;
 4) To check whether a table is available or not using checkTable function, you need to input the table size and number, the the program will print the table status; 
 5) To print the current status of all table using printAll function;
 6) Given the number of a group of customers, suggest a vacant table with minimal enough seats using recommendTable function, it will print the minimum number of the suitable size;
 7) To notify the waiter for tables occupied for too long(90 minutes for Table A and B, 2 hours for Table C).
 8) This system supports reservation. Customers can reserve a table that is available in advance. Each table can only be reserved for 90 minutes. In this period, other customer cannot occupy this table. However, if customers don’t show up in 90 minutes, this table will return available for other customers to occupy and reserve.

## Authors
Junyuan Wang <<u3553285@connect.hku.hk>>

Hongli Xu <<xuhongli@connect.hku.hk>>
