use mooc;

CREATE TABLE student (
	sid char(8) comment '学生编号',
    name char(10) comment '姓名',
    sex char(2) comment '性别',
    age int comment '年龄',
    did char(2) comment '系编号',
    class char(6) comment '班级号'
) comment='学生表';

CREATE TABLE dept (
	did char(2) comment '院系编号',
    name char(10) comment '院系系名',
    ean char(10) comment '系主任'
) comment='院系表';

CREATE TABLE course (
	cid char(3) comment '课程编号',
    name char(12) comment '课程名',
    hours int comment '学时',
    credit float comment '学分',
    tid char(3) comment '教师编号'
) comment='课程表';

CREATE TABLE teacher (
	tid char(3) comment'教师编号',
    name char(10) comment'教师名称',
    did char(2) comment '系编号',
    salary float comment '工资'
) comment='教师表';

CREATE TABLE  s_c (
	sid char(8) comment '学生编号',
	cid char(3) comment '课程编号',
    score float(1) comment '成绩'
) comment='学生选课表';

