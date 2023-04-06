// This is the implementation of the sequence of strings (sos) ADT

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string-io.h"
#include "sos.h"

struct sos {
  int len;
  int maxlen;
  char **data;
};

// see sos.h
struct sos *sos_read(void) {
  struct sos *seq = sos_create();
  while (1) {
    char *line = read_line();
    if (line == NULL) {
      break;
    }
    sos_insert_end(seq, line);
    free(line);
  }
  return seq;
}

// see sos.h
struct sos *sos_create(void) {
  struct sos *new_sos = malloc(sizeof(struct sos));
  new_sos->len = 0;
  new_sos->maxlen = 1;
  new_sos->data = malloc(new_sos->maxlen * sizeof(char *));
  return new_sos;
}

// see sos.h
void sos_destroy(struct sos *seq) {
  assert(seq);
  for (int i = 0; i < seq->len; ++i) {
    free(seq->data[i]);
  }
  free(seq->data);
  free(seq);
  seq = NULL;
}

// see sos.h
int sos_length(const struct sos *seq) {
  return seq->len;
}

// copy_str(s) copies the constant string to a new string to 
//    heap and returns a pointer
// requires: s is valid
// effects: allocates memory
// time: O(n)
char *copy_str(const char *s) {
  assert(s);
  int len = strlen(s);
  char *copy_str = malloc(len * sizeof(char) + 1);
  strcpy(copy_str, s);
  return copy_str;
}

// see sos.h
void sos_insert_end(struct sos *seq, const char *s) {
  assert(seq);
  assert(s);
  if (seq->len == seq->maxlen) {
    seq->maxlen *= 2;
    seq->data = realloc(seq->data, seq->maxlen * sizeof(char *));
  }
  char *new_str = copy_str(s);
  seq->data[seq->len] = new_str;
  ++seq->len;
}

// see sos.h
void sos_print(const struct sos *seq) {
  assert(seq);
  if (seq->len == 0) {
    return;
  }
  for (int i = 0; i < seq->len; ++i) {
    printf("%s\n", seq->data[i]);
  }
}

// see sos.h
const char *sos_item_at(const struct sos *seq, int pos) {
  assert(seq);
  assert(0 <= pos && pos < sos_length(seq));
  return seq->data[pos];
}

// see sos.h
void sos_remove_end(struct sos *seq) {
  assert(seq);
  assert(sos_length(seq) > 0);
  free(seq->data[seq->len - 1]);
  seq->data[seq->len - 1] = NULL;
  --seq->len;
}

// see sos.h
void sos_insert_at(struct sos *seq, int pos, const char *s) {
  assert(seq);
  assert(s);
  assert(0 <= pos && pos <= sos_length(seq));
  if (seq->len == seq->maxlen) {
    seq->maxlen *= 2;
    seq->data = realloc(seq->data, seq->maxlen * sizeof(char *));
  }
  char *new_str = copy_str(s);
  for (int i = seq->len; i > pos; --i) {
    seq->data[i] = seq->data[i - 1];
  }
  seq->data[pos] = new_str;
  ++seq->len;
}

// see sos.h
void sos_remove_at(struct sos *seq, int pos) {
  assert(seq);
  assert(0 <= pos && pos < sos_length(seq));
  free(seq->data[pos]);
  seq->data[pos] = NULL;
  for (int i = pos; i < seq->len - 1; ++i) {
    seq->data[i] = seq->data[i + 1];
  }
  --seq->len;
}

// see sos.h
void sos_replace_at(struct sos *seq, int pos, const char *s) {
  assert(seq);
  assert(s);
  assert(0 <= pos && pos < sos_length(seq));
  free(seq->data[pos]);
  seq->data[pos] = copy_str(s);
}

// see sos.h
void sos_swap(struct sos *seq, int pos1, int pos2) {
  assert(seq);
  assert(0 <= pos1 && pos2 < sos_length(seq));
  if (pos1 == pos2) {
    return;
  } else {
    char *temp = seq->data[pos1];
    seq->data[pos1] = seq->data[pos2];
    seq->data[pos2] = temp;
  }
}

// see sos.h
struct sos *sos_dup(const struct sos *seq) {
  assert(seq);
  struct sos *dup_sos = sos_create();
  for (int i = 0; i < seq->len; ++i) {
    sos_insert_end(dup_sos, seq->data[i]);
  }
  return dup_sos;
}
