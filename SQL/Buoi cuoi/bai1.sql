-- Create a new database called 'BaiTap10'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap10'
)
CREATE DATABASE BaiTap10
GO

use BaiTap10

--tao type moi:
create TYPE mytype from VARCHAR(40) not null

--tao cac bang can thiet:
create table BookCode
(
	BookCode int PRIMARY KEY not null IDENTITY,
	BookTitle mytype,
	Author mytype,
	Edition int,
	BookPrice money,
	Copies int
)

create table Member
(
	MemberCode int PRIMARY Key not null IDENTITY,
	Name mytype,
	Address mytype,
	PhoneNumber varchar(10)
)

create table IssueDetails
(
	MemberCode int,
	BookCode int,
	IssueDate DATETIME,
	ReturnDate DATETIME
)

--gan rang buoc:
alter table BookCode add CONSTRAINT chk_bkprice check(BookPrice > 10)
alter table BookCode add IssueID UNIQUEIDENTIFIER
alter table Member alter COLUMN PhoneNumber VARCHAR(12)
alter table IssueDetails add CONSTRAINT fk_bkcode FOREIGN KEY (BookCode) REFERENCES BookCode(BookCode)
alter table IssueDetails add CONSTRAINT fk_memcode FOREIGN KEY (MemberCode) REFERENCES Member(MemberCode)

--chen du lieu vao bang:
insert BookCode
	(BookTitle,Author,Edition,BookPrice,Copies)
values
	('CF', 'Barlow', 3, 12, 5),
	('HTML', 'Parker', 2, 20, 10),
	('RDBMS', 'Long', 1, 15, 8),
	('EPC', 'Norton', 1, 22, 9),
	('Java by Example', 'Giles', 2, 13, 16),
	('Guide to advanced Java', 'Harding', 1, 14, 18)

insert Member
	(Name,Address,PhoneNumber)
values
	('Dam Vinh Hung', 'Quan 1 HCM', '0913123123'),
	('My Le', 'Quan Thu Duc HCM', '0913123456'),
	('Kim Tu Long', 'Quan 10 HCM', '0912111222'),
	('Tai Linh', 'Hue', '0984123456'),
	('Ung Hoang Phuc', 'Quan 3 HCM', '0913444444'),
	('My Linh', 'Ba Dinh Ha Noi', '0984234432')

insert IssueDetails
values
	(1, 6, '10/09/2005', '10/20/2005'),
	(2, 5, '01/01/2006', '01/05/2006'),
	(3, 4, '01/10/2006', '01/15/2006'),
	(4, 3, '01/20/2006', '01/25/2006'),
	(5, 2, '02/01/2006', '02/05/2006'),
	(6, 1, '03/01/2006', '03/25/2006')

--bo sung cot gender cho bang Member va cap nhat gioi tinh:
alter table Member add Gender bit
update Member set Gender = case
when MemberCode in (1,3,4,5) then 1
when MemberCode in (2,6) then 0
end

--co bao nhieu nam, bao nhieu nu:
select Gender, COUNT(Gender)
from Member
GROUP by Gender

--tong so sach trong thu vien:
select sum(Copies)
from BookCode

--Nhung quyen sach co chu cai C:
select*
from BookCode
where BookTitle like '%c%'

--Doc gia song o TP HCM:
select*
from Member
where Address like '%HCM%'

--Nhung quyen sach duoc muon vao nam 2006:
select BookTitle
from IssueDetails a join BookCode b on a.BookCode=b.BookCode
where DATEPART(YY,IssueDate) = 2006
order by BookTitle asc