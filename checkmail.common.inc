<?php

/**
 * @file
 * This file contains common functionality used in multiple files.
 */

/**
 * Encrypts a user's password.
 *
 * This function gives the option of not encrypting, by simply returning the
 * password, if the Encrypt (http://drupal.org/project/encrypt) module is not
 * installed.
 *
 * @param string $password
 *   The password to encrypt.
 *
 * @return string
 *   The encrypted password.
 */
function _checkmail_encrypt_password($password) {
  $config = config('checkmail.settings');
  if ($config->get('checkmail_use_encryption') === 1) {
    if (module_exists('encrypt')) {
      $password = encrypt($password);
    }
  }
  return $password;
}

/**
 * Decrypts a user's password.
 *
 * This function gives the option of not decrypting, by simply returning the
 * password, if the Encrypt (http://drupal.org/project/encrypt) module is not
 * installed.
 *
 * @param string $password
 *   The password to decrypt.
 *
 * @return string
 *   The decrypted password.
 */
function _checkmail_decrypt_password($password) {
  $config = config('checkmail.settings');
  if ($config->get('checkmail_use_encryption') === 1) {
    if (module_exists('encrypt')) {
      $password = decrypt($password);
    }
  }
  return $password;
}
