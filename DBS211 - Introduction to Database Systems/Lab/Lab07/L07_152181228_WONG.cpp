// Student Name : Tsz Wa Wong
// Student ID : 152181228
// Date : 2024-04-07
// DBS211 Lab07 NBB
#include <iostream>
#include <occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

int main(void)
{
	Environment* env = nullptr;
	Connection* conn = nullptr;
	string str;
	string usr = "dbs211_241nbb36";
	string pass = "29340321";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	
	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		Statement* stmt = conn->createStatement();
		
		// Report 1
		ResultSet* rs1 = stmt->executeQuery("SELECT employeenumber, firstname, lastname, phone, extension FROM retailemployees JOIN retailoffices ON retailemployees.officecode = retailoffices.officecode WHERE retailoffices.city = 'San Francisco' ORDER BY employeenumber");
		cout << "------------------------- Report 1 (Employee Report) -----------------------------------" << endl;
		cout << "EmployeeID   First Name        Last Name         Phone            Extension" << endl;
		cout << "------------ ----------------- ----------------- ---------------- ---------" << endl;
		while (rs1->next())
		{
			int employeeNo = rs1->getInt(1);
			string firstName = rs1->getString(2);
			string lastName = rs1->getString(3);
			string phone = rs1->getString(4);
			string ext = rs1->getString(5);
			cout.width(12);
			cout.setf(ios::left);
			cout << employeeNo << " ";
			cout.width(17);
			cout << firstName << " ";
			cout.width(17);
			cout << lastName << " ";
			cout.width(16);
			cout << phone << " " << ext << endl;
		}

		// Report 2
		cout << endl;
		ResultSet* rs2 = stmt->executeQuery("SELECT DISTINCT reta_mgr.employeenumber, reta_mgr.firstname, reta_mgr.lastname, phone, reta_mgr.extension FROM retailemployees reta_emp JOIN retailemployees reta_mgr ON reta_emp.reportsto = reta_mgr.employeenumber JOIN retailoffices ON reta_mgr.officecode = retailoffices.officecode ORDER BY reta_mgr.employeenumber");
		cout << "------------------------- Report 2 (Manager Report) -----------------------------------" << endl;
		cout << "EmployeeID   First Name        Last Name         Phone            Extension" << endl;
		cout << "------------ ----------------- ----------------- ---------------- ---------" << endl;
		while (rs2->next())
		{
			int employeeNo = rs2->getInt(1);
			string firstName = rs2->getString(2);
			string lastName = rs2->getString(3);
			string phone = rs2->getString(4);
			string ext = rs2->getString(5);
			cout.width(12);
			cout.setf(ios::left);
			cout << employeeNo << " ";
			cout.width(17);
			cout << firstName << " ";
			cout.width(17);
			cout << lastName << " ";
			cout.width(16);
			cout << phone << " " << ext << endl;
		}

		conn->terminateStatement(stmt);
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;

}