#ifndef H_typeAlias
#define H_typeAlias

typedef char           t_int8, *p_int8;
typedef unsigned char  t_uint8, boolean, *p_uint8, *p_boolean;

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
	long value;
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
	unsigned long value;
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

#endif // H_typeAlias