/*	$Id: login.h,v 1.0 2020/03/29 15:20:40 despair Exp $ */
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

#pragma once

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

/*
 * The elements in our template file.
 * The element key names are in the "templs" array.
 * See sendtemplate() for how this is used.
 */
enum index_templ {
	TEMPL_TITLE,
	TEMPL_NAME,
	TEMPL_REMOTE_ADDR,
	LOGIN_TEMPL__MAX
};

