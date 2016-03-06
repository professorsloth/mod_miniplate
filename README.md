# mod_miniplate

## Dependencies

`mod_miniplate` is designed for and tested on Apache 2.4.

**Debian**

    # apt-get install apache2 apache2-dev

**Fedora**

    # dnf install httpd httpd-devel

## Install

The default target in the Makefile will try to build and install the module.
After the installation, the web server must be restarted for the module to be loaded.

Please note that the default make target compiles *and* installs the module.

    # make
    # service httpd restart 

## Setup

Miniplate is a handler for HTML files.
You can add this to your `.htaccess`.

    AddHandler miniplate .html

## Usage

### Template file

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

### Content file

Files should only hold content that is to be injected in the template.
`index.html` could look like this:

    <h1>An article</h1>
    <p>This is some dummy content.</p>

The above content file injected into the template above yields:

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

## Disabling `mod_miniplate` for subdirectories

Inside the subdirectory where you want to disable `mod_miniplate`, add this to its `.htaccess`.

    RemoveHandler .html

## Licence

`mod_miniplate` uses the license commonly known as the BSD 3-clause license. See file `LICENCE`.
