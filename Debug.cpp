#include "Linked-List-Cpp.h"
#include <cstdlib>
#include <iostream>
/*
int main(int argc, char* argv[])
{
	int ints[] = {114514,8546844,11455854};
	LinkList<int> i = LinkList<int>(ints,std::end(ints) - std::begin(ints));
	system("pause");
}*/
template <typename T>
void DebugPrint(const std::string& message, const T& value)
{
    std::cout << message << ": " << value << std::endl;
}

// Debug print function specialization for pointers
template <typename T>
void DebugPrint(const std::string& message, const T* ptr)
{
    std::cout << message << ": " << (ptr != nullptr ? *ptr : "nullptr") << std::endl;
}

// Debug print function for LinkedListItem
template <typename T>
void DebugPrint(const std::string& message, const LinkedListItem<T>& item)
{
    std::cout << message << ":" << std::endl;
    DebugPrint("  This", item.ThisPtr());
    DebugPrint("  Last", item.LastPtr());
    DebugPrint("  Next", item.NextPtr());
}

// Debug print function for LinkList
template <typename Class, typename IAllocator>
void DebugPrint(const std::string& message, const LinkList<Class, IAllocator>& list)
{
    std::cout << message << ":" << std::endl;
    for (IAllocator i = 0; i < list.Length(); i++)
    {
        DebugPrint("  Item " + std::to_string(i), list[i]);
    }
}

int main()
{
    try
    {
        // Create sample objects
        int value1 = 10;
        int value2 = 20;
        int value3 = 30;
        int value4 = 40;

        // Create a LinkList
        LinkList<int> list;

        // Push items into the list
        list.Push_Back(value1);
        list.Push_Back(value2);
        list.Push_Back(value3);

        // Debug print the list
        DebugPrint("List", list);

        // Modify an item
        list[(unsigned long long int)1] = value4;

        // Debug print the modified list
        DebugPrint("Modified List", list);
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}