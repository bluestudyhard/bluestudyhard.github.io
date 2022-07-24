use finalworks;
show tables;

create table if not exists human(
    name varchar(255) not null,
    id varchar(255) not null,
    score varchar(255) not null
) engine=innodb;

insert into human
values
    ('Stupidsheep','2114100306','100'),
    ('OrganicFish','2114100328','100'),
    ('Bluestudyhard','2114100314','100');

select * from users;