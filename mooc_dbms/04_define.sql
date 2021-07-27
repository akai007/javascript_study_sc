CREATE DATABASE mooc CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci;
USE mooc;

CREATE TABLE s
(
	sno CHAR(6) PRIMARY KEY,
    sn CHAR(10) NOT NULL,
    sd CHAR(16),
    sb DATE,
    sex CHAR(2)
);

CREATE TABLE c
(
	cno CHAR(6) PRIMARY KEY,
    cn CHAR(10) NOT NULL,
    pc CHAR(6),
    
    FOREIGN KEY (pc) REFERENCES c(cno)
);

CREATE TABLE sc
(
	sno CHAR(6),
    cno CHAR(10),
    grade INT(3),
    
    PRIMARY KEY (sno, cno),
    FOREIGN KEY (sno) REFERENCES s(sno),
    FOREIGN KEY (cno) REFERENCES c(cno)
);
