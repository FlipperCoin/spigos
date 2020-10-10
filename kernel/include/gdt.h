// NOTE: Code & Data kernel segments are assumed in the gdt_flush procedure, change the value there aswell if you change it here
#define CODE_SEGMENT_KERNEL 1
#define DATA_SEGMENT_KERNEL 2
#define CODE_SEGMENT_USER 3
#define DATA_SEGMENT_USER 4
#define KERNEL_TASK_STATE_SEGMENT 5

void initGdt();
