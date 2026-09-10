Hopium
=====================================

https://europazeus.org

What is Hopium?
----------------

Hopium is a decentralised digital currency with near-instant transaction speeds and negligible transaction fees built upon Proof of Stake 3.0 (PoSV3, BPoS) as
introduced by the Hopium development team.

Current Hopium maintenance information is published at https://europazeus.org.

Software
--------

Hopium is the name of open source software which enables the use of this currency. It takes Hopium to the next level by building upon
Bitcoin Core 0.13.2 with some patches from newer Bitcoin Core versions to offer performance enhancements, wider compatibility with third party services and a more advanced base.

For current maintenance and release information, see https://europazeus.org. The maintained source location is https://github.com/Xnuva-Blockchain-Project/Hopium.

Network bootstrap
-----------------

Until fixed-seed discovery is included in maintained clients, a fresh Hopium
node can bootstrap from the project public node:

```ini
addnode=81.130.208.151:22536
```

The address above is the Xnuva Blockchain Project T620 node on a static public
IPv4 address. Only the Hopium P2P port is used; RPC should not be exposed to the
public Internet.

License
-------

Hopium is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

Development branches may contain work that has not completed release
qualification. Maintained release tags identify source states that have
completed the project's release-validation process.

Change log can be found in [CHANGELOG.md](CHANGELOG.md).

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).


Testing
-------

Testing and code review might be the bottleneck for development. Please help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

Maintained releases should complete clean builds, available automated tests and manual release validation before publication.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
