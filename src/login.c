/*	$Id: login.c,v 1.48 2020/03/29 15:20:40 despair Exp $ */
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

/*
 * Template key names (as in @@TITLE@@ in the file).
 */
static const char *const template_field_names[TEMPL__MAX] = {
	"title", /* TEMPL_TITLE */
	"name", /* TEMPL_NAME */
	"remote_addr", /* TEMPL_REMOTE_ADDR */
};

/*
 * Callback for filling in a particular template part.
 * Let's just be simple for simplicity's sake.
 */
static
template(key, arg)
size_t key;
void* arg;
{
	struct tstrct *p = arg;

	switch (key) {
	case (TEMPL_TITLE):
		khtml_puts(&p->req, "Minecraft Admin Panel");
		break;
	case (TEMPL_NAME):
		khtml_puts(&p->req, "name");
		break;
	case (TEMPL_REMOTE_ADDR):
		khtml_puts(&p->req, p->r->remote);
		break;
	default:
		return(0);
	}

	return(1);
}

/*
 * Demonstrates how to use templates.
 * Returns HTTP 200 and the template content.
 */
void
sendindex(req)
struct kreq *req;
{
	struct ktemplate t;
	struct tstrct p;

	memset(&t, 0, sizeof(struct ktemplate));
	memset(&p, 0, sizeof(struct tstrct));

	p.r = req;
	t.key = template_field_names;
	t.keysz = TEMPL__MAX;
	t.arg = &p;
	t.cb = template;

	resp_open(req, KHTTP_200);
	khtml_open(&p.req, req, 0);
	khttp_template(req, &t, "templates/index/template.xml");
	khtml_close(&p.req);
}

void
sendlogin(req)
struct kreq *req;
{
	struct ktemplate t;
	struct tstrct p;

	memset(&t, 0, sizeof(struct ktemplate));
	memset(&p, 0, sizeof(struct tstrct));

	p.r = req;
	t.key = template_field_names;
	t.keysz = TEMPL__MAX;
	t.arg = &p;
	t.cb = template;

	resp_open(req, KHTTP_200);
	khtml_open(&p.req, req, 0);
	khttp_template(req, &t, "templates/login/template.xml");
	khtml_close(&p.req);
}

