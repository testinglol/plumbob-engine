
uint __thiscall FUN_00416a49(int *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if ((param_1[0x45] == 0) || (uVar1 = *(ushort *)(param_1[0x45] + 4), uVar1 == 0xffff)) {
    if ((*param_1 == 0) && ((-1 < param_2 && (param_2 < 0x13)))) {
      uVar2 = (uint)*(ushort *)(&DAT_00666758 + param_2 * 2);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = (uint)uVar1 + param_2;
  }
  return uVar2;
}

