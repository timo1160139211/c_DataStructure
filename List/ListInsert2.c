Status ListInsert(SqList *L,int i,ElemType e)
{
		int k;
			if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
						return ERROR;
				if (i<1 || i>L->length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
							return ERROR;

					if (i<=L->length)        /* 若插入数据位置不在表尾 */
							{
										for(k=L->length-1; k>=i-1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */
														L->data[k+1] = L->data[k];
											}
						L->data[i-1]=e;          /* 将新元素插入 */
							L->length++;

								return OK;
}
