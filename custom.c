// This is a place for you to create your own "custom" codebook

#include "sos.h"
#include "custom.h"

// see custom.h
struct sos *build_custom_codebook(void) {
  struct sos *seq = sos_create();
  for (int i = 0; i <= 127; ++i) {
    sos_insert_end(seq, "");
  }
  // Template is:
  // sos_replace_at(seq, 'letter_to_be_replaced', "replaced string");
  sos_replace_at(seq, '.', "i won");
  sos_replace_at(seq, 'A', "ask your academic advisor +");
  sos_replace_at(seq, 'B', "basic skill issue +");
  sos_replace_at(seq, 'C', "cry about it +");
  sos_replace_at(seq, 'D', "didnt ask +");
  sos_replace_at(seq, 'E', "egrep +");
  sos_replace_at(seq, 'F', "failed spcom223 +");
  sos_replace_at(seq, 'G', "ggez +");
  sos_replace_at(seq, 'H', "hello world! +");
  sos_replace_at(seq, 'I', "invalid opinion");
  sos_replace_at(seq, 'J', "jk +");
  sos_replace_at(seq, 'K', "k. +");
  sos_replace_at(seq, 'L', "league of legends player +");
  sos_replace_at(seq, 'M', "memory leak +");
  sos_replace_at(seq, 'N', "no co-op +");
  sos_replace_at(seq, 'O', "orem ipsum dolor sit amet +");
  sos_replace_at(seq, 'P', "piazza post +");
  sos_replace_at(seq, 'Q', "quote tweet +");
  sos_replace_at(seq, 'R', "read FAQ +");
  sos_replace_at(seq, 'S', "stackexchange user +");
  sos_replace_at(seq, 'T', "think again +");
  sos_replace_at(seq, 'U', "uwu +");
  sos_replace_at(seq, 'V', "violated policy 71 +");
  sos_replace_at(seq, 'W', "waterloo is my favourite +");
  sos_replace_at(seq, 'X', "xenomorph +");
  sos_replace_at(seq, 'Y', "you fell off +");
  sos_replace_at(seq, 'Z', "zero pr");
  sos_replace_at(seq, 'a', "angry +");
  sos_replace_at(seq, 'b', "basic skill issue +");
  sos_replace_at(seq, 'c', "cry about it +");
  sos_replace_at(seq, 'd', "didnt ask +");
  sos_replace_at(seq, 'e', "egrep +");
  sos_replace_at(seq, 'f', "failed spcom223 +");
  sos_replace_at(seq, 'g', "ggez +");
  sos_replace_at(seq, 'h', "hello world! +");
  sos_replace_at(seq, 'i', "invalid write of size 4 +");
  sos_replace_at(seq, 'j', "jk +");
  sos_replace_at(seq, 'k', "k. +");
  sos_replace_at(seq, 'l', "league of legends player +");
  sos_replace_at(seq, 'm', "mald +");
  sos_replace_at(seq, 'n', "no co-op +");
  sos_replace_at(seq, 'o', "orem ipsum dolor sit amet +");
  sos_replace_at(seq, 'p', "PUBLIC TEST FAILED +");
  sos_replace_at(seq, 'q', "quote tweet +");
  sos_replace_at(seq, 'r', "[REDACTED] +");
  sos_replace_at(seq, 's', "segmentation fault +");
  sos_replace_at(seq, 't', "TEST FAILED +");
  sos_replace_at(seq, 'u', "uwu +");
  sos_replace_at(seq, 'v', "violated policy 71 +");
  sos_replace_at(seq, 'w', "waterloo is my favourite +");
  sos_replace_at(seq, 'x', "xenomorph +");
  sos_replace_at(seq, 'y', "you fell off +");
  sos_replace_at(seq, 'z', "zero lp +");

  return seq;
}
