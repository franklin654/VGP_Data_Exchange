// Code generated by colf(1); DO NOT EDIT.
// The compiler used schema file demo.colf and GamePadReading.colf for package VGP_Data_Exchange.

#include "Colfer.h"
#include <errno.h>
#include <stdlib.h>

#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__) || \
    defined(__SYSC_ZARCH__)
#define COLFER_ENDIAN
#endif


size_t colfer_size_max = 16 * 1024 * 1024;
size_t colfer_list_max = 64 * 1024;



size_t vgp_data_exchange_gamepad_reading_marshal_len(const vgp_data_exchange_gamepad_reading* o) {
	size_t l = 1;

	{
		size_t n = o->buttons.len;
		if (n) {
			if (n > colfer_list_max) {
				errno = EFBIG;
				return 0;
			}
			vgp_data_exchange_gamepad_buttons* a = o->buttons.list;
			for (size_t i = 0; i < n; ++i) l += vgp_data_exchange_gamepad_buttons_marshal_len(&a[i]);
			for (l += 2; n > 127; n >>= 7, ++l);
			if (l > colfer_size_max) {
				errno = EFBIG;
				return 0;
			}
		}
	}

	if (o->left_trigger != 0.0f) l += 5;

	if (o->right_trigger != 0.0f) l += 5;

	if (o->left_thumbstick_x != 0.0f) l += 5;

	if (o->left_thumbstick_y != 0.0f) l += 5;

	if (o->right_thumbstick_x != 0.0f) l += 5;

	if (o->right_thumbstick_y != 0.0f) l += 5;

	if (l > colfer_size_max) {
		errno = EFBIG;
		return 0;
	}
	return l;
}

size_t vgp_data_exchange_gamepad_reading_marshal(const vgp_data_exchange_gamepad_reading* o, void* buf) {
	// octet pointer navigation
	uint8_t* p = buf;

	{
		size_t n = o->buttons.len;
		if (n) {
			*p++ = 0;

			uint_fast32_t x = n;
			for (; x >= 128; x >>= 7) *p++ = x | 128;
			*p++ = x;

			vgp_data_exchange_gamepad_buttons* a = o->buttons.list;
			for (size_t i = 0; i < n; ++i) p += vgp_data_exchange_gamepad_buttons_marshal(&a[i], p);
		}
	}

	if (o->left_trigger != 0.0f) {
		*p++ = 1;

#ifdef COLFER_ENDIAN
		memcpy(p, &o->left_trigger, 4);
		p += 4;
#else
		uint_fast32_t x;
		memcpy(&x, &o->left_trigger, 4);
		*p++ = x >> 24;
		*p++ = x >> 16;
		*p++ = x >> 8;
		*p++ = x;
#endif
	}

	if (o->right_trigger != 0.0f) {
		*p++ = 2;

#ifdef COLFER_ENDIAN
		memcpy(p, &o->right_trigger, 4);
		p += 4;
#else
		uint_fast32_t x;
		memcpy(&x, &o->right_trigger, 4);
		*p++ = x >> 24;
		*p++ = x >> 16;
		*p++ = x >> 8;
		*p++ = x;
#endif
	}

	if (o->left_thumbstick_x != 0.0f) {
		*p++ = 3;

#ifdef COLFER_ENDIAN
		memcpy(p, &o->left_thumbstick_x, 4);
		p += 4;
#else
		uint_fast32_t x;
		memcpy(&x, &o->left_thumbstick_x, 4);
		*p++ = x >> 24;
		*p++ = x >> 16;
		*p++ = x >> 8;
		*p++ = x;
#endif
	}

	if (o->left_thumbstick_y != 0.0f) {
		*p++ = 4;

#ifdef COLFER_ENDIAN
		memcpy(p, &o->left_thumbstick_y, 4);
		p += 4;
#else
		uint_fast32_t x;
		memcpy(&x, &o->left_thumbstick_y, 4);
		*p++ = x >> 24;
		*p++ = x >> 16;
		*p++ = x >> 8;
		*p++ = x;
#endif
	}

	if (o->right_thumbstick_x != 0.0f) {
		*p++ = 5;

#ifdef COLFER_ENDIAN
		memcpy(p, &o->right_thumbstick_x, 4);
		p += 4;
#else
		uint_fast32_t x;
		memcpy(&x, &o->right_thumbstick_x, 4);
		*p++ = x >> 24;
		*p++ = x >> 16;
		*p++ = x >> 8;
		*p++ = x;
#endif
	}

	if (o->right_thumbstick_y != 0.0f) {
		*p++ = 6;

#ifdef COLFER_ENDIAN
		memcpy(p, &o->right_thumbstick_y, 4);
		p += 4;
#else
		uint_fast32_t x;
		memcpy(&x, &o->right_thumbstick_y, 4);
		*p++ = x >> 24;
		*p++ = x >> 16;
		*p++ = x >> 8;
		*p++ = x;
#endif
	}

	*p++ = 127;

	return p - (uint8_t*) buf;
}

size_t vgp_data_exchange_gamepad_reading_unmarshal(vgp_data_exchange_gamepad_reading* o, const void* data, size_t datalen) {
	// octet pointer navigation
	const uint8_t* p = data;
	const uint8_t* end;
	int enderr;
	if (datalen < colfer_size_max) {
		end = p + datalen;
		enderr = EWOULDBLOCK;
	} else {
		end = p + colfer_size_max;
		enderr = EFBIG;
	}

	if (p >= end) {
		errno = enderr;
		return 0;
	}
	uint_fast8_t header = *p++;

	if (header == 0) {
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		size_t n = *p++;
		if (n > 127) {
			n &= 127;
			for (int shift = 7; ; shift += 7) {
				if (p >= end) {
					errno = enderr;
					return 0;
				}
				size_t c = *p++;
				if (c <= 127) {
					n |= c << shift;
					break;
				}
				n |= (c & 127) << shift;
			}
		}
		if (n > colfer_list_max) {
			errno = EFBIG;
			return 0;
		}

		vgp_data_exchange_gamepad_buttons* a = calloc(n, sizeof(vgp_data_exchange_gamepad_buttons));
		for (size_t i = 0; i < n; ++i) {
			size_t read = vgp_data_exchange_gamepad_buttons_unmarshal(&a[i], p, (size_t) (end - p));
			if (!read) {
				if (errno == EWOULDBLOCK) errno = enderr;
				return read;
			}
			p += read;
		}
		o->buttons.len = n;
		o->buttons.list = a;

		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 1) {
		if (p+4 >= end) {
			errno = enderr;
			return 0;
		}
#ifdef COLFER_ENDIAN
		memcpy(&o->left_trigger, p, 4);
		p += 4;
#else
		uint_fast32_t x = *p++;
		x <<= 24;
		x |= (uint_fast32_t) *p++ << 16;
		x |= (uint_fast32_t) *p++ << 8;
		x |= (uint_fast32_t) *p++;
		memcpy(&o->left_trigger, &x, 4);
#endif
		header = *p++;
	}

	if (header == 2) {
		if (p+4 >= end) {
			errno = enderr;
			return 0;
		}
#ifdef COLFER_ENDIAN
		memcpy(&o->right_trigger, p, 4);
		p += 4;
#else
		uint_fast32_t x = *p++;
		x <<= 24;
		x |= (uint_fast32_t) *p++ << 16;
		x |= (uint_fast32_t) *p++ << 8;
		x |= (uint_fast32_t) *p++;
		memcpy(&o->right_trigger, &x, 4);
#endif
		header = *p++;
	}

	if (header == 3) {
		if (p+4 >= end) {
			errno = enderr;
			return 0;
		}
#ifdef COLFER_ENDIAN
		memcpy(&o->left_thumbstick_x, p, 4);
		p += 4;
#else
		uint_fast32_t x = *p++;
		x <<= 24;
		x |= (uint_fast32_t) *p++ << 16;
		x |= (uint_fast32_t) *p++ << 8;
		x |= (uint_fast32_t) *p++;
		memcpy(&o->left_thumbstick_x, &x, 4);
#endif
		header = *p++;
	}

	if (header == 4) {
		if (p+4 >= end) {
			errno = enderr;
			return 0;
		}
#ifdef COLFER_ENDIAN
		memcpy(&o->left_thumbstick_y, p, 4);
		p += 4;
#else
		uint_fast32_t x = *p++;
		x <<= 24;
		x |= (uint_fast32_t) *p++ << 16;
		x |= (uint_fast32_t) *p++ << 8;
		x |= (uint_fast32_t) *p++;
		memcpy(&o->left_thumbstick_y, &x, 4);
#endif
		header = *p++;
	}

	if (header == 5) {
		if (p+4 >= end) {
			errno = enderr;
			return 0;
		}
#ifdef COLFER_ENDIAN
		memcpy(&o->right_thumbstick_x, p, 4);
		p += 4;
#else
		uint_fast32_t x = *p++;
		x <<= 24;
		x |= (uint_fast32_t) *p++ << 16;
		x |= (uint_fast32_t) *p++ << 8;
		x |= (uint_fast32_t) *p++;
		memcpy(&o->right_thumbstick_x, &x, 4);
#endif
		header = *p++;
	}

	if (header == 6) {
		if (p+4 >= end) {
			errno = enderr;
			return 0;
		}
#ifdef COLFER_ENDIAN
		memcpy(&o->right_thumbstick_y, p, 4);
		p += 4;
#else
		uint_fast32_t x = *p++;
		x <<= 24;
		x |= (uint_fast32_t) *p++ << 16;
		x |= (uint_fast32_t) *p++ << 8;
		x |= (uint_fast32_t) *p++;
		memcpy(&o->right_thumbstick_y, &x, 4);
#endif
		header = *p++;
	}

	if (header != 127) {
		errno = EILSEQ;
		return 0;
	}

	return (size_t) (p - (const uint8_t*) data);
}

size_t vgp_data_exchange_gamepad_buttons_marshal_len(const vgp_data_exchange_gamepad_buttons* o) {
	size_t l = 1;

	if (o->gamepad_buttons_menu) l++;

	if (o->gamepad_buttons_view) l++;

	if (o->gamepad_buttons_a) l++;

	if (o->gamepad_buttons_b) l++;

	if (o->gamepad_buttons_x) l++;

	if (o->gamepad_buttons_y) l++;

	if (o->gamepad_buttons_d_pad_up) l++;

	if (o->gamepad_buttons_d_pad_down) l++;

	if (o->gamepad_buttons_d_pad_left) l++;

	if (o->gamepad_buttons_d_pad_right) l++;

	if (o->gamepad_buttons_left_shoulder) l++;

	if (o->gamepad_buttons_right_shoulder) l++;

	if (o->gamepad_buttons_left_thumbstick) l++;

	if (o->gamepad_buttons_right_thumbstick) l++;

	if (l > colfer_size_max) {
		errno = EFBIG;
		return 0;
	}
	return l;
}

size_t vgp_data_exchange_gamepad_buttons_marshal(const vgp_data_exchange_gamepad_buttons* o, void* buf) {
	// octet pointer navigation
	uint8_t* p = buf;

	if (o->gamepad_buttons_menu) *p++ = 0;

	if (o->gamepad_buttons_view) *p++ = 1;

	if (o->gamepad_buttons_a) *p++ = 2;

	if (o->gamepad_buttons_b) *p++ = 3;

	if (o->gamepad_buttons_x) *p++ = 4;

	if (o->gamepad_buttons_y) *p++ = 5;

	if (o->gamepad_buttons_d_pad_up) *p++ = 6;

	if (o->gamepad_buttons_d_pad_down) *p++ = 7;

	if (o->gamepad_buttons_d_pad_left) *p++ = 8;

	if (o->gamepad_buttons_d_pad_right) *p++ = 9;

	if (o->gamepad_buttons_left_shoulder) *p++ = 10;

	if (o->gamepad_buttons_right_shoulder) *p++ = 11;

	if (o->gamepad_buttons_left_thumbstick) *p++ = 12;

	if (o->gamepad_buttons_right_thumbstick) *p++ = 13;

	*p++ = 127;

	return p - (uint8_t*) buf;
}

size_t vgp_data_exchange_gamepad_buttons_unmarshal(vgp_data_exchange_gamepad_buttons* o, const void* data, size_t datalen) {
	// octet pointer navigation
	const uint8_t* p = data;
	const uint8_t* end;
	int enderr;
	if (datalen < colfer_size_max) {
		end = p + datalen;
		enderr = EWOULDBLOCK;
	} else {
		end = p + colfer_size_max;
		enderr = EFBIG;
	}

	if (p >= end) {
		errno = enderr;
		return 0;
	}
	uint_fast8_t header = *p++;

	if (header == 0) {
		o->gamepad_buttons_menu = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 1) {
		o->gamepad_buttons_view = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 2) {
		o->gamepad_buttons_a = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 3) {
		o->gamepad_buttons_b = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 4) {
		o->gamepad_buttons_x = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 5) {
		o->gamepad_buttons_y = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 6) {
		o->gamepad_buttons_d_pad_up = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 7) {
		o->gamepad_buttons_d_pad_down = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 8) {
		o->gamepad_buttons_d_pad_left = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 9) {
		o->gamepad_buttons_d_pad_right = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 10) {
		o->gamepad_buttons_left_shoulder = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 11) {
		o->gamepad_buttons_right_shoulder = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 12) {
		o->gamepad_buttons_left_thumbstick = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header == 13) {
		o->gamepad_buttons_right_thumbstick = 1;
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		header = *p++;
	}

	if (header != 127) {
		errno = EILSEQ;
		return 0;
	}

	return (size_t) (p - (const uint8_t*) data);
}

size_t vgp_data_exchange_message_marshal_len(const vgp_data_exchange_message* o) {
	size_t l = 1;

	{
		size_t n = o->contents.len;
		if (n > colfer_size_max) {
			errno = EFBIG;
			return 0;
		}
		if (n) for (l += 2 + n; n > 127; n >>= 7, ++l);
	}

	if (l > colfer_size_max) {
		errno = EFBIG;
		return 0;
	}
	return l;
}

size_t vgp_data_exchange_message_marshal(const vgp_data_exchange_message* o, void* buf) {
	// octet pointer navigation
	uint8_t* p = buf;

	{
		size_t n = o->contents.len;
		if (n) {
			*p++ = 0;

			uint_fast32_t x = n;
			for (; x >= 128; x >>= 7) *p++ = x | 128;
			*p++ = x;

			memcpy(p, o->contents.utf8, n);
			p += n;
		}
	}

	*p++ = 127;

	return p - (uint8_t*) buf;
}

size_t vgp_data_exchange_message_unmarshal(vgp_data_exchange_message* o, const void* data, size_t datalen) {
	// octet pointer navigation
	const uint8_t* p = data;
	const uint8_t* end;
	int enderr;
	if (datalen < colfer_size_max) {
		end = p + datalen;
		enderr = EWOULDBLOCK;
	} else {
		end = p + colfer_size_max;
		enderr = EFBIG;
	}

	if (p >= end) {
		errno = enderr;
		return 0;
	}
	uint_fast8_t header = *p++;

	if (header == 0) {
		if (p >= end) {
			errno = enderr;
			return 0;
		}
		size_t n = *p++;
		if (n > 127) {
			n &= 127;
			for (int shift = 7; shift < sizeof(size_t) * CHAR_BIT; shift += 7) {
				if (p >= end) {
					errno = enderr;
					return 0;
				}
				size_t c = *p++;
				if (c <= 127) {
					n |= c << shift;
					break;
				}
				n |= (c & 127) << shift;
			}
		}
		if (n > colfer_size_max) {
			errno = EFBIG;
			return 0;
		}
		if (p+n >= end) {
			errno = enderr;
			return 0;
		}
		o->contents.len = n;

		void* a = malloc(n);
		o->contents.utf8 = (char*) a;
		if (n) {
			memcpy(a, p, n);
			p += n;
		}
		header = *p++;
	}

	if (header != 127) {
		errno = EILSEQ;
		return 0;
	}

	return (size_t) (p - (const uint8_t*) data);
}
