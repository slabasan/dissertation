#!/usr/local/bin/Rscript

width.cm <- 6
height.cm <- 3
pdf("ch2-concurrency-horiz.pdf",
    width = width.cm/2.54,
    height = height.cm/2.54,
    pointsize = 10)
par(mgp = c(2.2,0.45,0),
    tcl = -0.4,
    mar = c(3.3,3.6,1.1,1.1))
plot.new()
legend("center",
       title = "Concurrency",
       ncol = 4,
       c("1", "2", "3", "4"),
       pch = 19,
       col = c("black", "red", "green", "blue"),
       bty = "n",
       cex = 1.2,
       x.intersp = 1
       #text.width = 0.33
       )
dev.off()

#
