
void __thiscall FUN_004aad1d(int param_1,LPRECT param_2,LPRECT param_3)

{
  int iVar1;
  int *piVar2;
  int yBottom;
  int xRight;
  
  piVar2 = (int *)(param_1 + 0x28);
  xRight = *(int *)(param_1 + 0x30) - *piVar2;
  yBottom = *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c);
  param_2->left = *piVar2;
  param_2->top = *(LONG *)(param_1 + 0x2c);
  param_2->right = *(LONG *)(param_1 + 0x30);
  param_2->bottom = *(LONG *)(param_1 + 0x34);
  param_3->left = *piVar2;
  param_3->top = *(LONG *)(param_1 + 0x2c);
  param_3->right = *(LONG *)(param_1 + 0x30);
  param_3->bottom = *(LONG *)(param_1 + 0x34);
  iVar1 = *(int *)(param_1 + 0x170);
  if (iVar1 == 0) {
    SetRect(param_2,0,0,0,0);
  }
  else {
    if ((xRight <= iVar1) || (xRight <= -iVar1)) goto LAB_004aade5;
    if (iVar1 < 0) {
      param_2->left = param_2->left + iVar1 + xRight;
      param_3->right = param_2->left;
    }
    else {
      param_2->right = param_2->right + (iVar1 - xRight);
      param_3->left = param_2->right;
    }
  }
  iVar1 = *(int *)(param_1 + 0x174);
  if (iVar1 != 0) {
    if ((iVar1 < yBottom) && (-iVar1 < yBottom)) {
      if (iVar1 < 0) {
        param_3->top = param_3->top + iVar1 + yBottom;
        return;
      }
      param_3->bottom = param_3->bottom + (iVar1 - yBottom);
      return;
    }
    SetRect(param_2,0,0,xRight,yBottom);
    SetRect(param_3,0,0,0,0);
    return;
  }
LAB_004aade5:
  SetRect(param_3,0,0,0,0);
  return;
}

