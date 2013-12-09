# $Id: compute_scores.R,v 1.3 2010/11/11 01:41:28 benoitborrel Exp $

##
# Compute semantic similarity scores between nodes of a given corpus.
#

## get arguments as strings
# 1:corpus path
# 2:scores filename
# 3:stopwords flag (0|1)
# 4:stemming flag (0|1)
# 5:weighting flag (0|1)
# 6:weighting scope (lw|lwgw)
# 7:local weighting scheme (lw_logtf|lw_bintf)
# 8:global weighting scheme (gw_normalisation|gw_idf|gw_gfidf|entropy|gw_entropy)
# 9:lsa flag (0|1)
#10:svd method (share|ndocs|kaiser|raw|fraction)
#11:correlation method (cosine|pearson|spearman)
args <- commandArgs(trailingOnly=TRUE)

# load lsa package from library
library("lsa")

# load english stopwords
if (args[3] == "1") { data(stopwords_en) }

## set corpus textmatrix
# stopwords and/xor/nor stemming?
if ((args[3] == "0") && (args[4] == "0")) {
  tmc <- textmatrix(args[1])
}
if ((args[3] == "0") && (args[4] == "1")) {
  tmc <- textmatrix(args[1], stemming=TRUE)
}
if ((args[3] == "1") && (args[4] == "0")) {
  tmc <- textmatrix(args[1], stopwords=stopwords_en)
}
if ((args[3] == "1") && (args[4] == "1")) {
  tmc <- textmatrix(args[1], stemming=TRUE, stopwords=stopwords_en)
}

# get matrix number of columns, ie documents
nb_col <- ncol(tmc)

# weighting?
if (args[5] == "1") {
  # local and global weighting or just local weighting?
  if (args[6] == "lw") {
    tmc <- do.call(args[7], list(tmc))
  }
  if ((args[6] == "1wgw")) {
    tmc <- do.call(args[7], list(tmc)) * do.call(args[8], list(tmc))
  }
}

# lsa?
if (args[9] == "1") {
  if (args[10] == "share") {
    lsa <- do.call("lsa", list(tmc, dims=dimcalc_share()))
  }
  if (args[10] == "ndocs") {
    lsa <- do.call("lsa", list(tmc, dims=dimcalc_ndocs(nb_col)))
  }
  if (args[10] == "kaiser") {
    lsa <- do.call("lsa", list(tmc, dims=dimcalc_kaiser()))
  }
  if (args[10] == "raw") {
    lsa <- do.call("lsa", list(tmc, dims=dimcalc_raw()))
  }
  if (args[10] == "fraction") {
    lsa <- do.call("lsa", list(tmc, dims=dimcalc_fraction(frac=(1/50))))
  }
  tmc <- as.textmatrix(lsa)
}

# set scores matrix colnames and rownames
scores <- array(0, dim=c(nb_col, nb_col))
text_ids <-list.files(args[1])
colnames(scores) <- text_ids
rownames(scores) <- text_ids

# compute the correlation between each vectors of corpus textmatrix
# and the tested text textmatrix
for (i in 1:nb_col) {
  # set tested text textmatrix
  tmt <- tmc[, i]

  # compute the Pearson or Spearman correlation coefficient
  # between corpus textmatrix texts vectors and tested text vector
  if (args[11] == "Pearson") {
    scores[i, ] <- cor(tmt, tmc, method="pearson")
  }
  if (args[11] == "Spearman") {
    scores[i, ] <- cor(tmt, tmc, method="spearman")
  }
}
# compute the cosine measure
# between corpus textmatrix texts vectors and tested text vector
if (args[11] == "cosine") {
  scores <- cosine(tmc)
}

# export into CSV file
#write.csv2(scores, file = args[2]) # sep=; dec=,
write.csv(scores, file = args[2]) # sep=, dec=.
