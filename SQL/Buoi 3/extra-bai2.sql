--Extra:
--1.
select AVG(age) [Tuổi trung bình]
from Student;
--2.
--Cách 1:
select name[Họ và tên], age[Tuổi cao nhất]
from Student
where Age=(select MAX(age)
from Student);--truy vấn con
--3.
select name[Họ và tên], age[Tuổi cao nhất]
from Student
where Age=(select MIN(age)
from Student);--truy vấn con
--4.
select name[Tên môn học], mark[Điểm cao nhất]
from Test a
	join StudentTest b on a.TestID=b.TestID
where mark=(select MAX(mark)
from StudentTest);--truy vấn con
--5.
select name[Tên môn học], mark[Điểm cao nhất]
from Test a
	join StudentTest b on a.TestID=b.TestID
where mark=(select MIN(mark)
from StudentTest);--truy vấn con
--6.
select name, date
from Student a join StudentTest b
	on a.RN=b.RN
where date=(select MAX(date)
from StudentTest);
--7.
select name, date
from Student a join StudentTest b
	on a.RN=b.RN
where date=(select MIN(date)
from StudentTest);
--8.
select SUM(age)[Tổng tuổi]
from Student;
--9.
select name, DATEDIFF(dy,date,getdate())
from Test a
	join StudentTest b on a.TestID=b.TestID
--select name,DATEDIFF(dy,date,getdate()) from Test
--	join StudentTest on Test.TestID=StudentTest.TestID
--select getdate();
--SELECT DATEADD(MM,3,'2010-06-20');
--SELECT DATENAME(MM,GETDATE());
--SELECT DATEPART(MM,GETDATE());
--10.
select name, mark
from Student a join StudentTest b
	on a.RN=b.RN
where Mark=(select MAX(mark)
from StudentTest);
--11.
select name, mark
from Student a join StudentTest b
	on a.RN=b.RN
where Mark=(select MIN(mark)
from StudentTest);
--12.
select name, AVG(mark)[Điểm trung bình]
from Student a join StudentTest b
	on a.RN=b.RN
group by a.rn,name
order by AVG(mark) desc;
--13.
select a.name[Họ tên sinh viên], c.name[Tên môn học]
from Student a
	join StudentTest b on a.RN=b.RN join Test c
	on b.TestID=c.TestID;
--14.
select*
from Student
where RN
	not in(select RN
from StudentTest);
--15.
select a.name, c.name, mark
from Student a join StudentTest b
	on a.RN=b.RN join Test c on b.TestID=c.TestID
where Mark<5;
--16.
select top(1) with ties
	name, AVG(mark)
from Student a
	join StudentTest b on a.RN=b.RN
group by a.RN,Name
order by AVG(mark) desc;
--17.
select top(1) with ties
	name, AVG(mark)
from Student a
	join StudentTest b on a.RN=b.RN
group by a.RN,Name
order by AVG(mark);
--18.
select name, MAX(mark)
from Test a join StudentTest b
	on a.TestID=b.TestID
group by a.TestID,Name;
--19.
select a.name[Họ tên sinh viên], c.name[Tên môn học]
from Student a
	left join StudentTest b on a.RN=b.RN left join Test c
	on b.TestID=c.TestID;