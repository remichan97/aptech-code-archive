-- Create a new database called 'BaiTap11'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap11'
)
CREATE DATABASE BaiTap11
GO

use BaiTap11

--tao cac bang can thiet:
create table Student
(
	StudentId int PRIMARY KEY IDENTITY not null,
	Name VARCHAR(50),
	Age tinyint,
	stGender bit
)

create table Books
(
	BookID int PRIMARY KEY IDENTITY not null,
	Name varchar(50),
	TotalPage int,
	Type varchar(10),
	Quantity int
)

create table Borrows
(
	BorrowID int IDENTITY not null,
	StudentID int not null,
	BookID int not null,
	BorrowDate datetime
)

create table ReturnBooks
(
	ReturnID int IDENTITY not null,
	StudentID int not null,
	BookID int not null,
	BorrowDate datetime,
	ReturnDate datetime
)

--gan rang buoc:
alter table Books add CONSTRAINT chk_total check(TotalPage > 0)
alter table Borrows add constraint pk_brw PRIMARY KEY (BorrowID,StudentID,BookID)
alter table ReturnBooks add CONSTRAINT pk_rtn PRIMARY KEY (ReturnID,StudentID,BookID)

--chen du lieu:
insert Student
	(Name,Age,stGender)
values
	('Henry', 25, 1),
	('Britney', 20, 0),
	('Beckham', 16, null),
	('Madona', 17, 0),
	('Effenberg', 30, 1)

insert Books
	(Name,TotalPage,Quantity)
VALUES
	('Access 2K', 100, 3),
	('Logic C', 60, 4),
	('HTML', 200, 2),
	('Core Java', 50, 1),
	('SQL 2K', 1000, 6)

insert Borrows
	(StudentID,BookID,BorrowDate)
VALUES
	(1, 5, '09/15/2007'),
	(2, 2, '09/14/2007'),
	(2, 3, '09/20/2007'),
	(2, 1, '09/16/2007'),
	(2, 1, '09/16/2007'),
	(3, 4, '09/19/2007'),
	(4, 4, '09/21/2007')

--Cap nhat truong type theo tieu chi: 'Thin' neu TotalPage < 100, 'Normal' neu TotalPage trong khoang 100 den 1000, 'Thick' neu > 1000:
update Books set [Type] = case
when TotalPage < 100 then 'Thin'
when TotalPage between 100 and 1000 then 'Normal'
when TotalPage > 1000 then 'Thick'
end

--Danh sach sinh vien sap xep theo truong Age:
select*
from Student
ORDER by Age

--Sinh vien nhieu tuoi nhat
select top(1)
	*
from Student
order by Age DESC

--Tong so sach trong kho:
select sum(Quantity)
from Books

--Nhung sinh vien co stGender la null
select*
from Student
where stGender is null

--Nhung sinh vien co ky tu dau tien la B:
select*
from Student
where Name like 'B%'

--bookID, borrowDate cua nhung quyen duoc muon hon 10 ngay:
select BookID, BorrowDate
from Borrows
where DATEDIFF(dd,BorrowDate,GETDATE()) > 10
--hien thi 1/2 tong so sach:
select top(50) percent
	*
from Books
--Viet cau lenh SQL mo ta hanh dong: Quyen sach Access 2K duoc tra boi Britney:
insert into ReturnBooks
	(StudentID,BookID,BorrowDate)
SELECT StudentID, BookID, BorrowDate
from Borrows
WHERE StudentID in (Select StudentID
	from Student
	where name like 'Britney') and BookID in (select BookID
	from Books
	where Name like 'Access 2K')
update ReturnBooks set ReturnDate = getdate()
--Viet cau lenh SQL mo ta hanh dong: Quyen sach SQL2K duoc tra boi Henry:
insert into ReturnBooks
	(StudentID,BookID,BorrowDate)
SELECT StudentID, BookID, BorrowDate
from Borrows
WHERE StudentID in (Select StudentID
	from Student
	where name like 'Henry') and BookID in (select BookID
	from Books
	where Name like 'SQL 2K')
--Viet cau lenh SQL mo ta hanh dong: Madona muon quyen sach SQL2K vao ngay 28/01/2016
if exists (SELECT BookID
from Books
where Name like 'SQL 2K' and Quantity > 0)
begin
	insert Borrows
		(StudentID,BookID,BorrowDate)
	VALUES
		(4, 5, '01/28/2016')
	update Books set Quantity = Quantity - 1 where Name like 'SQL 2K'
end
--Viet cau lenh SQL mo ta hanh dong: Madona tra quyen sach 'SQL2K' vao ngay 28/03/2016
insert into ReturnBooks
	(StudentID,BookID,BorrowDate)
SELECT StudentID, BookID, BorrowDate
from Borrows
where StudentID in (select StudentID
	from Student
	where Name like 'Madona') and BookID in (select BookID
	from Books
	where Name like 'SQL 2K')
update ReturnBooks set ReturnDate = '03/28/2016' where StudentID in (select StudentID
from Student
where Name like 'Madona')
update Books set Quantity = Quantity + 1 where Name like 'SQL 2K'
--Hien thi BookID,BorrowDate cua nhung quyen sach duoc muon hon 10 ngay tinh tu luc muoc den luc tra:
SELECT BookID, BorrowDate
from ReturnBooks
where DATEDIFF(dd,BorrowDate,ReturnDate) > 10
GROUP by BookID,BorrowDate
