# 并-交-差 处理

# 求学过002号课的同学 或学过 003号课的同学学号
(SELECT sid FROM s_c WHERE cid = '002')
UNION
(SELECT sid FROM s_c WHERE cid = '003');

# 既学过002号，又学过003号课的同学学号
-- (SELECT sid FROM s_c WHERE cid -- = '002')
-- INTERSECT
-- (SELECT sid FROM s_c WHERE cid = '003')

# 假定素有学生都有选课，求没学过002号课程的学生学号
-- SELECT DISTINCT sid FROM s_c
-- EXCEPT
-- SELECT sid FROM s_c WHERE cid = '002';












