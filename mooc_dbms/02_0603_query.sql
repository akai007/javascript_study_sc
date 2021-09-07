use mooc;

# 检索教师表中所有工资少于 1500元 或者工资大于2000 并且是03系的教师姓名
SELECT name
FROM teacher
WHERE ( salary < 1500 or salary > 2000 ) and did = '03';

# 求或者学过001号课程 或者学过002号课程的学生学号
SELECT sid
FROM s_c
WHERE cid = '001' OR cid = '002';

# 求有薪水差额的任意两位教师
SELECT 
	t1.name as '教师1',
    t2.name as '教师2'
FROM teacher t1, teacher t2
WHERE t1.salary > t2.salary;

# 求年龄有差异的任意两位同学的姓名
SELECT 
	s1.name '学生1',
    s2.name '学生2'
FROM student s1, student s2
WHERE s1.age > s2.age;

# 求既学过 001 又学过 002 号课的所有学生学号
SELECT sc1.sid
FROM s_c sc1, s_c sc2
WHERE 
	sc1.sid = sc2.sid 
    and sc1.cid = '001' 
    and sc2.cid = '002';

# 求 001课程 比 002 课程 成绩 高的所有学生学号
SELECT sc1.sid
FROM s_c sc1, s_c sc2
WHERE 
	sc1.sid = sc2.sid 
    and sc1.cid = '001'
    and sc2.cid = '002'
    and sc1.score > sc2.score;

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



