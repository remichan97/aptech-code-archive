-- Code demo SQL:
--DataBase (DB): Cơ sở dữ liệu, là 1 kho chứa dữ liệu được phân
--loại theo phương pháp dùng bảng (table).
--Tạo cơ sở dữ liệu:
create database DB_C2005L;
--SQL Server không phân biệt hoa, thường
--Không bắt buộc phải có ; ở cuối lệnh
--Sử dụng DB:
use DB_C2005L;
--Tạo bảng:
create table Students(
	id int primary key identity not null,
	name varchar(30),
	age float,
	status tinyint
);
--primary key (PK): Khóa chính, để phân biệt các bản ghi
--(các dòng, record) với nhau, để thực hiện liên kết bảng.
--identiy: mặc định sẽ là identity(1,1), dùng để thực hiện
--việc tăng giá trị tự động cho cột tương ứng. Cú pháp hoàn
--chỉnh là identity(n,m): tự động tăng bắt đầu từ n, mỗi lần
--tăng m đơn vị.
--not null: Yêu cầu cột tương ứng không được null. Lưu ý
--rằng cột PK (cột chứa khóa chính) không được phép null.
--Chèn (Insert) dữ liệu vào bảng:
insert Students(name,age,status) values(N'Huyền Trang',19,1);
--Xem (Select) dữ liệu bảng:
select*from Students;
--Sửa cột:
alter table Students alter column name nvarchar(30);
--Sửa dữ liệu bảng:
update Students set name=N'Huyền Trang' where id in(1,2,3,4);
--Xóa dữ liệu bảng:
delete from Students where id=1;
--CRUD:Create Read Update Delete
--Tạo bảng Marks để chứa điểm số:
create table Marks(
	StudentId int not null,
	SubjectID int not null,
	mark float
);
--Thiết lập quan hệ giữa 2 bảng:
--Dùng khóa ngoại (Foreign Key - FK)
--Cú pháp:
-- ALTER TABLE Tên_bảng1 ADD CONSTRAINT Tên_ràng_buộc
-- FOREIGN KEY(Tên_cột_đặt_FK) REFERENCES
-- Tên_bảng2(Tên_cột_đặt_PK);
--Ví dụ:
alter table Marks add constraint fk_studentid foreign key
	(StudentId) references Students(id);
--Tạo bảng Subjects:
create table Subjects(
	id int not null identity,
	name nvarchar(30)
);
alter table Subjects add constraint pk_id primary key(id);
alter table Marks add constraint fk_subjectid foreign key
(SubjectId) references Subjects(id);
--Xóa ràng buộc:
alter table Marks drop constraint fk_subjectid;