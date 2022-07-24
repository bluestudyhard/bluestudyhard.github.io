use homework;
# select *
# from stuinfo;

-- 修改学生表的基本信息
drop procedure if exists update_stuinfo;
create procedure update_stuinfo(in stunum varchar(255), in stutype varchar(255), in val char(15))
begin
    if (stutype = 'number') then
        update stuinfo
            left join stuxskc using (number)
        set stuinfo.number = val
          , stuxskc.number = val
        where stuinfo.number = stunum;
    elseif (stutype = 'name') then
        update stuinfo
        set stuinfo.name = val
        where number = stunum;
    elseif (stutype = 'project') then
        update stuinfo
        set stuinfo.project = val
        where number = stunum;
    elseif (stutype = 'totalnumber') then
        update stuinfo
        set stuinfo.totalnumber = val
        where number = stunum;
    elseif (stutype = 'sex') then
        update stuinfo
        set stuinfo.sex = val
        where number = stunum;
    elseif (stutype = 'born') then
        update stuinfo
        set stuinfo.born = val
        where number = stunum;
    end if;

end;
# call update_stuinfo('蓝习之', 'number', '2114100314');
# select *
# from stuinfo;
# update stuinfo,stuxskc
# set stuinfo.number = '211410031144',
#     stuxskc.number = '211410031144'
# where stuxskc.number = stuinfo.number
#   and stuinfo.name = '蓝习之';
#
# select *
# from stuxskc;
-- 修改课程表的基本信息
drop procedure if exists update_course;
create procedure update_course(in courseID char(10), in stutype varchar(255), in val varchar(255))
begin
    if (stutype = 'courseNum') then
        update stukc
            left join stuxskc using (courseNum)
        set stukc.courseNum   = val,
            stuxskc.courseNum = val
        where stukc.courseNum = courseID;
    elseif (stutype = 'courseName') then
        update stukc
        set stukc.courseName = val
        where stukc.courseNum = courseID;
    elseif (stutype = 'term') then
        update stukc
        set stukc.term = val
        where stukc.courseNum = courseID;
    elseif (stutype = 'studyhour') then
        update stukc
        set stukc.studyhour = val
        where stukc.courseNum = courseID;
    elseif (stutype = 'point') then
        update stukc
        set stukc.point = val
        where stukc.courseNum = courseID;
    end if;
end;

# call update_course('102', 'courseName', 'Java程序设计');
# update stukc,stuxskc
# set stukc.courseNum   = '102',
#     stuxskc.courseNum = '102'
# where stukc.courseNum = '103'
#   and stuxskc.courseNum = '103';
# select *
# from stuxskc;
# select *
# from stukc;

-- 修改成绩
drop procedure if exists update_score;
create procedure update_score(in stunum char(15), in stutype varchar(255), in val varchar(255))
begin
    if (stutype = 'number') then
        update stuxskc
            left join stuinfo using (number)
        set stuinfo.number = val
          , stuxskc.number = val
        where stuxskc.number = stunum;
    elseif (stutype = 'score') then
        update stuxskc
        set score = val
        where stuxskc.number = stunum;
    elseif (stutype = 'courseNum') then
        update stuxskc
            left join stukc using (courseNum)
        set stuxskc.courseNum = val,
            stukc.courseNum   = val
        where stuxskc.courseNum = stunum;
    end if;
end;
use homework;
select *
from employee;

desc stuxskc;
drop procedure if exists create_table;
create procedure create_table()
begin
    create table if not exists zi
    (
        序号 varchar(255) not null primary key,
        字  varchar(255) not null,
        字数 varchar(255) not null
    );
end;
call create_table();
desc zi;
drop procedure if exists count_word;
create procedure count_word(in number varchar(255), in word varchar(255), in c varchar(255))
begin
    declare summ int;
    declare i int;
    declare nam varchar(255);
    select count(序号) into summ from xs;
    set i = 1;
    while i < summ
        do
            select 姓名 into nam from xs;

        end while;
end;

select *
from xs
where 姓名 like '_';
select count(序号)
from xs;
set @str = "温怡彤";
select @str;
select substring(@str, 2, 1);
select *
from xs
where 姓名 like '%怡%';


delimiter //
drop procedure if exists count_word;
create procedure count_word()
begin
    declare names varchar(4); -- 名字们
    declare flag int default 0;
    declare cur cursor for select 姓名 from xs; -- 主要是要用到游标去遍历每一行的名字
    declare continue handler for not found set flag = 1; -- 游标的停止条件

    drop table if exists zi; -- 结果表
    create table zi
    (
        no   int,
        name varchar(4),   -- 单个名
        cnt  int default 0 -- 出现的次数
    );

    open cur; -- 打开游标
    fetch cur into names; -- 开始遍历
    set @j = 1;-- 每个人编号
    while flag <> 1 -- 一直到遍历 not found
        do
            set @str = right(names, length(names) / 3 - 1); -- 提取名，由于汉字是三个字节的，所以还要长度除以3
            set @i = 1; -- 循环的i
            while @i <= length(@str) / 3 -- 一直到名的末尾
                do
                    set @x = substr(@str, @i, 1); -- 单个地截取名的字符
                    set @cnt = (select count(name) from zi where name = @x); -- 判断是否在结果表里了

                    if @cnt = 0 then
                        insert into zi values (@j, @x, 1); -- 不在的话就插入这个结果
                        set @j = @j+1;
                    else
                        update zi set cnt = cnt + 1 where name = @x; -- 在的话就出现次数+1
                    end if;
                    set @i = @i + 1; -- 然后下标+1
                end while;
         --   set @j = @j + 1;
            fetch cur into names; -- 游标往下走一行 -- 其实也就是指针啦
        end while;
    close cur; -- 用完要关闭游标
    select * from zi; -- 输出结果
end//
delimiter ;

call count_word();
# call update_score('2114100314', '206', 'score', '87');
# select *
# from stuxskc;
#
# select *
# from stuinfo
# where stuinfo.name = '蓝习之';
# select *
# from stuinfo
#          right join stuxskc using (number)
#          right join stukc using (courseNum)
# where stuinfo.name = '蓝习之';
