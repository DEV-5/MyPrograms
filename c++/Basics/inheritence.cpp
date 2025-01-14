//source = https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance

/*
 *Access speccifiers:
 *  Everything that is aware of Base is also aware that Base contains publicMember.
 *  Only the children (and their children) are aware that Base contains protectedMember.
 *  No one but Base is aware of privateMember.
 *
 *Inheritance:
 *  If the inheritance is public, everything that is aware of Base and Child is also aware that Child inherits from Base.
 *  If the inheritance is protected, only Child, and its children, are aware that they inherit from Base.
 *  If the inheritance is private, no one other than Child is aware of the inheritance.
 */


class A 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
