#include <cstdint>
#include <cstddef>

//buffer data type
typedef struct buf_t buf_t;
//buffer pimpl
typedef buf_t* buf_handle_t;

buf_handle_t buf_init(uint8_t* buffer, size_t size);
void buf_free(buf_handle_t me);
void buf_reset(buf_handle_t me);
void buf_put(buf_handle_t me, uint8_t data);//overwrites old data if buffer full
void buf_put_v2(buf_handle_t me, uint8_t data);//doesnt overwrites old data if buffer full
int buf_get(buf_handle_t me, uint8_t* data);
bool buf_isEmpty(buf_handle_t me);
bool buf_isFull(buf_handle_t me);
size_t buf_maxSize(buf_handle_t me);
size_t buf_currentSize(buf_handle_t);

struct buf_t {
    uint8_t* buffer;
    size_t head;
    size_t tail;
    bool isFull;
};



