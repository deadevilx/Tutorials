
#include "misc.h"
#include <math.h>

bool fs_exists(const char *fname) {
	bool exists = true;

	FILE *f = fopen(fname, "rb+");
	if (f) {
		fclose(f);
	} else {
		exists = false;
	}

	return exists;
}

int fs_size(const char *fname) {
	int size = 0;

	if (fs_exists(fname)) {
		FILE *f = fopen(fname, "rb");
		if (f) {
			fseek(f, 0, SEEK_END);
			size = ftell(f);
			fclose(f);
		}
	}

	return size;
}

int db_add_customer(const char *fname, const Customer& c) {
	FILE *f;

	// create empty file if not exists
	if (!fs_exists(fname)) {
		f = fopen(fname, "w");
		if (f) {
			fclose(f);
		} else {
			return -1;
		}
	}

	// add customer to database file
	int size = fs_size(fname);
	// if file size not aligned
	size = size / sizeof(Customer);

	f = fopen(fname, "rb+");
	if (f) {
		fseek(f, size * sizeof(Customer), SEEK_SET);

		fwrite(&c, sizeof(c), 1, f);

		fclose(f);
	} else {
		return -2;
	}

	return 0;
}

int db_print_customer(const char *fname, int index) {
	FILE *f;
	Customer c;

	f = fopen(fname, "rb");
	if (f) {
		fseek(f, index * sizeof(Customer), SEEK_SET);

		fread(&c, sizeof(c), 1, f);

		fclose(f);

		printf("Customer #%d info:\n", index);
		printf("\tFirst Name: %s\n", c.first_name);
		printf("\tLast Name: %s\n", c.last_name);
		switch (c.gender) {
		case G_MALE:
			printf("\tGender: male\n");
			break;
		case G_FEMALE:
			printf("\tGender: female\n");
			break;
		default:
			printf("\tGender: unknown\n");
		}
		printf("\tAccount: %d\n", c.account);
		printf("\tPhone: %d\n", c.phone);

		printf("\n");
	} else {
		return -1;
	}

	return 0;
}
