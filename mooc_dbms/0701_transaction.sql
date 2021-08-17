USE mooc;

CREATE TABLE bank_account
(
	accNo CHAR(6) PRIMARY KEY,
    balance BIGINT,
    
    CHECK( balance >= 0)
);

INSERT INTO bank_account VALUES ('001', 1500);
INSERT INTO bank_account VALUES ('002', 0);

SELECT * FROM bank_account;

# excute line by line
START TRANSACTION;
	UPDATE bank_account
	SET balance = balance - 1000
	WHERE accNo = '001';

	UPDATE bank_account
	SET balance = balance + 1000
	WHERE accNo = '002';
COMMIT;
ROLLBACK;
	SELECT * FROM bank_account;
