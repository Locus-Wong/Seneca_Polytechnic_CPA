// Workshop 9 - Multi-Threading, Thread Class

#ifndef SENECA_PROCESSDATA_H
#define SENECA_PROCESSDATA_H

#include <string>

namespace seneca
{
	void computeAvgFactor(const int*, int, int, double&);
	void computeVarFactor(const int*, int, int, double, double&);

	class ProcessData
	{
		int total_items{};
		int* data{};
	public:
		ProcessData(const std::string&);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(const std::string&, double&, double&);
	};
}

#endif
