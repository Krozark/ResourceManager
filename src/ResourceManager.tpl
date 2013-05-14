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
    T& ResourceManager<K,T>::add(const K& key,const T* obj)
    {
        resource.insert(std::make_pair<K,T>(key,*obj));
        return resource[key];
    };

    template<class K,class T>
    T& ResourceManager<K,T>::add(const K& key,const T& obj)
    {
        resource.insert(std::make_pair<K,T>(key,obj));
        return resource[key];
    };

    template<class K,class T>
    template <Args ...>
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
};
