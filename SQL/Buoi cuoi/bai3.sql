-- Create a new database called 'BaiTap12'
-- Connect to the 'master' database to run this snippet
USE master
GO
-- Create the new database if it does not exist already
IF NOT EXISTS (
	SELECT name
FROM sys.databases
WHERE name = N'BaiTap12'
)
CREATE DATABASE BaiTap12
GO

use BaiTap12

--tao cac bang can thiet:
create table NhaCungCap
(
	MaNhaCC nvarchar(10) not null primary key,
	TenNhaCC nvarchar(40),
	DiaChi NVARCHAR(60),
	Phone nvarchar(24),
	Fax nvarchar(24),
	HomePage ntext
)

create table NhanVien
(
	MaNV nvarchar(10) primary key not null,
	HoTen nvarchar(20),
	ChucDanh nvarchar(30),
	NgaySinh smalldatetime,
	NgayNhanViec smalldatetime,
	DiaChi nvarchar(50),
	Phone nvarchar(20),
	Photo IMAGE,
	GhiChu ntext
)

create table HoaDon
(
	MaHD nvarchar(10) not null primary key,
	MaKH nvarchar(10),
	MaNV nvarchar(10),
	NgayLapHD smalldatetime,
	NgayNhanHang smalldatetime,
	Tien int,
	thue float,
	TongSoTien int
)

create table LoaiSanPham
(
	MaLoaiSP nvarchar(10) not null primary key,
	TenLoaiSP nvarchar(15),
	MoTa ntext
)

create table SanPham
(
	MaSp NVARCHAR(10) not null primary key,
	TenSP NVARCHAR(40),
	MaNhaCC nvarchar(10),
	MaLoaiSP nvarchar(10),
	DVT NVARCHAR(20),
	DonGia smallint,
	SoLuong smallint,
	SoLuongTT smallint,
	Discontinued bit
)

create table HoaDonChiTiet
(
	MaHD nvarchar(10),
	MaSP nvarchar(10),
	DonGia int,
	SoLuong smallint,
	GiamGia real,
	ThanhTien int
)

create table KhachHang
(
	MaKh NVARCHAR(10) not null primary key,
	TenKH nvarchar(30),
	DiaChi ntext,
	Phone nvarchar(24),
	Email nvarchar(30)
)

--gan rang buoc:
alter table SanPham add CONSTRAINT fk_mlsp FOREIGN key (MaLoaiSP) REFERENCES LoaiSanPham(MaLoaiSP)
alter table SanPham add CONSTRAINT fk_mncc FOREIGN key (MaNhaCC) REFERENCES NhaCungCap(MaNhaCC)
alter table HoaDonChiTiet add CONSTRAINT fk_msp FOREIGN Key (MaSP) REFERENCES SanPham(MaSP)
alter table HoaDonChiTiet add CONSTRAINT fk_mhd FOREIGN key (MaHD) REFERENCES HoaDon(MaHD)
alter table HoaDon add CONSTRAINT fk_mkh FOREIGN key (MaKH) REFERENCES KhachHang(MaKH)

--chen du lieu:
insert NhaCungCap
VALUES
	('BAN', 'Cong ty Ban Mai', '64 Hang Bun', '048286745', null, 'www.binhminh.com'),
	('OCE', 'Cong ty Ocean', '26 Tran Quy Cap', '048924712', null, 'www.ocean.com'),
	('RDO', 'Cong ty Rang Dong', '97 Hoang Hoa Tham', '048923711', null, 'www.rdong.com')

insert KhachHang
VALUES
	('01', 'Hoa Binh', 'Ha Noi', '0913567222', 'hb@fpt.vn'),
	('02', 'Quang Long', 'Ha Noi', '048123445', 'qlong@yahoo.com'),
	('03', 'Nguyen Tuan', 'Hai Phong', '098467231', 'tuan@yahoo.com')

insert NhanVien
	(MaNV,HoTen,ChucDanh,NgaySinh,NgayNhanViec,DiaChi,Phone)
VALUES
	('01', 'Lan Huong', 'Ban Hang', '11/23/1980', '1/15/2004', 'Hoa Binh', '091234865'),
	('02', 'Bich Hue', 'Tiep thi', '12/31/1979', '1/22/2001', 'Quang Binh', '098568253'),
	('03', 'Tung Chi', 'Ban Hang', '8/9/1986', '1/14/2005', 'Ha Noi', '0912367299'),
	('04', 'Kien Cuong', 'Thu kho', '9/19/1979', '1/22/2003', 'Ha Noi', '0912367299')

insert LoaiSanPham
VALUES
	('DL', 'Dien lanh', null),
	('DT', 'Dien tu', null),
	('MP', 'Hang my pham', null),
	('TD', 'Hang tieu dung', null)

insert SanPham
values
	('001', 'Vo tuyen', 'BAN', 'DT', 'Chiec', 4000, 25, 5, 0),
	('002', 'Radio', 'BAN', 'DT', 'Chiec', 200, 150, 20, 0),
	('003', 'CD Player', 'BAN', 'DT', 'Chiec', 2000, 45, 10, 0),
	('004', 'Tu lanh', 'RDO', 'DL', 'Chiec', 6000, 22, 5, 0),
	('005', 'May lam kem', 'RDO', 'DL', 'Chiec', 7000, 19, 4, 0),
	('007', 'May dieu hoa', 'RDO', 'DL', 'Chiec', 9000, 38, 7, 0),
	('008', 'Xa phong thom', 'OCE', 'TD', 'Banh', 6, 200, 50, 0),
	('009', 'Duong', 'OCE', 'TD', 'Kg', 9, 550, 50, 0),
	('010', 'Sua', 'OCE', 'TD', 'Hop', 120, 80, 20, 0),
	('011', 'Mi miliket', 'OCE', 'TD', 'Thung', 200, 56, 8, 0)

INSERT HoaDon
values
	('01', '02', '01', '12/14/2007', '12/15/2007', 0, 0.05, 0),
	('02', '01', '01', '1/19/2006', '2/15/2006', 0, 0.05, 0),
	('03', '02', '02', '10/30/2006', '1/1/2006', 0, 0.1, 0)

insert HoaDonChiTiet
values
	('03', '003', 0, 3, 0.02, 0),
	('03', '007', 0, 2, 0.01, 0),
	('03', '011', 0, 10, 0, 0),
	('02', '010', 0, 11, 0.04, 0),
	('02', '002', 0, 2, 0.01, 0),
	('01', '004', 0, 1, 0.05, 0),
	('01', '009', 0, 15, 0.04, 0)

--cap nhat cot thanh tien cua bang HoaDonChiTiet theo cong thuc: ThanhTien= DonGia*SoLuong*(1-GiamGia):
update HoaDonChiTiet set HoaDonChiTiet.DonGia = SanPham.DonGia from SanPham inner join HoaDonChiTiet on HoaDonChiTiet.MaSP=SanPham.MaSp where HoaDonChiTiet.MaSP in (select MaSP from SanPham)
update HoaDonChiTiet set ThanhTien = DonGia*SoLuong*(1-GiamGia)

--cap nhat thong tin truong Tien trong hoa don = tong so tien cua cac mat hang trong hoa don = tong cot ThanhTien cua cac ban ghi trong HoaDonChiTiet co cung MaHD. Cap nhat truong TongSoTien=Tien*(1+Thue):
