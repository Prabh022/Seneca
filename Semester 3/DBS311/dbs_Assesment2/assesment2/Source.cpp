#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <occi.h>
#include <cstring>
#include <iomanip>
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;
int main() {
	// Declare environment and connection variables 
	Environment* env = nullptr;
	Connection* conn = nullptr;

	// Define and initialize the variable to store the username, password, and the host address
	string user = "dbs311_223zbb29";
	string pass = "26989108";
	string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";

	// Make the environment and the connection.
	// Make sure you handle any errors may be thrown as you program is executed. 
	env = Environment::createEnvironment(Environment::DEFAULT);
	conn = env->createConnection(user, pass, constr);

	// Prepare a statement to query the database
	Statement* stmt = conn->createStatement("SELECT first_name, last_name, job_title FROM employees WHERE employee_id = :1");

	// Prompt the user for the employee id
	int emp_id;
	cout << "Please enter the employee id: ";
	cin >> emp_id;

	// Bind the employee id to the statement
	stmt->setInt(1, emp_id);

	// Execute the query
	ResultSet* rs = stmt->executeQuery();

	// Retrieve the results
	if (rs->next()) {
		cout << "First name: " << rs->getString(1) << endl;
		cout << "Last name: " << rs->getString(2) << endl;
		cout << "Job title: " << rs->getString(3) << endl;
	}

	// Close the statement and connection
	conn->terminateStatement(stmt);
	env->terminateConnection(conn);
	Environment::terminateEnvironment(env);
}
