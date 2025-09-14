namespace my
{ int x ; int y ; } ;
namespace your
{ int x ; int y ; } ;
int main(){
    int x;
    x = 10; // ???
    using  my::x ;
    x = 11; // ???
    y = 11; // ???
    my :: x = 12; // ??
    using namespace my ;
    using namespace your ;
    x = 20;
    y = 20;
}