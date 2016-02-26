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

Miniplate is a handler for HTML files.
You can add this to your `.htaccess`.

    AddHandler miniplate .html

## Template file

Miniplate expects a file called `_base.html` to exist in the same directory as the file to be served.
Keywords can be used to point out what content should be injected into it.

**(path)** - Request URI path. This is the `/hello` in `http://www.example.org/hello`.

**(content)** - The content of the filename the request was for.

    <!DOCTYPE html>
    <html>
    <head>
        <title>(path) - My site</title>
    </head>
    <body>
        (content)
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

