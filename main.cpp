#include <iostream>
#include <string>
#include <cstring>
class String
{
private:
    char* m_buffer;
    unsigned int m_bufferSize;
public:
    String(const char* string)
    {
        m_bufferSize = strlen(string);
        m_buffer = new char[m_bufferSize + 1];
        memcpy(m_buffer, string, m_bufferSize + 1);
    }

    char& operator[](unsigned int index)
    {
        return m_buffer[index];
    }
    //String(const String& other) = delete;

    String(const String& other)
        : m_bufferSize(other.m_bufferSize)
    {
        std::cout << "Constructed" << std::endl;

        m_buffer = new char[m_bufferSize + 1];;
        memcpy(m_buffer, other.m_buffer, m_bufferSize + 1);
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);

    ~String() { delete[] m_buffer; }
};

void PrintString(String string)
//void PrintString(const String& string)
{
    std::cout << string << std::endl;
}



std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buffer;
    return stream;
}

int main()
{
    String string = "Cherno";
    String second = string;
    string[2] = 'k';
    PrintString(string);
    PrintString(second);
    std::cin.get();
    return 0;
}