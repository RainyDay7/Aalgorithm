void Levelorder(TreeNode *T)//层次遍历
{
	if (!T)
		return;
	TreeNode *temp;
	queue<TreeNode*>q;
	q.push(T);
	while (!q.empty())
	{
		temp = q.front();
		cout << temp->val;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
		q.pop();
	}
}
void DeepOrder(TreeNode *T)//深度遍历
{
	if (!T)
		return;
	TreeNode *temp;
	stack<TreeNode*>s;
	s.push(T);
	while (!s.empty())
	{
		temp = s.top();
		cout << temp->val;
		s.pop();
		if (temp->left)
			s.push(temp->left);
		if (temp->right)
			s.push(temp->right);
	}
}


