-- Create a new database called 'BaiTap9'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap9'
)
CREATE DATABASE BaiTap9
GO

use BaiTap9

--tao cac bang can thiet:
create table Sach
(
	MaSach int IDENTITY primary key not null,
	TenSach varchar(90),
	TacGia varchar(40),
	NhaXB varchar(30),
	ChuDe varchar(30),
	DonGia int,
	TrongKho int,
)

create table KhachHang
(
	MaKH int not null IDENTITY PRIMARY KEY,
	TenKH varchar(50) not null,
	DiaChi varchar(60) not null,
	Quan varchar(30) not null,
	DienThoai int not null,
	NguoiGT varchar(30)
)

create table SachBan
(
	SoHD int not null IDENTITY PRIMARY KEY,
	MaKH int,
	MaSach int,
	NgayMua date,
	DonGia int,
	SoLuong int
)

--tao cac rang buoc:
alter table SachBan add CONSTRAINT fk_makh FOREIGN key (MaKH) REFERENCES KhachHang(MaKH)
alter table SachBan add CONSTRAINT fk_masach FOREIGN KEY (MaSach) REFERENCES Sach(MaSach)

--chen du lieu:
insert Sach
	(TenSach,TacGia,NhaXB,ChuDe,DonGia,TrongKho)
VALUES
	('Hoang hon tren song', 'Gia Phong', 'Van hoa', 'Tinh yeu', 120, 11),
	('Cay lua nuoc', 'Le May', 'KHKT', 'Khoa hoc', 30, 24),
	('Tam ly truoc mua thi', 'Hai Dang', 'Giao duc', 'Tam ly', 42, 32)

insert KhachHang
	(TenKH,DiaChi,Quan,DienThoai,NguoiGT)
VALUES
	('Le Cong', '22 Hang Buom', 'Hoan Kiem', 098123654, 'Hoang Kim'),
	('Van Nghe', '19 Lo Duc', 'Hoan Kiem', 098123456, null),
	('Tran Thong', '19 Doi Can', 'Ba Dinh', 012345678, null),
	('Hoang Tin', '38 Linh Nam', 'Hoang Mai', 0913037950, null)

insert SachBan
	(MaKH,MaSach,NgayMua,DonGia,SoLuong)
VALUES
	(1, 2, '11/22/2006', 30, 5),
	(1, 3, '7/15/2005', null, 4),
	(2, 1, '4/25/2006', null, 7),
	(3, 1, '11/15/2005', null, 9)

--hien thi cac dau sach xuat ban boi nha xuat ban "KHKT":
select*
FROM Sach
where NhaXB like '%KHKT%'

--Danh sach nha xuat ban, va so dau sach tuong ung cua tung nxb theo thu tu tang dan cua nha xuat ban:
select NhaXB, TenSach
from Sach
ORDER by NhaXB asc

--Danh sach khach hang song trong quan Ba Dinh, cung voi ten dau sach khach hang da mua:
select TenKH, Quan, TenSach
from KhachHang a join SachBan b on a.MaKH=b.MaKH join Sach c on b.MaSach=c.MaSach
where Quan like '%Ba Dinh%'

--Danh sach khach hang, va tong so sach ma tung khach hang da mua:
select a.MaKH, TenKH, SUM(SoLuong) [So luong sach da mua]
from SachBan a join KhachHang b on a.MaKH=b.MaKH
group by a.MaKH,TenKH

--Danh sach khach hang, ten nha xuat ban cua nhung dau sach ho da mua:
select TenKH, NhaXB
from SachBan a join KhachHang b on a.MaKH=b.MaKH join Sach c on a.MaSach=c.MaSach

--Danh sach khach hang, cung voi so lan mua sach cua tung khach hang do:
select TenKH, count(a.MaKH) [So lan mua sach]
from SachBan a join KhachHang b on a.MaKH=b.MaKH
group by TenKH

--Danh sach cac quan va tong gia tri mua sach cua cac khach song trong quan do theo thu tu giam dan:
select Quan, sum(case when SoLuong*b.DonGia is null then 0 else SoLuong*b.DonGia end) [Tong gia tri sach da mua]
from SachBan a full join Sach b on a.MaSach=b.MaSach full join KhachHang c on a.MaKH=c.MaKH
GROUP by Quan ORDER by [Tong gia tri sach da mua] desc
