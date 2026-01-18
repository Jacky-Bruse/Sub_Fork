# subconverter

A powerful utility for converting between various proxy subscription formats.

https://github.com/MetaCubeX/subconverter

## Features

- **Multiple Format Support**: Convert between various proxy subscription formats including Clash, V2Ray, SS, SSR, and more
- **Rule-based Conversion**: Support for custom rules and rule sets
- **RESTful API**: Simple HTTP API for subscription conversion
- **Docker Support**: Easy deployment using Docker
- **Auto Upload**: Optional automatic upload to Gist
- **Customizable**: Extensive configuration options via TOML/YAML/INI files
- **Cross-platform**: Supports Windows, Linux, and macOS

## Table of Contents

- [Quick Start](#quick-start)
- [Docker Deployment](#docker-deployment)
- [Supported Types](#supported-types)
- [Basic Usage](#basic-usage)
- [Advanced Usage](#advanced-usage)
- [Auto Upload](#auto-upload)

## Quick Start

1. Download the latest release from the [releases page](https://github.com/asdlokj1qpi23/subconverter/releases)
2. Extract the archive
3. Run the executable
4. Access the conversion interface at `http://localhost:25500`

## Docker Deployment

### Using Docker Run

```bash
# Run the container detached, forward internal port 25500 to host port 25500
docker run -d --restart=always -p 25500:25500 asdlokj1qpi23/subconverter:latest

# Verify the service is running
curl http://localhost:25500/version
```

### Using Docker Compose

```yaml
version: '3'
services:
  subconverter:
    image: asdlokj1qpi23/subconverter:latest
    container_name: subconverter
    ports:
      - "25500:25500"
    restart: always
```

## Supported Types

| Type                              | As Source | As Target    | Target Name    |
|-----------------------------------|:---------:| :----------: |----------------|
| Clash                             |     ✓     |      ✓       | clash          |
| ClashR                            |     ✓     |      ✓       | clashr         |
| Quantumult                        |     ✓     |      ✓       | quan           |
| Quantumult X                      |     ✓     |      ✓       | quanx          |
| Loon                              |     ✓     |      ✓       | loon           |
| SS (SIP002)                       |     ✓     |      ✓       | ss             |
| SS Android                        |     ✓     |      ✓       | sssub          |
| SSD                               |     ✓     |      ✓       | ssd            |
| SSR                               |     ✓     |      ✓       | ssr            |
| Surfboard                         |     ✓     |      ✓       | surfboard      |
| Surge 2                           |     ✓     |      ✓       | surge&ver=2    |
| Surge 3                           |     ✓     |      ✓       | surge&ver=3    |
| Surge 4                           |     ✓     |      ✓       | surge&ver=4    |
| V2Ray                             |     ✓     |      ✓       | v2ray          |
| Telegram-liked HTTP/Socks 5 links |     ✓     |      ×       | Only as source |
| Singbox                           |     ✓      |      ✓       | singbox        |

Notice:

1. Shadowrocket users should use `ss`, `ssr` or `v2ray` as target.

2. You can add `&remark=` to Telegram-liked HTTP/Socks 5 links to set a remark for this node. For example:

   - tg://http?server=1.2.3.4&port=233&user=user&pass=pass&remark=Example

   - https://t.me/http?server=1.2.3.4&port=233&user=user&pass=pass&remark=Example


---

## Basic Usage

### API Endpoint

```
http://localhost:25500/sub?target={TARGET}&url={URL}&config={CONFIG}
```

### Parameters

| Parameter | Required | Description | Example |
|-----------|:--------:|-------------|----------|
| target | Yes | Target subscription format | clash, v2ray, ss, ssr |
| url | Yes | Source subscription URL (URLEncoded) | https%3A%2F%2Fexample.com%2Fsub |
| config | No | External configuration file URL (URLEncoded) | https%3A%2F%2Fexample.com%2Fconfig.ini |

### Example

To convert a subscription to Clash format:
```
http://localhost:25500/sub?target=clash&url=https%3A%2F%2Fexample.com%2Fsub
```

### Merging Multiple Subscriptions

To merge multiple subscriptions, join them with '|' before URLEncoding:
```
Original URLs:
1. https://sub1.com/sub
2. https://sub2.com/sub

Combined: https://sub1.com/sub|https://sub2.com/sub

URLEncoded: https%3A%2F%2Fsub1.com%2Fsub%7Chttps%3A%2F%2Fsub2.com%2Fsub
```

## Advanced Usage

### Configuration Files

The program supports three configuration file formats:
- TOML (pref.toml)
- YAML (pref.yml)
- INI (pref.ini)

### API Endpoints

| Endpoint | Method | Description |
|----------|--------|-------------|
| /version | GET | Get version information |
| /sub | GET | Convert subscription |
| /refreshrules | GET | Refresh ruleset cache |
| /readconf | GET | Reload configuration |
| /updateconf | POST | Update configuration |

### Environment Variables

| Variable | Description |
|----------|-------------|
| API_MODE | Enable/disable API mode |
| MANAGED_PREFIX | Set managed configuration prefix |
| API_TOKEN | Set access token for protected endpoints |

## Auto Upload

To enable automatic Gist upload:

1. Create a [Personal Access Token](https://github.com/settings/tokens/new)
2. Add the token to `gistconf.ini`:
```ini
[common]
token = your_personal_access_token
```
3. Add `&upload=true` to your subscription URL

## Development

### Building from Source

```bash
git clone https://github.com/asdlokj1qpi23/subconverter.git
cd subconverter
cmake .
make
```

### Requirements

- C++ 17 compatible compiler
- CMake 3.0+
- OpenSSL
- zlib
- curl
- rapidjson
- yaml-cpp

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## Thanks
[tindy2013](https://github.com/tindy2013)
[https://github.com/tindy2013/subconverter](https://github.com/tindy2013/subconverter)
