# 视图
use mooc;
# 定义一个视图 cs_stu 为计算机系学生，通过该视图可以将Student表中 其他系的学生屏蔽掉
CREATE VIEW cs_stu AS (
	SELECT *
    FROM student
    WHERE did in (
		SELECT did FROM dept WHERE name = '计算机'
    )
);
SELECT * FROM cs_stu

# 定义一个视图teach 为教师任课情况，把teacher表中的个人隐私方面的信息，如工资等信息屏蔽掉，仅反映教哪门课以及学分等。
CREATE VIEW teach AS (
	SELECT t.name t_name, c.name c_name
    FROM course c, teacher t
    WHERE c.tid = t.tid
);
SELECT * FROM teach ;
SELECT * FROM teach WHERE c_name = '数据库';














