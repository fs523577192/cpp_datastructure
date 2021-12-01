#ifndef H_typeAlias
#define H_typeAlias

typedef float          t_float32, *p_float32;
typedef double         t_float64, *p_float64;

typedef char           t_int8, *p_int8;
typedef unsigned char  t_uint8, t_boolean, *p_uint8, *p_boolean;

typedef union {
	short value;
	struct {
        #ifdef M_high_endian
			t_int8  high;
			t_uint8 low;
		#else
			t_uint8 low;
			t_int8  high;
		#endif
	} components;
} t_int16, *p_int16;
typedef union {
	unsigned short value;
	struct {
		#ifdef M_high_endian
			t_uint8 high;
			t_uint8 low;
		#else
			t_uint8 low;
			t_uint8 high;
		#endif
	} components;
} t_uint16, t_unicode, *p_uint16, *p_unicode;

typedef union {
	int value;
	struct {
        #ifdef M_high_endian
			t_int16  high;
			t_uint16 low;
		#else
			t_uint16 low;
			t_int16  high;
		#endif
	} components;
} t_int32, *p_int32;
typedef union {
	unsigned int value;
	struct {
		#ifdef M_high_endian
			t_uint16 high;
			t_uint16 low;
		#else
			t_uint16 low;
			t_uint16 high;
		#endif
	} components;
} t_uint32, *p_uint32;

typedef union {
	long long value;
	struct {
        #ifdef M_high_endian
			t_int32  high;
			t_uint32 low;
		#else
			t_uint32 low;
			t_int32  high;
		#endif
	} components;
} t_int64, *p_int64;
typedef union {
	unsigned long long value;
	struct {
		#ifdef M_high_endian
			t_uint32 high;
			t_uint32 low;
		#else
			t_uint32 low;
			t_uint32 high;
		#endif
	} components;
} t_uint64, *p_uint64;

#define H_defineAssignOperator(myType, cppType, op) myType& operator op(myType& a, myType& b) {a.value op b.value; return a;} \
        myType& operator op(myType& a, cppType b) {a.value op b; return a;}
#define H_defineAssignOperators(myType, cppType) \
        H_defineAssignOperator(myType, cppType, &=); \
        H_defineAssignOperator(myType, cppType, |=); \
        H_defineAssignOperator(myType, cppType, ^=); \
        H_defineAssignOperator(myType, cppType, +=); \
        H_defineAssignOperator(myType, cppType, -=); //H_defineAssignOperator(myType, cppType, =); \

#define H_defineOperator(myType, cppType, op) myType operator op(myType a, myType b) {myType result = {a.value op b.value}; return result;} \
        myType operator op(myType a, cppType b) {myType result = {a.value op b}; return result;} \
        myType operator op(cppType a, myType b) {myType result = {a op b.value}; return result;}
#define H_defineOperators(myType, cppType) H_defineOperator(myType, cppType, &) \
        H_defineOperator(myType, cppType, |) \
        H_defineOperator(myType, cppType, ^) \
        H_defineOperator(myType, cppType, +) \
        H_defineOperator(myType, cppType, -)

#define H_defineComparator(myType, cppType, op) t_boolean operator op(myType a, myType b) {return a.value op b.value;} \
        t_boolean operator op(myType a, cppType b) {return a.value op b;} \
        t_boolean operator op(cppType a, myType b) {return a op b.value;}
#define H_defineComparators(myType, cppType) H_defineComparator(myType, cppType, ==) \
        H_defineComparator(myType, cppType, <) \
        H_defineComparator(myType, cppType, <=) \
        H_defineComparator(myType, cppType, >) \
        H_defineComparator(myType, cppType, >=)

#define H_defineAllOperators(myType, cppType) H_defineAssignOperators(myType, cppType) \
        H_defineOperators(myType, cppType) \
        H_defineComparators(myType, cppType)

H_defineAllOperators(t_int32, int);

H_defineAllOperators(t_uint32, unsigned int);

H_defineAllOperators(t_int64, long long);

H_defineAllOperators(t_uint64, unsigned long long);

#undef H_defineAllOperators
#undef H_defineAssignOperators
#undef H_defineAssignOperator
#undef H_defineOperators
#undef H_defineOperator
#undef H_defineComparators
#undef H_defineComparator

// String
#include <memory>
#include <string>
typedef std::shared_ptr<const std::string> String;

#endif // H_typeAlias
