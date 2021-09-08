# 静态完整性约束
use mooc;

CREATE TABLE student_ (
	sid CHAR(8) not null unique,
    name CHAR(10),
    sex CHAR(2) CONSTRAINT ct_sex CHECK(sex='男' or sex = '女'),
    age INT,
    did char(2) REFERENCES dept(did) ON DELETE CASCADE,
    class char(6),
    
    CHECK(age > 0)
);

INSERT INTO student_ 
	SELECT * FROM student;
    
ALTER TABLE s_c
	ADD PRIMARY KEY (sid,cid);
    
ALTER TABLE student_
	MODIFY sid CHAR(8) PRIMARY KEY;
    
CREATE TRIGGER student_insert AFTER INSERT
	ON student_ FOR EACH ROW SET @str='a new student join!';

INSERT INTO student_ VALUES ('1231', 'lk', '妖', 22, '01', '001');
