int poziom(node *&t, int key)
{
	node *n = t;
	int level = 1;

	while (n != NULL && n->x != key) {
		level++;
		if (key < n->x)
			n = n->left;
		else n = n->right;
	}
	return n ? level : 0;
}