This module will resize uploaded images to be below the set dimensions. It is
not an image style or other presentation layer module. If you want to maintain
the original image you should use
[Image Resize Filter](https://www.drupal.org/project/image_resize_filter) or an
image style. The use case for this module is sites where users may upload very
large images, but you do not want/need to keep the original.

## Related

These modules will allow you to adjust the site of the displayed image while
leaving the original untouched:

 * [Image Resize Filter](https://www.drupal.org/project/image_resize_filter)
 * [Imagecache](https://www.drupal.org/project/imagecache)

## Usage

Simply enable the module and it will begin resizing images when they are
uploaded. It will scan for images above the configured dimensions once a day and
queue them to be resized.

By default this module will resize images to be under 2560x1600. If you want to
change the dimensions it uses then you need to edit your settings.php and set
the following:

```
<?php
  $conf['max_image_size_width'] = 2560;
  $conf['max_image_size_height'] = 1600;
?>
```

## This project has been sponsored by:

**McMurry/TMG**
  McMurry/TMG is a world-leading, results-focused content marketing firm. We
  leverage the power of world-class content — in the form of the broad
  categories of video, websites, print and mobile — to keep our clients’ brands
  top of mind with their customers.  Visit http://www.mcmurrytmg.com for more
  information.
