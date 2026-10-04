
uint __thiscall FUN_00479115(int param_1,char *param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (param_2[2] == '\x01') {
    bVar1 = *(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x60) + 0x10) + *param_2 * 4) +
                     (int)param_2[1]);
    if ((bVar1 < 0x10) || (bVar1 == 0x10)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = (uint)param_2 & 0xffffff00;
  }
  return uVar2;
}

