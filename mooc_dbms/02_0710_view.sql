# 视图

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
	SELECT t.name, c,name, 
    FROM s_c sc, teacher t
    WHERE t.tid = c.tid
);















