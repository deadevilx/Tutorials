
#include "misc.h"
#include <math.h>
#include "main.h"
#include <io.h>

std::vector<Person *> persons;

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

int db_save() {
	FILE *f = fopen(DB_FILE_NAME, "wb");

	if (f) {
		for (int i = 0; i < persons.size(); i++) {
			fseek(f, Person::PERSON_ITEM_SZ * i, SEEK_SET);

			EPerson pType = persons[i]->getPersonType();

			if (pType == P_CUSTOMER) {
				fwrite(&pType, sizeof(pType), 1, f);
				char *pstr = persons[i]->getFirstName();
				fwrite(pstr, Person::USER_NAME_SZ, 1, f);
				pstr = persons[i]->getLastName();
				fwrite(pstr, Person::USER_NAME_SZ, 1, f);
				EGender g = persons[i]->getGender();
				fwrite(&g, sizeof(g), 1, f);
				int account = ((Customer *)persons[i])->getAccount();
				fwrite(&account, sizeof(account), 1, f);
				int phone = ((Customer *)persons[i])->getPhone();
				fwrite(&phone, sizeof(phone), 1, f);
			} else if (pType == P_EMPLOYEE) {
			}
		}

		fclose(f);
	}

	return 0;
}

int db_load() {
	for (int i = 0; i < persons.size(); i++) {
		delete persons[i];
	}

	persons.clear();

	// Load persons list

	return 0;
}

int db_save_txt() {
	return 0;
}

// ==================================================================================

int Customer::showInfo() {
		printf("Customer ->\n");
		printf("\tFirst Name: %s\n", this->getFirstName());
		printf("\tLast Name: %s\n", this->getLastName());
		switch (this->getGender()) {
		case G_MALE:
			printf("\tGender: male\n");
			break;
		case G_FEMALE:
			printf("\tGender: female\n");
			break;
		default:
			printf("\tGender: unknown\n");
		}
		printf("\tAccount: %d\n", this->getAccount());
		printf("\tPhone: %d\n", this->getPhone());

		printf("\n");

		return 0;
}

// ==================================================================================

int Employee::showInfo() {
	return 0;
}

EPerson Employee::getPersonType() {
	return P_EMPLOYEE;
}

void Employee::donate_bonus(const int donate_to, unsigned sum) {
}
