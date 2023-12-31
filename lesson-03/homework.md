# Домашнее задание к лекции №3

## Написать аллокатор со стратегией линейного выделения памяти

Должна быть реализована структура и функции для работы с этой структурой:
```c++
struct Allocator;

Allocator* init_allocator(size_t maxSize);
char* alloc(Allocator *alloc, size_t size);
void reset(Allocator *alloc);
void clear(Allocator *alloc)

```

Что должно происходить:
- При вызове init\_allocator аллоцируется динамическая память указанного размера (при помощи new);
- При повторном вызое init\_allocator выделенная ранее память должна освободиться и выделиться новая;
- При вызове alloc возвращает указатель на блок запрошенного размера или nullptr, если места недостаточно;
- Пользователь может вызвать метод alloc несколько раз подряд. Соответственно нужно хранить не только указатель на начало памяти, но и смещение от начала (offset) --- то место, где располагается ещё не занятая пользователем память;
- После вызова reset аллокатор позволяет использовать свою память снова. То есть память, ранее выделенная при помощи alloc становится "невалидной", её пользователь может переиспользовать, вызвав опять alloc. offset при методе reset снова указывает на начало;
- delete вызывается в clear (но никак не при reset)!
- init\_allocator может вызываться несколько раз, память, выделенная ранее, должна освобождаться.

При вызове init\_allocator аллоцируется указанный размер, после чего при вызове alloc возвращает указатель на блок запрошенного размера или nullptr, если места недостаточно. После вызова reset аллокатор позволяет использовать свою память снова.

Так же нужно будет написать gtest на различные проверки.
