-- Create a new database called 'BaiTap1'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap1'
)
CREATE DATABASE BaiTap1
GO

--Creating required tables:
USE BaiTap1
--Target the newly created Database

CREATE TABLE Student
(
	StudentId int PRIMARY KEY IDENTITY not null,
	StudentName NVARCHAR(50) not null,
	age INT not null,
	email NVARCHAR(100) not null
)

CREATE TABLE Classes
(
	ClassID int PRIMARY key IDENTITY not null,
	ClassName NVARCHAR(50) not null
)

CREATE table Subjects
(
	SubjectID int PRIMARY KEY IDENTITY not null,
	SubjectName NVARCHAR(50) not NULL
)

create table ClassStudent
(
	StudentID int IDENTITY not null,
	ClassID int not null
)

CREATE TABLE Marks
(
	Mark int not null,
	SubjectID int not null,
	StudentID int not null
)

--Assigning relationships:
alter table Marks ADD CONSTRAINT fk_subjects FOREIGN KEY (SubjectID) REFERENCES Subjects(SubjectID)

alter table Marks ADD CONSTRAINT fk_stdid FOREIGN KEY (StudentID) REFERENCES Student(StudentID)

alter table ClassStudent ADD CONSTRAINT fk_std FOREIGN KEY (StudentID) REFERENCES Student(StudentID)

alter table ClassStudent ADD CONSTRAINT fk_clssid FOREIGN KEY (ClassID) REFERENCES Classes(ClassID)

--Data Insertion:

--Student data:
insert Student
	(StudentName,age,email)
VALUES('Nguyen Quang An', 18, 'an@yahoo.com')
insert Student
	(StudentName,age,email)
VALUES('Nguyen Cong Vinh', 20, 'vinh@gmail.com')
insert Student
	(StudentName,age,email)
VALUES('Nguyen Van Quyen', 19, 'quyen@yahoo.com')
insert Student
	(StudentName,age,email)
VALUES('Pham Thanh Binh', 25, 'binh@yahoo.com')
insert Student
	(StudentName,age,email)
VALUES('Nguyen Van Tai Em', 30, 'taiem@sport.vn')
-- SELECT*FROM Student (checking data)

--Classes Data:

insert Classes
	(ClassName)
VALUES('C0706L')
insert Classes
	(ClassName)
VALUES('C0708G')
-- SELECT*FROM Classes (checking data, again)

--ClassesStudent Data:

INSERT ClassStudent
	(ClassID)
VALUES(1)
INSERT ClassStudent
	(ClassID)
VALUES(1)
INSERT ClassStudent
	(ClassID)
VALUES(2)
INSERT ClassStudent
	(ClassID)
VALUES(2)
INSERT ClassStudent
	(ClassID)
VALUES(2)
-- SELECT*FROM ClassStudent (and another one)

--Subject Data:

INSERT Subjects
	(SubjectName)
VALUES('SQL')
INSERT Subjects
	(SubjectName)
VALUES('Java')
INSERT Subjects
	(SubjectName)
VALUES('C')
INSERT Subjects
	(SubjectName)
VALUES('Visual Basic')
-- select*from Subjects (again, checking data...)

-- Marks Data:

INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(8, 1, 1)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(4, 2, 1)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(9, 1, 1)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(7, 1, 3)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(3, 1, 4)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(5, 2, 5)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(8, 3, 3)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(1, 3, 5)
INSERT Marks
	(Mark,SubjectID,StudentID)
VALUES(3, 2, 4)
-- select*from Marks (yup, data checking, but this is the final check.)

--Finished with 4 queries errored out.