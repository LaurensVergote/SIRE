#ifndef MULTITON_H
#define MULTITON_H

#include <map>
#include <string>

template <typename T, typename Key = std::string>
class Multiton
{
public:
    static void destroyAllInstances()
    {
        for (typename std::map<Key, T*>::const_iterator it = instances.begin(); it != instances.end(); ++it)
            delete (*it).second;
        instances.clear();
    }

    static void destroyInstance(const Key& key)
    {
        delete instances[key];
        instances.erase(key);
    }

    static T* getPtr(const Key& key) {
        typename std::map<Key, T*>::const_iterator it = instances.find(key);

        if (it != instances.end()) {
            return (T*)(it->second);
        }

        T* instance = new T();
        instances[key] = instance;
        return instance;
    }

    static T& getRef(const Key& key) {
        return *getPtr(key);
    }

protected:
    Multiton() {}
    ~Multiton() {}

private:
    Multiton(const Multiton&) {}
    Multiton& operator= (const Multiton&) { return *this; }

    static std::map<Key, T*> instances;
};

template <typename T, typename Key>
std::map<Key, T*> Multiton<T, Key>::instances;

#endif
