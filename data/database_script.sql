CREATE TABLE users (
id serial primary key,
mail TEXT NOT NULL UNIQUE,
password TEXT NOT NULL,
created_on DATE DEFAULT CURRENT_TIMESTAMP,
role VARCHAR(64),
name  VARCHAR(64) NOT NULL UNIQUE,
balance float8);

CREATE TYPE transaction_type AS ENUM ('income','expense');
CREATE TABLE category_of_transaction(
id serial primary key,
user_id int references users(id),
name VARCHAR(64) NOT NULL,
type transaction_type NOT NULL
);
CREATE TABLE transaction(
id serial primary key,
category_id int references category_of_transaction(id) NOT NULL,
amount float8,
date DATE,
description TEXT)