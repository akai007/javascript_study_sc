
# 列出没有学过赵四老师讲授课程的所有同学的姓名
SELECT name
FROM student
WHERE name NOT IN (
	SELECT s.name
	FROM student s, s_c sc, course c, teacher t
	WHERE 
		sc.sid = s.sid
		and sc.cid = c.cid
		and t.name = '赵四'
);

# 找出工资最低的教师姓名
SELECT name
FROM teacher
WHERE salary <= ALL (
	SELECT salary
    FROM teacher
);

# 找出001号课成绩不是最高的所有学生的学号
SELECT sid
FROM s_c
WHERE 
	cid = '001'
	AND score < SOME(
		SELECT score
        FROM s_c
        WHERE cid = '001'
    );

# 找出所有课程都不及格的学生姓名
SELECT s.name
FROM student s, s_c sc
WHERE 
	sc.sid = s.sid
    AND sc.score < ALL(
		SELECT score
		FROM s_c
		WHERE sid = s.sid
    );

# 找出001号课程最高的所有学生学号
SELECT sc.sid 
FROM s_c sc
WHERE sc.score >= ALL(
	SELECT score
    FROM s_c
    WHERE sc.sid = sid
);

# 找出98030101号同学成绩最低的课程号
SELECT sc.cid
FROM s_c sc
WHERE 
	sc.sid = '98030101'
	AND sc.score <= ALL(
		SELECT score
		FROM s_c
		WHERE sid = sc.sid
	);

# 找出张三同学成绩最低的课程号
SELECT sc.cid
FROM s_c sc, student s
WHERE 
	sc.sid = s.sid
	AND s.name = '张三'
    AND sc.score <= ALL(
		SELECT score
        FROM s_c
        WHERE sid = s.sid
    );

# not in  等价于 <> all（子查询）
SELECT s.name
FROM student s
WHERE s.sid not in (
	SELECT sid FROM s_c WHERE sid = s.sid AND cid = '001'
);
# 等价于
SELECT s.name
FROM student s
WHERE s.sid <> ALL (
	SELECT sid FROM s_c WHERE sid = s.sid AND cid = '001'
);













