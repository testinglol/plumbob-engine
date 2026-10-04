
/* WARNING: Removing unreachable block (ram,0x004489ae) */

int * __thiscall FUN_00448998(int *param_1,undefined1 *param_2)

{
  int iVar1;
  
  *param_1 = 0;
  iVar1 = FUN_00401742(0x18);
  *param_1 = iVar1;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = *param_2;
  *(undefined1 *)*param_1 = 0;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(int *)(*param_1 + 8) = *param_1;
  *(int *)(*param_1 + 0xc) = *param_1;
  return param_1;
}

