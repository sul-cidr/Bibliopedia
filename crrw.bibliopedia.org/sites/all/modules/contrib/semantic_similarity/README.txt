# $Id: README.txt,v 1.3 2011/01/30 01:34:21 benoitborrel Exp $

Semantic Similarity README


CONTENTS OF THIS FILE
----------------------

  * Overview
  * Features
  * Background technologies
  * Installation (see INSTALL.txt)
  * Usage
  * Notes


OVERVIEW
--------

Semantic Similarity automatically computes the semantic similarity scores
between each node, which helps to detect duplicate (high scores) or
complementary (medium scores) content.


FEATURES
--------

  * computes scores at cron time
  * provides blocks [1] on node page to display a node's most/least semantically
    similar nodes
  * provides a page [2] that list most/least semantically similar nodes
  * integrated with Views
  * supports English only


BACKGROUND TECHNOLOGIES
-----------------------

These scores are computed by integrating Drupal with the R Project for
Statistical Computing [3] and its Latent Semantic Analysis package. The semantic
similarity scores, obtained from a Latent Semantic Analysis algorithm [4] a well
established one in text mining, is an effective measure of semantic relatedness
[5].

Semantic Similarity module utilizes advanced text mining. It offers a truly
semantic approach that applies the Latent Semantic Analysis (LSA) algorithm to
approximate the meaning of nodes, thereby exposing semantic structure to
computation. LSA combines the classical vector-space model — well known in
computational linguistics — with a Singular Value Decomposition (SVD, [6]), a
two-mode factor analysis. Thus, bag-of-words representations of nodes can be
mapped into a modified vector space that is assumed to reflect semantic
structure. The module then computes the distance amongst the vectors. This
distance is in fact a measure of semantic relatedness between texts.

The algorithm, segmented in 3 steps (pre-process, process and post-process) and
simply configurable, permits to choose between 2400 combinaisons of factors,
allowing the user (with proper permissions) to fine tune the relevancy of the
scores.


INSTALLATION
------------

See INSTALL.txt.


USAGE
-----

The nodes semantic similarity scores are automatically computed at cron time
(must be system root/administrator).

The node's scores are on-the-fly deleted from database upon node delete
operation.


NOTES
-----

1. Both provided by the module default view or the module. The module block has
   a nice radial map but not the view one.
2. By the module default view.
3. http://www.r-project.org
4. http://en.wikipedia.org/wiki/Latent_semantic_analysis
5. http://en.wikipedia.org/wiki/Semantic_relatedness
6. http://en.wikipedia.org/wiki/Singular_value_decomposition
