# Removed boilerplate documentation to prevent misleading reader.

import os.path
import sys
sys.path.insert(1, os.path.abspath(os.environ.get('DOXYREST_ROOT', './')))

project = 'Tree'
copyright = '2020, Aditya Dalmia'
author = 'Aditya Dalmia'
release = '0.1.0-alpha'

master_doc = 'index'

extensions = [
    'doxyrest'  # For conversion between doxygen and sphinx rst input.
]
source_suffix = ".rst"
exclude_patterns = ['page_index.rst']

html_theme = 'sphinx_rtd_theme'
html_theme_path = ['_themes']

primary_domain = 'cpp'
highlight_language = 'c++'
pygments_style = 'friendly'
