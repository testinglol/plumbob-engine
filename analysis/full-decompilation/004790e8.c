
uint __thiscall FUN_004790e8(int param_1,char *param_2)

{
  uint uVar1;
  
  if ((param_2[2] == '\x01') && (*(int *)(param_1 + 0x60) != 0)) {
    uVar1 = (uint)(*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x60) + 0x10) + *param_2 * 4) +
                            (int)param_2[1]) < 0x10);
  }
  else {
    uVar1 = (uint)param_2 & 0xffffff00;
  }
  return uVar1;
}

