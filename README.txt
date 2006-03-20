Overview
--------

Checkmail.module checks a POP3 mail account and prints the number of mails in your 
INBOX, and the total size of the mails in your mailbox.

WORKS ONLY WITH A POP3 MAIL ACCOUNT!!!

NOTE! If you turn off the cache setting for the block, it will query the POP3
server on every page load where the block is displayed. It is a good idea to
configure the block to display on only certain pages and/or confirm with the
mail server administrator the amount of use you expect. The default cache
expiration before re-checking the server is 60 seconds.

This module does not encrypt your POP3 login information, so if your server is
compromised, the attacker could have access to your plaintext login information.


Configuration
-------------

There are several configuration options to set:

- POP3 email server
Enter your e-mail server address: mail.example.com

- POP3 email port
Enter the connection port, used to get access to the mail server. If you don't know
what this is, leave the default configuration for port 110.

- POP3 email username
- POP3 email password


Requirements
------------

- Drupal version 4.7 or newer
- Permission to use the fsockopen() and other socket functions in PHP

Authors
-------

Stefan Nagtegaal <Stefan at: Sempre-Crescendo.nl>
http://www.Sempre-Crescendo.nl/

David Kent Norman <deekayen at: deekayen {dot} net>
http://deekayen.net/