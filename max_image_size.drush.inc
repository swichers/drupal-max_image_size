<?php
/**
 * @file
 * Drush file with custom commands.
 */

/**
 * Implements hook_drush_command().
 */
function max_image_size_drush_command() {

  $items['max-image-size'] = array(
    'description' => dt('Process items from the translation queue.'),
    'aliases' => array('mis'),
    'options' => array(
      'queue' => dt('Queue images that need processing.'),
      'process' => dt('Process a batch of images.'),
      'items' => dt('The number of images to process.'),
    ),
    'examples' => array(
      'drush mis --queue' => dt('Queue items to process.'),
      'drush mis --process --items=250' => dt('Processes a batch of 250 items.'),
    ),
  );

  return $items;
}

/**
 * Drush command implementation for dealing with image resizing.
 */
function drush_max_image_size() {


  $queue = drush_get_option('queue', false);
  $process = drush_get_option('process', true);

  if ($queue) {

    $result = max_image_size_queue_unprocessed_images();
    if ($result) {

      drush_log(dt('Discovered @count new files.', array('@count' => $result)), 'ok');
    }
  }

  if ($process) {

    $limit = drush_get_option('items', 200);
    $queue = DrupalQueue::get('max_image_size');
    $queue->createQueue();

    if ('all' == $limit) {

      $limit = $queue->numberOfItems();
    }

    if ($limit > $queue->numberOfItems()) {

      $limit = $queue->numberOfItems();
    }

    for ($i = 0; $i < $limit; $i++) {

      $item = $queue->claimItem();
      drush_log(dt('Processing file id @fid', array('@fid' => $item->data)), 'ok');
      max_image_size_resize_callback($item->data);
      $queue->deleteItem($item);
    }

    drush_log(dt('Processed @count items', array('@count' => $limit)), 'ok');
  }

  return true;
}
