ResourceManager
===============

A  resource manager (usefull in game engine).

Class
-----

* rm::ResourceManager\<K,T\> Rmanager;
* K is type of key
* T is type of resource

if T if pointer, auto delet are make.


Fonction
--------

* T& add(const K& key,T&& obj)
* T& add(const K& key,const T& obj)
* T& add(const K& key,const Args& ... args)
* bool remove(const K& key)
* void clear()
* T& operator[](const K& key)


Exemple
-------

See main.cpp for exemple

