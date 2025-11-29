# console_app_3 — Simple Employee DB (C)

A small console application that manages employee records in memory using an array of structs. Provides a menu-driven interface to create, list, search, update, delete employees and optionally save/load to a file.

## Features
- Add new employee records (name, id, email, phone, age, etc.)
- List all employees
- Search employee by ID (or name)
- Update and delete employee records
- Optional simple persistence: save/load records to/from a file
- Menu-driven console UI with basic input helpers

## Data model
- Each record is stored in a struct, for example:
  - int id
  - char name[...]
  - char email[...]
  - char phone[...]
  - int age
- Records are stored in a fixed-size array (MAX_EMPLOYEES) in memory.

## Core functions (expected / recommended)
- add_employee(struct Employee arr[], int &count, const Employee *e)
- list_employees(const Employee arr[], int count)
- find_employee_by_id(const Employee arr[], int count, int id) -> index or -1
- update_employee(Employee arr[], int index, const Employee *newData)
- delete_employee(Employee arr[], int *count, int index)
- save_employees(const Employee arr[], int count, const char *filename)
- load_employees(Employee arr[], int *count, const char *filename)
- simple input helpers: read_string(), read_int(), confirm()


