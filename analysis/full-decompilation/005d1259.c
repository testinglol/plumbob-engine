
void __thiscall FUN_005d1259(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0xe0) == *(int *)(param_1 + 0xe4)) {
    local_c = 0xffffffff;
    local_8 = 0;
    FUN_005d1682(*(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xec) >> 2,&local_c);
  }
  iVar1 = *(int *)(param_1 + 0xe0);
  *(undefined4 *)(iVar1 + param_3 * 8) = *param_2;
  *(undefined4 *)(iVar1 + 4 + param_3 * 8) = param_2[1];
  return;
}

