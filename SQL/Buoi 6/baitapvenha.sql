-- Create a new database called 'BaiTap6'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap6'
)
CREATE DATABASE BaiTap6
GO

use BaiTap6

--tao cac bang can thiet:
create table Students
(
	StudentID int not null,
	Name VARCHAR(50),
	Age TINYINT,
	stGender bit
)

create table Projects
(
	PID int IDENTITY,
	PName varchar(50),
	Cost float,
	Type varchar(10)
)

create table StudentProject
(
	StudentID int not null,
	PID int not null,
	WorkDate date,
	Duration int
)

--tao cac rang buoc:
alter TABLE Students add CONSTRAINT chk_age check(Age between 15 and 33)
alter table Students add CONSTRAINT pk_id PRIMARY KEY (StudentID)
alter table Projects add CONSTRAINT pk_pid PRIMARY key (PID)
alter table StudentProject add CONSTRAINT pk_cmb PRIMARY key (StudentID,PID)
alter table StudentProject add CONSTRAINT df_dur DEFAULT(0) for Duration

--dua du lieu vao bang:
insert Students
	(StudentID,Name,Age,stGender)
values
	(1, 'Joe Hart', 25, 1),
	(2, 'Colin Doyle', 20, 1),
	(3, 'Paul Robinson', 16, Null),
	(4, 'Luis Garcia Paulson', 17, 0),
	(5, 'Ben Foster', 30, 1)

insert Projects
	(PName,Cost)
VALUES
	('NewYork Bridge', 100),
	('Tenda Road', 60),
	('Google Road', 200),
	('The Star Bridge', 50)

insert StudentProject
	(StudentID,PID,WorkDate,Duration)
values(1, 4, '05/15/2009', 3),
	(2, 2, '05/14/2009', 5),
	(2, 3, '05/20/2009', 6),
	(2, 1, '05/16/2009', 4),
	(3, 1, '05/16/2009', 6),
	(3, 4, '05/19/2009', 7),
	(4, 4, '05/21/2009', 8)

--Cap nhat gia tri cho cot Type bang Project:
update Projects set [Type] = case 
when Cost < 80 then 'Education'
when Cost >= 80 and Cost <= 150 then 'Normal'
when Cost >150 then 'Goverment'
end

--Nhung sinh vien lam viec cho hon 1 du an:
select StudentID, count(a.PID) [Project Involved]
from StudentProject a join Projects b on a.PID=b.PID
group by StudentID
HAVING COUNT(a.PID) > 1

--Nhung sinh vien co tong so thoi gian lam viec lon nhat dua theo cot duration:
select StudentID, sum(Duration)
from StudentProject
group by StudentID
order by sum(Duration) desc

--Sinh vien co ten chua cum tu 'Paul' lam viec cho du an 'The Star Bridge':
select a.StudentID, Name, pName
from StudentProject a join Students b on a.StudentID=b.StudentID join Projects c on a.PID=c.PID
WHERE Name like 'Paul%' and pName like 'The Star Bridge'

--Sinh vien khong lam du an nao:
select StudentID, Name
from Students
where StudentID not in (select StudentID
from StudentProject)
GO
--Tao view 'vvStudentProject' de hien thi thong tin ten sv, ten du an, workdate va duration, sap xep tang dan theo ten sinh vien:
create view vvStudentProject
as
	SELECT top(99.99) percent
		Name, pName, WorkDate, Duration
	from StudentProject a join Students b on a.StudentID=b.StudentID join Projects c on a.PID=c.PID
	order by Name asc
go
--Tao index cho hai cot Student Name va Project Name cua view 'vvStudentProject'
alter VIEW vvStudentProject
with
	encryption,
	SCHEMABINDING
as
	SELECT Name, pName, WorkDate, Duration
	from dbo.StudentProject a join dbo.Students b on a.StudentID=b.StudentID join dbo.Projects c on a.PID=c.PID
go
create unique CLUSTERED index ixStudentName on vvStudentProject(Name, pName)
go
--Tao thu tuc luu tru spWorking co mot tham so nhan vao ten sinh vien, neu co trong bang thi hien thi ten va du an, con lai thi hien thi toan bo ten sinh vien va du an da tham gia:
create PROCEDURE spWorking
	(@stdName varchar(50))
AS
BEGIN
	if exists(select Name, PName
	from Students a join StudentProject b on a.StudentID=b.StudentID join Projects c on b.PID=c.PID
	where Name LIKE '%'+@stdName+'%')
select Name, PName
	from Students a join StudentProject b on a.StudentID=b.StudentID join Projects c on b.PID=c.PID
	where Name like '%'+@stdName+'%'
else if (@stdName = 'any')
select Name, PName
	from Students a join StudentProject b on a.StudentID=b.StudentID join Projects c on b.PID=c.PID
else
PRINT 'Not Found!'
end
go
--Tao trigger tgUpdateTrig tren bang Student, trigger nay co nhiem vu nhu sau: khi sua StudentID cua bang Students thi cung se sua StudentID cua bang StudentProject:
-- inserted và updated được sinh ra khi trigger được kích hoạt, lưu các thay đổi liên đới, sau đó hai bảng đó sẽ bị drop sau khi trigger kết thúc công việc
-- inserted để lưu các giá trị đưa vào, deleted để lưu các giá trị bị loại bỏ
create TRIGGER tgUpdateTrig on Students INSTEAD OF update AS
BEGIN
	update Students set StudentID = (select StudentID
	from inserted) where StudentID = (select StudentID
	from deleted)
	update StudentProject set StudentID = (select StudentID
	from inserted) where StudentID = (select StudentID
	from deleted)
END
--Tao thu tuc spDropOut co mot tham so nhan vao ten du an, neu co thi se xoa toan bo thong tin lien quan den du an do:
go
create PROCEDURE spDropOut
	(@pName varchar(50))
AS
BEGIN
	if exists (select*
	from Projects
	where PName = @pName)
	BEGIN
		DELETE from StudentProject where PID in (select PID
		from Projects
		where PName like '%'+@pName+'%')
		Delete from Projects where PName like '%'+@pName+'%'
	END
END
go