
uint __thiscall FUN_005de5db(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x8c))(4);
  if (((((char)piVar1 == '\0') || (unaff_retaddr < 0)) ||
      (piVar1 = param_1 + 0x1f, param_1[0x21] - *piVar1 <= unaff_retaddr)) ||
     ((param_2 < 0 || (param_1[0x22] - param_1[0x20] <= param_2)))) {
    uVar2 = (uint)piVar1 & 0xffffff00;
  }
  else {
    uVar2 = CONCAT31((int3)((uint)piVar1 >> 8),1);
  }
  return uVar2;
}

