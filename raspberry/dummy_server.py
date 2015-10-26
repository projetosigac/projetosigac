''' A dummy web server intended to test the proxy application
It prints the request to the console
'''

from wsgiref.util import setup_testing_defaults
from wsgiref.simple_server import make_server

# A relatively simple WSGI application. It's going to print out the
# environment dictionary after being updated by setup_testing_defaults
def simple_app(environ, start_response):
    setup_testing_defaults(environ)

    status = '200 OK'
    headers = [('Content-type', 'text/plain')]

    start_response(status, headers)

    ret = ["%s: %s\n" % (key, value)
           for key, value in environ.iteritems() if
           key in ('REQUEST_METHOD','QUERY_STRING','PATH_INFO','CONTENT_LENGTH')]

    try:
        request_body_size = int(environ['CONTENT_LENGTH'])
        request_body = environ['wsgi.input'].read(request_body_size)
    except (TypeError, ValueError):
        request_body = "0"
    try:
        response_body = str(request_body)
    except:
        response_body = "error"
    
    print(response_body)
    
    return ret

httpd = make_server('', 8000, simple_app)
print "Serving on port 8000..."
httpd.serve_forever()
