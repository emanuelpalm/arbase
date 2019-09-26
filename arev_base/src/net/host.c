#include <arev/net/host.h>

const char *arev_InternetAsCStr(uint8_t internet) {
    switch (internet) {
        case AREV_NET_INTERNET_NONE:
            return "None";
        case AREV_NET_INTERNET_IPV4:
            return "IPv4";
        case AREV_NET_INTERNET_IPV6:
            return "IPv6";
        default:
            return "Invalid";
    }
}

const char *arev_TransportAsCStr(uint8_t transport) {
    switch (transport) {
        case AREV_NET_TRANSPORT_NONE:
            return "None";
        case AREV_NET_TRANSPORT_TCP:
            return "TCP";
        default:
            return "Invalid";
    }
}