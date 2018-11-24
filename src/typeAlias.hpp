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

// operator override for t_int32
t_int32 operator&(t_int32 a, t_int32 b) {
	a.value &= b.value;
	return a;
}
t_int32 operator&(long a, t_int32 b) {
	b.value &= a;
	return b;
}
t_int32 operator&(t_int32 a, long b) {
	a.value &= b;
	return a;
}
t_int32 operator|(t_int32 a, t_int32 b) {
	a.value |= b.value;
	return a;
}
t_int32 operator|(long a, t_int32 b) {
	b.value = a | b.value;
	return b;
}
t_int32 operator|(t_int32 a, long b) {
	a.value |= b;
	return a;
}
t_int32 operator+(t_int32 a, t_int32 b) {
	a.value += b.value;
	return a;
}
t_int32 operator+(long a, t_int32 b) {
	b.value += a;
	return b;
}
t_int32 operator+(t_int32 a, long b) {
	a.value += b;
	return a;
}
t_int32 operator-(t_int32 a, t_int32 b) {
	a.value -= b.value;
	return a;
}
t_int32 operator-(long a, t_int32 b) {
	b.value = a - b.value;
	return b;
}
t_int32 operator-(t_int32 a, long b) {
	a.value -= b;
	return a;
}
t_boolean operator>(t_int32 a, t_int32 b) {
	return a.value > b.value;
}
t_boolean operator>(long a, t_int32 b) {
	return a > b.value;
}
t_boolean operator>(t_int32 a, long b) {
	return a.value > b;
}
t_boolean operator<(t_int32 a, t_int32 b) {
	return a.value < b.value;
}
t_boolean operator<(long a, t_int32 b) {
	return a < b.value;
}
t_boolean operator<(t_int32 a, long b) {
	return a.value < b;
}
t_boolean operator>=(t_int32 a, t_int32 b) {
	return a.value >= b.value;
}
t_boolean operator>=(long a, t_int32 b) {
	return a >= b.value;
}
t_boolean operator>=(t_int32 a, long b) {
	return a.value >= b;
}
t_boolean operator<=(t_int32 a, t_int32 b) {
	return a.value <= b.value;
}
t_boolean operator<=(long a, t_int32 b) {
	return a <= b.value;
}
t_boolean operator<=(t_int32 a, long b) {
	return a.value <= b;
}

// operator override for t_uint32
t_uint32 operator&(t_uint32 a, t_uint32 b) {
	a.value &= b.value;
	return a;
}
t_uint32 operator&(unsigned long a, t_uint32 b) {
	b.value &= a;
	return b;
}
t_uint32 operator&(t_uint32 a, unsigned long b) {
	a.value &= b;
	return a;
}
t_uint32 operator|(t_uint32 a, t_uint32 b) {
	a.value |= b.value;
	return a;
}
t_uint32 operator|(unsigned long a, t_uint32 b) {
	b.value = a | b.value;
	return b;
}
t_uint32 operator|(t_uint32 a, unsigned long b) {
	a.value |= b;
	return a;
}
t_uint32 operator+(t_uint32 a, t_uint32 b) {
	a.value += b.value;
	return a;
}
t_uint32 operator+(unsigned long a, t_uint32 b) {
	b.value += a;
	return b;
}
t_uint32 operator+(t_uint32 a, unsigned long b) {
	a.value += b;
	return a;
}
t_uint32 operator-(t_uint32 a, t_uint32 b) {
	a.value -= b.value;
	return a;
}
t_uint32 operator-(unsigned long a, t_uint32 b) {
	b.value = a - b.value;
	return b;
}
t_uint32 operator-(t_uint32 a, unsigned long b) {
	a.value -= b;
	return a;
}
t_boolean operator>(t_uint32 a, t_uint32 b) {
	return a.value > b.value;
}
t_boolean operator>(unsigned long a, t_uint32 b) {
	return a > b.value;
}
t_boolean operator>(t_uint32 a, unsigned long b) {
	return a.value > b;
}
t_boolean operator<(t_uint32 a, t_uint32 b) {
	return a.value < b.value;
}
t_boolean operator<(unsigned long a, t_uint32 b) {
	return a < b.value;
}
t_boolean operator<(t_uint32 a, unsigned long b) {
	return a.value < b;
}
t_boolean operator>=(t_uint32 a, t_uint32 b) {
	return a.value >= b.value;
}
t_boolean operator>=(unsigned long a, t_uint32 b) {
	return a >= b.value;
}
t_boolean operator>=(t_uint32 a, unsigned long b) {
	return a.value >= b;
}
t_boolean operator<=(t_uint32 a, t_uint32 b) {
	return a.value <= b.value;
}
t_boolean operator<=(unsigned long a, t_uint32 b) {
	return a <= b.value;
}
t_boolean operator<=(t_uint32 a, unsigned long b) {
	return a.value <= b;
}

// operator override for t_int64
t_int64 operator&(t_int64 a, t_int64 b) {
	a.value &= b.value;
	return a;
}
t_int64 operator&(long long a, t_int64 b) {
	b.value &= a;
	return b;
}
t_int64 operator&(t_int64 a, long long b) {
	a.value &= b;
	return a;
}
t_int64 operator|(t_int64 a, t_int64 b) {
	a.value |= b.value;
	return a;
}
t_int64 operator|(long long a, t_int64 b) {
	b.value = a | b.value;
	return b;
}
t_int64 operator|(t_int64 a, long long b) {
	a.value |= b;
	return a;
}
t_int64 operator+(t_int64 a, t_int64 b) {
	a.value += b.value;
	return a;
}
t_int64 operator+(long long a, t_int64 b) {
	b.value += a;
	return b;
}
t_int64 operator+(t_int64 a, long long b) {
	a.value += b;
	return a;
}
t_int64 operator-(t_int64 a, t_int64 b) {
	a.value -= b.value;
	return a;
}
t_int64 operator-(long long a, t_int64 b) {
	b.value = a - b.value;
	return b;
}
t_int64 operator-(t_int64 a, long long b) {
	a.value -= b;
	return a;
}
t_boolean operator>=(t_int64 a, t_int64 b) {
	return a.value >= b.value;
}
t_boolean operator>=(long long a, t_int64 b) {
	return a >= b.value;
}
t_boolean operator>=(t_int64 a, long long b) {
	return a.value >= b;
}
t_boolean operator<=(t_int64 a, t_int64 b) {
	return a.value <= b.value;
}
t_boolean operator<=(long long a, t_int64 b) {
	return a <= b.value;
}
t_boolean operator<=(t_int64 a, long long b) {
	return a.value <= b;
}
t_boolean operator>(t_int64 a, t_int64 b) {
	return a.value > b.value;
}
t_boolean operator>(long long a, t_int64 b) {
	return a > b.value;
}
t_boolean operator>(t_int64 a, long long b) {
	return a.value > b;
}
t_boolean operator<(t_int64 a, t_int64 b) {
	return a.value < b.value;
}
t_boolean operator<(long long a, t_int64 b) {
	return a < b.value;
}
t_boolean operator<(t_int64 a, long long b) {
	return a.value < b;
}

// operator override for t_uint64
t_uint64 operator&(t_uint64 a, t_uint64 b) {
	a.value &= b.value;
	return a;
}
t_uint64 operator&(unsigned long long a, t_uint64 b) {
	b.value &= a;
	return b;
}
t_uint64 operator&(t_uint64 a, unsigned long long b) {
	a.value &= b;
	return a;
}
t_uint64 operator|(t_uint64 a, t_uint64 b) {
	a.value |= b.value;
	return a;
}
t_uint64 operator|(unsigned long long a, t_uint64 b) {
	b.value = a | b.value;
	return b;
}
t_uint64 operator|(t_uint64 a, unsigned long long b) {
	a.value |= b;
	return a;
}
t_uint64 operator+(t_uint64 a, t_uint64 b) {
	a.value += b.value;
	return a;
}
t_uint64 operator+(unsigned long long a, t_uint64 b) {
	b.value += a;
	return b;
}
t_uint64 operator+(t_uint64 a, unsigned long long b) {
	a.value += b;
	return a;
}
t_uint64 operator-(t_uint64 a, t_uint64 b) {
	a.value -= b.value;
	return a;
}
t_uint64 operator-(unsigned long long a, t_uint64 b) {
	b.value = a - b.value;
	return b;
}
t_uint64 operator-(t_uint64 a, unsigned long long b) {
	a.value -= b;
	return a;
}
t_boolean operator>(t_uint64 a, t_uint64 b) {
	return a.value > b.value;
}
t_boolean operator>(unsigned long long a, t_uint64 b) {
	return a > b.value;
}
t_boolean operator>(t_uint64 a, unsigned long long b) {
	return a.value > b;
}
t_boolean operator<(t_uint64 a, t_uint64 b) {
	return a.value < b.value;
}
t_boolean operator<(unsigned long long a, t_uint64 b) {
	return a < b.value;
}
t_boolean operator<(t_uint64 a, unsigned long long b) {
	return a.value < b;
}
t_boolean operator>=(t_uint64 a, t_uint64 b) {
	return a.value >= b.value;
}
t_boolean operator>=(unsigned long long a, t_uint64 b) {
	return a >= b.value;
}
t_boolean operator>=(t_uint64 a, unsigned long long b) {
	return a.value >= b;
}
t_boolean operator<=(t_uint64 a, t_uint64 b) {
	return a.value <= b.value;
}
t_boolean operator<=(unsigned long long a, t_uint64 b) {
	return a <= b.value;
}
t_boolean operator<=(t_uint64 a, unsigned long long b) {
	return a.value <= b;
}

#endif // H_typeAlias
