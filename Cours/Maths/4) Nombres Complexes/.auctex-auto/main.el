(TeX-add-style-hook
 "main"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "inputenc"
    "amsfonts"
    "amssymb"
    "amsmath")
   (LaTeX-add-environments
    "defi"
    "form"))
 :latex)

