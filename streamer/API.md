# API

## JSON RPC

This is LWS plugin

struct api_jsonrpc_method {
	char *name;
	void *instance;
	func (*instance, json_params);
};

api_jsonrpc(json_request) { //This func called from transport
	//parse json request
	//find method (route)
	//extract json params
	//call api_jsonrpc_create_source(json_params)
	//handle return
}

## Lua

struct api_lua_method {
	char *name;
	void *instance;
	func (*instance, lua_state);
};

api_lua_register_method(struct api_lua_method method) {
	//register method
}

## Module

module_init_by_config(*config, *log) {}


module_api_jsonrpc_create_source(*instance, json_params) {
        //parse params json
        //convert params to c_params
        //call api_create_source(c_params)
        //handle return
}

module_api_lua_create_source(*instance, lua_state) {
        //parse params from lua stack
        //convert params to c_params
        //call api_create_source(c_params)
        //handle return
}

module_api_create_source(*instance, c_params) {
	//check param validity
	//do action	
}


## Ideas

Layers:
	C
		JSON RPC
		LUA

Transport (for JSON RPC):
	HTTP (http://ip:port/api)
	MQTT (???)
	Websockets (???)
	UDS (???)
	Webrtc datachannel (???)		



/v1/system

/v1/debug

/v1/source/list

## Sources

Common api

	RAW (???)
	ENC_H264
	ENC_H265
	ENC_MJPEG

	ENC_OPUS
	ENC_AAC

One time jpeg encoder ???

## Platforms

Have independent uniq api

/v1/hi3516cv100
/v1/[platform]


Streamers:
	RTP
	RTSP/RTP
	Webrtc
	RTMP push
	HTTP
	Websockets

## Updates

http://ip:port/api/v1/update JSON RPC
http://ip:port/update HTTP FORM DATA
