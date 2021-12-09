-- Create a new database called 'BaiTap5'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap5'
)
CREATE DATABASE BaiTap5
GO

use BaiTap5

--tao cac bang can thiet

create table Student
(
	RN int IDENTITY,
	Name NVARCHAR(40),
	Age tinyint,
	Gender bit
)

create table Subjects
(
	sID int IDENTITY,
	sName VARCHAR(20),
)

create table StudentSubject
(
	RN int not null,
	sID int not null,
	Mark float,
	Date date
)

--gan rang buoc
alter table Student add CONSTRAINT pk_std PRIMARY key(RN)
alter table Subjects add CONSTRAINT pk_sid PRIMARY key(sID)
alter table StudentSubject add CONSTRAINT pk_rn PRIMARY key (Rn,sID)
alter table StudentSubject add CONSTRAINT chk_mark CHECK (0 <= Mark and Mark <= 10)
alter table StudentSubject add CONSTRAINT fk_rn FOREIGN key (RN) REFERENCES Student(RN)
alter table StudentSubject add CONSTRAINT fk_sid FOREIGN key (sID) REFERENCES Subjects(sID)

--dua du lieu

insert Student
	(Name, Age)
values
	(N'Mỹ Linh', 19),
	(N'Đàm Vĩnh Hưng', 19),
	(N'Kim Tử Long', 20),
	(N'Tài Linh', 18),
	(N'Mỹ Lệ', 21),
	(N'Ngọc Oanh', 20)

insert Subjects
	(sName)
values
	('SQL'),
	('LGC'),
	('HTML'),
	('CF')

insert StudentSubject
	(RN,sID,Mark,[Date])
values
	(1, 1, 8, '7/28/2005'),
	(2, 2, 3, '7/29/2005'),
	(3, 3, 9, '7/31/2005'),
	(4, 1, 5, '7/30/2005'),
	(5, 4, 10, '7/19/2005'),
	(6, 1, 9, '7/25/2005')

--cap nhat gioi tinh cho hoc vien:
update Student set Gender = 0 where RN in (1,4,5)
update Student set Gender = 1 where RN = 3

--Bo sung them mon hoc:
insert Subjects
	(sName)
VALUES
	('Core'),
	('Java'),
	('VB.NET')

--Cac mon hoc ma hoc vien chua co diem:
select sID, sName
from Subjects
where sID not in (select sID
from StudentSubject)
--Mon hoc co nhieu hon 1 diem:
select sName, count(a.sID) [Subject ID]
from Subjects a join StudentSubject b on a.sID=b.sID
group by sName
having count(b.sID) > 1
--Danh sach cac mon hoc, diem cao nhat moi mon, mon chua co diem thi dat la NULL:
select sName, max(Mark) [Max Mark]
from Subjects a left JOIN StudentSubject b on a.sID=b.sID
group by sName
ORDER by max(Mark)
--Hien thi thong tin RN, sID, Name, Age, Gender, sName, Mark, Date, voi truong Gender hien thi Male thay cho 1, Female thay cho 0:
select a.RN, c.sID, Name, Age, sName, Mark, Date, Gender = case Gender
when 0 then 'Female'
when 1 then 'Male'
else 'Unknown'
end
from StudentSubject a join Student b on a.RN=b.RN join Subjects c on a.sID=c.sID
--Tao index tren cac cot Name cua bang Student, sName cua bang Subjects, cot (RN,sID) cua bang StudentSubject:
create INDEX idx_name on Student(Name)
create index idx_sname on Subjects(sName)
create index idx_rn on StudentSubject(RN,sID)
--Danh sach cac hoc sinh gioi (DTB > 8.0 va khong co mon nao duoi diem 5):
select b.RN,Name, avg(Mark)[Average]
from StudentSubject a join Student b on a.RN=b.RN
where Mark > 5
group by b.RN,Name
having avg(Mark) > 8
--Danh sach hoc sinh kha (DTB > 6.5 va chi duoc mot mon duoi 5 diem nhung diem nay khong duoc duoi 3)
select b.RN,Name, avg(Mark)[Average]
from StudentSubject a join Student b on a.RN=b.RN
where Mark >= 3 and (select count(Mark) from StudentSubject where Mark >=3 and Mark < 5) <= 1
group by b.RN, Name
having avg(Mark) > 6.5