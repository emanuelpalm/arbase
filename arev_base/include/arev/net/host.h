#ifndef AREV_NET_HOST_H
#define AREV_NET_HOST_H

#include <stdint.h>

#define AREV_NET_ADDRESS_SIZE 16

/// Supported internet layer protocols.
enum {
    AREV_NET_INTERNET_NONE = (uint8_t) 0,
    AREV_NET_INTERNET_IPV4,
    AREV_NET_INTERNET_IPV6,
};

/// Supported transport layer protocols.
enum {
    AREV_NET_TRANSPORT_NONE = (uint8_t) 0,
    AREV_NET_TRANSPORT_TCP,
};

/// A network host.
typedef struct {
    /// Internet layer protocol used to communicate with host.
    uint8_t internet;

    /// Transport layer protocol used to communicate with host.
    uint8_t transport;

    /// Host address.
    uint8_t address[AREV_NET_ADDRESS_SIZE];

    /// Host port.
    uint16_t port;
} arev_Host;

/// Returns C-string representation of given internet protocol identifier.
const char *arev_InternetAsCStr(uint8_t internet);

/// Returns C-string representation of given transport protocol identifier.
const char *arev_TransportAsCStr(uint8_t transport);

#endif
