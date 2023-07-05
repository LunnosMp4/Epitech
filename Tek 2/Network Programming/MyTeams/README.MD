## Protocol

Here is the protocol used by the server and the client.

### USAGE

* Client:       /command arg1 arg2 ... argN
* Protocol:     CODE_FONCTION BWA arg1 arg2 ... argN\n
* Server:       CODE_RESPONSE BWA MESSAGE BWA arg1 arg2 ... argN\r\n

### EXAMPLE

* Client:       /login Lunnos
* Protocol:     01 BWA Lunnos\n
* Server:       101 BWA Login Successful BWA UUID Lunnos\r\n

### CODE

* CODE_FONCTION: 2 numbers between 01 and 14
* CODE_STATUS: 1: Success, 2: Error, 3: Unauthorized, 4: Unknow
* CODE_RESPONSE: CODE_STATUS + CODE_FONCTION

### CODE_FONCTION

* 01: Login
* 02: Logout
* 03: Message
* 04: Send
* 05: Subscribe
* 06: Unsubscribe
* 07: Subscribed
* 08: Use
* 09: User
* 10: Users
* 11: Create
* 12: Info
* 13: List
* 14: Help

**00 is reserved for common response.**
* 200: Bad Request (Wrong arguments)
* 300: Unauthorized (User not logged)