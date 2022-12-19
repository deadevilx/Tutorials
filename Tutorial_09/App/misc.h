#ifndef _MISC_H
#define _MISC_H

#include <cstring>
#include <string>

enum EGender {G_UNKNOWN = 0, G_MALE, G_FEMALE};

struct db_header {
	unsigned last_accessed;

	db_header() {
		last_accessed = 0;
	}
};

struct Customer {
	char first_name[256];
	char last_name[256];
	EGender gender;
	int account;
	int phone;

	Customer() {
		memset(first_name, 0, sizeof(first_name));
		memset(last_name, 0, sizeof(last_name));
		gender = G_UNKNOWN;
		account = -1;
		phone = -1;
	}
};

bool db_exists(const char *fname);
int fs_size(const char *fname);
int db_add_customer(const char *fname, const Customer& c);
int db_print_customer(const char *fname, int index);
int db_upd_customer(const char* fname, const Customer& c, int index);
int db_ins_customer(const char* fname, const Customer& c, int index);
int db_convert_to_txt(const char* fname);
int db_drop(const char* fname);
int db_del_customer(const char* fname, int index);
int db_upd_customer_spec(const char* fname, int index);

#endif
