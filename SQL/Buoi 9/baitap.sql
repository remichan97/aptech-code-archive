
-- Create a new database called 'BaiTap8'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap8'
)
CREATE DATABASE BaiTap8
GO

use BaiTap8

--tao cac bang can thiet:
create table Food
(
	fID int PRIMARY KEY not null,
	Name nvarchar(30),
	Price money
)

create table FoodStuff
(
	sID int PRIMARY KEY not null,
	Name NVARCHAR(30),
	Type int
)

create TABLE FoodDetail
(
	fID int not null,
	sID int not null
)

--gan rang buoc:
alter table FoodDetail add CONSTRAINT fk_fid FOREIGN key (fID) REFERENCES Food(fID)
alter table FoodDetail add CONSTRAINT fk_sid FOREIGN key (sID) REFERENCES FoodStuff(sID)

--chen du lieu:
insert Food
values
	(1, N'Gà hấp xì dầu', 27000),
	(2, N'Sườn nõn sốt chanh', 33000),
	(3, N'Bò xào hành tỏi', 23000),
	(4, N'Cá thu sốt', 31000)

insert FoodStuff
values
	(1, N'Thịt gà', 1),
	(2, N'Thịt lợn', 1),
	(3, N'Thịt bò', 1),
	(4, N'Cá thu', 1),
	(5, N'Hành', 2),
	(6, N'Tỏi', 2),
	(7, N'Cà chua', 2),
	(8, N'Xì dầu', 2),
	(9, N'Chanh', 2),
	(10, N'Hạt tiêu', 2)

insert FoodDetail
values
	(1, 1),
	(1, 8),
	(2, 2),
	(2, 9),
	(2, 7),
	(2, 5),
	(3, 3),
	(3, 5),
	(3, 6),
	(4, 4),
	(4, 7)

--hien thi cac mon an va ten thuc pham dung de che bien:
SELECT a.Name, c.Name
from Food a join FoodDetail b on a.fID=b.fID join FoodStuff c on b.sID=c.sID
order by a.Name asc

--nhung loai nguyen lieu khong duoc dung de che bien mon nao:
SELECT*
from FoodStuff
where sID not in (select sID
from FoodDetail)

--nhung loai thuc pham dung de nau nhieu hon mot mon an:
select Name
from FoodStuff a join FoodDetail b on a.sID=b.sID
group by Name
HAVING COUNT(a.sID) > 1

--mon an duoc che bien tu nhieu loai thuc pham nhat:
select top(1)
	Name
from Food a join FoodDetail b on a.fID=b.fID
group by Name
order by COUNT(b.fID) desc

--hien thi danh sach cac loai thuc pham, voi 1 = thuc pham chinh, 2 = gia vi:
select sID, Name, [Type] = case [Type]
when 1 then N'Thực phẩm chính'
when 2 then N'Gia vị'
end
from FoodStuff

--tao view ten la vw_FoodList hien thi gia cac mon an sap xep theo gia giam dan:
go
create view vw_FoodList
AS
	select top(99.99) percent
		*
	from Food
	ORDER BY Price desc
go
--tang gia cac mon len 10%, in ra man hinh gia da thay doi, sau do tra ve nhu cu~:
update Food set Price = Price+(Price*0.1)
select*
from Food
update Food set Price = 27000 where fID = 1
update Food set Price = 33000 where fID = 2
update Food set Price = 23000 where fID = 3
update Food set Price = 21000 where fID = 4

--tao sp ten la sp_FoodChoice nhan vao mot tham so la so tien, sp nay se in ra cac mon nho hon so tien nhan vao:
go
CREATE PROCEDURE sp_FoodChoice
	(@Cash money)
as
select*
from Food
where Price < @Cash
go
--sua sp tren de nhan vao 2 gia tri, gia tri thu nhat la ten thuc pham, thu hai nhan vao 2 gia tri re va dat, sp nay se hien ra man hinh cac mon thoa man 2 dieu kien: mon an duoc che bien tu cac loai thuc pham tuong tu gia tri thu nhat, gia tri thu hai neu la re thi in ra cac mon < 30000, dat thi >=30000, '*' thi lay gia bat ky:
alter PROCEDURE sp_FoodChoice
	(@nguyenlieu nvarchar(30),
	@tien nvarchar(10))
as
if exists (select a.sID
from FoodDetail a join FoodStuff b on a.sID=b.sID
WHERE Name like N'%'+@nguyenlieu+'%')
BEGIN
	if @tien = 'Rẻ'
	BEGIN
		select c.Name,Price
		from FoodDetail a join FoodStuff b on a.sID=b.sID join Food c on a.fID=c.fID
		WHERE b.Name like N'%'+@nguyenlieu+'%' and Price < 30000
	end
	else if @tien ='Đắt'
	BEGIN
		select c.Name,Price
		from FoodDetail a join FoodStuff b on a.sID=b.sID join Food c on a.fID=c.fID
		WHERE b.Name like N'%'+@nguyenlieu+'%' and Price >= 30000
	end
	else if @tien = '*'
		select c.Name,Price
		from FoodDetail a join FoodStuff b on a.sID=b.sID join Food c on a.fID=c.fID
		WHERE b.Name like N'%'+@nguyenlieu+'%'
END
go
--tao mot trigger tg_NoUpdatePrice ngan khong cho phep update gia >=40000, neu co tinh thi bao ra thong bao 'Gia phai nho hon 40000'
create trigger tg_NoUpdatePrice on Food for update as
	if (select Price
from inserted) >= 40000
	BEGIN
	PRINT 'Giá phải nhỏ hơn 40000'
	ROLLBACK TRAN
end
go
--tao mot trigger tg_delFood tren bang Food de khi xoa mot mon an trong bang se xoa toan bo du lieu lien quan den no trong CSDL:
CREATE trigger tg_delFood on Food instead of DELETE AS
BEGIN
	alter table FoodDetail drop CONSTRAINT fk_fid
	delete from Food where fID in (select fID
	from deleted)
	delete from FoodDetail where fID in (select fID
	from deleted)
	alter table FoodDetail add CONSTRAINT fk_fid FOREIGN key (fID) REFERENCES Food(fID)
end
