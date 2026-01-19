#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

int max_sneklang_memory(int max_threads, int memory_per_thread)
{
    int result = max_threads * memory_per_thread;
    return result;
}

float get_average(int x, int y, int z)
{
    int sum = x + y + z;
    float avg = sum / 3.0;
    return avg;
};

void coordinate_update_x(coordinate_t coord, int new_x)
{
    coord.x = new_x;
}

coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x)
{
    coord.x = new_x;
    return coord;
}

unsigned long size_of_addr(long long i)
{
    unsigned long sizeof_snek_version = sizeof(&i);
    return sizeof_snek_version;
}

codefile_t change_filetype(codefile_t *f, int new_filetype)
{
    codefile_t new_f = *f;
    printf("Address of new_f: %p\n", &new_f);
    new_f.filetype = new_filetype;
    f->lines = 200;
    return new_f;
}

void update_file(int filedata[200], int new_filetype, int new_num_lines)
{
    filedata[1] = new_num_lines;
    filedata[2] = new_filetype;
    filedata[199] = 0;
}

void dump_graphics(graphics_t gsettings[10])
{
    int *ptr = (int *)gsettings;
    for (int i = 0; i < 30; i++)
    {
        printf("settings[%d] = %d\n", i, ptr[i]);
    }
}

void concat_strings(char *str1, const char *str2)
{
    char *end = str1;
    while (*end != '\0')
    {
        end++;
    }

    while (*str2 != '\0')
    {
        *end = *str2;
        end++;
        str2++;
    }

    *end = '\0';
}

void strncat_example()
{
    char str1[50] = "Hello";
    char str2[] = " World";

    strncat(str1, str2, 2);
    printf("Result: %s\n", str1);
}

int smart_append(TextBuffer *dest, const char *src)
{
    if (!dest || !src)
        return 1;
    const int max_buffer_size = 64;
    size_t src_len = strlen(src);
    size_t available_space = max_buffer_size - dest->length - 1;
    printf("avalb space: %lu\n", available_space);

    if (src_len > available_space)
    {
        strncat(dest->buffer, src, available_space);
        dest->length = max_buffer_size - 1;
        return 1;
    }
    strcat(dest->buffer, src);
    dest->length += src_len;
    return 0;
}

int ssmart_append(TextBuffer *dest, const char *src)
{
    if (!dest || !src)
    {
        return 1;
    }
    const int max_bf_cap = 64;
    size_t src_len = strlen(src);
    size_t dbf_cap = max_bf_cap - ((dest->length) + 1);
    printf("dbf cap: %lu\n", dbf_cap);

    if (src_len > dbf_cap)
    {
        strncat(dest->buffer, src, dbf_cap);
        dest->length = max_bf_cap - 1;
        return 1;
    }
    strncat(dest->buffer, src, dbf_cap);
    dest->length += src_len;
    return 0;
}

employee_t create_employee(int id, char *name)
{
    employee_t emp = {
        .id = id,
        .name = name,
        .department = NULL};
    return emp;
}

department_t create_department(char *name)
{
    department_t dept = {
        .name = name,
        .manager = NULL};
    return dept;
}

void assign_employee(employee_t *emp, department_t *department)
{
    emp->department = department;
}

void assign_manager(department_t *dept, employee_t *manager)
{
    dept->manager = manager;
}

void format_object(snek_object_t obj, char *buffer)
{

    switch (obj.kind)
    {
    case INTEGER:
        sprintf(buffer, "There are %d lights!", obj.data.v_int);
        break;
    case STRING:
        sprintf(buffer, "There are %s lights!", obj.data.v_string);
        break;
    default:
        sprintf(buffer, "Unknown object kind");
        break;
    }
}

snek_object_t new_integer(int i)
{
    return (snek_object_t){
        .kind = INTEGER,
        .data = {.v_int = i}};
}

snek_object_t new_string(char *str)
{
    // NOTE: We will learn how to copy this data later.
    return (snek_object_t){
        .kind = STRING,
        .data = {.v_string = str}};
}

void printMessageOne()
{
    const char *message = "Dark mode?\n";
    printStackPointerDiff();
    printf("%s\n", message);
}

void printMessageTwo()
{
    const char *message = "More like...\n";
    printStackPointerDiff();
    printf("%s\n", message);
}

void printMessageThree()
{
    const char *message = "dark roast.\n";
    printStackPointerDiff();
    printf("%s\n", message);
}

// don't touch below this line

void printStackPointerDiff()
{
    static void *last_sp = NULL;
    void *current_sp;
    current_sp = __builtin_frame_address(0);
    long diff = (char *)last_sp - (char *)current_sp;
    if (last_sp == NULL)
    {
        last_sp = current_sp;
        diff = 0;
    }
    printf("---------------------------------\n");
    printf("Stack pointer offset: %ld bytes\n", diff);
    printf("---------------------------------\n");
}

coord_t new_coord(int x, int y)
// coord_t *new_coord(int x, int y)
{
    coord_t c;
    c.x = x;
    c.y = y;
    // return &c;
    return c;
}

// int *new_int_array(int size)
// {
//     int *new_arr = (int *)malloc(size * sizeof(int)); // Allocate memory
//     if (new_arr == NULL)
//     {
//         fprintf(stderr, "Memory allocation failed\n");
//         exit(1); // Exit if allocation fails
//     }
//     return new_arr;
// }

// Helper function to check if a pointer is on the stack
bool is_on_stack(void *ptr)
{
    void *stack_top = __builtin_frame_address(0);
    uintptr_t stack_top_addr = (uintptr_t)stack_top;
    uintptr_t ptr_addr = (uintptr_t)ptr;

    // Check within a threshold in both directions (e.g., 1MB)
    uintptr_t threshold = 1024;

    return ptr_addr >= (stack_top_addr - threshold) && ptr_addr <= (stack_top_addr + threshold);
}

char *get_full_greeting(char *greeting, char *name, int size)
{
    // char full_greeting[100];
    char *full_greeting = (char *)malloc(size * sizeof(char)); // Allocate memory
    if (full_greeting == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit if allocation fails
    }
    snprintf(full_greeting, size, "%s %s", greeting, name);
    return full_greeting;
}

int *allocate_scalar_array(int size, int multiplier)
{
    // allocate size ints on the heap
    int *arr = malloc(size * sizeof *arr);
    if (arr == NULL)
    {
        // gracefully signal failure
        return NULL;
    }

    // arr[i] = i * multiplier
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * multiplier;
    }

    return arr; // caller owns this memory; must free(arr)
}

void allocate_int(int **pointer_pointer, int value)
{
    // Allocating memory and updating the original pointer
    int *pointer = (int *)malloc(sizeof(int));
    *pointer_pointer = pointer; // Update the pointer that pointer_pointer is pointing to
    if (*pointer_pointer == NULL)
    {
        return;
    }
    // Assigning a value to the allocated memory
    **pointer_pointer = value; // Set the raw value to a ptr
}

token_t **create_token_pointer_array(token_t *tokens, size_t count)
{
    token_t **token_pointers = malloc(count * sizeof(token_t *));
    if (token_pointers == NULL)
    {
        exit(1);
    }
    for (size_t i = 0; i < count; ++i)
    // for (size_t i = 0; i < count; ++i)
    {
        token_t *space_for_new_token = malloc(sizeof(token_t)); // allocate new space for each token on the heap.
        // token_pointers[i] = &tokens[i];
        token_pointers[i] = space_for_new_token; // Store the address of the new space in the array instead of the stack address.
        *space_for_new_token = tokens[i];        // Copy the members of the input struct into the newly allocated one.
        // token_pointers[i]->literal = tokens[i].literal;
        // token_pointers[i]->line = tokens[i].line;
        // token_pointers[i]->column = tokens[i].column;
    }
    // for (size_t i = 0; i < count; ++i)
    // {
    //     printf("token_pointers[%zu] = %p\n", i, (void *)token_pointers[i]);
    // }
    return token_pointers;
}

void snek_zero_out(void *ptr, snek_object_kind_t kind)
{
    switch (kind)
    {
    case INTEGER:
        ((snek_int_t *)ptr)->value = 0;
        // printf("Integer: %d\n", ((snek_int_t *)ptr)->value);
        break;

    case FLOAT:
        ((snek_float_t *)ptr)->value = 0;
        // printf("Float: %f\n", ((snek_float_t *)ptr)->value);
        break;

    case BOOL:
        ((snek_bool_t *)ptr)->value = 0;
        // printf("Bool: %d\n", ((snek_bool_t *)ptr)->value);
        break;

    default:
        printf("Unknown kind!\n");
        break;
    }
}

void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

    printf("%d", tmp);
}
void swap_strings(char **a, char **b)
{
    // printf("%c\n", *a[0]);
    // printf("%c\n", *b[0]);
    // printf("%s\n", *a);
    // printf("%s\n", *b);
    char *tmp = *a;
    // printf("%s\n", tmp);
    *a = *b;
    // printf("%s\n", *b);
    *b = tmp;
    // printf("%s\n", *a);
}

void swap(void *vp1, void *vp2, size_t size)
{
    unsigned char *temp_buffer = malloc(size); // allocate 4 bytes
    // unsigned char **tb = malloc(size); // allocate 4 bytes
    if (temp_buffer == NULL)
    {
        return;
    }
    // printf("%d\n", *(int *)vp1);
    // printf("%d\n", *tb);

    // int temp = *(int *)vp1;
    // printf("%d\n", temp);
    // printf("%d\n", *(int *)vp1);
    // printf("%d\n", *(int *)vp2);
    memcpy(temp_buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, temp_buffer, size);
    // printf("----------------\n");
    // printf("%d\n", *(int *)vp1);
    // printf("%d\n", *(int *)vp2);

    free(temp_buffer);
}

stack_t *stack_new(size_t capacity)
{
    stack_t *stack = malloc(sizeof(stack_t));
    // printf("%zu\n", sizeof(stack_t));
    // printf("%zu\n", sizeof(*stack));
    if (stack == NULL)
    {
        return NULL;
    }
    stack->count = 0;
    stack->capacity = capacity;
    stack->data = malloc(stack->capacity * sizeof(void *));
    // stack->data = malloc(stack->capacity * sizeof *stack->data);
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }

    // stack->data
    // printf("%zu\n", stack->count);

    // return stack;
    return stack;
}

void stack_push(stack_t *stack, void *obj)
{
    if (stack->count == stack->capacity)
    {
        stack->capacity *= 2;
        void **temp = realloc(stack->data, stack->capacity * sizeof(void *));
        // if (temp == NULL)
        // {
        //     stack->capacity /= 2;
        //     return;
        // }
        // stack->data = temp;
        if (temp == NULL)
        {
            // this if: for mark and sweep GC
            exit(1);
        }
    }
    stack->data[stack->count] = obj;
    stack->count++;
    return;
}

void *stack_pop(stack_t *stack)
{
    if (stack->count == 0)
    {
        return NULL;
    }
    stack->count--;
    return stack->data[stack->count];
}

void stack_free(stack_t *stack)
{
    if (stack == NULL)
    {
        return;
    }
    else if (stack->data != NULL)
    {
        free(stack->data);
    }
    free(stack);
}

void stack_remove_nulls(stack_t *stack)
{
    size_t new_count = 0;

    // Iterate through the stack and compact non-NULL pointers.
    for (size_t i = 0; i < stack->count; ++i)
    {
        if (stack->data[i] != NULL)
        {
            stack->data[new_count++] = stack->data[i];
        }
    }

    // Update the count to reflect the new number of elements.
    stack->count = new_count;

    // Optionally, you might want to zero out the remaining slots.
    for (size_t i = new_count; i < stack->capacity; ++i)
    {
        stack->data[i] = NULL;
    }
}

// ! WRONG
void scary_double_push(stack_t *s)
{
    // int value = 1337;
    // stack_push(s, (void *)value);
    int *ptr = malloc(sizeof(int));
    *ptr = 1024;
    // *ptr = value2;
    stack_push(s, ptr);
}

// for (int j = 0; sneklang_text[j] != '\0'; j++)
// {
//     printf("%c\n", sneklang_text[j]);
// }
// while (*sneklang_text != '\0')
// {                                           // while not end of string
//     printf("char: '%c'\n", *sneklang_text); // look at the char p points to
//     sneklang_text++;                        // move to next char
// }

void stack_push_multiple_types(stack_t *s)
{
    float *ptr = malloc(sizeof(float));
    *ptr = 3.14;
    // stack_push(s, *ptr);
    stack_push(s, ptr);
    // stack_push(s, &ptr);
    const char *sneklang_text = "Sneklang is blazingly slow!";
    int str_len = strlen(sneklang_text) + 1;
    char *char_mem = (char *)malloc(str_len * sizeof(char));
    memcpy(char_mem, sneklang_text, str_len);
    stack_push(s, char_mem);
}

void vm_track_object(vm_t *vm, snek_object_t *obj)
{
    stack_push(vm->objects, obj);
}

snek_object_t *_new_snek_object(vm_t *vm)
{
    snek_object_t *obj = calloc(1, sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->is_marked = false;
    vm_track_object(vm, obj);
    // obj->refcount = 1; //refcount GC
    return obj;
}

snek_object_t *new_snek_integer(vm_t *vm, int value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = INTEGER;
    obj->data.v_int = value;
    return obj;
}

snek_object_t *new_snek_float(vm_t *vm, float value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_string(vm_t *vm, char *value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    size_t len = strlen(value) + 1;
    char *char_plus_null_terminator = malloc(sizeof(char) * len);
    if (obj == NULL)
    {
        free(obj);
        return NULL;
    }
    // memcpy(char_plus_null_terminator, value, len);
    strcpy(char_plus_null_terminator, value);
    obj->kind = STRING;
    obj->data.v_string = char_plus_null_terminator;
    return obj;
}

snek_object_t *new_snek_vector3(vm_t *vm,
                                snek_object_t *x, snek_object_t *y, snek_object_t *z)
{
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};
    refcount_inc(x);
    refcount_inc(y);
    refcount_inc(z);
    return obj;
}

snek_object_t *new_snek_array(vm_t *vm, size_t size)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }
    snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
    if (elements == NULL)
    {
        free(obj);
        return NULL;
    }
    obj->kind = ARRAY;
    // snek_array_t arr = {size, elements};
    obj->data.v_array = (snek_array_t){.size = size, .elements = elements};
    // obj->data.v_array = arr;
    return obj;
}

snek_object_t *snek_array_get(snek_object_t *snek_obj, size_t index)
{
    if (snek_obj == NULL)
    {
        return false;
    }
    if (snek_obj->kind != ARRAY)
    {
        return false;
    }
    if (index >= snek_obj->data.v_array.size)
    {
        return false;
    }
    return snek_obj->data.v_array.elements[index];
}

bool snek_array_set(snek_object_t *snek_obj, size_t index, snek_object_t *value)
{
    if (snek_obj == NULL || value == NULL)
    {
        return false;
    }
    if (snek_obj->kind != ARRAY)
    {
        return false;
    }
    if (index >= snek_obj->data.v_array.size)
    {
        return false;
    }
    refcount_inc(value);
    if (snek_obj->data.v_array.elements[index] != NULL)
    {
        refcount_dec(snek_obj->data.v_array.elements[index]);
    }

    snek_obj->data.v_array.elements[index] = value;
    return true;
}

int snek_length(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return -1;
    }

    switch (obj->kind)
    {
    case INTEGER:
        return 1;
    case FLOAT:
        return 1;
    case STRING:
        return strlen(obj->data.v_string);
    case VECTOR3:
        return 3;
    case ARRAY:
        return obj->data.v_array.size;
    default:
        return -1;
    }
}

// snek_object_t *snek_add(snek_object_t *a, snek_object_t *b)
// {
//     if (a == NULL || b == NULL)
//     {
//         return NULL;
//     }

//     switch (a->kind)
//     {
//     case INTEGER:
//         switch (b->kind)
//         {
//         case INTEGER:
//             return new_snek_integer(a->data.v_int + b->data.v_int);
//         case FLOAT:
//             return new_snek_float((float)a->data.v_int + b->data.v_float);
//         default:
//             return NULL;
//         }
//     case FLOAT:
//         switch (b->kind)
//         {
//         case FLOAT:
//             return new_snek_float(a->data.v_float + b->data.v_float);
//         default:
//             return snek_add(b, a);
//         }
//     case STRING:
//         switch (b->kind)
//         {
//         case STRING:
//         {
//             int a_len = strlen(a->data.v_string);
//             int b_len = strlen(b->data.v_string);
//             int len = a_len + b_len + 1;
//             char *dst = calloc(len, sizeof(char));

//             strcat(dst, a->data.v_string);
//             strcat(dst, b->data.v_string);

//             snek_object_t *obj = new_snek_string(dst);
//             free(dst);

//             return obj;
//         }
//         default:
//             return NULL;
//         }
//     case VECTOR3:
//         switch (b->kind)
//         {
//         case VECTOR3:
//             return new_snek_vector3(
//                 snek_add(a->data.v_vector3.x, b->data.v_vector3.x),
//                 snek_add(a->data.v_vector3.y, b->data.v_vector3.y),
//                 snek_add(a->data.v_vector3.z, b->data.v_vector3.z));
//         default:
//             return NULL;
//         }
//     case ARRAY:
//         switch (b->kind)
//         {
//         case ARRAY:
//         {
//             size_t a_len = (size_t)snek_length(a);
//             size_t b_len = (size_t)snek_length(b);
//             size_t length = a_len + b_len;

//             snek_object_t *array = new_snek_array(length);

//             for (int i = 0; i < a_len; i++)
//             {
//                 snek_array_set(array, i, snek_array_get(a, i));
//             }

//             for (int i = 0; i < b_len; i++)
//             {
//                 snek_array_set(array, i + a_len, snek_array_get(b, i));
//             }

//             return array;
//         }
//         default:
//             return NULL;
//         }
//     default:
//         return NULL;
//     }
// }

void refcount_inc(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }
    obj->refcount++;
}

void refcount_dec(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }
    obj->refcount--;
    if (obj->refcount == 0)
    {
        return refcount_free(obj);
    }
    return;
}

void refcount_free(snek_object_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
        break;
    case STRING:
        free(obj->data.v_string);
        break;
    case VECTOR3:
        refcount_dec(obj->data.v_vector3.x);
        refcount_dec(obj->data.v_vector3.y);
        refcount_dec(obj->data.v_vector3.z);
        break;
    case ARRAY:
        snek_array_t array = obj->data.v_array;
        for (size_t i = 0; i < array.size; i++)
        {
            refcount_dec(array.elements[i]);
        }
        free(array.elements);
        break;
    default:
        exit(1);
    }
    free(obj);
}

vm_t *vm_new()
{
    vm_t *vm = malloc(sizeof(vm_t));
    if (vm == NULL)
    {
        return NULL;
    }

    vm->frames = stack_new(8);
    if (vm->frames == NULL)
    {
        return NULL;
    }

    vm->objects = stack_new(8);
    if (vm->objects == NULL)
    {
        return NULL;
    }

    return vm;
}

// void vm_free(vm_t *vm)
// {
//     if (vm == NULL)
//         return;

//     stack_free(vm->frames);
//     stack_free(vm->objects);

//     free(vm);
// }

void vm_frame_push(vm_t *vm, frame_t *frame)
{
    stack_push(vm->frames, frame);
}

frame_t *vm_new_frame(vm_t *vm)
{
    frame_t *f = malloc(sizeof(frame_t));
    f->references = stack_new(8);
    vm_frame_push(vm, f);
    return f;
}

void frame_free(frame_t *frame)
{
    stack_free(frame->references);
    free(frame);
}

void snek_object_free(snek_object_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
        break;
    case STRING:
        free(obj->data.v_string);
        break;
    case VECTOR3:
        break;
    case ARRAY:
        snek_array_t *array = &obj->data.v_array;
        free(array->elements);
        break;
    default:
        break;
    }
    free(obj);
}
//! Mark and Sweep Need to revisit
void vm_free(vm_t *vm)
{
    for (size_t i = 0; i < vm->frames->count; i++)
    {
        frame_free(vm->frames->data[i]);
    }
    stack_free(vm->frames);

    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_free(vm->objects->data[i]);
    }
    stack_free(vm->objects);
    free(vm);
}

void frame_reference_object(frame_t *frame, snek_object_t *obj)
{
    stack_push(frame->references, obj);
}

void mark(vm_t *vm)
{
    for (size_t i = 0; i < vm->frames->count; i++)
    {
        frame_t *frame = (frame_t *)vm->frames->data[i];
        for (size_t j = 0; j < frame->references->count; j++)
        {
            snek_object_t *obj = frame->references->data[j];
            obj->is_marked = true;
        }
    }
}

// snek_object_t defines what an object is, and frame_t(via its references stack) helps the VM understand which objects are currently in use by the running code.They work together to manage the program's data effectively.

void trace(vm_t *vm)
{
    stack_t *gray_objects = stack_new(8);
    if (gray_objects == NULL)
    {
        return;
    }
    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_t *obj = vm->objects->data[i];
        if (obj->is_marked == true)
        {
            stack_push(gray_objects, obj);
        }
    }
    while (gray_objects->count != 0)
    {
        snek_object_t *obj = (snek_object_t *)stack_pop(gray_objects);
        trace_blacken_object(gray_objects, obj);
    }
    stack_free(gray_objects);
}

// frame_t *frame = (frame_t *)vm->frames->data[i];
void trace_blacken_object(stack_t *gray_objects, snek_object_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
    case STRING:
        break;
    case VECTOR3:
        snek_vector_t *vector3 = &obj->data.v_vector3;
        trace_mark_object(gray_objects, vector3->x);
        trace_mark_object(gray_objects, vector3->y);
        trace_mark_object(gray_objects, vector3->z);
        break;
    case ARRAY:
        snek_array_t *array = &obj->data.v_array;
        for (size_t i = 0; i < array->size; i++)
        {
            trace_mark_object(gray_objects, array->elements[i]);
        }
        break;
    default:
        break;
    }
}

void trace_mark_object(stack_t *gray_objects, snek_object_t *obj)
{
    if (obj == NULL || obj->is_marked == true)
    {
        return;
    }
    obj->is_marked = true;
    stack_push(gray_objects, obj);
}

int can_access_registry(int is_premium, int reputation, int has_2fa)
{
    if (is_premium == 1 || (reputation >= 100 && has_2fa == 1))
    {
        return true;
    }
    return false;
}

void vm_collect_garbage(vm_t *vm)
{
    mark(vm);
    trace(vm);
    sweep(vm);
}

void sweep(vm_t *vm)
{
    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_t *obj = vm->objects->data[i];
        if (obj->is_marked == true)
        {
            obj->is_marked = false;
        }
        else
        {
            snek_object_free(obj);
            vm->objects->data[i] = NULL;
        }
    }
    stack_remove_nulls(vm->objects);
}

int main()
{
    int result = can_access_registry(1, 0, 0);
    (void)result;
    return 0;
    /////////////////
    // vm_t *vm = vm_new();
    // frame_t *frame = vm_new_frame(vm);

    // // (void)frame;
    // snek_object_t *x = new_snek_integer(vm, 5);
    // snek_object_t *y = new_snek_integer(vm, 5);
    // snek_object_t *z = new_snek_integer(vm, 5);
    // snek_object_t *vector = new_snek_vector3(vm, x, y, z);

    // frame_reference_object(frame, vector);
    // mark(vm);
    // // (void)frame;

    // return 0;
    /////////////////
    // snek_object_t *first = new_snek_array(1);
    // snek_object_t *second = new_snek_array(1);
    // // refcounts: first = 1, second = 1
    // snek_array_set(first, 0, second);
    // // refcounts: first = 1, second = 2
    // snek_array_set(second, 0, first);
    // // refcounts: first = 2, second = 2
    // refcount_dec(first);
    // refcount_dec(second);
    // return 0;
    ///////////////////
    // snek_object_t *obj = new_snek_string("Hello @wagslane!");

    // refcount_inc(obj);

    // refcount_dec(obj);

    // refcount_dec(obj);

    // return 0;

    // snek_object_t *one = new_snek_integer(1);
    // snek_object_t *ones = new_snek_array(2);
    // assert(snek_array_set(ones, 0, one));
    // assert(snek_array_set(ones, 1, one));

    // snek_object_t *hi = new_snek_string("hi");
    // snek_object_t *hellos = new_snek_array(3);
    // assert(snek_array_set(hellos, 0, hi));
    // assert(snek_array_set(hellos, 1, hi));
    // assert(snek_array_set(hellos, 2, hi));

    // snek_object_t *result = snek_add(ones, hellos);

    // (void)result;
    // return 0;
    // snek_object_t *one = new_snek_float(1.0);
    // snek_object_t *two = new_snek_float(2.0);
    // snek_object_t *three = new_snek_float(3.0);
    // snek_object_t *four = new_snek_float(4.0);
    // snek_object_t *five = new_snek_float(5.0);
    // snek_object_t *six = new_snek_float(6.0);

    // snek_object_t *v1 = new_snek_vector3(one, two, three);
    // snek_object_t *v2 = new_snek_vector3(four, five, six);
    // snek_object_t *result = snek_add(v1, v2);
    //
    // snek_object_t *obj = new_snek_array(2);
    // snek_object_t *first = new_snek_string("First");
    // // snek_object_t *second = new_snek_integer(3);

    // snek_array_set(obj, 0, first);
    // snek_array_get(obj, 0);
    // // snek_array_set(obj, 1, second);

    // return 0;
    ///   //
    // snek_object_t *obj = new_snek_array(2);

    // (void)obj;

    // return 0;
    // ///   //
    // stack_t *s = stack_new(4);

    // stack_push_multiple_types(s);

    // // float *f = s->data[0];

    // return 0;
    /////   //
    // stack_t *s = stack_new(2);

    // scary_double_push(s);

    // int value = (int)s->data[0];
    // // // printf("%zu", sizeof(int *));
    // // // printf("%zu", sizeof(s->data[0]));
    // int correct_value = 1337;
    // if (value == correct_value)
    // {
    //     return 0;
    // }

    // return 0;
    /////   //
    // stack_t *s = stack_new(2);
    // int one = 1;
    // int two = 2;
    // int three = 3;

    // stack_push(s, &one);
    // stack_push(s, &two);

    // stack_push(s, &three);

    // int *popped = stack_pop(s);

    // (void)popped;

    // // popped = stack_pop(s);

    // // popped = stack_pop(s);

    // // popped = stack_pop(s);

    // return 0;
    ///////   //
    // stack_t *s = stack_new(1);

    // int a = 1;

    // stack_push(s, &a);
    // // stack_push(s, &a);

    // return 0;
    /////////   //
    // stack_t *s = stack_new(3);
    // stack_new(3);

    // return 0;
    ///////////
    // int i1 = 1234;
    // int i2 = 5678;

    // swap(&i1, &i2, sizeof(int));

    // return 0;
    ///////////
    // char *a = "Hello";
    // char *b = "Goodbye";

    // swap_strings(&a, &b);
    // // printf("%s\n", *a);
    // // printf("%s\n", *b);

    // return 0;
    ///////////
    // int a = 5;
    // int b = 6;

    // swap_ints(&a, &b);

    // return 0;
    ///////////
    // snek_int_t integer;
    // integer.value = 42;
    // snek_zero_out(&integer, INTEGER);

    // snek_float_t float_num;
    // float_num.value = 3.14;
    // snek_zero_out(&float_num, FLOAT);

    // snek_bool_t boolean;
    // boolean.value = 1;
    // snek_zero_out(&boolean, BOOL);

    // return 0;
    ///////////
    // token_t token = {"hello", 1, 1};
    // token_t **result = create_token_pointer_array(&token, 1);

    // // result[0] is token_t*
    // printf("literal:   %s\n", result[0]->literal);
    // printf("line: %d\n", result[0]->line);
    // printf("column:   %d\n", result[0]->column);

    // // if create_token_pointer_array did deep mallocs:
    // free(result[0]); // free the token copy
    // free(result);    // free the pointer array

    // // (void)result;
    // return 0;
    // ///////////
    // int size = 5;
    // int multiplier = 2;
    // allocate_scalar_array(size, multiplier);
    // int *result = allocate_scalar_array(size, multiplier);

    // // // printf("result: %d\n", *result);
    // // for (int i = 0; i < 5; i++)
    // // {
    // //     printf("%d", result[i]);
    // // }

    // return 0;
    // ///////////
    // char *result = get_full_greeting("Hello", "Alice", 20);

    // new_int_array(100);

    // int *arr_of_6 = new_int_array(6);
    // arr_of_6[0] = 69;
    // arr_of_6[1] = 42;
    // arr_of_6[2] = 420;
    // arr_of_6[3] = 1337;
    // arr_of_6[4] = 7;
    // arr_of_6[5] = 0;

    // return 0;
    // ///////////
    //! look over
    // coord_t c1 = new_coord(10, 20);
    // coord_t c2 = new_coord(30, 40);
    // coord_t c3 = new_coord(50, 60);
    // // coord_t *c1 = new_coord(10, 20);
    // // coord_t *c2 = new_coord(30, 40);
    // // coord_t *c3 = new_coord(50, 60);

    // printf("c1: %d, %d\n", c1.x, c1.y);
    // printf("c2: %d, %d\n", c2.x, c2.y);
    // printf("c3: %d, %d\n", c3.x, c3.y);

    // return 0;
    // ///////////
    //! look over
    // printMessageOne();
    // printMessageTwo();
    // printMessageThree();
    // return 0;
    // ///////////
    // char buffer[100];
    // snek_object_t i = new_integer(5);
    // format_object(i, buffer);

    // return 0;
    // ///////////
    // strncat_example();

    // TextBuffer dest;
    // strcpy(dest.buffer, "This is a long string");
    // dest.length = 21;
    // const char *src = " that will fill the whole buffer and leave no space for some of the chars.";
    // int result = smart_append(&dest, src);

    // TextBuffer dest;
    // strcpy(dest.buffer, "This is a very long string that will fill up the entire buffer.");
    // dest.length = 63;
    // const char *src = " Extra";
    // int result = smart_append(&dest, src);

    // TextBuffer dest;
    // char *str = strcpy(dest.buffer, "");
    // dest.length = 0;
    // const char *src = "Hello";
    // const char *mine = "----mine----";
    // const char *boot = "----boot----";
    // printf("%s\n", mine);
    // int result1 = ssmart_append(&dest, src);
    // printf("%s\n", boot);
    // int result2 = smart_append(&dest, src);

    // printf("result: %d\n", result);

    // Checks for available space before appending.
    // Appends as much as possible if there's not enough space.
    // Always ensures the buffer remains null-terminated.
    // Returns a status indicating whether the full append was possible.
    ///////////////
    // char str_front[100] = "Obi";
    // const char *str_end = "nna";
    // // printf("str front: %s\n", str_front);
    // // printf("str end: %s\n", str_end);
    // // printf(": %c\n", str_front[0]);

    // concat_strings(str_front, str_end);
    // return 0;
    ///////////////
    // int arr[5];
    // int *ptr = arr;         // 'arr' decays to 'int*'
    // int value = *(arr + 2); // 'arr' decays to 'int*'

    // return 0;
    ///////////////
    // coordinate_t points[3] = {
    //     {5, 4, 1},
    //     {7, 3, 2},
    //     {9, 6, 8}};

    // coordinate_t *ptr = points;

    // printf("Address of points: %p\n", &points);
    // printf("Address in ptr (points[0]): %p\n", ptr);
    // printf("value at address in ptr (points[0]) bf: x=%d, y=%d, z=%d\n", (ptr + 1)->x, (ptr + 1)->y, (ptr + 1)->z);
    // (ptr + 1)->x = 1;
    // (ptr + 1)->y = 1;
    // (ptr + 1)->z = 1;
    // printf("value at address in ptr (points[0]) af: x=%d, y=%d, z=%d\n", (ptr + 1)->x, (ptr + 1)->y, (ptr + 1)->z);

    // int *points_start = (int *)points; // cast struct to ints; possible b/c arrays&structs are contigous in memory

    // int *points_start = (int *)points;
    //////////////
    // Print updated array
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", numbers[i]);
    // }
    // printf("\n");

    //////////////
    // codefile_t original;
    // original.lines = 100;
    // original.filetype = 1;
    // printf("Address of orginal: %p\n", &original);
    // printf("val at orginal bf change: %d\n", original.lines);
    // codefile_t result = change_filetype(&original, 2);
    // printf("val at orginal af change: %d\n", original.lines);

    ///////////////
    // int age = 16;
    // int *ptr = &age; // ptr holds the address of age

    // printf("Address of i: %p\n", (void *)ptr);
    // int val_at_ptr = *ptr;
    // printf("Value at that address: %d\n", *ptr);
    // printf("Value at that address: %d\n", val_at_ptr);
    //                    ^^^^^^ dereference: go to that address and retrive the data
    // *ptr = 60; // change the value through the pointer
    // printf("Value at that address: %d\n", *ptr);
    //////////////
    // unsigned long size = size_of_addr(55);
    // printf("The address of size is: %p\n", &size);
    // printf("sizeof(&i), long long ptr is: %lu\n", size);
}

// %d - digit(integer) %c - character %f - floating point number % s - string(char *)