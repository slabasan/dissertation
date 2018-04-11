SHELL = /bin/sh

all: LabasanDissertation.pdf

LabasanDissertation.pdf: *.tex sections/*.tex *.bib sections/chapter*/*.inc
	pdflatex LabasanDissertation.tex
	bibtex LabasanDissertation
	touch LabasanDissertation.tex
	pdflatex LabasanDissertation.tex
	pdflatex LabasanDissertation.tex

clean:
	if (rm -f *.pdf *.lof *.lot *.out *.log *.aux *.bbl *.blg *.toc *.dvi *.ps *.brf *.lbl sections/*.aux) then :; fi

