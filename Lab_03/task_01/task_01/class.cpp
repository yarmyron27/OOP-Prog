#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;

public:
    Base() : publicVar(1), protectedVar(2), privateVar(3) {}
};

//PublicDerived — публічне успадкування
class PublicDerived : public Base {
public:
    void modifyVar() {
        publicVar = 10;
        protectedVar = 20;
        //privateVar = 30; недоступна зміна значення
    }
};

//ProtectedDerived - захищене успадкування
class ProtectedDerived : protected Base {
public:
    void modifyVar() {
        publicVar = 10;
        protectedVar = 20;
        //privateVar = 30; недоступна зміна значення
    }
};

//PrivateDerived - приватне успадкування
class PrivateDerived : private Base {
public:
    void modifyVar() {
        publicVar = 10;
        protectedVar = 20;
        //privateVar = 30; недоступна зміна значення
    }
};


int main() {
    PublicDerived pub;
    pub.publicVar = 100;
    //pub.protectedVar = 100; не маємо доступу залишається protected
    //pub.privateVar = 300; не маємо доступу залишається private

    ProtectedDerived prot;
    //prot.publicVar = 100; не маємо доступу перетворюється на protected
    //prot.protectedVar = 300; не маємо доступу залишаєтся protected
    //prot.privateVar = 300; не маємо доступу залишається private

    PrivateDerived priv;
    //priv.publicVar = 100; не маємо доступу перетворюється на private
    //priv.protectedVar = 300; не маємо доступу перетворюється на private
    //priv.privateVar = 300; не маємо доступу залишається private

}
