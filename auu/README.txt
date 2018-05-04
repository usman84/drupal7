
Auto Unblock Users
--------------

This module was developed to improve the user management for block users. By default
and has only the options to unblock blocked user automatically.

With Auto Unblock Users module, a site administrator may choose the option to unblock
user automatically or not.

These are the features included:

Duration of unblocking
-----------------------
The duration of unblocking user(s) depends on the administer settings of
Login Seceurity module (/admin/config/people/login_security). There is track
option in such setting as "Track time", administrator can also change it.

Please note that Auto Unblock Users will not unblock those users who were blocked
by administrator manually.

A blocked account could be unblocked through the administration section:
  /admin/user/user

Installation
------------
To install the module, download and paste into module directory (/sites/all/modules
or /sites/all/modules/contrib) and extract it
Go to administer module page (/admin/modules) find the module under the "Other" category
Enable and save the configurations.

That's it.

Configuration options
---------------------
You should have the 'administer site configuration' permission to configure the
Login Security module. In the same configuration form, there will a new option will
appear on the top as "Unblock Users Automatically?" check if if its aleady not
and save the configurations.

Its done

Notifications
-------------
 The module also provides some notifications for the users to understand what is
 happening.

 - After unblocking the account automatically, user will see and notification
   that you are unblocked.
 - On that time, adminitrator will have also log to know that someone is unbloked
   bu AUU module.

Thanks
