select * from xs
where bday like '1994%';
select xs.name,number,pname
from xs join xs_kc on xs.number = xs_kc.number1
where coursenum = '102';



select xs.name,number,pname,coursen
from xs_kc join kc on xs_kc.coursenum = kc.coursenum
from xs join kc on xs.number = kc.number1;


select name,number,pname
from xs where number not in
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

select name,number
from xs
    timestampdiff(day,born,now())-(
        select timestampdiff(day,bron,now())
        from xs
        where xs.number = '081208'
    )diff
    where number = '081208'and sex = '1';

select phone ,number1 from employees where address like '%中山%';
use xscj;
SELECT * from kc;