#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <unordered_map>
#include <utility>

namespace rm
{
    template<class K,class T>
    class ResourceManager
    {
        public:
            ResourceManager();
            ~ResourceManager();

            ResourceManager(const ResourceManager&) = delete;
            ResourceManager& operator=(const ResourceManager) = delete;

            T& add(const K& key,T&& obj);

            T& add(const K& key,const T& obj);

            template <typename ... Args>
            T& add(const K& key,const Args& ... args);

            bool remove(const K& key);

            bool find(const K& key) const;

            void clear();

            inline T& operator[](const K& key){return resource[key];};

        private : 
            std::unordered_map<K,T> resource;

            void do_clear(std::integral_constant<bool, true>);
            void do_clear(std::integral_constant<bool, false>);

            bool do_remove(const K& key,std::integral_constant<bool, true>);
            bool do_remove(const K& key,std::integral_constant<bool, false>);

    };
};

#include "ResourceManager.tpl"
#endif
