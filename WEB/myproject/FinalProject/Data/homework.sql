/*
 Navicat Premium Data Transfer

 Source Server         : blue
 Source Server Type    : MySQL
 Source Server Version : 80028
 Source Host           : localhost:3306
 Source Schema         : homework

 Target Server Type    : MySQL
 Target Server Version : 80028
 File Encoding         : 65001

 Date: 14/06/2022 21:38:38
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for stuinfo
-- ----------------------------
DROP TABLE IF EXISTS `stuinfo`;
CREATE TABLE `stuinfo`
(
    `number`      varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `name`        varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `sex`         int(0)                                                  NULL DEFAULT NULL,
    `project`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `born`        varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `totalnumber` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of stuinfo
-- ----------------------------
INSERT INTO `stuinfo`
VALUES ('2114100314', '蓝习之', 1, '软件工程', '2003.02.08', '52');
INSERT INTO `stuinfo`
VALUES ('2114100136', '温一筒', 0, '软件工程', '2002.02.29', '52');
INSERT INTO `stuinfo`
VALUES ('2114100306', '陈羊睡', 1, '软件工程', '2002.09.27', '53');
INSERT INTO `stuinfo`
VALUES ('2114100328', '有机鱼', 1, '软件工程', '2003.03.04', '53');
INSERT INTO `stuinfo`
VALUES ('2114100310', '黄辉神', 1, '网络安全', '1998.02.02', '49');
INSERT INTO `stuinfo`
VALUES ('2114100315', '李龙宝', 0, '计算机', '2008.02.03', '51');
INSERT INTO `stuinfo`
VALUES ('2114100312', '江建勇', 0, '网络工程', '1990.01.01', '49');

-- ----------------------------
-- Table structure for stukc
-- ----------------------------
DROP TABLE IF EXISTS `stukc`;
CREATE TABLE `stukc`
(
    `courseNum`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `courseName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `term`       int(0)                                                  NULL DEFAULT NULL,
    `studyhour`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `point`      varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of stukc
-- ----------------------------
INSERT INTO `stukc`
VALUES ('102', 'Java程序设计', 1, '68', '4');
INSERT INTO `stukc`
VALUES ('206', '离散数学', 4, '68', '4');
INSERT INTO `stukc`
VALUES ('208', '数据结构', 5, '68', '4');
INSERT INTO `stukc`
VALUES ('209', '操作系统', 6, '68', '4');
INSERT INTO `stukc`
VALUES ('210', '计算机原理', 5, '85', '5');
INSERT INTO `stukc`
VALUES ('212', '数据库原理', 7, '68', '4');
INSERT INTO `stukc`
VALUES ('301', '计算机网络', 5, '51', '3');
INSERT INTO `stukc`
VALUES ('302', '软件工程导论', 4, '51', '3');

-- ----------------------------
-- Table structure for stuxskc
-- ----------------------------
DROP TABLE IF EXISTS `stuxskc`;
CREATE TABLE `stuxskc`
(
    `number`    int(0)                                                  NULL DEFAULT NULL,
    `courseNum` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `score`     varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of stuxskc
-- ----------------------------
INSERT INTO `stuxskc`
VALUES (2114100314, '302', '90');
INSERT INTO `stuxskc`
VALUES (2114100314, '208', '92');
INSERT INTO `stuxskc`
VALUES (2114100314, '206', '87');
INSERT INTO `stuxskc`
VALUES (2114100136, '302', '90');
INSERT INTO `stuxskc`
VALUES (2114100136, '206', '80');
INSERT INTO `stuxskc`
VALUES (2114100136, '102', '90');
INSERT INTO `stuxskc`
VALUES (2114100306, '302', '93');
INSERT INTO `stuxskc`
VALUES (2114100306, '206', '82');
INSERT INTO `stuxskc`
VALUES (2114100306, '212', '91');
INSERT INTO `stuxskc`
VALUES (2114100328, '302', '95');
INSERT INTO `stuxskc`
VALUES (2114100328, '208', '99');
INSERT INTO `stuxskc`
VALUES (2114100328, '206', '85');
INSERT INTO `stuxskc`
VALUES (2114100310, '212', '85');
INSERT INTO `stuxskc`
VALUES (2114100310, '102', '85');
INSERT INTO `stuxskc`
VALUES (2114100310, '301', '90');
INSERT INTO `stuxskc`
VALUES (2114100315, '102', '80');
INSERT INTO `stuxskc`
VALUES (2114100315, '210', '81');
INSERT INTO `stuxskc`
VALUES (2114100315, '209', '85');
INSERT INTO `stuxskc`
VALUES (2114100312, '301', '80');
INSERT INTO `stuxskc`
VALUES (2114100312, '209', '85');
INSERT INTO `stuxskc`
VALUES (2114100312, '206', '90');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`
(
    `root`     int(0)                                                  NULL DEFAULT NULL,
    `account`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
    `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB
  CHARACTER SET = utf8
  COLLATE = utf8_general_ci
  ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user`
VALUES (0, '2114100314', '0990lk');
INSERT INTO `user`
VALUES (1, 'teacherhzu114', 'teacher');

-- ----------------------------
-- Procedure structure for update_course
-- ----------------------------
DROP PROCEDURE IF EXISTS `update_course`;
delimiter ;;
CREATE
    DEFINER = `root`@`localhost` PROCEDURE `update_course`(in coursenum char(10), in stutype varchar(255),
                                                           in val varchar(255))
begin
    if (stutype = 'coursenum') then
        update stukc
            left join stuxskc using (courseNum)
        set stukc.courseNum   = val,
            stuxskc.courseNum = val
        where stukc.courseNum = coursenum;

    elseif (stutype = 'courseName') then
        update stukc
        set stukc.courseName = val
        where stukc.courseNum = coursenum;
    elseif (stutype = 'point') then
        update stukc
        set stukc.point = val
        where stukc.courseNum = coursenum;
    end if;
end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for update_score
-- ----------------------------
DROP PROCEDURE IF EXISTS `update_score`;
delimiter ;;
CREATE
    DEFINER = `root`@`localhost` PROCEDURE `update_score`(in stunum char(15), in coursenum char(15),
                                                          in stutype varchar(255), in val varchar(255))
begin
    if (stutype = 'score') then
        update stuxskc
        set score = val
        where stuxskc.number = stunum
          and stuxskc.courseNum = coursenum;
    end if;
end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for update_stuinfo
-- ----------------------------
DROP PROCEDURE IF EXISTS `update_stuinfo`;
delimiter ;;
CREATE
    DEFINER = `root`@`localhost` PROCEDURE `update_stuinfo`(in stunum varchar(255), in stutype varchar(255),
                                                            in val varchar(255))
begin
    if (stutype = 'class') then
        update stuinfo
        set stuinfo.class = val
        where number = stunum;
    elseif (stutype = 'number') then
        update stuinfo
        set stuinfo.number = val
        where number = stunum;
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

end
;;
delimiter ;

call update_stuinfo('2114100360', 'number', '2114100306');

select *
from stuinfo;