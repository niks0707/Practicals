-- Creating the Employee table
CREATE TABLE Employee (
    Eno INT PRIMARY KEY,
    Ename VARCHAR(50),
    Title VARCHAR(50),
    Dno INT
);

INSERT INTO Employee (Eno, Ename, Title, Dno) VALUES
    (1, 'John Doe', 'Manager', 5),
    (2, 'Jane Smith', 'Employee', 15),
    (3, 'Michael Johnson', 'Manager', 25),
    (4, 'Emily Brown', 'Employee', 10),
    (5, 'Robert Lee', 'Employee', 20),
    (6, 'Sophia Wilson', 'Manager', 30);


-- Creating the Employee fragments
CREATE TABLE Employee1 AS SELECT * FROM Employee WHERE Dno BETWEEN 1 AND 10;
CREATE TABLE Employee2 AS SELECT * FROM Employee WHERE Dno BETWEEN 11 AND 20;
CREATE TABLE Employee3 AS SELECT * FROM Employee WHERE Dno BETWEEN 21 AND 30;

-- 1
SELECT * FROM Employee1;
SELECT * FROM Employee2;
SELECT * FROM Employee3;

-- 2
SELECT Ename FROM Employee1 WHERE Title = 'Manager';

-- 3
SELECT * FROM Employee2 WHERE Dno = 25
UNION
SELECT * FROM Employee3 WHERE Dno = 25;

-- 4
UPDATE Employee3 SET Title = 'Senior Manager' WHERE Dno = 30;


-- 5
SELECT Ename FROM Employee1 WHERE Dno IN (5, 10)
UNION
SELECT Ename FROM Employee2 WHERE Dno IN (5, 10)
UNION
SELECT Ename FROM Employee3 WHERE Dno IN (5, 10);
