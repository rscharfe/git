static struct combine_diff_path *intersect_paths(struct combine_diff_path *curr, int n, int num_parent)
	int i, cmp;
static char *grab_blob(const struct object_id *oid, unsigned int mode,
		*size = fill_textconv(textconv, df, &blob);
		blob = read_sha1_file(oid->hash, &type, size);
	if (5 < len && !memcmp("@@ -", line, 4)) {
		if (parse_hunk_header(line, len,
				      &state->ob, &state->on,
				      &state->nb, &state->nn))
			return;
		state->lno = state->nb;
		if (state->nn == 0) {
			/* @@ -X,Y +N,0 @@ removed Y lines
			 * that would have come *after* line N
			 * in the result.  Our lost buckets hang
			 * to the line after the removed lines,
			 *
			 * Note that this is correct even when N == 0,
			 * in which case the hunk removes the first
			 * line in the file.
			 */
			state->lost_bucket = &state->sline[state->nb];
			if (!state->nb)
				state->nb = 1;
		} else {
			state->lost_bucket = &state->sline[state->nb-1];
		}
		if (!state->sline[state->nb-1].p_lno)
			state->sline[state->nb-1].p_lno =
				xcalloc(state->num_parent,
					sizeof(unsigned long));
		state->sline[state->nb-1].p_lno[state->n] = state->ob;
		return;
	}
static void combine_diff(const struct object_id *parent, unsigned int mode,
	parent_file.ptr = grab_blob(parent, mode, &sz, textconv, path);
	if (xdi_diff_outf(&parent_file, result_file, consume_line, &state,
			  &xpp, &xecfg))
	int abbrev = opt->flags.full_index ? GIT_SHA1_HEXSZ : DEFAULT_ABBREV;
		abb = find_unique_abbrev(elem->parent[i].oid.hash,
	abb = find_unique_abbrev(elem->oid.hash, abbrev);
	if (added)
		dump_quoted_path("--- ", "", "/dev/null",
				 line_prefix, c_meta, c_reset);
	else
		dump_quoted_path("--- ", a_prefix, elem->path,
				 line_prefix, c_meta, c_reset);
	userdiff = userdiff_find_by_path(elem->path);
		textconv = userdiff_get_textconv(userdiff);
		result = grab_blob(&elem->oid, elem->mode, &result_size,
				result = grab_blob(&elem->oid, elem->mode,
						   &result_size, NULL, NULL);
				result = grab_blob(&oid, elem->mode,
			result_size = fill_textconv(textconv, df, &result);
				if (convert_to_git(&the_index, elem->path, result, len, &buf, global_conv_flags_eol)) {
			buf = grab_blob(&elem->parent[i].oid,
			if (!oidcmp(&elem->parent[i].oid,
				     &elem->parent[j].oid)) {
			combine_diff(&elem->parent[i].oid,
	const struct oid_array *parents, struct diff_options *opt)
		int stat_opt = (output_format &
				(DIFF_FORMAT_NUMSTAT|DIFF_FORMAT_DIFFSTAT));
		paths = intersect_paths(paths, i, num_parent);
		paths = find_paths_generic(oid, parents, &diffopts);
		stat_opt = (opt->output_format &
				(DIFF_FORMAT_NUMSTAT|DIFF_FORMAT_DIFFSTAT));
		else if (opt->output_format &
			 (DIFF_FORMAT_NUMSTAT|DIFF_FORMAT_DIFFSTAT))