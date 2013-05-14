#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <unordered_map>

namespace rm
{
    template<class K,class T>
    class ResourceManager
    {
        ResourceManager();
        ~ResourceManager();

        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager) = delete;

        T& add(const K& key,const T* obj);

        T& add(const K& key,const T& obj);

        template <Args ...>
        T& add(const K& key,const Args& ... args);

        bool remove(const K& key);

        void clear();

        T& operator[](const K&);

        private : 
        std::unordered_map<K,T*> resource;

    };

};

#include "ResourceManager.tpl"
#endif
