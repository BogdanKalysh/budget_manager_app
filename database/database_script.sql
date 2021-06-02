CREATE TABLE users (
	id SERIAL PRIMARY KEY, 
	mail TEXT NOT NULL UNIQUE, 
	password TEXT NOT NULL, 
	created_on DATE DEFAULT CURRENT_TIMESTAMP, 
	name VARCHAR(64) NOT NULL, 
	balance INT 
);

CREATE TYPE transaction_type AS ENUM ('income', 'expense');

CREATE TABLE category(
	id SERIAL PRIMARY KEY, 
	user_id INT NOT NULL, 
	name VARCHAR(64) NOT NULL, 
	type transaction_type NOT NULL,
	color VARCHAR(9) NOT NULL, 

	FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE ON UPDATE RESTRICT
);

CREATE TABLE transaction(
	id SERIAL PRIMARY KEY, 
	category_id INT NOT NULL, 
	amount INT NOT NULL, 
	date DATE NOT NULL DEFAULT CURRENT_TIMESTAMP, 
	description TEXT,

	FOREIGN KEY (category_id) REFERENCES category(id) ON DELETE CASCADE ON UPDATE RESTRICT
);

