# mod_miniplate

## Dependencies

Compiling Apache modules is easiest done with the `apxs` command.

**Debian**

    # apt-get install apache2-dev

**Fedora**

    # dnf install httpd-devel

## Install

The default target in the Makefile will try to build and install the module.
After the installation, the web server must be restarted for the module to be loaded.

    # make
    # service httpd restart 

## Setup

Miniplate a handler for HTML files.
It was designed with MultiViews in mind.
You can add this to your `.htaccess`.

    AddHandler miniplate .html
    Options +MultiViews

## Template file

Miniplate expects a file called `_base.html` to exist in the same directory as the file to be served.
It must contain two occurrences of `%s`. The first is for the title (it's the URI path), the second is where the content will be injected.

    <!DOCTYPE html>
    <html>
    <head>
        <title>%s - My site</title>
    </head>
    <body>
        %s
    </body>
    </html>

## Content file

Files should only hold the content to be injected in the template.
`index.html` could look like this:

    <h1>An article</h1>
    <p>This is some dummy content.</p>

This content file injected into the template above would yield:

    <!DOCTYPE html>
    <html>
    <head>
        <title>/ - My site</title>
    </head>
    <body>
        <h1>An article</h1>
    <p>This is some dummy content.</p>
    </body>
    </html>

