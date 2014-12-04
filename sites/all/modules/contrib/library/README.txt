Author:  Jess Straatmann
Released under the GPL


Description:
============
This module allows users to manage nodes as assets that may be available or unavailable. Users may create custom content types and then add those content types to the library.

It supports multiple copies of a library item associated with one node, and each copy may be individually made available or unavailable.

The module allows administrators to define their own library actions. Library actions may make an item available, unavailable, or not change an item's status. Every transaction is associated with a Drupal user. If you use the trigger module (part of core) with the library module, each library action generates a trigger that you can assign further actions to. The module includes a few built-in actions (send an email, extend the due date of an item).

To get the full functionality of the module, you should have Triggers enabled.


Requirements:
=============
Drupal 7.x


Installation:
=============
Copy the entire library module directory to your module directory and enable the library module.
After installing the library module, the site administrator needs to enable library functionality on at least one content type.  To add library functionality to a content type, modify the content type settings at admin/structure/types/manage/<type>.  Select 'Yes' for Library Item under Workflow settings.


Library Settings:
=========
Library module settings may be configured at admin/config/workflow/library.  No options are enabled by default, so to see any additional functionality, users will need to modify the settings. Settings include:
#Use unique identifiers (barcodes) on library items
#Display specific actions as options
#Display terms from specific vocabularies in library lists
#Modify status text (e.g. "Available" vs. "IN")
#Enable due date functionality
#Add/rename library actions

The library module comes with two default library actions: 'Check In' and 'Check Out'.  You may rename these and/or create new library actions at admin/settings/library/actions.
Each library action has it's own permission, so access control can be very fine-grained.

Every library action creates an individual trigger if the Trigger module is enabled.  Site administrators may assign further actions to occur with a specific library action (e.g send an email) by assigning them at admin/structure/trigger/library.  Currently, only the library module provided actions are compatible with these triggers.


Functionality Removed from Drupal 6:
====================================
In the interests of maintaining this module, functionality has been reduced/simplified in the following ways:
All CCK-dependent functionality has been removed. This means you may not select certain CCK fields to add to the library items list. Consider using a view instead.
No "unique title check" functionality.  If you would like this functionality, please look at the Unique Field module http://drupal.org/project/unique_field
No library-specific search.  The search API changed in Drupal 7, and the added functionality of a module-specific search is not that great since limiting a search to specific content types is something that can be done in another module or by using the views module with an exposed search field.
No upgrade from Patron module included, so please make sure to upgrade to the latest Drupal 6 version of library before upgrading to Drupal 7.
