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

This module can encrypt the login password(s), if you are using Encryption
module. If you choose not to use it, your passwords will not be encrypted, so
that if your server is compromised, the attacker could have access to your plain
text password(s).

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
  - Show the number of messages in the inbox: Check this to include the total
    number of messages in the inbox as part of the display.
  - Show the number of recent (new) messages in the inbox: Check this to include
    the total number of recent (new) messages in the inbox as part of the
    display. NOTE: This only works for IMAP configurations.
  - Show the number of unread messages in the inbox: Check this to include the
    total number of unread messages in the inbox as part of the display. NOTE:
    This only works for IMAP configurations.
  - Show the total size of the mailbox: Check this to include the total size of
    the mailbox as part of the display. NOTE: This only works for POP3
    configurations.

- Server Settings:
  - E-mail server type: Select the type of server, either IMAP or POP3.
  - E-mail server name: Fill in your e-mail server's name (for example,
    mail.example.com).
  - E-mail server port: Fill in your e-mail server's port number. For POP3
    servers, the default is 110. For IMAP servers, the default is 143. If you
    are using a secure connection with SSL, the default for POP3 is 995 and for
    IMAP is 993, but check with your system administer for the correct number
    for your mail server.
  - Secure login: Check this box to make a secure connection to the mail server.
  - Validate certificate: Check this box to validate the certificate, when using
    a secure connection.
  - Encrypt session using SSL: Check this box to use SSL when connecting to the
    server.
  - Encrypt session using TLS: Check this box to use TLS when connecting to the
    server.

- Authentication Settings:
  - Use encryption when saving the user's password. By default, the login
    information is saved in clear text in the data field of the user table.
    Check this box to enable encrypting the passwords before saving them. This
    option requires the Encryption module to be installed.
  - Use additional fields in the user account to collect the login ID and
    password from each user.
  - Use the form fields in the 'Log in settings' fieldset below for the login
    information. (All users allowed access will see the same information.)

- Log In Settings
  - E-mail server log in ID: The login ID of the email account being checked.
  - Password: The password for the above account. NOTE: The password is stored
    in the database, and it is not encrypted.

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
