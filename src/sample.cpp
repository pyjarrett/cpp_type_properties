#include "type_properties.hpp"

struct EmptyClass {};

struct VirtualDestructor {
  virtual ~VirtualDestructor() {}
};

struct AbstractClass {
  virtual void a_member_function() = 0;
  virtual void another_member_function();
};
void AbstractClass::a_member_function() {}


struct ClassWithFunction {
  void a_member_function() {}
};


int main() {
  using namespace type_properties;
  print_properties_for_type(EmptyClass);
  print_properties_for_type(VirtualDestructor);
  print_properties_for_type(AbstractClass);
  print_properties_for_type(ClassWithFunction);
  return 0;
}
