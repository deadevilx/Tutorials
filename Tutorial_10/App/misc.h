#ifndef _MISC_H
#define _MISC_H

#include <cstring>
#include <string>

enum EGender {G_UNKNOWN = 0, G_MALE, G_FEMALE};

class Person {
private:
	char *first_name;
	char *last_name;
	EGender gender;
protected:
	static int userNameSize = 256;
public:
	Person() {
		first_name = new char[userNameSize];
		last_name = new char[userNameSize];

		memset(first_name, 0, userNameSize);
		memset(last_name, 0, userNameSize);
		gender = G_UNKNOWN;
	}

	inline char *getFirstName() { return first_name; };
	inline char *getLastName() { return last_name; };
	inline EGender getGender() { return gender; };

	inline void setFirstName(char *first_name) { this->first_name = first_name; };
	inline void setLastName(char *last_name) { this->last_name = last_name; };
	inline void setGender(EGender gender) { this->gender = gender;}

	virtual int showInfo() = 0;
	virtual int writeToDatabase(const char *fname, int index) = 0;
	virtual int readFromDatabase(const char *fname, int index) = 0;

	virtual ~Person() {
		delete[] first_name;
		delete[] last_name;
	}
};

class Customer : public Person {
private:
	int account;
	int phone;

public:
	Customer() : Person() {
		account = -1;
		phone = -1;
	}

	virtual int showInfo();
	virtual int writeToDatabase(const char *fname, int index);
	virtual int readFromDatabase(const char *fname, int index);

	virtual ~Customer() {
	}
};

class Employee : public Person {
private:
protected:
public:
	Employee() : Person() {
	}

	virtual int showInfo();
	virtual int writeToDatabase(const char *fname, int index);
	virtual int readFromDatabase(const char *fname, int index);

	virtual ~Employee() {
	}
};

class Stuff {
private:
protected:
public:
	Stuff() {
	};

	virtual ~Stuff() {
	};
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
