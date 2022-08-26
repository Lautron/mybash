#include "command.h"
#include <assert.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct pipeline_s {
  GQueue∗ commands;
  bool should_wait;
} pipeline_s;

pipeline pipeline_new(void)
{
  pipeline self;
  self = malloc(sizeof(pipeline_s));
  self->commands = NULL;
  self->should_wait = true;

  // Didn't put predicate members inside variables to prevent useless computation when deactivating assertions
  assert(self != NULL && pipeline_is_empty(self) && pipeline_get_wait(self));
  return self;
}

pipeline pipeline_destroy(pipeline self)
{
  assert(self != NULL);
  g_queue_free_full(self->commands, scommand_destroy); // free queue using second arg to destroy each element
  self->commands = NULL;
  free(self);
  self = NULL;
  assert(self == NULL);
  return self;
}
