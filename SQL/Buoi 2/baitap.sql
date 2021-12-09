-- Create a new database called 'BaiTap2'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
	WHERE name = N'BaiTap2'
)
CREATE DATABASE BaiTap2
GO

USE BaiTap2

CREATE TABLE Test
(
	testID int IDENTITY PRIMARY key,
	name varchar(20)
)

CREATE TABLE Student
(
	RN int IDENTITY primary key,
	name varchar(20),
	age TINYINT
)

CREATE TABLE StudentTest
(
	RN int not null,
	testID int not null,
	date DATE,
	mark float,
)

alter TABLE StudentTest add CONSTRAINT fk_rn FOREIGN key (RN) REFERENCES Student(RN)
alter TABLE StudentTest add CONSTRAINT fk_testID FOREIGN key (testID) REFERENCES Test(TestID)
alter table StudentTest add CONSTRAINT pk_rnid PRIMARY key (RN, testID)

insert Student
	(name, age)
VALUES
	('Nguyen Hong Ha', 20),
	('Truong Ngoc Anh', 30),
	('Tuan Minh', 25),
	('Dan Truong', 22)

insert Test
	(name)
VALUES
	('EPC'),
	('DWMX'),
	('SQL1'),
	('SQL2')

insert StudentTest
	(RN,testID,date,mark)
VALUES
	(1, 1, '7/17/2006', 8),
	(1, 2, '7/18/2006', 5),
	(1, 3, '7/19/2006', 7),
	(2, 1, '7/17/2006', 7),
	(2, 2, '7/18/2006', 4),
	(2, 3, '7/19/2006', 2),
	(3, 1, '7/17/2006', 10),
	(3, 3, '7/18/2006', 1)
--a dua diem duoi dang 4 chu so, 2 chu so thap phan
select testID, convert(numeric(4,2), mark) as diem
from StudentTest

--b hoc vien co tuoi >25
SELECT*
from Student
WHERE age > 25

--c hoc vien co tuoi trong khoang tu 20 den 30
SELECT*
from Student
WHERE age BETWEEN 20 and 30

--d mon hoc co chua ky tu 's'
SELECT*
from Test
where name like '%S%'

--e record co diem > 5 trong StudentTest
SELECT*
from StudentTest
WHERE mark > 5

--f hoc vien co ten gom 4 ky tu
SELECT*
from Student
where name like '% ____'

--g hoc vien co ho gom 6 ky tu
SELECT*
from Student
where name like '______ %'

--h hoc vien co ho gom 6 ky tu nhung khong chua ky tu 'r'
SELECT*
from Student
where name like '[^r][^r][^r][^r][^r][^r] %'

--i them cot status voi gia tri mac dinh la Young
alter table Student add Status varchar(10) not null CONSTRAINT df_young default 'Young' with values

--k loai bo toan bo fk
alter table StudentTest drop CONSTRAINT fk_rn,fk_testID

--l laoi bo toan bo pk
alter table StudentTest drop CONSTRAINT pk_rnid

--m loai bo toan bo cac bang
-- Drop the table 'Test' in schema 'dbo'
IF EXISTS (
	SELECT *
FROM sys.tables
	JOIN sys.schemas
	ON sys.tables.schema_id = sys.schemas.schema_id
WHERE sys.schemas.name = N'dbo'
	AND sys.tables.name = N'Test'
)
	DROP TABLE dbo.Test
GO

drop table Test
-- Drop the table 'StudentTest' in schema 'dbo'
IF EXISTS (
	SELECT *
FROM sys.tables
	JOIN sys.schemas
	ON sys.tables.schema_id = sys.schemas.schema_id
WHERE sys.schemas.name = N'dbo'
	AND sys.tables.name = N'StudentTest'
)
	DROP TABLE dbo.StudentTest
GO

-- Drop the table 'Student' in schema 'dbo'
IF EXISTS (
	SELECT *
FROM sys.tables
	JOIN sys.schemas
	ON sys.tables.schema_id = sys.schemas.schema_id
WHERE sys.schemas.name = N'dbo'
	AND sys.tables.name = N'Student'
)
	DROP TABLE dbo.Student
GO

--n loai bo toan bo database
-- Drop the database 'BaiTap2'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Uncomment the ALTER DATABASE statement below to set the database to SINGLE_USER mode if the drop database command fails because the database is in use.
ALTER DATABASE BaiTap2 SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
-- Drop the database if it exists
IF EXISTS (
  SELECT name
FROM sys.databases
WHERE name = N'BaiTap2'
)
DROP DATABASE BaiTap2
GO