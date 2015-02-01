Checkmail
=========

Checkmail checks a POP3 or IMAP email account and reports statistics about the
mailbox.

This is the Backdrop port of the Drupal module that is here:
https://www.drupal.org/project/checkmail

The statistics it prints are one or more of the following: the total number of
email messages in the INBOX, the number of recent (new) email messages (IMAP
only), the number of unread email messages (IMAP only), the total size of the
email messages in the mailbox.

NOTE: If you turn off the cache setting for the block, it will query the
email server on every page load where the block is displayed. It is a good
idea to configure the block to display on only certain pages and/or confirm
with the mail server administrator the amount of use you expect. The default
cache expiration before re-checking the server is 1 minute.

This module can encrypt the login password(s), if you are using either the AES
encryption (https://drupal.org/project/aes) or Encryption
(https://drupal.org/project/encrypt) modules. If you choose not to use either of
them, your passwords will not be encrypted, so that if your server is
compromised, the attacker could have access to your plaintext password(s).


Requirements
------------

- Permission to use the fsockopen() and other socket functions in PHP.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

Configuration
-------------

There are several configuration options to set:

- General Settings:


###- Server Settings:
####  - POP3 email server: Enter your email server address: mail.example.com
  - POP3 email port: Enter the connection port, used to get access to the mail
    server. If you don't know what this is, leave the default configuration for
    port 110.
  - POP3 email username: The login ID of the email account being checked.
  - POP3 email password: The password for the above account.


- Authentication Settings:


- Log In Settings


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

Current Maintainers
-------------------

Jason Flatt (https://github.com/oadaeh)

Credits
-------
The module was originally created for Drupal by Stefan Nagtegaal
(http://drupal.org/user/612), and later updated by Kristjan Jansen
(http://drupal.org/user/11), and then again by David Kent Norman
(http://drupal.org/user/972).
