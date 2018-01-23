/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

typedef unsigned long long u64;
typedef unsigned int u32;
static constexpr u32 DJBH(const char* cp)
{
  u32 hash = 5381;
  while (*cp)
      hash = 33 * hash ^ (unsigned char) *cp++;
  return hash;
}

static constexpr u64 WASM_TEST_ACTION(const char* cls, const char* method)
{
  return u64(DJBH(cls)) << 32 | u64(DJBH(method));
}

#define WASM_TEST_HANDLER(CLASS, METHOD) \
  if( action == WASM_TEST_ACTION(#CLASS, #METHOD) ) { \
     CLASS::METHOD(); \
     return; \
  }
   
#pragma pack(push, 1)
struct dummy_action {
  char a; //1
  unsigned long long b; //8
  int  c; //4
};

struct u128_action {
  unsigned __int128  values[3]; //16*3
};
#pragma pack(pop)

static_assert( sizeof(dummy_action) == 13 , "unexpected packing" );
static_assert( sizeof(u128_action) == 16*3 , "unexpected packing" );

struct test_types {
  static unsigned int types_size();
  static unsigned int char_to_symbol();
  static unsigned int string_to_name();
  static unsigned int name_class();
};

struct test_print {
  static void test_prints();
  static void test_printi();
  static void test_printi128();
  static void test_printn();
};

#define DUMMY_ACTION_DEFAULT_A 0x45
#define DUMMY_ACTION_DEFAULT_B 0xab11cd1244556677
#define DUMMY_ACTION_DEFAULT_C 0x7451ae12

struct test_action {

  static void read_action_normal();
  static void read_action_to_0();
  static void read_action_to_64k();
  static void require_notice();
  static void require_auth();
  static void assert_false();
  static void assert_true();
  static void now();

};

struct test_math {
  static void test_multeq();
  static void test_diveq();
  static void test_diveq_by_0();
  static void test_double_api();
  static void test_double_api_div_0();
};

struct test_db {
   static unsigned int key_i64_general();
   static unsigned int key_i64_remove_all();
   static unsigned int key_i64_small_load();
   static unsigned int key_i64_small_store();
   static unsigned int key_i64_store_scope();
   static unsigned int key_i64_remove_scope();
   static unsigned int key_i64_not_found();
   static unsigned int key_i64_front_back();

   static unsigned int key_i128i128_general();
   static unsigned int key_i64i64i64_general();
   static unsigned int key_str_general();
   static unsigned int key_str_table();

   static unsigned int key_str_setup_limit();
   static unsigned int key_str_min_exceed_limit();
   static unsigned int key_str_under_limit();
   static unsigned int key_str_available_space_exceed_limit();
   static unsigned int key_str_another_under_limit();

   static unsigned int key_i64_setup_limit();
   static unsigned int key_i64_min_exceed_limit();
   static unsigned int key_i64_under_limit();
   static unsigned int key_i64_available_space_exceed_limit();
   static unsigned int key_i64_another_under_limit();

   static unsigned int key_i128i128_setup_limit();
   static unsigned int key_i128i128_min_exceed_limit();
   static unsigned int key_i128i128_under_limit();
   static unsigned int key_i128i128_available_space_exceed_limit();
   static unsigned int key_i128i128_another_under_limit();

   static unsigned int key_i64i64i64_setup_limit();
   static unsigned int key_i64i64i64_min_exceed_limit();
   static unsigned int key_i64i64i64_under_limit();
   static unsigned int key_i64i64i64_available_space_exceed_limit();
   static unsigned int key_i64i64i64_another_under_limit();
};

struct test_crypto {
   static unsigned int test_sha256();
   static unsigned int sha256_no_data();
   static unsigned int asert_sha256_false();
   static unsigned int asert_sha256_true();
   static unsigned int asert_no_data();
};

struct test_transaction {

  static void send_action();
  static void send_action_empty();
  static void send_action_max();
  static void send_action_large();
  static void send_action_recurse();
  static void send_action_inline_fail();
  static void send_transaction();
  static void send_transaction_empty();
  static void send_transaction_max();
  static void send_transaction_large();
};

struct test_chain {
  static unsigned int test_activeprods();
};

struct test_string {
  static void construct_with_size();
  static void construct_with_data();
  static void construct_with_data_copied();
  static void construct_with_data_partially();
  static void copy_constructor();
  static void assignment_operator();
  static void index_operator();
  static void index_out_of_bound();
  static void substring();
  static void substring_out_of_bound();
  static void concatenation_null_terminated();
  static void concatenation_non_null_terminated();
  static void assign();
  static void comparison_operator();
  static void print_null_terminated();
  static void print_non_null_terminated();
  static void print_unicode();
  static void valid_utf8();
  static void invalid_utf8();
  static void string_literal();
};

struct test_fixedpoint {
   static unsigned int create_instances();
   static unsigned int test_addition();
   static unsigned int test_subtraction();
   static unsigned int test_multiplication();
   static unsigned int test_division();
};

struct test_real {
   static unsigned int create_instances();
   static unsigned int test_addition();
   static unsigned int test_multiplication();
   static unsigned int test_division();
};

struct test_compiler_builtins {
   static void test_multi3();
   static void test_divti3();
   static void test_divti3_by_0();
   static void test_lshlti3();
   static void test_lshrti3();
   static void test_ashlti3();
   static void test_ashrti3();
};

struct test_account {
   static void test_balance_acc1();
};

struct test_extended_memory {
	static void test_initial_buffer();
	static void test_page_memory();
	static void test_page_memory_exceeded();
	static void test_page_memory_negative_bytes();
};

struct test_memory {
   static void test_memory_allocs();
   static void test_memory_hunk();
   static void test_memory_hunks();
   static void test_memory_hunks_disjoint();
   static void test_memset_memcpy();
   static void test_memcpy_overlap_start();
   static void test_memcpy_overlap_end();
   static void test_memcmp();
};
