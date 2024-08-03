/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 03 Aug 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "LineManager.h"
#include "Utilities.h"

namespace seneca {
LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
{
    Utilities util;
    size_t pos = 0;
    bool more = true;
    std::ifstream files(file);
    if (!files) {
        throw std::string("Unable to open [") + file + "] file.";
    }
    std::string record;
    while (std::getline(files, record)) {
        pos = 0;
        more = true;
        std::string nextWorkstationName;
        std::string workstationName = util.extractToken(record, pos, more); // Extract the workstation name
        if (more) { // if there is more token to extract
            nextWorkstationName = util.extractToken(record, pos, more); // Extract the next workstation name
        }
        
        Workstation* currentStation = nullptr;
        Workstation* nextStation = nullptr;
        
        std::for_each(stations.begin(), stations.end(), [workstationName, nextWorkstationName, &currentStation, &nextStation](Workstation* ws) {
            if (ws->getItemName() == workstationName) {
                currentStation = ws;
            }
            if (ws->getItemName() == nextWorkstationName) {
                nextStation = ws;
            }
        });
        
        if (currentStation) {
            m_activeLine.push_back(currentStation);
            m_activeLine.back()->setNextStation(nextStation);
        }
    }
    
    // Find the first station
    std::for_each(m_activeLine.begin(), m_activeLine.end(), [this](Workstation* station) {
        bool isFirstStation = std::none_of(m_activeLine.begin(), m_activeLine.end(), [station](Workstation* otherStation) {
            return otherStation->getNextStation() == station;
        });
        if (isFirstStation) {
            m_firstStation = station;
        }
    });
    
    m_cntCustomerOrder = g_pending.size(); // Update the total number of customer orders
}

void LineManager::reorderStations()
{
    std::vector<Workstation*> reorderedLine;
    Workstation* currentStation = m_firstStation; // retrieve the first station
    while (currentStation)
    {
        reorderedLine.push_back(currentStation);
        currentStation = currentStation->getNextStation();
    }
    m_activeLine = reorderedLine; // Update m_activeLine with the reordered line	
}

bool LineManager::run(std::ostream& os)
{
    static size_t iterationCount = 0;
    os << "Line Manager Iteration: " << ++iterationCount << '\n';
    if (!g_pending.empty())
    {
        *m_firstStation += std::move(g_pending.front()); // Move the first pending order to the first station's m_orders if there are any pending orders
        g_pending.pop_front(); // remove the first pending order
    }
    
    for (auto* station : m_activeLine)
    {
        station->fill(os); // for each station on the line, executes one fill operation
    }
    
    for (auto* station : m_activeLine)
    {
        station->attemptToMoveOrder(); // for each station on the line, attempts to move an order down the line
    }
    
    return g_pending.empty() && (g_completed.size() + g_incomplete.size() == m_cntCustomerOrder); // return true if all customer orders have been filled or cannot be filled, otherwise returns false
}

void LineManager::display(std::ostream& os) const
{
    for (const auto* station : m_activeLine)
    {
        station->display(os); // Displays all active stations on the assembly line in their current order
    }
}

}
