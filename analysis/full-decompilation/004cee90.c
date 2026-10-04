
void __thiscall FUN_004cee90(int param_1,int param_2)

{
  int *piVar1;
  
  if (9999999 < param_2) {
    param_2 = 9999999;
  }
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  (**(code **)(*piVar1 + 0x7c))(param_2,param_2 >> 0x1f,param_1 + 0x28);
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 0x40;
  return;
}

