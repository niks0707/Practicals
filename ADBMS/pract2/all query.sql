-- Create Books table
CREATE TABLE Books (
    ISBN VARCHAR(10) PRIMARY KEY,
    primaryAuthor VARCHAR(50),
    topic VARCHAR(50),
    totalStock INT,
    price DECIMAL(10, 2)
);

-- Create BookStore table
CREATE TABLE BookStore (
    storeNo VARCHAR(2) PRIMARY KEY,
    city VARCHAR(50),
    state VARCHAR(50),
    zip INT,
    inventoryValue DECIMAL(10, 2)
);

-- Create Stock table
CREATE TABLE Stock (
    storeNo VARCHAR(2),
    ISBN VARCHAR(10),
    Qty INT,
    PRIMARY KEY (storeNo, ISBN),
    FOREIGN KEY (storeNo) REFERENCES BookStore(storeNo),
    FOREIGN KEY (ISBN) REFERENCES Books(ISBN)
);

-- Insert data into Books table
INSERT INTO Books (ISBN, primaryAuthor, topic, totalStock, price)
VALUES
    ('1234', 'Author A', 'Fiction', 100, 25.99),
    ('5678', 'Author B', 'Non-Fiction', 150, 49.99),
    ('9101', 'Author C', 'Mystery', 75, 85.50),
    ('2345', 'Author D', 'Science Fiction', 120, 15.00);

-- Insert data into BookStore table
INSERT INTO BookStore (storeNo, city, state, zip, inventoryValue)
VALUES
    ('S1', 'City A', 'State X', 15000, 5248.49),
    ('S2', 'City B', 'State Y', 35000, 7325.76),
    ('S3', 'City C', 'State Z', 65000, 8912.33),
    ('S4', 'City D', 'State W', 85000, 6719.15);

-- Insert data into Stock table
INSERT INTO Stock (storeNo, ISBN, Qty)
VALUES
    ('S1', '1234', 50),
    ('S1', '5678', 75),
    ('S2', '9101', 60),
    ('S3', '2345', 90);
    
    
    
    
    
-- my code 

select * from books;
select * from bookstore;
select * from stock;


-- Find the total number of books in stock where price is between $15 and $55: 

SELECT SUM(Qty) AS TotalBooksInStock
FROM Stock
JOIN Books ON Stock.ISBN = Books.ISBN
WHERE Books.price BETWEEN 15.00 AND 55.00;


-- Update the book price of book No=1234 from $45 to $55 at site S3:

UPDATE Books
SET price = 55.00
WHERE ISBN = '1234';



-- Find the total number of books at site S2:

SELECT SUM(Qty) AS TotalBooksAtS2
FROM Stock
WHERE storeNo = 'S2';
