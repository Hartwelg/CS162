#ifndef BAG_H
#define BAG_H
#include <string>
#include <sstream>
template <class T>
class Bag
{
public:
    Bag();
    ~Bag();
    Bag(const Bag<T>& other);
    Bag<T>& operator=(const Bag<T>& other);
    void addItem(T item);
    bool contains(T item);
    std::string toString() const;
    bool removeItem(T item);
    bool isEmpty();
    void dump();
    int numberOf(T item);
    void removeAll(T item);
    T pickRandom();
    void dumpInto(Bag<T>& other);
    Bag<T> extractAll(T item);
private:
    void grow();

    T* stuff;
    int size;
    int capacity;
};

template <class T>
Bag<T>::Bag()
{
    size = 0;
    capacity = 10;
    stuff = new T[capacity];
}
template <class T>
Bag<T>::Bag(const Bag<T> &other)
{
    size = other.size;
    capacity = other.capacity;
    stuff = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        stuff[i] = other.stuff[i];
    }
}
template <class T>
Bag<T>& Bag<T>::operator=(const Bag<T>& other)
{
    if (&other == this)
    {
        return *this;
    }
    capacity = other.capacity;

    size = other.size;

    delete [] stuff;

    stuff = new T[other.capacity];

    for(int i = 0; i < size; i++)
    {
        stuff[i] = other.stuff[i];
    }

    return *this;
}
template <class T>
void Bag<T>::grow()
{
    int thisSize = capacity * 2;
    T* thisList = new T[thisSize];
    for (int i = 0; i < capacity; i++)
    {
        thisList[i] = stuff[i];
    }
    capacity = thisSize;
    delete [] stuff;
    stuff = thisList;
}
template <class T>
Bag<T>::~Bag()
{
    delete [] stuff;
}
template <class T>
void Bag<T>::addItem(T item)
{
        if (size == capacity)
        {
            grow();
        }
        stuff[size] = item;
        size++;
}
template <class T>
bool Bag<T>::contains(T item)
{
    int num = 0;

    for (int i = 0; i < size; i++)
    {
        if (stuff[i] == item)
        {
            num++;
        }
    }

    if(num > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
std::string Bag<T>::toString() const
{
    std::stringstream ss;
    ss << "{";
    for (int i = 0; i < size - 1; i++)
    {
        ss << stuff[i] << ", ";
    }
    if (size > 0)
    {
        ss << stuff[size - 1];
    }
    ss << "}";
    return ss.str();
}
template <class T>
bool Bag<T>::removeItem(T item)
{
    for (int i = 0; i < size; i++)
    {
        if (stuff[i] == item)
        {
            stuff[size] = item;
            size--;
            return true;
        }
    }
    return false;
}
template <class T>
bool Bag<T>::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}
template <class T>
void Bag<T>::dump()
{
    size = 0;
}
template <class T>
int Bag<T>::numberOf(T item)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if (stuff[i] == item)
        {
            total++;
        }
    }
    return total;
}
template <class T>
void Bag<T>::removeAll(T item)
{
    for (int i = 0; i < size; i++)
    {
        if (stuff[i] == item)
        {
            for (int j = i; j < size - 1; j++)
            {
                stuff[j] = stuff[j + 1];
            }
            i--;
            size--;
        }
    }
}
template <class T>
T Bag<T>::pickRandom()
{
    int random = rand() % size;
    for (int i = 0; i < size; i++)
    {
        if (i == random)
        {

            stuff[size] = stuff[i];
            for (int j = i; j < size - 1; j++)
            {
                stuff[j] = stuff[j + 1];
            }
            size--;
            return stuff[size + 1];
        }
    }
    return false;
}
template <class T>
void Bag<T>::dumpInto(Bag<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    for (int i = 0; i < size; i++)
    {
        other.stuff[size + i] = stuff[i];
    }
    other.size += size;
    dump();
}
template <class T>
Bag<T> Bag<T>::extractAll(T item)
{
    Bag<T> other;
    for (int i = 0; i < size; i++)
    {
        if (stuff[i] == item)
        {
            other.addItem(item);
            stuff[size] = stuff[i];
            for (int j = i; j < size - 1; j++)
            {
                stuff[j] = stuff[j + 1];
            }
            i--;
            size--;
        }
    }
    return other;
}
#endif // BAG_H
