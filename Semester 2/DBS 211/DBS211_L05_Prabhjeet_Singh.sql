-- ***********************
-- Name: Prabhjeet Singh
-- ID: 127024214
-- Date: 17 FEB 2022
-- Purpose: Lab 05 DBS211
-- ***********************
-- Q1 SOLUTION --
-- PART A --
CREATE TABLE L5_MOVIES (
  m_id NUMBER PRIMARY KEY,
  title VARCHAR(35) NOT NULL UNIQUE,
  release_year NUMBER NOT NULL,
  director_id NUMBER NOT NULL,
  score NUMBER(3, 2) DEFAULT 2.5 CHECK (score < 5 AND score > 0)
);

-- PART B  --
CREATE TABLE L5_ACTORS (
  a_id NUMBER PRIMARY KEY,
  first_name VARCHAR(20) NOT NULL,
  last_name VARCHAR(30) NOT NULL
);

-- PART C  --
CREATE TABLE L5_CASTINGS (
  movie_id NUMBER,
  actor_id NUMBER,
  FOREIGN KEY ( movie_id ) REFERENCES L5_MOVIES(m_id),
  FOREIGN KEY ( actor_id ) REFERENCES L5_ACTORS(a_id),
  PRIMARY KEY ( movie_id, actor_id )
);

-- PART D  --
CREATE TABLE L5_DIRECTORS (
  director_id NUMBER PRIMARY KEY,
  first_name VARCHAR(20) NOT NULL,
  last_name VARCHAR(30) NOT NULL
);

-- Q2 SOLUTION --
ALTER TABLE L5_MOVIES
ADD CONSTRAINT fk_movies
  FOREIGN KEY (director_id)
  REFERENCES L5_DIRECTORS(director_id);

-- Q3 SOLUTION --
DELETE FROM
  L5_DIRECTORS
WHERE 
  --DIRECTOR_ID = whatever value you want to delete;

-- Q4 SOLUTION --
--      A      --
DROP TABLE L5_CASTINGS;
DROP TABLE L5_ACTORS;
DROP TABLE L5_MOVIES;
DROP TABLE L5_DIRECTORS;
--      B      --
-- The order of statement plays a vital role in the tables as if we do not make them in a ordef , then it can show the errors
-- as if anyone is linked to each other it woulf create or show errors during droppping as it would put its effect on other
-- tables too which can show errors.