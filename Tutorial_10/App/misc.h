#ifndef _MISC_H
#define _MISC_H

#include <cstring>
#include <string>
#include <vector>

#define DB_FILE_NAME			"persons.db"
#define TXT_FILE_NAME			"persons.txt"

enum EGender {G_UNKNOWN = 0, G_MALE, G_FEMALE};
enum EPerson {P_CUSTOMER = 0, P_EMPLOYEE};
enum ERole {R_WORKER, R_MANAGER, R_DIRECTOR };

class Person {
private:
	char *first_name;
	char *last_name;
	EGender gender;
protected:
	EPerson pType;
public:
	static const int USER_NAME_SZ = 256;
	static const int PERSON_ITEM_SZ = 512;

	Person() {
		first_name = new char[USER_NAME_SZ];
		last_name = new char[USER_NAME_SZ];

		memset(first_name, 0, USER_NAME_SZ);
		memset(last_name, 0, USER_NAME_SZ);
		gender = G_UNKNOWN;
	};

	inline char *getFirstName() { return first_name; };
	inline char *getLastName() { return last_name; };
	inline EGender getGender() { return gender; };
	EPerson getPersonType() { return pType; };

	inline void setFirstName(char *first_name) { strncpy(this->first_name, first_name, USER_NAME_SZ - 1); };
	inline void setLastName(char *last_name) { strncpy(this->last_name, last_name, USER_NAME_SZ - 1); };
	inline void setGender(EGender gender) { this->gender = gender; };

	virtual int showInfo() = 0;

	virtual ~Person() {
		delete[] first_name;
		delete[] last_name;
	};
};

class Customer : public Person {
private:
	int account;
	int phone;

public:
	Customer() : Person() {
		pType = P_CUSTOMER;

		account = -1;
		phone = -1;
	};

	int getAccount() { return this->account; };
	int getPhone() { return this->phone; };

	void setAccount(int _account) { account = _account; };
	void setPhone(int phone) { this->phone = phone; };

	virtual int showInfo();

	virtual ~Customer() {
	};
};

class Employee : public Person {
private:
	ERole role;
	unsigned salary;
	unsigned month_bonus;
protected:
public:
	Employee() : Person() {
		pType = P_EMPLOYEE;

	};

	virtual int showInfo();
	virtual EPerson getPersonType();

	void donate_bonus(const int donate_to, unsigned sum);

	virtual ~Employee() {
	};
};

bool db_exists(const char *fname);
int fs_size(const char *fname);

int db_save();
int db_load();
int db_save_txt();

extern std::vector<Person *> persons;

#endif
