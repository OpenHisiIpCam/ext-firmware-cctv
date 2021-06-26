/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup api

#include "json-api.h"

#include <assert.h>
#include <json-c/json.h>

//#include "json.h"

/*
 * https://www.jsonrpc.org/
 * {"jsonrpc": "2.0", "method": "subtract", "params": {"subtrahend": 23,
 * "minuend": 42}, "id": 3}
 *
 *
 *
 */

int
api_init(api_params_t* params, api_t* api)
{
  assert(params != NULL);
  assert(api != NULL);

  // prepare methods list var

  if (PLATFORM_DUMMY) {
    // invoke func from dummy to get all it`s methods
  }

  if (PLATFORM_HI3516AV100 || PLATFORM_HI3516AV200 || PLATFORM_HI3516CV100 ||
      PLATFORM_HI3516CV200 || PLATFORM_HI3516CV300 || PLATFORM_HI3516CV500 ||
      PLATFORM_HI3516EV200) {
    /// \todo
  }

  if (PLATFORM_XM530) {
    /// \todo
  }

  if (PLATFORM_INFINITY6B0) {
    /// \todo
  }

  if (PLATFORM_INFINITY6E) {
    /// \todo
  }

  if (PLATFORM_NT9852X) {
    /// \todo
  }

  if (PLATFORM_NT9856X) {
    /// \todo
  }

  if (STREAMER_JPEG) {
    /// \todo
  }

  if (STREAMER_RTP) {
    /// \todo
  }

  if (STREAMER_PIPE) {
    /// \todo
  }

  if (STREAMER_WEBRTC) {
    /// \todo
  }

  return 0;
}

void
api_deinit(api_t* api)
{
  // free method list var
}

static void
check_type(struct json_object* val)
{

  char* val_type_str;
  int val_type = json_object_get_type(val);

  switch (val_type) {
    case json_type_null:
      val_type_str = "val is NULL";
      break;

    case json_type_boolean:
      val_type_str = "val is a boolean";
      break;

    case json_type_double:
      val_type_str = "val is a double";
      break;

    case json_type_int:
      val_type_str = "val is an integer";
      break;

    case json_type_string:
      val_type_str = "val is a string";
      // str = (char *) json_object_get_string(val);
      break;

    case json_type_object:
      val_type_str = "val is an object";
      break;

    case json_type_array:
      val_type_str = "val is an array";
      break;
  }

  printf("%s\n", val_type_str);
}

// code	message	meaning
//-32700	Parse error		Invalid JSON was received by the server.
// An error occurred on the server while parsing the JSON text. -32600	Invalid
// Request		The JSON sent is not a valid Request object. -32601
// Method not found	The method does not exist / is not available. -32602
// Invalid params		Invalid method parameter(s). -32603	Internal
// error		Internal JSON-RPC error. -32000 to -32099	Server
// error Reserved for implementation-defined server-errors.

static const char responce_parse_error[] =
  "{\"jsonrpc\": \"2.0\", \"error\": {\"code\": -32700, \"message\": \"Parse "
  "error\"}, \"id\": null}";
static const char responce_invalid_request[] =
  "{\"jsonrpc\": \"2.0\", \"error\": {\"code\": -32600, \"message\": \"Invalid "
  "Request\"}, \"id\": null}";
static const char responce_not_found[] =
  "{\"jsonrpc\": \"2.0\", \"error\": {\"code\": -32601, \"message\": \"Method "
  "not found\"}, \"id\": null}";
static const char responce_invalid_prams[] =
  "{\"jsonrpc\": \"2.0\", \"error\": {\"code\": -32602, \"message\": \"Invalid "
  "params\"}, \"id\": null}";
static const char responce_internal_error[] =
  "{\"jsonrpc\": \"2.0\", \"error\": {\"code\": -32603, \"message\": "
  "\"Internal error\"}, \"id\": null}";

char*
api2(api_t* api, const char* request)
{
  struct json_object* jobj;

  if (NULL == request) {
    return strdup(responce_parse_error);
  }

  jobj = json_tokener_parse(request);

  if (NULL == jobj) {
    return strdup(responce_parse_error);
  }

  struct json_object* jsonrpc;
  json_object_object_get_ex(jobj, "jsonrpc", &jsonrpc);

  if (NULL == jsonrpc) {
    json_object_put(jobj);
    return strdup(responce_invalid_request);
  }

  if (json_type_string != json_object_get_type(jsonrpc)) {
    json_object_put(jobj);
    return strdup(responce_invalid_request);
  }

  if (0 != strcmp("2.0", json_object_get_string(jsonrpc))) {
    json_object_put(jobj);
    return strdup(responce_invalid_request);
  }

  struct json_object* method;
  json_object_object_get_ex(jobj, "method", &method);

  if (NULL == method) {
    json_object_put(jobj);
    return strdup(responce_invalid_request);
  }

  if (json_type_string != json_object_get_type(method)) {
    json_object_put(jobj);
    return strdup(responce_invalid_request);
  }

  struct json_object* params;
  json_object_object_get_ex(jobj, "params", &params);

  if (NULL != params) {
    if (json_type_object != json_object_get_type(params)) {
      /// \todo return error, params should be object
    }
  }

  struct json_object* id;
  json_object_object_get_ex(jobj, "id", &id);

  if (NULL != id) {
    if (json_type_int == json_object_get_type(id)) {
      /// \todo responce id int
    } else if (json_type_string == json_object_get_type(id)) {
      /// \todo responce id string
    } else {
      /// \todo return error id maybe int or string
    }
  } else {
    /// \todo responce id null
  }

  const char* method_str = json_object_get_string(method);

  api_method_t* found = api->methods;

  struct json_object* result;

  while (NULL != found->path) {
    if (0 == strcmp(method_str, found->path)) {
      found->func(params, &result, found->user);
      break;
    }
    found++;
  }

  /// \todo route to method
  /// \todo error_t some_method(struct json_object *params, struct json_object
  /// **answer);
  ///
  /// {"jsonrpc": "2.0", "result": { something ... }, "id": "1"},
  ///

  json_object_put(jobj);

  return NULL;
}

void
api(const char* request, char* answer)
{

  // const char method[] = "/v1/system";
#if 0
  char* str = "{ \"msg-type\": [ \"0xdeadbeef\", \"irc log\" ], \
		\"msg-from\": { \"class\": \"soldier\", \"name\": \"Wixilav\" }, \
		\"msg-to\": { \"class\": \"supreme-commander\", \"name\": \"[Redacted]\" }, \
		\"msg-log\": [ \
			\"soldier: Boss there is a slight problem with the piece offering to humans\", \
			\"supreme-commander: Explain yourself soldier!\", \
			\"soldier: Well they don't seem to move anymore...\", \
			\"supreme-commander: Oh snap, I came here to see them twerk!\" \
			] \
		}";
#else
  char* str = "{\"jsonrpc\": \"2.0\", \"method\": \"subtract\", \"params\": "
              "{\"minuend\": 42, \"subtrahend\": 23},  \"id\": 3}";
#endif

  struct json_object* jobj;

  jobj = json_tokener_parse(str);

  if (NULL == jobj) {
    printf("JSON parse error\n");
    return;
  }

  printf("jobj from str:\n---\n%s\n---\n",
         json_object_to_json_string_ext(
           jobj, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY));

  struct json_object* name;
  json_object_object_get_ex(jobj, "params", &name);
  check_type(name);
  printf("pointer %p\n", name);
  printf("string value '%s'\n", json_object_get_string(name));
  printf("int value %d\n", json_object_get_int(name));
  printf("array length value %lu\n", json_object_array_length(name));

  json_object_put(jobj);
  // json_tokener_free(jobj);
  // jobj = json_tokener_parse(request);

  // check method

  // return 0;
}
