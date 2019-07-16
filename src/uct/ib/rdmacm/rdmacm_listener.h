/**
* Copyright (C) Mellanox Technologies Ltd. 2019.  ALL RIGHTS RESERVED.
*
* See file LICENSE for terms.
*/

#include <uct/base/uct_cm.h>
#include "rdmacm_def.h"

/**
 * An rdmacm listener for incoming connections requests on the server side.
 */
typedef struct uct_rdmacm_listener {
    uct_listener_t                       super;

    /** The rdmacm id assiciated with the listener */
    struct rdma_cm_id                    *id;

    /** Callback to invoke upon receving a connection request from a client */
    uct_listener_conn_request_callback_t conn_request_cb;

    /** User's data to be passed as argument to the conn_request_cb */
    void                                 *user_data;
} uct_rdmacm_listener_t;


UCS_CLASS_DECLARE(uct_rdmacm_listener_t, uct_cm_h, const struct sockaddr *,
                  socklen_t, const uct_listener_params_t *);
UCS_CLASS_DECLARE_NEW_FUNC(uct_rdmacm_listener_t, uct_listener_t,
                           uct_cm_h , const struct sockaddr *, socklen_t ,
                           const uct_listener_params_t *);
UCS_CLASS_DECLARE_DELETE_FUNC(uct_rdmacm_listener_t, uct_listener_t);