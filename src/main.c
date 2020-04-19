/*	$Id: main.c,v 1.0 2020/03/29 15:20:40 despair Exp $ */
/*
 * Copyright (c) 2014, 2015, 2017 Kristaps Dzonsons <kristaps@bsd.lv>
 * Copyright (c) 2020 Rick V. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <sys/types.h> /* size_t, ssize_t */
#include <stdarg.h> /* va_list */
#include <stddef.h> /* NULL */
#include <stdint.h> /* int64_t */
#include <stdlib.h>
#include <string.h> /* memset */

#include "kcgi.h"
#include "kcgihtml.h"
#include "app.h"

static const route_handler handlers[PAGE__MAX] = {
	sendindex, /* PAGE_INDEX */
	sendlogin
};

const char *const pages[PAGE__MAX] = {
	"index", /* PAGE_INDEX */
	"login", /* PAGE_LOGIN  */
};

/*
 * Open an HTTP response with a status code and a particular
 * content-type, then open the HTTP content body.
 * You can call khttp_head(3) before this: CGI doesn't dictate any
 * particular header order.
 */
void
resp_open(req, http)
struct kreq *req;
enum khttp http;
{
	enum kmime mime;

	/*
	 * If we've been sent an unknown suffix like '.foo', we won't
	 * know what it is.
	 * Default to an octet-stream response.
	 */
	if (KMIME__MAX == (mime = req->mime))
		mime = KMIME_APP_OCTET_STREAM;

	khttp_head(req, kresps[KRESP_STATUS],
		"%s", khttps[http]);
	khttp_head(req, kresps[KRESP_CONTENT_TYPE],
		"%s", kmimetypes[mime]);
	khttp_body(req);
}

main(argc, argv)
char** argv;
{
	struct kreq r;
	enum kcgi_err er;

	/* Set up our main HTTP context. */
	er = khttp_parse(&r, NULL, 0,
		pages, PAGE__MAX, PAGE_LOGIN);

	if (KCGI_OK != er)
		return(EXIT_FAILURE);

	/*
	 * Accept only GET, POST, and OPTIONS.
	 * Restrict to text/html and a valid page.
	 * If all of our parameters are valid, use a dispatch array to
	 * send us to the page handlers.
	 */

	if (KMETHOD_OPTIONS == r.method) {
		khttp_head(&r, kresps[KRESP_ALLOW],
			"OPTIONS GET POST");
		resp_open(&r, KHTTP_200);
	} else if (KMETHOD_GET != r.method &&
		   KMETHOD_POST != r.method) {
		resp_open(&r, KHTTP_405);
	} else if (PAGE__MAX == r.page ||
		   KMIME_TEXT_HTML != r.mime) {
		resp_open(&r, KHTTP_404);
	} else
		(*handlers[r.page])(&r);

	khttp_free(&r);
	return(EXIT_SUCCESS);
}

