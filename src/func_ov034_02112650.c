int func_ov034_02112650(int arg0, char *lhsObj, char *rhsObj)
{
    volatile char scratch[0x10];
    int rhs;
    int lhs = *(int *)(lhsObj + 0x10);

    (void)scratch;
    arg0 = *(int *)(rhsObj + 0xa8);
    rhs = arg0;

    if (rhs < 0 && lhs < 0 && lhs > rhs)
        return 1;
    return 0;
}
