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
/// \ingroup streamer

#include "jpeg.h"

#if 0
/*! @file
    @brief HTTP JPEG serving

    @ingroup http
*/

#include "http.h"

#include "openhisiipcam.h"


extern openhisiipcam *ohic;


int http_callback_jpeg(
		struct lws *wsi,
		enum lws_callback_reasons reason,
            	void *user,
		void *in,
		size_t len) {

#define BUF_SIZE 2048

    uint8_t buf[BUF_SIZE];
    uint8_t *start = &buf[0];
    uint8_t *p = start;
    uint8_t *end = &buf[sizeof(buf) - 1];

    uint32_t sent = 0;

    int i;
    int encoder=-1;

    http_jpeg_session *session = (http_jpeg_session *)user;

    switch (reason) {
        case LWS_CALLBACK_HTTP:

	        for (i=0;i<JPEG_ENCODERS_MAX;i++) {
		        if (ohic->vp.jpeg_encoders[i].state == enabled) {
			        if (ohic->vp.jpeg_encoders[i].last_frame_index != -1) {
				        if (strcmp((const char *)in+1, ohic->vp.jpeg_encoders[i].name) == 0) {
					        encoder = i;
					        break;
				        }
			        }
		        }
	        }
	        //printf("Accodring query %s found encoder %s by index %d\n", (char *)in, ohic->vp.jpeg_encoders[encoder].name, encoder);

	        if (encoder == -1) {
                printf("Corresponding encoder not found!\n");

                if (lws_return_http_status(wsi, HTTP_STATUS_NOT_FOUND, NULL)) {
                    printf("lws_return_http_status\n");
                    return -1;
                }

                if (lws_http_transaction_completed(wsi)) {
                    printf("lws_http_transaction_completed\n");
                    return -1;
                }

		        return -1;
	        } else {

                //printf("start econome send\n");
                //ECONOMY IMPLEMENTATION
                session->encoder = encoder;
		        session->frame = ohic->vp.jpeg_encoders[encoder].last_frame_index;
		        session->size = ohic->vp.jpeg_encoders[encoder].data[session->frame].size;
		        session->sent = 0;
		        session->pts  = ohic->vp.jpeg_encoders[encoder].data[session->frame].pts;

                /*
		        printf("encoder = %d, frame = %d, size = %d, sent = %d, pts = %ld\n",
			            session->encoder,
			            session->frame,
			            session->size,
			            session->sent,
			            session->pts);
                */

        	    if (lws_add_http_common_headers(wsi, HTTP_STATUS_OK,
                                                "image/jpeg",
                                                session->size,
                                                &p, end) ) return -1;

		        //printf("let finalize\n");
        	    if (lws_finalize_write_http_header(wsi, start, &p, end) ) return -1;
        	    lws_callback_on_writable(wsi);

		        //printf("headers sent\n");
	        }
	        return 0;

    case LWS_CALLBACK_HTTP_WRITEABLE:
        //first always check is encoder is in enabled state
        if (ohic->vp.jpeg_encoders[session->encoder].state == enabled) { //if still encoder alive
		    if (ohic->vp.jpeg_encoders[session->encoder].data[session->frame].pts == session->pts) { //if still we point to same frame
		        sent = lws_write(wsi,
			                    (uint8_t *)ohic->vp.jpeg_encoders[session->encoder].data[session->frame].data+session->sent,
				                (session->size - session->sent),
				                LWS_WRITE_HTTP);

			    if (sent < (session->size - session->sent)) {
				    //not all sent
                    printf("Can`t send all answer, plan another send event\n");
				    session->sent += sent;
				    lws_callback_on_writable(wsi);
				    return 0;
			    } else {
                    /*NOTICE: lws_http_transaction_completed: deferring due to partial
                    if (lws_http_transaction_completed(wsi)) {
                            printf("lws_http_transaction_completed\n");
                            return -1;
                        }
                    */
				    return -1;
			    }
            }
        }
        //push frame data to socket
        //if this is first data send, than check are there anything else
        //if sent != size && serving_mode == copy than allocate buffer for rest and save local copy
        //otherwise just sent offset and ask another write attempt

	    //sent = lws_write(wsi, (uint8_t *)fake_image+*offset, BUFSIZE, LWS_WRITE_HTTP);

	    return -1;
	    break;
    default:
	    return 0;
    }
    return 0;
}
#endif

int
jpeg_init(jpeg_params_t* params, jpeg_t* jpeg)
{

  return 0;
}

void
jpeg_deinit(jpeg_t* jpeg)
{}

#if 0
/*! @brief JPEG serving client data
 */
typedef struct
{
  /*
uint8_t *data;///< @brief Pointer to allocated buffer for client copy serving
data (used in copy serving mode). uint8_t encoder;///< @brief Number of encoder.
uint8_t frame;///< @brief Number of frame in encoder`s storage.
uint32_t sent;///< @brief Amount of served (pushed to socket) bytes.
uint32_t size;///< @brief Size of data to be sent, even for economy mode should
be used, as original data can be lost in case of slow client. uint64_t pts;///<
@brief Local copy of serving frame pts value, use it to check that original
storage still has same frame.
*/
} jpeg_lws_session_t;

static int
jpeg_lws_callback(struct lws* wsi,
                  enum lws_callback_reasons reason,
                  void* user,
                  void* in,
                  size_t len)
{
  return 0;
}

struct lws_http_mount
jpeg_lws_mount()
{
  return (struct lws_http_mount){ .mountpoint = "/jpeg",
                                  .mountpoint_len = 5,
                                  .origin_protocol = LWSMPRO_CALLBACK,
                                  .protocol = "jpeg" };
}
struct lws_protocols
jpeg_lws_protocol(jpeg_t* jpeg)
{
  return (struct lws_protocols){ .name = "jpeg",
                                 .callback = jpeg_lws_callback,
                                 .per_session_data_size =
                                   sizeof(jpeg_lws_session_t),
                                 .rx_buffer_size = 0,
                                 .user = jpeg };
}
#endif
