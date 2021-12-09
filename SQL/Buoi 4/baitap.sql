-- Create a new database called 'BaiTap3'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
		FROM sys.databases
		WHERE name = N'BaiTap3'
)
CREATE DATABASE BaiTap3
GO

use BaiTap3

--tao cac bang can thiet
create TABLE Customer (
	cID int IDENTITY PRIMARY key,
	cName VARCHAR(25),
	cAge tinyint,
	cGender bit
)

create TABLE Orders (
	oID int IDENTITY PRIMARY KEY,
	cID int,
	oDate Date
)

create TABLE Product (
	pID int IDENTITY PRIMARY KEY,
	pName VARCHAR(25),
	pPrice int
)

create TABLE OrderDetail (
	oID int,
	pID int,
	odQTY int
)

--gan rang buoc
alter table Orders add CONSTRAINT fk_cid foreign key (cID) references Customer(cID)
alter table OrderDetail add CONSTRAINT fk_oid foreign key (oID) references Orders(oID)
alter table OrderDetail add CONSTRAINT fk_pid foreign key (pID) references Product(pID)

--dua du lieu
insert Customer (cName,cAge,cGender) values ('Elisha Cuthbert', 26, 0), ('Cristinado Ronaldo', 23, 1), ('Gemma Atkinson', 24, 0), ('Maria Sharapova', 22, Null)
insert Orders (cID,oDate) values (1, '3/21/2008'), (2, '3/23/2008'), (1, '3/16/2008')
insert Product (pName,pPrice) values ('Washing Machine', 3), ('Fridge', 5), ('Air Conditioner', 7), ('Electric Fan', 1), ('Electric Cooker', 2)
INSERT OrderDetail (oID,pID,odQTY) values (1,1,3),(1,3,7),(1,4,2),(2,1,1),(3,1,8),(2,5,4),(2,3,3)
--danh sach hoa don theo oDate
select*from Orders order by oDate
--danh sach khach hang gom ten va ky tu dau tien cua ten
select cName, left(cName, 1)[First Character] from Customer
--san pham co gia cao nhat
SELECT top(1) pName[Product Name], pPrice[Highest Price] from Product order by pPrice desc
--san pham co gia thap nhat
SELECT top(1) pName[Product Name], pPrice[Highest Price] from Product order by pPrice asc
--hien thi danh sach theo dang: Price of + pName + is + pPrice +
SELECT 'Price of '+pName+' is ' +CONVERT(char(3),pPrice) from Product
--tao bang moi chua 3 san pham gia cao nhat va ten san pham do
SELECT top(3) pName, pPrice into Top3Product from Product order by pPrice desc
--khach hang co phan ten dai 15 ky tu
select cName from Customer WHERE cName LIKE '_______________'
--cac san pham co chua cum tu 'Electric'
select pName from Product WHERE pName like '%Electric%'
--ngay gio hien tai va ngay gio cong them 5000 phut
SELECT GETDATE(), DATEADD(mi,5000,getdate())
--xoa toan bo khoa ngoai
alter TABLE OrderDetail drop CONSTRAINT fk_oid,fk_pid
ALTER TABLE Orders DROP CONSTRAINT fk_cid
--xoa toan bo cac bang
drop table Customer
drop TABLE Product
drop table Top3Product
drop table OrderDetail
DROP table Orders
--xoa database
use master
drop DATABASE BaiTap3