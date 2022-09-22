#include <stdio.h>
#include <stdlib.h>

#include <circular_buffer.h>

#define EXAMPLE_BUFFER_SIZE 10

int main(void)
{
    uint8_t *buffer = malloc(EXAMPLE_BUFFER_SIZE * sizeof(uint8_t));
    cbuf_handle_t circular_buffer_handler_1 = circular_buf_init(buffer, EXAMPLE_BUFFER_SIZE);

    bool full = circular_buf_is_full(circular_buffer_handler_1);
    bool empty = circular_buf_is_empty(circular_buffer_handler_1);
    printf("Current buffer size: %zu\n", circular_buf_size(circular_buffer_handler_1));
    
    circular_buf_put(circular_buffer_handler_1, 20);
    circular_buf_put(circular_buffer_handler_1, 10);
    circular_buf_put(circular_buffer_handler_1, 2);
    circular_buf_put(circular_buffer_handler_1, 5);
    
    
    
    
    free(buffer);
    circular_buf_free(circular_buffer_handler_1);
    return EXIT_SUCCESS;
}