#!/usr/local/bin/Rscript

width.cm <- 16
height.cm <- 4
pdf("ch2-benchmarks-horiz.pdf",
    width = width.cm/2.54,
    height = height.cm/2.54,
    pointsize = 10)
par(mgp = c(2.2,0.45,0),
    tcl = -0.4,
    mar = c(3.3,3.6,1.1,1.1))
plot.new()
legend("center",
       title = "Micro-Benchmarks",
       ncol = 2,
       c("computeBound",
         "computeBoundILP",
         "memoryBound",
         "memoryBoundCacheThrash"),
       pch = 19,
       col = c("black", "red", "green", "blue"),
       bty = "n",
       cex = 1.2,
       x.intersp = 1,
       text.width = 0.33
       )
dev.off()

#
