
#include "misc.h"
#include <math.h>
#include "main.h"
#include <io.h>

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
		c.showInfo();
	} else {
		return -1;
	}

	return 0;
}

int db_upd_customer(const char* fname, const Customer& c, int index) {
	FILE* f;

	f = fopen(fname, "rb+");
	if (f) {
		fseek(f, index * sizeof(Customer), SEEK_SET);

		fwrite(&c, sizeof(c), 1, f);

		fclose(f);
	}
	else {
		return -3;
	}

	return 0;
}

int db_ins_customer(const char* fname, const Customer& c, int index) {
	FILE* f;
	Customer temp_1 = c;
	Customer temp_2;
	int size = fs_size(fname) / sizeof(Customer);

	f = fopen(fname, "rb+");
	if (f) {
		for (int i = 0; i <= (size - index); i++) { 

			fseek(f, (index + i) * sizeof(Customer), SEEK_SET);

			fread(&temp_2, sizeof(temp_2), 1, f);

			fseek(f, (index + i) * sizeof(Customer), SEEK_SET);

			fwrite(&temp_1, sizeof(temp_1), 1, f);

			temp_1 = temp_2;
		}
		fclose(f);
	}
	else {
		return -3;
	}

	return 0;
}

int db_convert_to_txt(const char* fname) {
	FILE* f;
	FILE* txt;
	Customer c;
	int size = fs_size(fname) / sizeof(Customer);
	
	f = fopen(fname, "rb");
	if (f) {
		txt = fopen(TXT_FILE_NAME, "w");
		for (int i = 0; i < size; i++) {
			fseek(f, i * sizeof(Customer), SEEK_SET);

			fread(&c, sizeof(c), 1, f);

			fprintf(txt, "First Name: %s\n", c.first_name);
			fprintf(txt, "Last Name: %s\n", c.last_name);
		
			switch (c.gender) {
			case G_MALE:
				fprintf(txt, "Gender: male\n");
				break;
			case G_FEMALE:
				fprintf(txt, "Gender: female\n");
				break;
			default:
				fprintf(txt, "Gender: unknown\n");
			}
			fprintf(txt, "Account: %d\n", c.account);
			fprintf(txt, "Phone: %d\n", c.phone);
			fprintf(txt, "\n");
		}
		fclose(f);
		fclose(txt);
	}
	else {
		return -1;
	}

	return 0;
}

int db_drop(const char* fname) {
	FILE* f;

	f = fopen(fname, "w");
	fclose(f);

	return 0;
}

int db_del_customer(const char* fname, int index) {
	FILE* f;
	Customer temp_1;
	int size = fs_size(fname) / sizeof(Customer);

	f = fopen(fname, "rb+");
	if (f) {
		for (int i = 0; i < (size - index - 1); i++) {

			fseek(f, (index + i + 1) * sizeof(Customer), SEEK_SET);

			fread(&temp_1, sizeof(temp_1), 1, f);

			fseek(f, (index + i) * sizeof(Customer), SEEK_SET);

			fwrite(&temp_1, sizeof(temp_1), 1, f);
		}
		_chsize(_fileno(f), fs_size(fname) - sizeof(Customer));
		fclose(f);
		
	}
	else {
		return -3;
	}

	return 0;
}

int db_upd_customer_spec(const char* fname, int index) {
	FILE* f;
	Customer c;
	char choice = 0;
	char user_gender[128] = { 0 };

	f = fopen(fname, "rb+");
	if (f) {
		fseek(f, index * sizeof(Customer), SEEK_SET);

		fread(&c, sizeof(c), 1, f);

		printf("Customer #%d update:\n", index);
		printf("\tUpdate First Name ? (y/n): ");
		scanf("\n%c", &choice);
		if (choice == 'y') {
			printf("\tNew First Name: ");
			scanf("%s", &c.first_name);
		}
		printf("\tUpdate Last Name ? (y/n): ");
		scanf("\n%c", &choice);
		if (choice == 'y') {
			printf("\tNew Last Name: ");
			scanf("%s", &c.last_name);
		}
		printf("\tUpdate Gender ? (y/n): ");
		scanf("\n%c", &choice);
		if (choice == 'y') {
			printf("\tNew Gender (male/female) : ");
			scanf("%s", &user_gender);
			if (!strcmp("male", user_gender)) {
				c.gender = G_MALE;
			}
			else if (!strcmp("female", user_gender)) {
				c.gender = G_FEMALE;
			}
			else {
				printf("Error: unknown gender\n");
				return -5;
			}
		}
		printf("\tUpdate Account ? (y/n): ");
		scanf("\n%c", &choice);
		if (choice == 'y') {
			printf("\tNew Account (10 digits): ");
			scanf("%d", &c.account);
		}
		printf("\tUpdate Phone ? (y/n): ");
		scanf("\n%c", &choice);
		if (choice == 'y') {
			printf("\tNew Phone: ");
			scanf("%d", &c.phone);
		}
		
		fseek(f, index * sizeof(Customer), SEEK_SET);
		fwrite(&c, sizeof(c), 1, f);

		fclose(f);
	}
	else {
		return -3;
	}
	return 0;
}

// ==================================================================================

int Customer::showInfo() {
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
}

int Customer::writeToDatabase(const char *fname, int index) {
}

int Customer::readFromDatabase(const char *fname, int index) {
}

// ==================================================================================

int Employee::showInfo() {
}

int Employee::writeToDatabase(const char *fname, int index) {
}

int Employee::readFromDatabase(const char *fname, int index) {
}
