//894 Kiểm tra cây nhị phân T có phải là "cây nhị phân tìm kiếm" hay không?
//0 là cây nhị phân
//1 ko phải là cây nhị phân
void TimMax(Tree c, int &Max)
{
    if (c==NULL)
        return ;
    if (c->pLeft != NULL)
        Max = (Max > c->pLeft->iX)? Max : c->pLeft->iX;
    if (c->pRight != NULL)
        Max = (Max > c->pRight->iX)? Max : c->pRight->iX;
    Max = (Max > c->iX) ? Max : c->iX;
    TimMax(c->pLeft,Max);
    TimMax(c->pRight,Max);
}

int KiemTra(Tree c)
{
    if (c==NULL)
        return 0;
    int Left = KiemTra(c->pLeft);
    int MaxL, MaxR;
    if (c->pLeft != NULL && c->pRight != NULL)
    {
        TimMax(c->pLeft, MaxL);
        TimMax(c->pRight, MaxR);
        if (!(MaxL < c->iX && c->iX < MaxR))
            return 1;
    }
    else if (c->pLeft == NULL && c->pRight != NULL)
    {
        TimMax(c->pRight, MaxR);
        if (!(c->iX < MaxR))
            return 1;
    }
    else if (c->pLeft != NULL && c->pRight == NULL)
    {
        TimMax(c->pLeft, MaxL);
        if (!(MaxL < c->iX))
            return 1;
    }
    int Right = KiemTra(c->pRight);
    return Left + Right;
}
void XuatKqKiemTra(Tree c)
{
    int Kt = KiemTra(c);
    if (Kt == 0)
        printf("nla cay nhi phan tim kiem");
    else
        printf("nko phai cay nhi phan tim kiem");
}
