#include <iomanip>
#include <iostream>


namespace type_properties {
using std::cout;
using std::setfill;
using std::setw;
constexpr int column_width = 46;


void
print_main_header(char const * name)
{
  cout << setfill('=') << setw(column_width) << '\n';
  cout << name << '\n';
  cout << setfill('=') << setw(column_width) << '\n';
}


void
print_divider_header(char const * divider_name)
{
  cout << std::left << setfill('_') << setw(column_width) << divider_name << "\n" << std::right;
}


/**
 * Use this instead of @c print_properties directly to more easily print type
 * information without specifying your type and its name separately.
 */
#define print_properties_for_type(type) print_properties<type>(#type);


/**
 * Provides a means to print most of the type property predicates easily for a
 * type.  This isn't the best thing if you have a bunch of types--it is more of
 * an educational tool.
 */
template<typename T>
void print_properties(
    char const * name
  , char const * yes = "\033[1;32myes\033[0m" // ANSI escape codes for green
  , char const * no = "\033[1;31mno\033[0m")  // and red
{
  // A lot of std:: functions used here, this makes it easier to work around.
  using namespace std;
  constexpr int field_width = 40;

  print_main_header(name);

#define check(name, type_fn) cout << setfill(' ') << setw(field_width) << #name " : " << (type_fn::value ? yes : no) << '\n';
  cout << setfill(' ') << setw(field_width) << "size : " << sizeof(T) << '\n';
  check(is_pod, is_pod<T>);
  check(is_standard_layout, is_standard_layout<T>);
  check(is_empty, is_empty<T>);
  check(is_trivial, is_trivial<T>);
  check(is_literal_type, is_literal_type<T>);

  print_divider_header("Polymorphism");
  check(is_abstract, is_abstract<T>);
  check(is_polymorphic, is_polymorphic<T>);

  print_divider_header("Construction");
  check(is_constructible, is_constructible<T>);
  check(is_trivially_constructible, is_trivially_constructible<T>);
  check(is_nothrow_constructible, is_nothrow_constructible<T>);
  check(is_default_constructible, is_default_constructible<T>);
  check(is_trivially_default_constructible, is_trivially_default_constructible<T>);
  check(is_nothrow_default_constructible, is_nothrow_default_constructible<T>);
  check(is_copy_constructible, is_copy_constructible<T>);
  check(is_trivially_copy_constructible, is_trivially_copy_constructible<T>);
  check(is_nothrow_copy_constructible, is_nothrow_copy_constructible<T>);
  check(is_move_constructible, is_move_constructible<T>);
  check(is_trivially_move_constructible, is_trivially_move_constructible<T>);
  check(is_nothrow_move_constructible, is_nothrow_move_constructible<T>);

  print_divider_header("Deconstruction");
  check(is_destructible, is_destructible<T>);
  check(is_trivially_destructible, is_trivially_destructible<T>);
  check(is_nothrow_destructible, is_nothrow_destructible<T>);
  check(has_virtual_destructor, has_virtual_destructor<T>);

  print_divider_header("Assignment");
  // Cannot use preprocessor to paste <T, T> with ::
  cout << setfill(' ') << setw(field_width) << "is_assignable : " << (is_assignable<T, T>::value ? yes : no) << '\n';
  cout << setfill(' ') << setw(field_width) << "is_trivially_assignable : " << (is_trivially_assignable<T, T>::value ? yes : no) << '\n';
  cout << setfill(' ') << setw(field_width) << "is_nothrow_assignable : " << (is_nothrow_assignable<T, T>::value ? yes : no) << '\n';
  check(is_copy_assignable, is_copy_assignable<T>);
  check(is_trivially_copy_assignable, is_trivially_copy_assignable<T>);
  check(is_nothrow_copy_assignable, is_nothrow_copy_assignable<T>);

  print_divider_header("Moving");
  check(is_move_assignable, is_move_assignable<T>);
  check(is_trivially_move_assignable, is_trivially_move_assignable<T>);
  check(is_nothrow_move_assignable, is_nothrow_move_assignable<T>);

  cout << '\n';
#undef check
}

} // namespace type_properties
