#include "error.h"

const error_t error_none = { .err = ERR_NONE };
const error_t error_general = { .err = ERR_GENERAL };
const error_t error_alloc = { .err = ERR_ALLOC };
const error_t error_notbuiltin = { .err = ERR_NOTBUILTIN };
const error_t error_notinited = { .err = ERR_NOTINITED };
