#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "aes.h"

#define FAIL -1
#define SUCC 0

unsigned char key_sha256[SHA_DIGEST_LENGTH];

void SHA256_gen(char str[], unsigned char *sha256_str){
	SHA256_CTX sha256;

	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str, strlen(str));
	SHA256_Final(sha256_str, &sha256);
}

int main(int argc, char *args[]){
	int i =0;
	char *key_str = "hello";
	char *file = args[1];

	SHA256_CTX sha256;
	// unsigned char sha256_str[SHA256_DIGEST_LENGTH];

	// SHA256_gen(str, sha256_str);
	SHA256_gen(key_str, key_sha256);

	for(i=0; i < SHA256_DIGEST_LENGTH; i++){
		printf("%02x", key_sha256[i]);
	}
	printf("\n");

	if( argc != 2 ){
		printf("[Usage] %s fs_src_file\n", args[0]);
		return FAIL;
	}


	// if( fs_encrypt_aes(key_sha256, args[1], strcat(args[1], ".enc") == SUCC){
	// 	fs_decrypt_aes(key_sha256, strcat(args[1], ".enc"),
	// 	strcat(args[1], ".dec");
	// 	printf("result:[%s]\n", strcat(args[1], ".dec");
	// }

	if( fs_encrypt_aes(key_sha256, file, "file.enc") == SUCC){
		fs_decrypt_aes(key_sha256, "file.enc", "file.dec");
		printf("result:[%s]\n", "file.dec");
	}

	return 0;
}
