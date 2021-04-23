
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

CREATE TABLE category_of_transaction(
	id SERIAL PRIMARY KEY, 
	user_id INT references users(id) NOT NULL, 
	name VARCHAR(64) NOT NULL, 
	type transaction_type NOT NULL
);

CREATE TABLE transaction(
	id SERIAL PRIMARY KEY, 
	category_id INT REFERENCES category_of_transaction(id) NOT NULL, 
	amount INT NOT NULL, 
	date DATE NOT NULL, 
	description TEXT
);
