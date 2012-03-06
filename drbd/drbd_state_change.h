#ifndef DRBD_STATE_CHANGE_H
#define DRBD_STATE_CHANGE_H

struct drbd_resource_state_change {
	struct drbd_resource *resource;
	enum drbd_role role[2];
	bool susp[2];
	bool susp_nod[2];
	bool susp_fen[2];
};

struct drbd_device_state_change {
	struct drbd_device *device;
	enum drbd_disk_state disk_state[2];
};

struct drbd_connection_state_change {
	struct drbd_connection *connection;
	enum drbd_conn_state cstate[2];
	enum drbd_role peer_role[2];
};

struct drbd_peer_device_state_change {
	struct drbd_peer_device *peer_device;
	enum drbd_disk_state disk_state[2];
	enum drbd_repl_state repl_state[2];
	bool resync_susp_user[2];
	bool resync_susp_peer[2];
	bool resync_susp_dependency[2];
};

struct drbd_state_change {
	unsigned int n_devices;
	unsigned int n_connections;
	struct drbd_resource_state_change resource[1];
	struct drbd_device_state_change *devices;
	struct drbd_connection_state_change *connections;
	struct drbd_peer_device_state_change *peer_devices;
};

extern struct drbd_state_change *remember_state_change(struct drbd_resource *, gfp_t);
extern void forget_state_change(struct drbd_state_change *);

#endif  /* DRBD_STATE_CHANGE_H */
