#ifndef H_interface
#define H_interface

#define M_interface   class

#define M_interface_method  public: virtual
#define M_end_interface_method  = 0;

#define M_declare_interface(name)   M_interface name { \
    M_interface_method ~name() {}

#define M_declare_interface_with_base(name, baseInterface)   M_interface name : public baseInterface { \
    M_interface_method ~name() {}

#define M_end_interface };

#define M_implements  public

#endif // H_interface