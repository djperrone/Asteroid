#pragma once

#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

class Timer {

private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTimePoint;
	std::chrono::time_point<std::chrono::steady_clock> m_tempTimePoint;
	std::chrono::time_point<std::chrono::steady_clock> m_endTimepoint;	
	
	long double start, end, duration, temp;

public:
	// Default Constructor
	Timer()
	{
		
	}	

	void Calc()
	{
		start = std::chrono::time_point_cast<std::chrono::seconds>(m_startTimePoint).time_since_epoch().count();
		end = std::chrono::time_point_cast<std::chrono::seconds>(m_endTimepoint).time_since_epoch().count();
		duration = (end - start);
	}

	inline void Reset() {start = end = duration = 0;}
	inline void Start() { m_startTimePoint = std::chrono::steady_clock::now(); }
	inline void Stop() { m_endTimepoint = std::chrono::steady_clock::now(); }

	inline long double GetStart(){ return start; }
	inline long double GetEnd(){ return end; }
	inline void SetTemp(long double t) { temp = t; }
	
};