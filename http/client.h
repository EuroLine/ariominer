//
// Created by Haifa Bogdan Adnan on 03/08/2018.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include "http.h"

struct ariopool_result {
    bool success;
};

struct ariopool_update_result : public ariopool_result {
    string block;
    string difficulty;
    uint32_t limit;
    string public_key;
    uint32_t height;
    string argon2profile;
    string recommendation;
};

struct ariopool_submit_result : public ariopool_result {
    string pool_response;
};

class ariopool_client : public http {
public:
    ariopool_client(const string &pool_address, const string &worker_id, const string &wallet_address);

    ariopool_update_result update(double hash_rate_cblocks, double hash_rate_gblocks);
    ariopool_submit_result submit(const string &hash, const string &nonce, const string &public_key);

private:
    bool __validate_response(const string &response);

    string __get_wallet_address();
    string __pool_address;
    string __worker_id;
    string __client_wallet_address;
    string __used_wallet_address;

    bool __force_hashrate_report;

    uint64_t __timestamp;
    uint64_t __last_hash_report;
};

#endif //PROJECT_CLIENT_H
