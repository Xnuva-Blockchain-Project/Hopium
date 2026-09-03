Hopium
=============

Setup
---------------------
Hopium is a full-node client and forms part of the backbone of the network. It downloads and stores blockchain history; synchronization time depends on the age of the local chain, available peers, computer performance and network connection.

For current Hopium maintenance and release information, visit [EuropaZeus](https://europazeus.org).

Running
---------------------
The following are some helpful notes on how to run Hopium on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/hopium-qt` (GUI) or
- `bin/hopiumd` (headless)

### Windows

Unpack the files into a directory, and then run hopium-qt.exe.

### OS X

Drag Hopium-Qt.app to your applications folder, and then run Hopium-Qt.

### Need Help?

* Current maintenance information: [EuropaZeus](https://europazeus.org).
* Maintained source location: [Xnuva Blockchain Project / Hopium](https://github.com/Xnuva-Blockchain-Project/Hopium).

Building
---------------------
The following are developer notes on how to build Hopium on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Hopium repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Maintained Source Location](https://github.com/Xnuva-Blockchain-Project/Hopium)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Unit Tests](unit-tests.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Current maintenance information: [EuropaZeus](https://europazeus.org).
* Development source location: [Xnuva Blockchain Project / Hopium](https://github.com/Xnuva-Blockchain-Project/Hopium).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
