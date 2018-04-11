#!/usr/local/bin/Rscript

width.cm <- 17
height.cm <- 5
pdf("ch2-datasets-horiz.pdf",
    width = width.cm/2.54,
    height = height.cm/2.54,
    pointsize = 10)
par(mgp = c(2.2,0.45,0),
    tcl = -0.4,
    mar = c(3.3,3.6,1.1,1.1))
plot.new()
legend("center",
       title = "Data Sets",
       ncol = 4,
       c("Enzo-1M",
         "REnzo-1M",
         "Enzo-10M",
         "REnzo-10M",
         "Nek5000",
         "RNek5000",
         "Enzo-80M",
         "REnzo-80M"),
       pch = 19,
       col = rainbow(8),
       bty = "n",
       cex = 1.2,
       x.intersp = 1
       #text.width = 0.33
       )
dev.off()

#
