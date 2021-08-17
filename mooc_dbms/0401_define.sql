CREATE DATABASE mooc CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci;
USE mooc;

CREATE USER 'mooc'@'%' IDENTIFIED BY 'mooc123';
GRANT ALL PRIVILEGES ON mooc . * TO 'mooc'@'%';

CREATE TABLE s
(
	sno CHAR(6) PRIMARY KEY,
    sn VARCHAR(10) NOT NULL,
    sd VARCHAR(16),
    sb DATE,
    sex CHAR(2),
    
    CHECK(sex IN('男', '女'))
);

CREATE TABLE c
(
	cno CHAR(6) PRIMARY KEY,
    cn VARCHAR(10) NOT NULL,
    pc CHAR(6) DEFAULT NULL,
    
    FOREIGN KEY (pc) REFERENCES c(cno)
);

CREATE TABLE sc
(
	sno CHAR(6),
    cno VARCHAR(6),
    grade INT,
    
    PRIMARY KEY (sno, cno),
    FOREIGN KEY (sno) REFERENCES s(sno)
		ON UPDATE CASCADE	# 级联更新
        ON DELETE NO ACTION, # 当级联删除时不操作
    FOREIGN KEY (cno) REFERENCES c(cno),
    
    CHECK(grade BETWEEN 0 AND 100)
);
