
void __thiscall FUN_00469700(int param_1,int param_2,int param_3,LPRECT param_4)

{
  LONG *pLVar1;
  tagRECT local_14;
  
  pLVar1 = (LONG *)(*(int *)(param_1 + 0xc) + *(int *)(param_2 + 4) * 0x14);
  param_4->left = *pLVar1;
  param_4->top = pLVar1[1];
  param_4->right = pLVar1[2];
  param_4->bottom = pLVar1[3];
  pLVar1 = (LONG *)(*(int *)(param_1 + 0xc) + *(int *)(param_3 + 4) * 0x14);
  local_14.left = *pLVar1;
  local_14.top = pLVar1[1];
  local_14.right = pLVar1[2];
  local_14.bottom = pLVar1[3];
  InflateRect(&local_14,1,1);
  InflateRect(param_4,1,1);
  IntersectRect(param_4,&local_14,param_4);
  return;
}

