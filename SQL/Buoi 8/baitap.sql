-- Create a new database called 'BaiTap7'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap7'
)
CREATE DATABASE BaiTap7
GO

use BaiTap7

--tao cac bang can thiet:
create table Customer
(
	CustomerID int not null,
	Name VARCHAR(30),
	Birth date,
	Gender bit
)

create table Product
(
	ProductID int not null,
	Name varchar(30),
	Pdesc text,
	Pimage varchar(200),
	PStatus bit
)

create table Comment
(
	ComID int IDENTITY not null,
	ProductID int not null,
	CustomerID int not null,
	Date DATETIME,
	Title varchar(200),
	Content text,
	Status bit
)

--chen cac du lieu:
insert Customer
	(CustomerID,Name,Birth,Gender)
values
	(1, 'Jonny Owen', '10/10/1980', 1),
	(2, 'Christina Tiny', '03/10/1989', 0),
	(3, 'Garry Kelly', '03/16/1990', null),
	(4, 'Tammy Beckham', '05/17/1980', 0),
	(5, 'David Phantom', '12/30/1987', 1)

insert Product
	(ProductID,Name,Pdesc,Pimage,PStatus)
values
	(1, 'Nokia N90', 'Mobile Nokia', 'image1.jpg', 1),
	(2, 'HP DV6000', 'Laptop', 'image2.jpg', null),
	(3, 'HP DV2000', 'Laptop', 'image3.jpg', 1),
	(4, 'Samsung G488', 'Mobile Samsung', 'image4.jpg', 0),
	(5, 'LCD Plasma', 'TV LCD', 'image5.jpg', 0)

insert Comment
	(ProductID,CustomerID,[Date],Title,Content,[Status])
values
	(1, 1, '03/15/2009', 'Hot product', null, 1),
	(2, 2, '03/14/2009', 'Hot price', 'Very much', 0),
	(3, 2, '03/20/2009', 'Cheapest', 'Unlimited', 0),
	(4, 2, '04/16/2009', 'Sale off', '50%', 1)

--gan rang buoc:
alter table Comment add CONSTRAINT df_date DEFAULT(getdate()) for Date
alter table Customer add CONSTRAINT pk_cid PRIMARY KEY (CustomerID)
alter table Product add CONSTRAINT pk_pid PRIMARY key (ProductID)
alter table Comment add CONSTRAINT pk_comid PRIMARY KEY (ComID)
alter table Comment add CONSTRAINT fk_pid FOREIGN KEY (ProductID) references Product(ProductID)
alter table Comment add CONSTRAINT fk_cid FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID)
alter table Product add CONSTRAINT un_img UNIQUE(Pimage)
--san pham co PStatus la null hoac 0:
select*
from Product
where PStatus is null or PStatus = 0
--san pham khong co binh luan nao:
select ProductID, Name
from Product
where ProductID not in (select ProductID
from Comment)
--nhung khach co nhieu binh luan nhat:
select top(1)
	Name, count(b.CustomerID) [Comment Count]
from Comment a join Customer b on a.CustomerID=b.CustomerID
group by Name
--tao view 'vwFull_Information' de xem cac binh luan gom cac cot: ma binh luan, ten khach, ten san pham, ngay binh luan, noi dung va trang thai binh luan, trong do trang thai 1 thay bang 'Accepted', 0 thay bang 'Not Accepted'
go
create view vwFull_Information
as
	select ComID, b.Name, c.Name[Product Name], [Date], Content, [Status] = case Status
when 0 then 'Not Accepted'
when 1 then 'Accepted'
end
	from Comment a join Customer b on a.CustomerID=b.CustomerID join Product c on a.ProductID=c.ProductID
--tao view 'vwCustomerList' de liet ke tat ca thong tin cua khach cong them cot Status, trong do cot Gender hien thi la Male thay cho 1, Female thay cho 0, Unknown thay cho Null, cot Status hien thi la Old neu tuoi >= 30 va young neu tuoi < 30
go
create view vwCustomerList
AS
	select CustomerID, Name, Birth, Gender = case Gender
when '0' then 'Female'
when '1' then 'Male'
else 'Unknown'
end, Status = case
when DATEDIFF(yy,Birth,getdate()) >= 30 then 'Old'
when DATEDIFF(yy,Birth,GETDATE()) < 30 then 'Young'
end
	from Customer
--sua view 'vCustomerList' de no chi chua cac cot CustomerID, Name, Birth, Gender cua bang Customer va tao index co ten ixCustomerName tren cot [Customer Name] cua view nay:
go
alter view vwCustomerList
with
	SCHEMABINDING
AS
	select CustomerID, Name[Customer Name], Birth, Gender
	from dbo.Customer
go
create UNIQUE CLUSTERED index ixCustomerName on vwCustomerList ([Customer Name])
--Tao sp ten spStudent co mot tham so ten la @Name: neu tim thay @Name o bang Product thi se liet ke tat ca cac binh luan cua san pham co ten tuong tu @Name, neu khong thi kiem tra xem @Name co trong bang Customer khong, neu co thi liet ke tat ca binh luan cua khach co ten tuong tu @Name, neu @Name nhan vao '*' thi se liet ke toan bo comment dang co:
go
create PROCEDURE spStudent
	(@Name varchar(30))
as
BEGIN
	if exists(select Name
	from Product
	where Name like '%'+@Name+'%')
	BEGIN
		select a.ProductID, Title, Content
		from Comment a join Product b on a.ProductID=b.ProductID
		where Name like '%'+@Name+'%'
	END
	else if exists (select Name
	from Customer
	where Name like '%'+@Name+'%')
	BEGIN
		select a.CustomerID, Name, Title, Content
		from Comment a join Customer b on a.CustomerID=b.CustomerID
		where Name like '%'+@Name+'%'
	end
	else if @Name = '*'
		SELECT*
	From Comment
end
--Tao trigger co ten tgUpdateProduct de khi cap nhat ProductID o Product thi cung se cap nhat ProductID cua bang Comment:
go
create TRIGGER tgUpdateProduct on Product instead of Update as
BEGIN
	alter table Comment drop CONSTRAINT fk_pid
	update Comment set ProductID = (select ProductID
	from inserted) where ProductID = (select ProductID
	from deleted)
	update Product set ProductID = (select ProductID
	from inserted) where ProductID = (select ProductID
	from deleted)
	alter table Comment add CONSTRAINT fk_pid FOREIGN KEY (ProductID) REFERENCES Product(ProductID)
END
--Tao sp co ten la spDropOut co tham so la ten khach hang, neu tim thay trong cot Name cua bang Customer thi se xoa toan bo thong tin lien quan cua khach hang nay ra khoi CSDL:
go
CREATE PROCEDURE spDropOut(@CustomerName varchar(30))
AS
BEGIN
	if exists (select Name
	from Customer
	where Name like '%'+@CustomerName+'%')
	BEGIN
		delete from Customer where Name like '%'+@CustomerName+'%'
		delete from Comment where CustomerID in (select CustomerID
		from Customer
		where Name like '%'+@CustomerName+'%')
	END
END