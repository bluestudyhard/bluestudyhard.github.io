select *
from xs
where bday like '1994%';
select xs.name, number, pname
from xs
         join xs_kc on xs.number = xs_kc.number1
where coursenum = '102';



select name, number, pname
from xs
where number not in
      (
          select number1
          from xs_kc
          where coursenum in
                (
                    select coursenum1
                    from kc
                    where coursen = '计算机基础'
                )
      );

select name, number
from xs timestampdiff(day,born,now())-(
select timestampdiff(day, bron, now())
from xs
where xs.number = '081208'
    ) diff
where number = '081208' and sex = '1';

select phone, number1
from employees
where address like '%中山%';
use xscj;
SELECT *
from kc;

select *
from kc;
use yggl;
select *
from xs_kc;

select *
from xs;
select number,
       name,
       pname,
       totalnumber,
       (case
            when totalnumber is null then '尚未选课'
            when totalnumber < 42 then '未及格' end) as '等级'
from xs
where pname = '通信工程';


select number1,
       score,
       case
           when score < 60 then '不及格'
           when score > 60 and score < 70 then '及格'
           when score > 70 and score < 80 then '中'
           end as 成绩
from xs_kc
where coursenum = 101;
select number1, (score * 1.2)
from xs_kc;

select distinct number1, score
from xs_kc;

select max(score) as 最高分, min(score) as 最小分
from xs_kc
where number1 = '081101';

select sum(score) as 总分
from xs_kc
where number1 = 081101;

select avg(score) as 平均分
from xs_kc
where number1 = 081101;

select variance(score) as 方差
from xs_kc
where number1 = 081101;

select sex, count(*) as 总数
from xs
group by sex;

select sex
from xs;

select sex
from xs
group by sex;
select distinct sex
from xs;

select *
from xs;
select *
from xs_kc;
select *
from kc;

select coursen, count(*) as 总人数
from kc
         join xs_kc on xs_kc.coursenum = kc.coursenum1
group by coursen;

select *
from employees
order by number1 desc;
select pname, count(*) as 总人数, avg(totalnumber) as 平均分
from xs
group by pname;

select pname, sex, count(*) as 总人数
from xs
group by pname, sex
with rollup;

select number1 as 学号, avg(score) as 平均成绩, pname
from xs_kc,
     xs
where xs.pname = '计算机'
  and score > 80
group by score, number1; -- 前面用了avg，后面直接score就是平均成绩了

select pname, coursen, score
from xs,
     xs_kc,
     kc
where xs.pname = '计算机'
  and coursen = '离散数学'
order by score desc;

select sex, count(*) as 男女人数
from employees
group by sex;

select departmentID, count(*) as 人数
from employees,
     departments
where employees.dnum = departments.num
group by departmentID;

select study, count(*) as 人数
from employees
where study = '本科'
   or study = '大专'
   or study = '硕士'
group by study;

select departmentID, count(*) as 员工数量
from departments,
     employees
where employees.dnum = departments.num
  and employees.dnum > 3
group by departmentID;

select count(worktime) as 人员工作年份统计
from employees
group by worktime
order by worktime;

select name
from employees
group by born
order by born;

select name, sex, worktime, income
from salary,
     employees
where employees.number1 = salary.number
group by income, name, worktime, sex
order by income desc;

select name, number1, study, born, sex
from employees
order by number1
limit 3,5;

handler salary open;
handler salary read first
    where income > 2500;
handler salary read next
    where income > 2500;
handler salary close;


create or replace view yggl.cs_kc
as
select number, name, pname, coursenum, score
from xs,
     xs_kc
where xs.number = xs_kc.number1
  and xs.pname = '通信工程'
--  group by pname, name, number, coursenum, score;  -- 使用group by 不能更新表
    with check option;
select *
from cs_kc;

create or replace view yggl.kc_avg(num, score_avg)
as
select number, avg(score)
from xs,
     xs_kc
where xs.number = xs_kc.number1
  and xs.pname = '通信工程'
group by score;
select *
from kc_avg;

select num as 学号, score_avg as 平均成绩
from kc_avg
where score_avg > 85;

create or replace view cs_kcc(num, kc_c)
as
select number, count(coursenum)
from xs,
     kc,
     xs_kc
where xs_kc.number1 = xs.number
  and kc.coursenum1 = xs_kc.coursenum
  and xs.pname = '通信工程'
group by coursen;

create or replace view cs_xs
as
select number, name, pname, sex, bday, totalnumber
from xs
where xs.bday like '1994%'
with check option;

insert into cs_xs
values ('081256', '张三', '通信工程', 1, '1994-10-21', 50);
select *
from cs_xs;
select *
from xs;


update cs_kc
set score = 85
where cs_kc.number = '081210';
select number, score
from cs_kc
where cs_kc.number = '081210';

delete
from cs_xs
where cs_xs.number = '081256';

alter view cs_xs
    as
        select number, name, totalnumber
        from xs
        where pname = '通信工程';
select *
from cs_xs;

drop view cs_xs;

create or replace view ds_v
as
select num, departmentID, tips
from departments
with check option;

select *
from ds_v;

create or replace view employees_v
as
select number, name, income
from employees,
     salary
where employees.number1 = salary.number
with check option;

select *
from employees_v;

create or replace view employees_a_v
as
select number, name, dnum, income
from employees,
     salary
where employees.number1 = salary.number
with check option;
select *
from employees_a_v;

select departmentID as 部门名称
from ds_v
where num = 4;

select name, income as 实际收入
from employees_v
where employees_v.name = '王林';

insert into ds_v
values (6, '财务部', '财物管理');
select *
from ds_v;

update ds_v
set departmentID = '生产部'
where num = 5;
select *
from ds_v;

use mysql;
select *
from user;

use yggl;

select number, name, coursen, score
from xs,
     xs_kc,
     kc
where xs.number = xs_kc.number1
  and kc.coursenum1 = xs_kc.coursenum
  and kc.coursen = '离散数学'
  and xs_kc.score < 80;

select *
from xs
limit 10;
select *
from xs
limit 10,11;

select name, coursen, pname, score, sex
from xs
         join xs_kc on xs.number = xs.number
         join kc on kc.coursenum1 = xs_kc.coursenum
where xs.pname = '计算机'
  and kc.coursen = '计算机基础'
  and xs.sex = '1'
  and xs_kc.score > 90;
use yggl;
create or replace view yggl.ck_kcc
as
select number, name, pname, coursenum, score
from xs,
     xs_kc
where xs.number = xs_kc.number1
  and xs.pname = '通信工程'
with check option;
select *
from cs_kcc;

select 'I\nlove\nmy\nfamily';

select 0x43, cast(0x43 as unsigned);

select hex('HI');

select 0x4849, cast(0x4849 as unsigned);

select true,false;

set @num = (select number1 from employees where employees.name = '陈林琳');
select @num;

set @user1 = '010008';
select number1,name,study,born,sex,worktime,dnum from employees where employees.number1 = @user1;

set @female = 0;
select name,phone from employees where employees.sex = @female;

select @@version;

select current_time;
select  current_date,current_timestamp,current_user;

select 199-205,0.14-0.1,1.2+3.09345;

select '2019-5-6' + interval 33 Day;

select '2019-5-6' - interval 2 month ;

select 12%3, -32%7,7%0;
select '18AA'+'1',  'AA18'+1, '11x' * 3 * 'qwe';

select 8 = '8ab','8' = '8ab';
select 5<>5,5<>6,'a'<>'a','5a'<>'5b',NULL<>NULL, 0<>NULL, 0<>0;
select (1=1) AND (9>10),('c'='c') AND ('c'<'d');

select(1=1) OR (9>10), ('a'='c') OR (1>2);
select (1=1) XOR (4=3), (1<2) XOR (9<10);

select income-outcome from salary;

select * from employees
where study = '本科' and sex = '0';