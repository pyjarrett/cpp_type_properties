# cpp_type_properties
Prints type properties of C++ objects

# Purpose

Sometimes, you may want to know *exactly* what capabilities a type affords.  This just provides a quick way to do it.
Probably more of personal educational use especially for playing with types and checking strange cases.

This is a relatively lightweight solution also for checking a bunch of existing legacy types you may have floating around.

# Run the sample
```bash
bazel build //src:sample && bazel-bin/src/sample
```

# Types in the sample

```C++
struct EmptyClass {};

struct VirtualDestructor {
  virtual ~VirtualDestructor() {}
};

struct AbstractClass {
  virtual ~AbstractClass() {}
  virtual void a_member_function() = 0;
};


struct ClassWithFunction {
  void a_member_function() {}
};


```

# Sample output

```
=============================================
EmptyClass
=============================================
                                 size : 1
                               is_pod : yes
                   is_standard_layout : yes
                             is_empty : yes
                           is_trivial : yes
                      is_literal_type : yes
Polymorphism__________________________________
                          is_abstract : no
                       is_polymorphic : no
Construction__________________________________
                     is_constructible : yes
           is_trivially_constructible : yes
             is_nothrow_constructible : yes
             is_default_constructible : yes
   is_trivially_default_constructible : yes
     is_nothrow_default_constructible : yes
                is_copy_constructible : yes
      is_trivially_copy_constructible : yes
        is_nothrow_copy_constructible : yes
                is_move_constructible : yes
      is_trivially_move_constructible : yes
        is_nothrow_move_constructible : yes
Deconstruction________________________________
                      is_destructible : yes
            is_trivially_destructible : yes
              is_nothrow_destructible : yes
               has_virtual_destructor : no
Assignment____________________________________
                        is_assignable : yes
              is_trivially_assignable : yes
                is_nothrow_assignable : yes
                   is_copy_assignable : yes
         is_trivially_copy_assignable : yes
           is_nothrow_copy_assignable : yes
Moving________________________________________
                   is_move_assignable : yes
         is_trivially_move_assignable : yes
           is_nothrow_move_assignable : yes

=============================================
VirtualDestructor
=============================================
                                 size : 8
                               is_pod : no
                   is_standard_layout : no
                             is_empty : no
                           is_trivial : no
                      is_literal_type : no
Polymorphism__________________________________
                          is_abstract : no
                       is_polymorphic : yes
Construction__________________________________
                     is_constructible : yes
           is_trivially_constructible : no
             is_nothrow_constructible : yes
             is_default_constructible : yes
   is_trivially_default_constructible : no
     is_nothrow_default_constructible : yes
                is_copy_constructible : yes
      is_trivially_copy_constructible : no
        is_nothrow_copy_constructible : yes
                is_move_constructible : yes
      is_trivially_move_constructible : no
        is_nothrow_move_constructible : yes
Deconstruction________________________________
                      is_destructible : yes
            is_trivially_destructible : no
              is_nothrow_destructible : yes
               has_virtual_destructor : yes
Assignment____________________________________
                        is_assignable : yes
              is_trivially_assignable : no
                is_nothrow_assignable : yes
                   is_copy_assignable : yes
         is_trivially_copy_assignable : no
           is_nothrow_copy_assignable : yes
Moving________________________________________
                   is_move_assignable : yes
         is_trivially_move_assignable : no
           is_nothrow_move_assignable : yes

=============================================
AbstractClass
=============================================
                                 size : 8
                               is_pod : no
                   is_standard_layout : no
                             is_empty : no
                           is_trivial : no
                      is_literal_type : no
Polymorphism__________________________________
                          is_abstract : yes
                       is_polymorphic : yes
Construction__________________________________
                     is_constructible : no
           is_trivially_constructible : no
             is_nothrow_constructible : no
             is_default_constructible : no
   is_trivially_default_constructible : no
     is_nothrow_default_constructible : no
                is_copy_constructible : no
      is_trivially_copy_constructible : no
        is_nothrow_copy_constructible : no
                is_move_constructible : no
      is_trivially_move_constructible : no
        is_nothrow_move_constructible : no
Deconstruction________________________________
                      is_destructible : yes
            is_trivially_destructible : no
              is_nothrow_destructible : yes
               has_virtual_destructor : yes
Assignment____________________________________
                        is_assignable : yes
              is_trivially_assignable : no
                is_nothrow_assignable : yes
                   is_copy_assignable : yes
         is_trivially_copy_assignable : no
           is_nothrow_copy_assignable : yes
Moving________________________________________
                   is_move_assignable : yes
         is_trivially_move_assignable : no
           is_nothrow_move_assignable : yes

=============================================
ClassWithFunction
=============================================
                                 size : 1
                               is_pod : yes
                   is_standard_layout : yes
                             is_empty : yes
                           is_trivial : yes
                      is_literal_type : yes
Polymorphism__________________________________
                          is_abstract : no
                       is_polymorphic : no
Construction__________________________________
                     is_constructible : yes
           is_trivially_constructible : yes
             is_nothrow_constructible : yes
             is_default_constructible : yes
   is_trivially_default_constructible : yes
     is_nothrow_default_constructible : yes
                is_copy_constructible : yes
      is_trivially_copy_constructible : yes
        is_nothrow_copy_constructible : yes
                is_move_constructible : yes
      is_trivially_move_constructible : yes
        is_nothrow_move_constructible : yes
Deconstruction________________________________
                      is_destructible : yes
            is_trivially_destructible : yes
              is_nothrow_destructible : yes
               has_virtual_destructor : no
Assignment____________________________________
                        is_assignable : yes
              is_trivially_assignable : yes
                is_nothrow_assignable : yes
                   is_copy_assignable : yes
         is_trivially_copy_assignable : yes
           is_nothrow_copy_assignable : yes
Moving________________________________________
                   is_move_assignable : yes
         is_trivially_move_assignable : yes
           is_nothrow_move_assignable : yes
```
