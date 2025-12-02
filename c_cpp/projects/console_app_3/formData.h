// form_data.h
#ifndef FORM_DATA_H
#define FORM_DATA_H
#ifdef __cplusplus
extern "C" {
#endif
#define MAX_NAME_LENGTH     50
#define MAX_EMAIL_LENGTH    100
#define MAX_PHONE_LENGTH    20
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int age;
    int is_valid; 
} FormData;
FormData form_data_create(void);
int form_data_validate(const FormData* data);
int form_data_input(FormData* data);

void form_data_clear(FormData* data);
int form_data_is_empty(const FormData* data);
void form_data_print(const FormData* data);
#ifdef __cplusplus
}
#endif
#endif