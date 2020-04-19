/*	$Id: app.h,v 1.0 2020/03/29 15:20:40 despair Exp $ */
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

/*
 * Minecart admin panel web app
 * Assuming localhost/cgi-bin, the script is localhost/cgi-bin/admin.
 * kfcgi is a fastcgi wrapper for this app to use with nginx or other
 * non-cgi web server, much like openbsd's slowcgi(8).
 * This webapp will be deployed on a Sun, so we need a fcgi wrapper of
 * some kind.
 * Current URI routes:
 *   - /cgi-bin/admin/index
 *   - /cgi-bin/admin/login
 */

#ifndef APP_H
#define APP_H

/* Recognised URI routes.  See pages[] in main.c. */
enum page {
	PAGE_INDEX, /* this shows _behind_ the login page */
	PAGE_LOGIN,
	PAGE__MAX
};

/* web app api routes: for each route in page[], add a route handler here and in
 * handlers[] (main.c)
 */
void sendindex(struct kreq *);
void sendlogin(struct kreq *);

/* a utility function */
void resp_open(struct kreq *req, enum khttp http);

/*
 * We need a structure because we can't get the "r" from the request.
 * This is used by our template callback.
 */
struct tstrct {
	struct khtmlreq req;
	struct kreq *r;
};

/*
 * The elements in our template files.
 * The element key names are in the "templs" array.
 * See sendtemplate() for how this is used.
 */
enum template_fields {
	TEMPL_TITLE,
	TEMPL_NAME,
	TEMPL_REMOTE_ADDR,
	TEMPL__MAX
};

/*
 * We'll use this to route pages by creating an array indexed by our
 * page.
 * Then when the page is parsed, we'll route directly into it.
 */
typedef void (*route_handler)(struct kreq *);

#endif /* APP_H */

