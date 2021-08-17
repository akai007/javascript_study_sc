USE mooc;

# 插入单条
INSERT INTO s(sno, sn, sd, sb, sex)
VALUES ('s01', '张三', '计算机', '2021-07-29', '男');

# 插入多条
INSERT INTO s(sno, sn, sd, sb, sex)
VALUES 
	('s02', '李四', '美术', '2021-07-29', '女'),
	('s03', '王五', '计算机', '2021-07-28', '男');
    
# 触发主键唯一性约束
INSERT INTO s(sno, sn, sd, sb, sex)
VALUES ('s01', '张三', '计算机', '2021-07-29', '男');

# 触发自定义约束 性别只能是 男、女
INSERT INTO s(sno, sn, sd, sb, sex)
VALUES ('s04', '张三', '计算机', '2021-07-29', '人妖');

INSERT INTO c VALUES ('c01', '高等数学', NULL);
INSERT INTO c VALUES ('c02', '离散数学', 'c01');
INSERT INTO c VALUES ('c03', '数据结构', 'c02');
INSERT INTO c VALUES ('c04', '数据库', 'c03');

INSERT INTO sc VALUES ('s01', 'c01', 88);
