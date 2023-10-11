-- Create tables
CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(255)
);

CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

CREATE TABLE Course (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(255),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

CREATE TABLE Faculty (
    FacultyID INT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

CREATE TABLE Exam (
    ExamID INT PRIMARY KEY,
    ExamName VARCHAR(255),
    ExamDate DATE,
    CourseID INT,
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);

CREATE TABLE Result (
    ResultID INT PRIMARY KEY,
    ExamID INT,
    StudentID INT,
    Marks INT,
    FOREIGN KEY (ExamID) REFERENCES Exam(ExamID),
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);


INSERT INTO Department (DepartmentID, DepartmentName) VALUES
    (1, 'Computer Science'),
    (2, 'Electrical Engineering'),
    (3, 'Mechanical Engineering');
select * from Department;
    
INSERT INTO Student (StudentID, FirstName, LastName, DepartmentID) VALUES
    (101, 'Mangesh', 'Sharma', 1),
    (102, 'Yadnesh', 'Dada', 2),
    (103, 'Abhishek', 'Jadhav', 1);
select * from Student;


INSERT INTO Course (CourseID, CourseName, DepartmentID) VALUES
    (201, 'Introduction to C Programming', 1),
    (202, 'Compiler Design', 2),
    (203, 'ADBMS', 3);
select * from Course;


INSERT INTO Faculty (FacultyID, FirstName, LastName, DepartmentID) VALUES
    (301, 'Professor', 'M', 1),
    (302, 'Professor', 'N', 2),
    (303, 'Professor', 'J', 3);
select * from Faculty;


INSERT INTO Exam (ExamID, ExamName, ExamDate, CourseID) VALUES
    (401, 'ISE', '2023-03-15', 201),
    (402, 'Mid Term', '2023-06-01', 202),
    (403, 'End Term', '2023-04-20', 203);
select * from Exam;


INSERT INTO Result (ResultID, ExamID, StudentID, Marks) VALUES
    (501, 401, 101, 85),
    (502, 401, 102, 78),
    (503, 401, 103, 92);
select * from Result;