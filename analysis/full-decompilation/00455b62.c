
int * __thiscall FUN_00455b62(int *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = (int)param_2;
  iVar1 = (**(code **)(*param_2 + 0x80))();
  param_1[1] = iVar1;
  param_1[2] = *(int *)(*param_1 + 0xdc);
  iVar1 = *(int *)(*param_1 + 0x11c);
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  param_1[3] = iVar1;
  return param_1;
}

