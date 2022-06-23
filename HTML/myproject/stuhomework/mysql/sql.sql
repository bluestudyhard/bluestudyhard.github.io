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

#
#
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
