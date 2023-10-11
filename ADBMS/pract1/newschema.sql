-- Create the Student table
CREATE TABLE Student (
    regNo INT PRIMARY KEY,
    name VARCHAR(100),
    department VARCHAR(50),
    year INT
);

-- Create the ExamSection table
CREATE TABLE ExamSection (
    loginId VARCHAR(50) PRIMARY KEY,
    password VARCHAR(50)
);

-- Create the Exam table
CREATE TABLE Exam (
    examId INT PRIMARY KEY AUTO_INCREMENT,
    examType VARCHAR(100),
    examDate DATE
);

-- Create the Result table
CREATE TABLE Result (
    resultId INT PRIMARY KEY AUTO_INCREMENT,
    regNo INT,
    examId INT,
    credits INT,
    status ENUM('pass', 'fail'),
    totalMarks INT,
    marksObtain INT,
    FOREIGN KEY (regNo) REFERENCES Student(regNo),
    FOREIGN KEY (examId) REFERENCES Exam(examId)
);
