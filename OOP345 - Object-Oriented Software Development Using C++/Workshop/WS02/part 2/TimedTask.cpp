/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 23 May 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <iostream>
#include <chrono>
#include "TimedTask.h"
using namespace std;
namespace seneca
{

	TimedTask::TimedTask()
	{
		m_noOfRecords = 0;
	}

	void TimedTask::startClock()
	{

		startTime = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock()
	{

		endTime = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* nameOfTask)
	{
		if (m_noOfRecords < MAX_TASKS)
		{
			tasks[m_noOfRecords].taskName = nameOfTask;
			tasks[m_noOfRecords].unitTime = "nanoseconds";
			tasks[m_noOfRecords].taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
			m_noOfRecords++;
		}
	}

	// Friend insertion operator
	std::ostream& operator << (std::ostream& ostr, const TimedTask& T)
	{
		ostr << "--------------------------\n";
		ostr << "Execution Times:\n";
		ostr << "--------------------------\n";
		for (int i = 0; i < T.m_noOfRecords; ++i)
		{
			ostr.setf(std::ios::left);
			ostr.width(21);
			ostr << T.tasks[i].taskName;
			ostr.width(13);
			ostr.unsetf(std::ios::left);
			ostr << T.tasks[i].taskDuration.count() << " " << T.tasks[i].unitTime << "\n";
		}
		ostr << "--------------------------\n";
		return ostr;
	}
}
