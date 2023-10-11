-- Create the Supplier table
CREATE TABLE Supplier (
    Sno INT PRIMARY KEY,
    Sname VARCHAR(255),
    City VARCHAR(255),
    State VARCHAR(255)
);

-- Create the Part table
CREATE TABLE Part (
    Pno INT PRIMARY KEY,
    Pname VARCHAR(255),
    Category VARCHAR(255)
);

-- Create the Supplier-Part table
CREATE TABLE Supplier_Part (
    Sno INT,
    Pno INT,
    Qty INT,
    PRIMARY KEY (Sno, Pno),
    FOREIGN KEY (Sno) REFERENCES Supplier(Sno),
    FOREIGN KEY (Pno) REFERENCES Part(Pno)
);

-- Insert sample data into the Supplier table
INSERT INTO Supplier (Sno, Sname, City, State)
VALUES
    (1, 'Supplier1', 'City1', 'Maharashtra'),
    (2, 'Supplier2', 'City2', 'Karnataka'),
    (3, 'Supplier3', 'City3', 'Maharashtra'),
    (4, 'Supplier4', 'City4', 'Karnataka'),
    (5, 'Supplier5', 'City5', 'Maharashtra');

-- Insert sample data into the Part table
INSERT INTO Part (Pno, Pname, Category)
VALUES
    (1, 'Part1', 'Electronics'),
    (2, 'Part2', 'Mechanical'),
    (3, 'Part3', 'Electronics'),
    (4, 'Part4', 'Mechanical'),
    (5, 'Part5', 'Electronics');

-- Insert sample data into the Supplier-Part table
INSERT INTO Supplier_Part (Sno, Pno, Qty)
VALUES
    (1, 1, 100),
    (1, 2, 50),
    (2, 1, 75),
    (3, 2, 60),
    (4, 3, 120),
    (5, 4, 90),
    (1, 5, 40),
    (2, 4, 55),
    (3, 3, 70),
    (4, 2, 45);

select * from supplier;
select * from Part;
select * from supplier_Part;



-- 1) Retrieve all parts supplied by suppliers in Maharashtra:
SELECT SP.Pno, P.Pname, SP.Qty
FROM Supplier_Part SP
JOIN Supplier S ON SP.Sno = S.Sno
JOIN Part P ON SP.Pno = P.Pno
WHERE S.State = 'Maharashtra';

-- 2) Find all suppliers in Karnataka who supply parts in the category 'Electronics':
SELECT S.Sname, S.City, SP.Pno, P.Pname, P.Category, SP.Qty
FROM Supplier_Part SP
JOIN Supplier S ON SP.Sno = S.Sno
JOIN Part P ON SP.Pno = P.Pno
WHERE S.State = 'Karnataka' AND P.Category = 'Electronics';


-- 3) Retrieve the total quantity of each part supplied by suppliers in Maharashtra:
SELECT SP.Pno, P.Pname, SUM(SP.Qty) AS TotalQuantity
FROM Supplier_Part SP
JOIN Supplier S ON SP.Sno = S.Sno
JOIN Part P ON SP.Pno = P.Pno
WHERE S.State = 'Maharashtra'
GROUP BY SP.Pno, P.Pname;
 
 
 -- 4) List all suppliers in Karnataka who supply parts with part numbers in the range 101 to 200: 
SELECT S.Sno, S.Sname, S.City, SP.Pno, P.Pname, SP.Qty
FROM Supplier_Part SP
JOIN Supplier S ON SP.Sno = S.Sno
JOIN Part P ON SP.Pno = P.Pno
WHERE S.State = 'Karnataka' AND SP.Pno BETWEEN 101 AND 200;


-- 5) Find all parts supplied by suppliers in Maharashtra and Karnataka with a quantity greater than 100:
SELECT SP.Pno, P.Pname, SP.Qty, S.State
FROM Supplier_Part SP
JOIN Supplier S ON SP.Sno = S.Sno
JOIN Part P ON SP.Pno = P.Pno
WHERE (S.State = 'Maharashtra' OR S.State = 'Karnataka') AND SP.Qty > 100;
 