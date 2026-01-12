#ifndef PROXY_H_INCLUDED
#define PROXY_H_INCLUDED

#include <string>
#include <vector>

#include "utils/tribool.h"

using String = std::string;
using StringArray = std::vector<String>;

enum class ProxyType {
    Unknown,
    Shadowsocks,
    ShadowsocksR,
    VMess,
    Trojan,
    Snell,
    HTTP,
    HTTPS,
    SOCKS5,
    WireGuard,
    VLESS,
    Hysteria,
    Hysteria2,
    TUIC,
    AnyTLS
};

inline String getProxyTypeName(ProxyType type) {
    switch (type) {
        case ProxyType::Shadowsocks:
            return "SS";
        case ProxyType::ShadowsocksR:
            return "SSR";
        case ProxyType::VMess:
            return "VMess";
        case ProxyType::Trojan:
            return "Trojan";
        case ProxyType::Snell:
            return "Snell";
        case ProxyType::HTTP:
            return "HTTP";
        case ProxyType::HTTPS:
            return "HTTPS";
        case ProxyType::SOCKS5:
            return "SOCKS5";
        case ProxyType::WireGuard:
            return "WireGuard";
        case ProxyType::VLESS:
            return "Vless";
        case ProxyType::Hysteria:
            return "Hysteria";
        case ProxyType::Hysteria2:
            return "Hysteria2";
        case ProxyType::TUIC:
            return "Tuic";
        case ProxyType::AnyTLS:
            return "AnyTLS";
        default:
            return "Unknown";
    }
}

struct Proxy {
    ProxyType Type = ProxyType::Unknown;
    uint32_t Id = 0;
    uint32_t GroupId = 0;
    String Group;
    String Remark;
    String Hostname;
    uint16_t Port = 0;
    String CongestionControl;
    String Username;
    String Password;
    String EncryptMethod;
    String Plugin;
    String PluginOption;
    String Protocol;
    String ProtocolParam;
    String OBFS;
    String OBFSParam;
    String UserId;
    uint16_t AlterId = 0;
    String TransferProtocol;
    String FakeType;
    String AuthStr;

    bool TLSSecure = false;

    String Host;
    String Path;
    String Edge;

    String QUICSecure;
    String QUICSecret;

    tribool UDP;
    tribool XUDP;
    tribool TCPFastOpen;
    tribool AllowInsecure;
    tribool TLS13;

    uint16_t SnellVersion = 0;
    String ServerName;

    String SelfIP;
    String SelfIPv6;
    String PublicKey;
    String PrivateKey;
    String PreSharedKey;
    StringArray DnsServers;
    uint16_t Mtu = 0;
    String AllowedIPs = "0.0.0.0/0, ::/0";
    uint16_t KeepAlive = 0;
    String TestUrl;
    String ClientId;
    String Ports;
    String Auth;
    String Alpn;
    String UpMbps;
    String DownMbps;
    String Insecure;
    String Fingerprint;
    String OBFSPassword;
    String GRPCServiceName;
    String GRPCMode;
    String ShortId;
    String Flow;
    String Encryption;
    bool FlowShow = false;
    tribool DisableSni;
    tribool ReduceRtt;
    String UdpRelayMode = "native";
    uint16_t RequestTimeout = 15000;
    String token;
    std::vector<String> AlpnList;
    String PacketEncoding;

    // SMUX 多路复用
    tribool SmuxEnabled;
    String SmuxProtocol;              // smux/yamux/h2mux
    uint32_t SmuxMaxConnections = 0;
    uint32_t SmuxMinStreams = 0;
    uint32_t SmuxMaxStreams = 0;
    tribool SmuxPadding;
    tribool SmuxStatistic;
    tribool SmuxOnlyTcp;

    // ECH (Encrypted Client Hello)
    tribool EchEnabled;
    String EchConfig;

    // 端口跳跃 (Port Hopping)
    String Mport;                     // 端口范围
    uint32_t HopInterval = 0;         // 跳跃间隔 (ms)

    // HTTP Upgrade / WebSocket 增强
    tribool V2rayHttpUpgrade;
    tribool V2rayHttpUpgradeFastOpen;
    uint32_t WsMaxEarlyData = 0;
    String WsEarlyDataHeaderName;

    // mTLS 双向认证
    String Ca;                        // CA 证书路径
    String CaStr;                     // CA 证书内容
    String Certificate;               // 客户端证书
    String PrivateKeyPem;             // PEM 格式私钥
    String ClientFingerprint;         // 客户端 TLS 指纹

    // Hysteria2 增强
    uint32_t UpSpeed = 0;
    uint32_t DownSpeed = 0;
    uint32_t RecvWindowConn = 0;
    uint32_t RecvWindow = 0;
    tribool DisableMtuDiscovery;
    uint32_t CWND = 0;

    // TUIC 增强
    uint64_t InitialStreamReceiveWindow = 0;
    uint64_t MaxStreamReceiveWindow = 0;
    uint64_t InitialConnectionReceiveWindow = 0;
    uint64_t MaxConnectionReceiveWindow = 0;
    uint32_t MaxUdpRelayPacketSize = 0;
    uint32_t MaxDatagramFrameSize = 0;
    uint32_t MaxOpenStreams = 0;
    uint32_t IdleSessionCheckInterval = 0;
    uint32_t IdleSessionTimeout = 0;
    uint32_t MinIdleSession = 0;
    uint32_t UdpMtu = 0;

    // 其他 mihomo 参数
    String IpVersion;                 // auto/4/6
    tribool UdpOverTcp;
    uint32_t UdpOverTcpVersion = 0;
    String UnderlyingProxy;           // 链式代理
    String HeartbeatInterval;
    tribool FastOpen;
    String SNI;                       // 显式 SNI 字段

    // Trojan SS 混淆
    String TrojanSsMethod;
    String TrojanSsPassword;

    // VLESS 增强
    tribool GlobalPadding;
    tribool AuthenticatedLength;
    tribool PacketAddr;
};

#define SS_DEFAULT_GROUP "SSProvider"
#define SSR_DEFAULT_GROUP "SSRProvider"
#define V2RAY_DEFAULT_GROUP "V2RayProvider"
#define SOCKS_DEFAULT_GROUP "SocksProvider"
#define HTTP_DEFAULT_GROUP "HTTPProvider"
#define TROJAN_DEFAULT_GROUP "TrojanProvider"
#define SNELL_DEFAULT_GROUP "SnellProvider"
#define WG_DEFAULT_GROUP "WireGuardProvider"
#define XRAY_DEFAULT_GROUP "XRayProvider"
#define HYSTERIA_DEFAULT_GROUP "HysteriaProvider"
#define HYSTERIA2_DEFAULT_GROUP "Hysteria2Provider"
#define TUIC_DEFAULT_GROUP "TuicProvider"
#define ANYTLS_DEFAULT_GROUP "AnyTLSProvider"

#endif // PROXY_H_INCLUDED
