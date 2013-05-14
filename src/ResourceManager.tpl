#include <type_traits>

namespace rm
{
    template<class K,class T>
    ResourceManager<K,T>::ResourceManager()
    {
    };

    template<class K,class T>
    ResourceManager<K,T>::~ResourceManager()
    {
        clear();
    };


    template<class K,class T>
    T& ResourceManager<K,T>::add(const K& key,T&& obj)
    {
        std::pair<K,T> p(key,obj);
        resource.insert(p);
        return resource[key];
    };

    template<class K,class T>
    T& ResourceManager<K,T>::add(const K& key,const T& obj)
    {
        std::pair<K,T> p(key,obj);
        resource.insert(p);
        return resource[key];
    };

    template<class K,class T>
    template <typename ... Args>
    T& ResourceManager<K,T>::add(const K& key,const Args& ... args)
    {
        auto got = resource.find(key);
        if(got == resource.end())
            resource.emplace(args ...);
        return resource[key];
    };

    template<class K,class T>
    bool ResourceManager<K,T>::remove(const K& key)
    {
        auto got = resource.find(key);
        if(got != resource.end())
        {
            resource.erase(got);
            return true;
        }
        return false;
    };

    template<class K,class T>
    void ResourceManager<K,T>::clear()
    {
        do_clear(std::is_pointer<T>());
    };

    template<class K, class T>
    void ResourceManager<K, T>::do_clear(std::integral_constant<bool, true>)
    {
        for(auto& x:resource)
        delete x.second;
        resource.clear();
    }

    template<class K, class T>
    void ResourceManager<K, T>::do_clear(std::integral_constant<bool, false>)
    {
        resource.clear();
    }

};
