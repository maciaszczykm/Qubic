drop database employees;

create database employees;

use employees;

create table EMPLOYEE (
ID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
BIRTHDAY DATE,
FIRSTNAME VARCHAR(10),
LASTNAME VARCHAR(20),
GENDER VARCHAR(6),
HIREDATE DATE);

commit;