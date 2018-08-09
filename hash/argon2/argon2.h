//
// Created by Haifa Bogdan Adnan on 05/08/2018.
//

#ifndef ARIOMINER_ARGON2_H
#define ARIOMINER_ARGON2_H

#include "defs.h"

typedef void (*argon2_blocks_filler_ptr)(void *, int, argon2profile *, void *);

class argon2 {
public:
    argon2(argon2_blocks_filler_ptr filler, void *seed_memory, void *user_data);

    vector<string> generate_hashes(const argon2profile &profile, const string &base, const string &salt_ = "");

    void set_seed_memory(uint8_t *memory);
    void set_seed_memory_offset(size_t offset);
    void set_threads(int threads);
private:
    string __make_salt();
    void __initial_hash(const argon2profile &profile, uint8_t *blockhash, const string &base, const string &salt);
    void __fill_first_blocks(const argon2profile &profile, uint8_t *blockhash, int thread);
    string __encode_string(const argon2profile &profile, const string &salt, uint8_t *hash);

    argon2_blocks_filler_ptr __filler;
    int __threads;
    uint8_t *__seed_memory;
    size_t __seed_memory_offset;
    void *__user_data;

};


#endif //ARIOMINER_ARGON2_H