#include <iostream>
#include <chrono>
#include <array>
#include <memory>

class Timer
{
public:
	Timer()
	{
		m_startTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = end - start;

		double ms = duration * 0.001;

		std::cout << duration << "us(" << ms << "ms)\n";
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
};

int main()
{
	int value{ 0 };
	{
		Timer time;
		for (int i = 0; i < 100000; i++)
		{
			value += 2;
		}
	}

	struct Vector2 {
		float x, y;
	};
	
	std::array<std::shared_ptr<Vector2>, 1000> sharedArray;
	{
		Timer timer;
		for (int i = 0; i < sharedArray.size(); i++)
		{
			sharedArray[i] = std::make_shared<Vector2>();
		}
	}

	std::array<std::shared_ptr<Vector2>, 1000> Array;
	{
		Timer timer;
		for (int i = 0; i < Array.size(); i++)
		{
			Array[i] = std::shared_ptr<Vector2>(new Vector2);
		}
	}


	std::array<std::unique_ptr<Vector2>, 1000> uniqueArray;
	{
		Timer timer;
		for (int i = 0; i < uniqueArray.size(); i++)
		{
			uniqueArray[i] = std::make_unique<Vector2>();
		}
	}
	std::cin.get();
}

// If wanna benhmark performance should be run in release mode
// Get Warning in main function: Function uses '40052' bytes of stack.Consider moving some data to heap 
// Because in Windows each thread can store 1MB in stack 

//// ✅ Solution 1: Move std::array to heap using std::unique_ptr
//auto sharedArray1 = std::make_unique<std::array<std::shared_ptr<Vector2>, 1000>>();
//auto sharedArray2 = std::make_unique<std::array<std::shared_ptr<Vector2>, 1000>>();
//auto sharedArray3 = std::make_unique<std::array<std::shared_ptr<Vector2>, 1000>>();
//
//// ✅ Solution 2: Use std::vector instead of std::array (vector allocates on heap)
//std::vector<std::shared_ptr<Vector2>> sharedArray1(1000);
//std::vector<std::shared_ptr<Vector2>> sharedArray2(1000);
//std::vector<std::shared_ptr<Vector2>> sharedArray3(1000);
//
//// ✅ Solution 3: Use inside a class with constructor initialization
//class Something {
//public:
//	std::vector<std::shared_ptr<Vector2>> sharedArray1;
//	std::vector<std::shared_ptr<Vector2>> sharedArray2;
//	std::vector<std::shared_ptr<Vector2>> sharedArray3;
//
//	Something()
//		: sharedArray1(1000), sharedArray2(1000), sharedArray3(1000) {}
//};
//
//// ❌ Avoid this: large stack allocation (each array ~16KB on stack)
//std::array<std::shared_ptr<Vector2>, 1000> sharedArray1;
//std::array<std::shared_ptr<Vector2>, 1000> sharedArray2;
//std::array<std::shared_ptr<Vector2>, 1000> sharedArray3;