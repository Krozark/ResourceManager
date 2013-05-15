#include <iostream>

#include "ResourceManager/ResourceManager.hpp"

int main(int argc,char* argv[])
{
    {
        std::cout<<"with K= std::string, T = std::string"<<std::endl;
        rm::ResourceManager<std::string,std::string> Rmanager;

        std::string bar = "bar";
        std::string foo = "foo";
        std::string blah = "blah";


        std::cout<<"Init bar / foo"<<std::endl;
        std::cout<<"bar: "<<Rmanager.add(bar,std::string("bar value"))<<std::endl;
        std::cout<<"foo: "<<Rmanager.add(foo,foo)<<std::endl;

        std::cout<<std::endl<<"see bar / foo"<<std::endl;
        std::cout<<"bar: "<<Rmanager["bar"]<<std::endl;
        std::cout<<"foo: "<<Rmanager["foo"]<<std::endl;

        std::cout<<std::endl<<"Init blah"<<std::endl;
        std::cout<<"blah: "<<(Rmanager["blah"] = "blah value")<<std::endl;

        std::cout<<std::endl<<"bar = blah"<<std::endl;
        Rmanager[bar] = Rmanager[blah];

        std::cout<<std::endl<<" see bar / blah"<<std::endl;
        std::cout<<"bar: "<<Rmanager[bar]<<std::endl;
        std::cout<<"blah: "<<Rmanager[blah]<<std::endl;

        std::cout<<std::endl<<"remove bar"<<std::endl;
        Rmanager.remove(bar);

        std::cout<<std::endl<<"see bar"<<std::endl;
        std::cout<<"bar: "<<Rmanager[bar]<<std::endl;

        std::cout<<std::endl<<"clear"<<std::endl;
        Rmanager.clear();

        std::cout<<std::endl<<"see bar / foo / blah"<<std::endl;
        std::cout<<"bar: "<<Rmanager["bar"]<<std::endl;
        std::cout<<"foo: "<<Rmanager[foo]<<std::endl;
        std::cout<<"blah: "<<Rmanager[blah]<<std::endl;
    }

    {
        std::cout<<"with K= std::string, T = std::string*"<<std::endl;
        rm::ResourceManager<std::string,std::string*> Rmanager;

        std::string bar = "bar";
        std::string foo = "foo";
        std::string blah = "blah";


        std::cout<<"Init bar / foo"<<std::endl;
        std::cout<<"bar: "<<*Rmanager.add(bar,new std::string("bar value"))<<std::endl;
        std::cout<<"foo: "<<*Rmanager.add(foo,new std::string(foo))<<std::endl;

        std::cout<<std::endl<<"see bar / foo"<<std::endl;
        std::cout<<"bar: "<<*Rmanager["bar"]<<std::endl;
        std::cout<<"foo: "<<*Rmanager["foo"]<<std::endl;

        std::cout<<std::endl<<"Init blah"<<std::endl;
        std::cout<<"blah: "<<*(Rmanager["blah"] = new std::string("blah value"))<<std::endl;

        std::cout<<std::endl<<"bar = blah"<<std::endl;
        delete Rmanager[bar];
        Rmanager[bar] = new std::string(*Rmanager[blah]);

        std::cout<<std::endl<<" see bar / blah"<<std::endl;
        std::cout<<"bar: "<<*Rmanager[bar]<<std::endl;
        std::cout<<"blah: "<<*Rmanager[blah]<<std::endl;

        std::cout<<std::endl<<"remove bar"<<std::endl;
        Rmanager.remove(bar);

        std::cout<<std::endl<<"see bar"<<std::endl;
        std::cout<<"bar: "<<Rmanager[bar]<<std::endl;

        std::cout<<std::endl<<"clear"<<std::endl;
        Rmanager.clear();

        std::cout<<std::endl<<"see bar / foo / blah"<<std::endl;
        std::cout<<"bar: "<<Rmanager["bar"]<<std::endl;
        std::cout<<"foo: "<<Rmanager[foo]<<std::endl;
        std::cout<<"blah: "<<Rmanager[blah]<<std::endl;
    }
    

    return 0;
};
