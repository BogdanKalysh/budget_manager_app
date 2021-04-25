
CREATE TABLE users (
	id SERIAL PRIMARY KEY, 
	mail TEXT NOT NULL UNIQUE, 
	password TEXT NOT NULL, 
	created_on DATE DEFAULT CURRENT_TIMESTAMP, 
	role VARCHAR(64) NOT NULL, 
	name VARCHAR(64) NOT NULL UNIQUE, 
	balance INT 
);

CREATE TYPE transaction_type AS ENUM ('income', 'expense');

CREATE TABLE category(
	id SERIAL PRIMARY KEY, 
	user_id INT NOT NULL, 
	name VARCHAR(64) NOT NULL, 
	type transaction_type NOT NULL,

	FOREIGN KEY (user_id) REFERENCES user(id) ON DELETE RESTRICT ON UPDATE RESTRICT
);

CREATE TABLE transaction(
	id SERIAL PRIMARY KEY, 
	category_id INT NOT NULL, 
	amount INT NOT NULL, 
	date DATE NOT NULL, 
	description TEXT

	FOREIGN KEY (category_id) REFERENCES category(id) ON DELETE RESTRICT ON UPDATE RESTRICT
);
