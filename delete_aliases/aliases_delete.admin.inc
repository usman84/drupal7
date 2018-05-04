<?php

/**
 * @file
 * Admin page callbacks for the Aliases Delete module.
 *
 * @ingroup aliases_delete
 */

/**
 * Menu callback; select certain alias types to delete.
 */
function aliases_delete_delete_specific() {

  $form['specific'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose specific aliases to delete'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  // Iterate over an array of objects/alias types which can be deleted and provide checkboxes
  $objects = module_invoke_all('path_alias_types');
  foreach ($objects as $internal_name => $label) {
    $internal_name = substr($internal_name, 0, -1);
    $count = db_query("SELECT count(1) FROM {url_alias} WHERE source LIKE :src", array(':src' => "$internal_name%"))->fetchField();
    $form['specific'][$internal_name] = array(
      '#type' => 'checkbox',
      '#title' => $label, // This label is sent through t() in the hard coded function where it is defined
      '#default_value' => FALSE,
      '#description' => t('Delete aliases for all @label. Number of aliases which will be deleted: %count.', array('@label' => $label, '%count' => $count)),
    );

    switch ($internal_name) {
      case 'node':
        $form['specific']['content_types'] = array(
          '#type' => 'fieldset',
          '#title' => t('All Content Types'),
        );
        $content_types = node_type_get_types();
        foreach ($content_types as $c_key => $c_value) {
          $form['specific']['content_types'][$c_key] = array(
            '#type' => 'checkbox',
            '#title' => $c_value->name, // This label is sent through t() in the hard coded function where it is defined
            '#default_value' => FALSE,
            '#description' => t('Delete all aliases for all nodes type of @label.', array('@label' => $c_value->name)),
          );
        }
        break;

      case 'taxonomy/term':
        $form['specific']['taxonomies'] = array(
          '#type' => 'fieldset',
          '#title' => t('All Taxonomies'),
        );
        $vocabulary = taxonomy_get_vocabularies();
        foreach ($vocabulary as $v_value) {
          $form['specific']['taxonomies'][$v_value->machine_name] = array(
            '#type' => 'checkbox',
            '#title' => $v_value->name, // This label is sent through t() in the hard coded function where it is defined
            '#default_value' => FALSE,
            '#description' => t('Delete all aliases for all nodes type of @label.', array('@label' => $v_value->name)),
          );
        }
        break;

      case 'user':
        $form['specific']['user_roles'] = array(
          '#type' => 'fieldset',
          '#title' => t('All User Roles'),
        );
        $roles = user_roles();
        foreach ($roles as $r_value) {
          $form['specific']['user_roles'][$r_value] = array(
            '#type' => 'checkbox',
            '#title' => $r_value, // This label is sent through t() in the hard coded function where it is defined
            '#default_value' => FALSE,
            '#description' => t('Delete all aliases for all nodes type of @label.', array('@label' => $r_value)),
          );
        }
        break;
    }
  }

  return $form;
}
