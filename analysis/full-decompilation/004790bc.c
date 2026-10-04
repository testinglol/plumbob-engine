
uint __thiscall FUN_004790bc(int param_1,char *param_2)

{
  uint uVar1;
  
  if (param_2[2] == '\x01') {
    uVar1 = CONCAT31(param_2[1] >> 7,
                     *(char *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 0x10) + *param_2 * 4) +
                              (int)param_2[1]) != -1);
  }
  else {
    uVar1 = (uint)param_2 & 0xffffff00;
  }
  return uVar1;
}

