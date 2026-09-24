/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 6 - Class Templates
 * Description: Generic metric log practice and ADT contract
 * Due date: [Date]
 */

#include <iostream>
using namespace std;

/*
 * MetricLog ADT
 *
 * Data:
 * [Complete in Part E: describe the values managed by this log.]
 *
 * Operations:
 * [Complete in Part E: describe add(value).]
 //adds a new metric value to the log if space is available; returns true on success, false if full.
 * [Complete in Part E: describe get(index) and its precondition.]
 // Retrieves the metric value at the specified index. Precondition: 0 <= index < size().
 * [Complete in Part E: describe contains(target).]
 // Searches for a target metric in the log; returns true if found, false otherwise.
 * [Complete in Part E: describe size() and isEmpty().]
 //
 */

template <typename T>
class MetricLog
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Add a constant for a fixed capacity of four values.
    static const int CAPACITY = 4;
    // TODO (Part C): Add an array that stores values of the generic type.
    T values[CAPACITY];
    // TODO (Part C): Add an int that tracks how many values are stored.
    int count;

public:
    // TODO (Part C): Write a constructor that creates an empty log.
    MetricLog()
    {
        count = 0; // A new log starts with no stored values.
    }

    // TODO (Part C): Write add. It receives one generic value by const reference.
    // Return false when the log has no remaining capacity.
    bool add(const T& value)
    {
        if (count == CAPACITY)
        {
            return false;
        }
        values[count] = value;
        count++;
        return true;
    }

    // TODO (Part C): Write get. It receives a valid index and returns its stored value.
    T get(int index) const
    {
        return values[index];
    }

    // TODO (Part C): Write size as a const member function.
    int size() const
    {
        return count;
    }

    // TODO (Part C): Write isEmpty as a const member function.
    bool isEmpty() const
    {
        return count == 0;
    }

    bool contains(const T& target) const;
};

// ===== Do not resolve these TODOs yet (Part D) =====

// TODO (Part D): Define MetricLog<T>::contains outside the class.
// It receives a generic target by const reference.
// Return true when an equal stored value exists; otherwise return false.
template <typename T>
bool MetricLog<T>::contains(const T& target) const
{
    for (int i = 0; i < count; i++)
    {
        if (values[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << boolalpha;        // Print bool values as true or false.

    MetricLog<int> waitlistCounts;

    waitlistCounts.add(6);
    waitlistCounts.add(11);

    cout << "First waitlist count: " << waitlistCounts.get(0) << endl;
    cout << "Stored waitlist counts: " << waitlistCounts.size() << endl;

// ===== Do not resolve these TODOs yet (Part E) =====

    // TODO (Part E): Create a MetricLog<double> for session durations.
    MetricLog<double> sessionDurations;

    // TODO (Part E): Add two dummy duration values to that log.
    sessionDurations.add(42.5);
    sessionDurations.add(55.0);

    // TODO (Part E): Use contains with one value that exists and one that does not exist.
    // TODO (Part E): Print descriptive English labels for all results.
    cout << "First session duration: " << sessionDurations.get(0) << endl;
    cout << "Duration exists (42.5): " << sessionDurations.contains(42.5) << endl;
    cout << "Other duration exists (30.0): " << sessionDurations.contains(30.0) << endl;

    return 0;
}