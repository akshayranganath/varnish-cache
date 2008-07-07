/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2008 Linpro AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id$
 *
 * Stuff shared between main.c and fixed_token.c
 */

#include "vcc_token_defs.h"

struct vsb;
struct tokenlist;
struct token;

#define isident1(c) (isalpha(c))
#define isident(c) (isalpha(c) || isdigit(c) || (c) == '_' || (c) == '-')
#define isvar(c) (isident(c) || (c) == '.')
unsigned vcl_fixed_token(const char *p, const char **q);
extern const char *vcl_tnames[256];
void vcl_init_tnames(void);
void vcl_output_lang_h(struct vsb *sb);

#define PF(t)	(int)((t)->e - (t)->b), (t)->b

/* vcc_backend.c */
struct fld_spec;
struct fld_spec * vcc_FldSpec(struct tokenlist *tl, const char *first, ...);
void vcc_ResetFldSpec(struct fld_spec *f);
void vcc_IsField(struct tokenlist *tl, struct token **t, struct fld_spec *fs);
int vcc_FieldsOk(struct tokenlist *tl, const struct fld_spec *fs);
void vcc_ParseBackendHost(struct tokenlist *tl, int *nbh, const struct token *name, const char *qual, int serial);




/* vcc_dir_random.c */
void vcc_ParseRandomDirector(struct tokenlist *tl, struct token *t_dir);

