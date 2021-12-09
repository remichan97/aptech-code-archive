-- Create a new database called 'BaiTap4'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap4'
)
CREATE DATABASE BaiTap4
GO

use BaiTap4

--tao cac bang can thiet:
create table Customers
(
	MaKhach int IDENTITY primary key,
	Ten varchar(40),
	SoDienThoai int not null
)

create table Items
(
	MaHang int IDENTITY PRIMARY key,
	Ten varchar(20),
	SoLuong tinyint not null,
	DonGia int
)

CREATE table CustomerItem
(
	MaKhach int not null,
	MaHang int not null,
	SoLuongMua int
)

-- dien du lieu
insert Items
	(Ten,SoLuong,DonGia)
values
	('Tu lanh', 5, 3500),
	('Ti vi', 2, 3000),
	('Dieu hoa', 1, 8000),
	('Quat da', 5, 1700),
	('May giat', 3, 5000)

insert Customers
	(Ten,SoDienThoai)
values
	('Dinh Truong Son', 1234567),
	('Mai Thanh Minh', 1357999),
	('Nguyen Hong Ha', 2468888)

insert CustomerItem
	(MaKhach, MaHang, SoLuongMua)
values(1, 1, 4),
	(1, 5, 1),
	(2, 2, 1),
	(3, 3, 1),
	(3, 1, 1)

-- gan rang buoc
alter table CustomerItem add CONSTRAINT pk_ci PRIMARY KEY (MaKhach, MaHang)
alter table CustomerItem add CONSTRAINT fk_khach FOREIGN KEY (MaKhach) REFERENCES Customers(MaKhach)
alter table CustomerItem add CONSTRAINT fk_hang FOREIGN KEY (MaHang) REFERENCES Items(MaHang)

--tong so tien thu duoc tu cac khach hang
select sum(DonGia*SoLuongMua)
from CustomerItem a join Items b on a.MaHang=b.MaHang
--ten va so tien da mua cua khach hang da tra tien nhieu nhat
select top(1)
	c.Ten, sum(DonGia*SoLuongMua)
from CustomerItem a join Items b on a.MaHang=b.MaHang join Customers c on a.MaKhach=c.MaKhach
GROUP by c.Ten
--khach hang co 2468888 co mua Tu lanh khong?
if EXISTS (select SoDienThoai, MaHang
from Customers a join CustomerItem b on a.MaKhach=b.MaKhach
where MaHang = 1 and SoDienThoai = 2468888) print 'Co mua' else print'Khong mua'
--Tong so hang hoa va so ton tai trong kho
select a.Ten,isnull((a.Soluong - b.[Tong Mua]),a.Soluong) as [Hang ton],a.DonGia,(isnull((a.Soluong - b.[Tong Mua]),a.Soluong)*a.DonGia) 
from Items a left join (select Mahang,sum(SoLuongMua) as [Tong Mua] from CustomerItem group by Mahang) b on a.MaHang=b.Mahang ;

select sum(a.Soluong)-sum([Tong Mua]) as [HangTonKho],sum(a.DonGia*a.Soluong)-sum(a.DonGia*[Tong Mua]) as [TienTonKho] from Items a left join (select Mahang,sum(SoLuongMua) as [Tong Mua] from CustomerItem group by Mahang) b on a.MaHang=b.Mahang ;
--Danh sach 3 mon ban chay nhat
select top(3) with ties
	MaHang, sum(SoLuongMua)
from CustomerItem
group by MaHang
order by sum(SoLuongMua) desc
--Cac mon hang chua ban duoc san pham nao
select Ten from Items where MaHang not in (select MaHang from CustomerItem)
--Nhung nguoi mua nhieu hon 1 sp:
select Ten, count(distinct MaHang) as [Ma Hang] from Customers a join CustomerItem b on a.MaKhach=b.MaKhach GROUP by Ten having count(MaHang) > 1 
--Nhung nguoi mua hang nhieu hon 1 cai:
select a.MaKhach, Ten, SoLuongMua
from CustomerItem a join Customers b on a.MaKhach=b.MaKhach
where SoLuongMua >1
--Ten Khach hang, tong tien mua cua tung khach, hien thi them cot Level voi gia tri dien theo tieu chi: tong tien < 5000 thi gia tri la 'Level 1' tong tien trong khoang 5000 den 1000 thi gia tri la 'Level 2' tong tien >=10000 dien gia tri 'V.I.P'
select c.Ten[Ten Khach Hang], sum(DonGia*SoLuongMua)[Tong Tien], Level= case when sum(DonGia*SoLuongMua) < 5000 then 'Level 1' when sum(DonGia*SoLuongMua) >= 5000 and sum(DonGia*SoLuongMua) < 10000 then 'Level 2' when sum(DonGia*SoLuongMua) >= 10000 then 'V.I.P' end
from CustomerItem a join Items b on a.MaHang=b.MaHang join Customers c on a.MaKhach=c.MaKhach
group by c.Ten, c.MaKhach