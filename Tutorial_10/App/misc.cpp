
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
	char zer[1000];
	memset(zer, 0, 1000);

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
				int cust_size = 2 * Person::USER_NAME_SZ + sizeof(g) + sizeof(account) + sizeof(phone);
				fwrite(zer,Person::PERSON_ITEM_SZ - cust_size, 1, f);
			} else if (pType == P_EMPLOYEE) {
				fwrite(&pType, sizeof(pType), 1, f);
				char* pstr = persons[i]->getFirstName();
				fwrite(pstr, Person::USER_NAME_SZ, 1, f);
				pstr = persons[i]->getLastName();
				fwrite(pstr, Person::USER_NAME_SZ, 1, f);
				EGender g = persons[i]->getGender();
				fwrite(&g, sizeof(g), 1, f);
				ERole r = ((Employee*)persons[i])->getRole();
				fwrite(&r, sizeof(r), 1, f);
				unsigned salary = ((Employee*)persons[i])->getSalary();
				fwrite(&salary, sizeof(salary), 1, f);
				unsigned month_bonus = ((Employee*)persons[i])->getMonth_bonus();
				fwrite(&month_bonus, sizeof(month_bonus), 1, f);
				int emp_size = 2 * Person::USER_NAME_SZ + sizeof(g) + sizeof(ERole) + sizeof(salary) + sizeof(month_bonus);
				fwrite(zer, Person::PERSON_ITEM_SZ - emp_size, 1, f);
			}
		}

		fclose(f);
	}

	return 0;
}

int db_load(const char *fname) {
	for (int i = 0; i < persons.size(); i++) {
		delete persons[i];
	}

	persons.clear();

	// Load persons list
	int size = fs_size(fname) / Person::PERSON_ITEM_SZ;
	int account, phone;
	char first_name[Person::USER_NAME_SZ];
	char last_name[Person::USER_NAME_SZ];
	EPerson pType;
	EGender g;
	ERole r;
	unsigned salary, month_bonus;
	FILE* f = fopen(DB_FILE_NAME, "rb");

	if (f) {
		for (int i = 0; i < size; i++) {
			fseek(f, Person::PERSON_ITEM_SZ * i, SEEK_SET);
			fread(&pType, sizeof(pType), 1, f);

			if (pType == P_CUSTOMER) {
				Person* p = new Customer;
				
				fread(&first_name, Person::USER_NAME_SZ, 1, f);
				p->setFirstName(first_name);
				fread(&last_name, Person::USER_NAME_SZ, 1, f);
				p->setLastName(last_name);
				fread(&g, sizeof(EGender), 1, f);
				p->setGender(g);
				fread(&account, sizeof(account), 1, f);
				((Customer*)p)->setAccount(account);
				fread(&phone, sizeof(phone), 1, f);
				((Customer*)p)->setPhone(phone);

				persons.push_back(p);
			}
			else if (pType == P_EMPLOYEE) {
				Person* p = new Employee;

				fread(&first_name, Person::USER_NAME_SZ, 1, f);
				p->setFirstName(first_name);
				fread(&last_name, Person::USER_NAME_SZ, 1, f);
				p->setLastName(last_name);
				fread(&g, sizeof(EGender), 1, f);
				p->setGender(g);
				fread(&r, sizeof(ERole), 1, f);
				((Employee*)p)->setRole(r);
				fread(&salary, sizeof(salary), 1, f);
				((Employee*)p)->setSalary(salary);
				fread(&month_bonus, sizeof(month_bonus), 1, f);
				((Employee*)p)->setMonth_bonus(month_bonus);

				persons.push_back(p);
			}
		}

		fclose(f);
	}

	return 0;
}

int db_save_txt() {
	FILE* f = fopen(TXT_FILE_NAME, "w");

	for (int i = 0; i < persons.size(); i++) {

		EPerson pType = persons[i]->getPersonType();

		if (pType == P_CUSTOMER) {
			fprintf(f, "Customer: \n");
			char* pstr = persons[i]->getFirstName();
			fprintf(f, "First name: %s \n", pstr);
			pstr = persons[i]->getLastName();
			fprintf(f, "Last name: %s \n", pstr);
			EGender g = persons[i]->getGender();
			switch (g) {
			case G_MALE:
				fprintf(f, "Gender: male\n");
				break;
			case G_FEMALE:
				fprintf(f, "Gender: female\n");
				break;
			default:
				fprintf(f, "Gender: unknown\n");
			}
			int account = ((Customer*)persons[i])->getAccount();
			fprintf(f, "Account: %d \n", account);
			int phone = ((Customer*)persons[i])->getPhone();
			fprintf(f, "Phone: %d \n", phone);
			fprintf(f, "\n");
		}
		else if (pType == P_EMPLOYEE) {
			fprintf(f, "Employee: \n");
			char* pstr = persons[i]->getFirstName();
			fprintf(f, "First name: %s \n", pstr);
			pstr = persons[i]->getLastName();
			fprintf(f, "Last name: %s \n", pstr);
			EGender g = persons[i]->getGender();
			switch (g) {
			case G_MALE:
				fprintf(f, "Gender: male\n");
				break;
			case G_FEMALE:
				fprintf(f, "Gender: female\n");
				break;
			default:
				fprintf(f, "Gender: unknown\n");
			}
			ERole r = ((Employee*)persons[i])->getRole();
			switch (r) {
			case R_WORKER:
				fprintf(f, "Role: worker\n");
				break;
			case R_MANAGER:
				fprintf(f, "Role: manager\n");
				break;
			case R_DIRECTOR:
				fprintf(f, "Role: director\n");
				break;
			default:
				fprintf(f, "Role: unknown\n");
			}
			unsigned salary = ((Employee*)persons[i])->getSalary();
			fprintf(f, "Salary: %d \n", salary);
			unsigned month_bonus = ((Employee*)persons[i])->getMonth_bonus();
			fprintf(f, "Month bonus: %d \n", month_bonus);
			fprintf(f, "\n");
		}
	}
	fclose(f);
	
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
	printf("Employee ->\n");
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

	switch (this->getRole()) {
	case R_WORKER:
		printf("\tRole: worker\n");
		break;
	case R_MANAGER:
		printf("\tRole: manager\n");
		break;
	case R_DIRECTOR:
		printf("\tRole: director\n");
		break;
	default:
		printf("\tRole: unknown\n");
	}

	printf("\tSalary: %d $\n", this->getSalary());
	printf("\tMonth bonus: %d $\n", getMonth_bonus());
	printf("\n");
	return 0;
}

EPerson Employee::getPersonType() {
	return P_EMPLOYEE;
}

void Employee::donate_bonus(const int donate_to, unsigned sum) {
}

Person* add_person() {
	int ibuf = 0;
	char strbuf_abc[128] = { 0 };
	printf("Person type (%d - Customer, %d - Employee): ", P_CUSTOMER, P_EMPLOYEE);
	scanf("%d", &ibuf);

	if (ibuf == P_CUSTOMER) {
		Person* p = new Customer();

		printf("\tFirst Name: ");
		scanf("%s", strbuf_abc);
		p->setFirstName(strbuf_abc);

		printf("\tLast Name: ");
		scanf("%s", strbuf_abc);
		p->setLastName(strbuf_abc);

		bool a = true;
		while (a) {
			printf("\tGender (male/female): ");
			scanf("%s", strbuf_abc);
			if (!strcmp("male", strbuf_abc)) {
				p->setGender(G_MALE);
				a = false;
			}
			else if (!strcmp("female", strbuf_abc)) {
				p->setGender(G_FEMALE);
				a = false;
			}
			else {
				printf("Error: unknown gender\n");
			}
		}
		printf("\tAccount (10 digits): ");
		scanf("%d", &ibuf);
		((Customer*)p)->setAccount(ibuf);

		printf("\tPhone: ");
		scanf("%d", &ibuf);
		((Customer*)p)->setPhone(ibuf);

		return p;
	}
	else if (ibuf == P_EMPLOYEE) {
		Person* p = new Employee();

		printf("\tFirst Name: ");
		scanf("%s", strbuf_abc);
		p->setFirstName(strbuf_abc);

		printf("\tLast Name: ");
		scanf("%s", strbuf_abc);
		p->setLastName(strbuf_abc);

		bool a = true;
		while (a) {
			printf("\tGender (male/female): ");
			scanf("%s", strbuf_abc);
			if (!strcmp("male", strbuf_abc)) {
				p->setGender(G_MALE);
				a = false;
			}
			else if (!strcmp("female", strbuf_abc)) {
				p->setGender(G_FEMALE);
				a = false;
			}
			else {
				printf("Error: unknown gender\n");
				continue;
			}
		}

		bool b = true;
		while (b) {
			printf("\tRole (worker/manager/director): ");
			scanf("%s", strbuf_abc);
			if (!strcmp("worker", strbuf_abc)) {
				((Employee*)p)->setRole(R_WORKER);
				b = false;
			}
			else if (!strcmp("manager", strbuf_abc)) {
				((Employee*)p)->setRole(R_MANAGER);
				b = false;
			}
			else if (!strcmp("director", strbuf_abc)) {
				((Employee*)p)->setRole(R_DIRECTOR);
				b = false;
			}
			else {
				printf("Error: unknown role\n");
			}
		}
		printf("\tSalary $: ");
		scanf("%d", &ibuf);
		((Employee*)p)->setSalary(ibuf);

		printf("\tMonth bonus $: ");
		scanf("%d", &ibuf);
		((Employee*)p)->setMonth_bonus(ibuf);

		return p;
	}
}