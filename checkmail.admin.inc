<?php

/**
 * @file
 * The administratice settings for Checkmail.
 */

/**
 * Set administrative configuration options.
 *
 * @return array
 *   The generated form.
 */
function checkmail_admin_settings($form, &$form_state) {
  $config = config('checkmail.settings');

  $form['checkmail_general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );
  $form['checkmail_general_settings']['checkmail_number_of_messages'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show the number of messages in the inbox."),
    '#default_value' => empty($config->get('checkmail_number_of_messages')) ? 1 : $config->get('checkmail_number_of_messages'),
    '#description' => t("Checking this will include the total number of messages in the inbox as part of the display."),
  );
  $form['checkmail_general_settings']['checkmail_number_of_recent_messages'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show the number of recent (new) messages in the inbox."),
    '#default_value' => empty($config->get('checkmail_number_of_recent_messages')) ? 1 : $config->get('checkmail_number_of_recent_messages'),
    '#description' => t("Checking this will include the total number of <em>recent (new)</em> messages in the inbox as part of the display. NOTE: This only works for IMAP configurations."),
  );
  $form['checkmail_general_settings']['checkmail_number_of_unread_messages'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show the number of unread messages in the inbox."),
    '#default_value' => empty($config->get('checkmail_number_of_unread_messages')) ? 1 : $config->get('checkmail_number_of_unread_messages'),
    '#description' => t("Checking this will include the total number of <em>unread</em> messages in the inbox as part of the display. NOTE: This only works for IMAP configurations."),
  );
  $form['checkmail_general_settings']['checkmail_size_of_mailbox'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show the total size of the mailbox."),
    '#default_value' => empty($config->get('checkmail_size_of_mailbox')) ? 1 : $config->get('checkmail_size_of_mailbox'),
    '#description' => t("Checking this will include the total size of the mailbox as part of the display. NOTE: This only works for POP3 configurations."),
  );

  $form['checkmail_server_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Server settings'),
  );
  // Collect basic server information.
  $form['checkmail_server_settings']['checkmail_server_type'] = array(
    '#type' => 'select',
    '#title' => t('E-mail server type'),
    '#default_value' => empty($config->get('checkmail_server_type')) ? 0 : $config->get('checkmail_server_type'),
    '#options' => array(
      'imap' => t('IMAP'),
      'pop3' => t('POP3'),
    ),
  );
  $form['checkmail_server_settings']['checkmail_server_address'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail server name'),
    '#default_value' => empty($config->get('checkmail_server_address')) ? '' : $config->get('checkmail_server_address'),
    '#description' => t("Fill in your e-mail server's name (for example, mail.example.com)."),
    '#required' => TRUE,
  );
  $form['checkmail_server_settings']['checkmail_server_port'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail server port'),
    '#default_value' => empty($config->get('checkmail_server_port')) ? '' : $config->get('checkmail_server_port'),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t("Fill in your e-mail server's port number. For POP3 servers, the default is 110. For IMAP servers, the default is 143. If you are using a secure connection with SSL, the default for POP3 is 995 and for IMAP is 993, but check with your system administer for the correct number for your mail server."),
    '#required' => TRUE,
  );
  // Collect advanced server information.
  $form['checkmail_server_settings']['checkmail_secure_log_in'] = array(
    '#type' => 'checkbox',
    '#title' => t('Secure login'),
    '#default_value' => empty($config->get('checkmail_secure_log_in')) ? 0 : $config->get('checkmail_secure_log_in'),
    '#description' => t('Check this box to make a secure connection to the mail server.'),
  );
  $form['checkmail_server_settings']['checkmail_validate_cert'] = array(
    '#type' => 'checkbox',
    '#title' => t('Validate certificate'),
    '#default_value' => empty($config->get('checkmail_validate_cert')) ? 0 : $config->get('checkmail_validate_cert'),
    '#description' => t('Check this box to validate the certificate, when using a secure connection.'),
  );
  $form['checkmail_server_settings']['checkmail_use_ssl'] = array(
    '#type' => 'checkbox',
    '#title' => t('Encrypt session using SSL'),
    '#default_value' => empty($config->get('checkmail_use_ssl')) ? 0 : $config->get('checkmail_use_ssl'),
    '#description' => t('Check this box to use SSL when connecting to the server.'),
  );
  $form['checkmail_server_settings']['checkmail_use_tls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Encrypt session using TLS'),
    '#default_value' => empty($config->get('checkmail_use_tls')) ? 0 : $config->get('checkmail_use_tls'),
    '#description' => t('Check this box to use TLS when connecting to the server.'),
  );

  // Collect user information.
  $form['checkmail_authentication_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication settings'),
  );
  $disabled = !module_exists('encrypt');
  $form['checkmail_authentication_settings']['checkmail_use_encryption'] = array(
    '#type' => 'checkbox',
    '#title' => t("Use encryption when saving the user's password."),
    '#disabled' => $disabled,
    '#default_value' => empty($config->get('checkmail_use_encryption')) ? 0 :  $config->get('checkmail_use_encryption'),
    '#description' => t("By default, the login information is saved in clear text in the data field of the user table. Check this box to enable encrypting the passwords before saving them. This option requires the !encrypt module.",
      array(
        '!encrypt' => l(t('Encrypt'), 'http://drupal.org/project/encrypt'),
      )
    ),
  );
  $options = array(
    'user_fields' => t('Use additional fields in the user account to collect the login ID and password from each user.'),
    'admin_fields' => t("Use the form fields in the 'Log in settings' fieldset below for the login information. (All users allowed access will see the same information.)"),
  );
  $form['checkmail_authentication_settings']['checkmail_account_info'] = array(
    '#type' => 'radios',
    '#options' => $options,
    '#default_value' => empty($config->get('checkmail_account_info')) ? 'user_fields' : $config->get('checkmail_account_info'),
  );

  $form['checkmail_authentication_settings']['checkmail_option_four'] = array(
    '#type' => 'fieldset',
    '#title' => t('Log in settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['checkmail_authentication_settings']['checkmail_option_four']['checkmail_login_id'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail server log in ID'),
    '#default_value' => empty($config->get('checkmail_login_id')) ? '' : $config->get('checkmail_login_id'),
  );
  $description = '';
  if ($config->get('checkmail_use_encryption') === 0) {
    $description = t('NOTE: The password is stored in the database, and it is not encrypted.');
  }
  $form['checkmail_authentication_settings']['checkmail_option_four']['checkmail_login_password'] = array(
    '#type' => 'password_confirm',
    '#description' => $description,
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Provides extra validation for the administrative settings form.
 *
 * @param array $form
 *   The contents of the form fields.
 * @param array $form_state
 *   The state of the form after submission.
 */
function checkmail_admin_settings_validate($form, &$form_state) {
  if ($form_state['values']['checkmail_account_info'] == 'admin_fields') {
    if ($form_state['values']['checkmail_login_id'] == '') {
      form_set_error('checkmail_login_id', t('You must provide a log in ID.'));
    }
    if ($form_state['values']['checkmail_login_password'] == '') {
      form_set_error('checkmail_login_password', t('You must provide a password.'));
    }
  }
}

/**
 * Provides extra functionality when saving the administrative settings form.
 *
 * @param array $form
 *   The contents of the form fields.
 * @param array $form_state
 *   The state of the form after submission.
 */
function checkmail_admin_settings_submit($form, &$form_state) {
  $config = config('checkmail.settings');

  $config->set('checkmail_number_of_messages', $form_state['values']['checkmail_number_of_messages']);
  $config->set('checkmail_number_of_recent_messages', $form_state['values']['checkmail_number_of_recent_messages']);
  $config->set('checkmail_number_of_unread_messages', $form_state['values']['checkmail_number_of_unread_messages']);
  $config->set('checkmail_size_of_mailbox', $form_state['values']['checkmail_size_of_mailbox']);
  $config->set('checkmail_server_type', $form_state['values']['checkmail_server_type']);
  $config->set('checkmail_server_address', $form_state['values']['checkmail_server_address']);
  $config->set('checkmail_server_port', $form_state['values']['checkmail_server_port']);
  $config->set('checkmail_secure_log_in', $form_state['values']['checkmail_secure_log_in']);
  $config->set('checkmail_validate_cert', $form_state['values']['checkmail_validate_cert']);
  $config->set('checkmail_use_ssl', $form_state['values']['checkmail_use_ssl']);
  $config->set('checkmail_use_tls', $form_state['values']['checkmail_use_tls']);
  $config->set('checkmail_use_encryption', $form_state['values']['checkmail_use_encryption']);
  $config->set('checkmail_account_info', $form_state['values']['checkmail_account_info']);
  $config->set('checkmail_login_id', $form_state['values']['checkmail_login_id']);

  if ($form_state['values']['checkmail_use_encryption'] == 1) {
    module_load_include('inc', 'checkmail', 'checkmail.common');
    $config->set('checkmail_login_password', _checkmail_encrypt_password($form_state['values']['checkmail_login_password']));
  }

  $config->save();
  backdrop_set_message(t('The configuration options have been saved.'));
}
