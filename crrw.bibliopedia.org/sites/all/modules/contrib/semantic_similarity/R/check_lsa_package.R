# $Id: check_lsa_package.R,v 1.2 2010/10/07 01:37:23 benoitborrel Exp $

##
# Check lsa package installed version.
#

# get installed packages
pkgs = noquote(installed.packages())

# if lsa package is installed, get its version, else FALSE
if (is.element("lsa", pkgs)) { pkgs["lsa", "Version"] } else { print(FALSE) }
