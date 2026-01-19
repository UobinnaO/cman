#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct SnekObject snek_object_t;

typedef struct coordinate
{
    int x;
    int y;
    int z;
} coordinate_t;

void coordinate_update_x(coordinate_t coord, int new_x);
// void coordinate_update_x(coordinate_t* coord, int new_x);
coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x);

unsigned long size_of_addr(long long i);

typedef struct CodeFile
{
    int lines;
    int filetype;
} codefile_t;

codefile_t change_filetype(codefile_t *f, int new_filetype);

void update_file(int filedata[200], int new_filetype, int new_num_lines);

typedef struct Graphics
{
    int fps;
    int height;
    int width;
} graphics_t;

void dump_graphics(graphics_t gsettings[10]);

void concat_strings(char *str1, const char *str2);
// int concat_strings(char *str1, const char *str2);

typedef struct
{
    size_t length;
    char buffer[64];
} TextBuffer;

int smart_append(TextBuffer *dest, const char *src);

typedef struct Employee employee_t;
typedef struct Department department_t;

typedef struct Employee
{
    int id;
    char *name;
    department_t *department;
} employee_t;

typedef struct Department
{
    char *name;
    employee_t *manager;
} department_t;

employee_t create_employee(int id, char *name);
department_t create_department(char *name);

void assign_employee(employee_t *emp, department_t *department);
void assign_manager(department_t *dept, employee_t *manager);

typedef enum SnekObjectKind
{
    INTEGER,
    FLOAT,
    BOOL,
    STRING,
    VECTOR3, // could be any collection type: Arrays, lists, dictionaries, and sets
    ARRAY
} snek_object_kind_t;

// typedef enum SnekObjectKind
// {
//     INTEGER,
//     STRING
// } snek_object_kind_t;

typedef struct SnekVector
{
    snek_object_t *x;
    snek_object_t *y;
    snek_object_t *z;
} snek_vector_t;

typedef struct
{
    size_t size;
    snek_object_t **elements;
} snek_array_t;

typedef union SnekObjectData
{
    int v_int;
    char *v_string;
    // float *v_float;
    float v_float;
    snek_vector_t v_vector3;
    snek_array_t v_array;
} snek_object_data_t;

typedef struct SnekObject
{
    bool is_marked;
    snek_object_kind_t kind;
    snek_object_data_t data;
    int refcount;
} snek_object_t;

snek_object_t new_integer(int);
snek_object_t new_string(char *str);
void format_object(snek_object_t obj, char *buffer);

typedef union SensorData
{
    long int temperature;
    long int humidity;
    long int pressure;
} sensor_data_t;

typedef union PacketPayload
{
    char text[256];            // 256 bytes
    unsigned char binary[256]; // 256 bytes
    struct ImageData
    {
        int width;                // 4 bytes
        int height;               // 4 bytes
        unsigned char data[1024]; // 1024 bytes
    } image;
} packet_payload_t;

typedef union Item
{
    struct
    {
        int damage;
        int range;
        int size;
    } weapon;
    struct
    {
        int healingAmount;
        int duration;
    } potion;
    struct
    {
        int doorID;
    } key;
} item_t;

typedef union PacketHeader
{
    struct
    {
        uint16_t src_port;
        uint16_t dest_port;
        uint32_t seq_num;
    } components;
    uint8_t raw[8];
} packet_header_t;

void printMessageOne();
void printMessageTwo();
void printMessageThree();
void printStackPointerDiff();

typedef struct
{
    int x;
    int y;
} coord_t;

char *get_full_greeting(char *greeting, char *name, int size);

int *allocate_scalar_array(int size, int multiplier);

void allocate_int(int **pointer_pointer, int value);

typedef struct Token
{
    char *literal;
    int line;
    int column;
} token_t;

token_t **create_token_pointer_array(token_t *tokens, size_t count);

typedef struct SnekInt
{
    char *name;
    int value;
} snek_int_t;

typedef struct SnekFloat
{
    char *name;
    float value;
} snek_float_t;

typedef struct SnekBool
{
    char *name;
    unsigned int value;
} snek_bool_t;

void snek_zero_out(void *ptr, snek_object_kind_t kind);

void swap_ints(int *a, int *b);

void swap_strings(char **a, char **b);

typedef struct CoffeeShop
{
    uint64_t quality;
    uint64_t taste;
    uint64_t branding;
} coffee_shop_t;

typedef struct Stack
{
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

typedef struct VirtualMachine
{
    stack_t *frames;
    stack_t *objects;
} vm_t;

void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);

void trace_blacken_object(stack_t *gray_objects, snek_object_t *ref);
void trace_mark_object(stack_t *gray_objects, snek_object_t *ref);

stack_t *stack_new(size_t capacity);
void stack_push(stack_t *stack, void *obj);
void *stack_pop(stack_t *stack);
void stack_free(stack_t *stack);
void stack_remove_nulls(stack_t *stack);

void scary_double_push(stack_t *s);
void stack_push_multiple_types(stack_t *s);

snek_object_t *new_snek_integer(vm_t *vm, int value);
snek_object_t *new_snek_float(vm_t *vm, float value);
snek_object_t *new_snek_string(vm_t *vm, char *value);

snek_object_t *new_snek_vector3(vm_t *vm, snek_object_t *x, snek_object_t *y, snek_object_t *z);

snek_object_t *new_snek_array(vm_t *vm, size_t value);

int snek_length(snek_object_t *obj);
snek_object_t *snek_add(snek_object_t *a, snek_object_t *b);

void refcount_inc(snek_object_t *obj);
void refcount_dec(snek_object_t *obj);
void refcount_free(snek_object_t *obj);

// typedef struct VirtualMachine
// {
//     stack_t *frames;
//     stack_t *objects;
// } vm_t;

vm_t *vm_new();
void vm_free(vm_t *vm);

typedef struct StackFrame
{
    stack_t *references;
} frame_t;

void vm_frame_push(vm_t *vm, frame_t *frame);
frame_t *vm_new_frame(vm_t *vm);

void frame_free(frame_t *frame);

void vm_collect_garbage(vm_t *vm);
void sweep(vm_t *vm);