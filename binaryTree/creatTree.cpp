tree *creat(char *xian,char *zhong,int len){///先序中序建二叉树
    tree *t=new tree;
    if(len<=0)return NULL;
    t->data=*xian;
    char *p;
    for(p=zhong;p<zhong+len;p++)
        if(*p==*xian)break;
    int k=p-zhong;
    t->l=creat(xian+1,zhong,k);
    t->r=creat(xian+k+1,p+1,len-k-1);
    return t;
}
 
tree *rcreat(char *zhong,char *hou,int len){///中序后序建二叉树
    tree *t=new tree;
    if(len<=0)return NULL;
    t->data=*(hou+len-1);
    char *p;
    for(p=zhong;p<zhong+len;p++)
        if(*p==*(hou+len-1))break;
        int k=p-zhong;
    t->l=rcreat(zhong,hou,k);
    t->r=rcreat(zhong+k+1,hou+k,len-k-1);
return t;
}

tree *_creat(tree *t){///带','建二叉树
    t=new tree;
    char x=shu[q++];
    if(x==',')t=NULL;
    else {
        t->data=x;
        t->l=_creat(t->l);
        t->r=_creat(t->r);
    }
return t;
}
