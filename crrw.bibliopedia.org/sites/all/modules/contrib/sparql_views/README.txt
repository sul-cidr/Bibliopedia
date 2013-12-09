SPARQL Views module
-------------------
By Lin Clark, lin-clark.com

This module adds:
-  A query plugin for Views to query remote SPARQL endpoints, RDF files, and
   RDFa on Web pages.
-  An entity type, sparql_views_entity, that is used to maintain an internal
   representation of the resource/predicate relationship. Bundles of this entity
   can be created either in code or through Field UI and provide the fields for
   manipulation with Views. The RDF mapping for the fields in the bundle is what
   is used to construct the query.
  
INSTRUCTIONS
------------
1. Enable sparql_views, views_ui, and rdfui.
2. Register an endpoint at admin/structure/sparql_registry.
   Example: DBpedia, http://dbpedia.org/sparql
3. Create namespace prefix mappings for any vocabulary terms you will be using
   at admin/config/services/rdf/namespaces.
   Example: dbpprop:name uses a mapping between the 'dbpprop' prefix and the
   URI 'http://dbpedia.org/property/'.
4. Create a SPARQL Views resource and indicate which endpoints it is available
   in at admin/structure/sparql-views.
   Example: Person, available in DBpedia.
5. Add fields to the resource and give those fields RDF mappings.
   Example: Name field with an RDF mapping of dbpprop:name.
6. Add a new view at admin/structure/views/add, selecting the endpoint's
   SPARQL Views view type in the drop down. Continue & edit.
7. Add fields, filters, etc.

SUGGESTED VIEWS CONFIGURATION
-----------------------------
In the Settings tab:
-  Uncheck 'Automatically update preview on changes'
-  Check 'Show the SQL Query'

HONOR ROLL
----------
Thank you to:
-  Remon Georgy (http://drupal.org/user/143827) for the idea to use an internal
   representation of the remote resources.
-  Stéphane 'scor' Corlosquet (http://drupal.org/user/52142) for user testing,
   documentation, and patches.
-  Matthias 'netsensei' Vandermaesen (http://drupal.org/user/350460) for patches
   to the original SPARQL Views and brainstorming.
-  Laura 'laura s' Scott (http://drupal.org/user/18973) for UI help on the
   Drupal 6 version.
-  Mark Birbeck (http://drupal.org/user/101283) for testing and bug reporting.
-  Google Summer of Code and Drupal's GSOC organizing team for initial support.
-  Everyone who contributed ideas and suggestions in the issue queue and at
   Drupal events.