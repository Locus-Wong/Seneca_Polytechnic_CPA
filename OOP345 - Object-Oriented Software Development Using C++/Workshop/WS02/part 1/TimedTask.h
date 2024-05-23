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
#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H
#include <iostream>
#include <chrono>
#include <string>
namespace seneca
{
	struct Task
	{
		std::string taskName{};
		std::string unitTime{};
		std::chrono::steady_clock::duration taskDuration;

	};

	class TimedTask
	{
		static const int MAX_TASKS = 10;
		int m_noOfRecords{};
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		Task tasks[MAX_TASKS]{};
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* nameOfTask);
		friend std::ostream& operator << (std::ostream& ostr, const TimedTask& T);
	};
}
#endif
