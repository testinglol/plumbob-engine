
uint __thiscall FUN_00530b47(int param_1,int param_2,undefined4 *param_3)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  
  if (param_2 == -1) {
    param_2 = 0xb;
  }
  else if ((param_2 < 0) || (0x15 < param_2)) {
    return in_EAX & 0xffffff00;
  }
  iVar1 = FUN_004096c2();
  *param_3 = *(undefined4 *)(iVar1 + 0x14);
  param_3[1] = *(undefined4 *)(iVar1 + 0x18);
  param_3[2] = *(undefined4 *)(iVar1 + 0x1c);
  iVar1 = *(int *)(iVar1 + 0x20) / 0x16;
  param_3[3] = iVar1;
  param_2 = (iVar1 - param_3[1]) * param_2;
  param_3[3] = param_3[3] + param_2;
  param_3[1] = param_3[1] + param_2;
  FUN_005a5e1c(param_1 + 0x204);
  uVar2 = FUN_005a5e72();
  return uVar2;
}

