
uint FUN_005d704f(uint param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  cVar1 = (**(code **)(*piVar2 + 0x18))();
  if (cVar1 == '\0') {
    uVar3 = (-(uint)((param_1 & 4) != 0) & 0x80800000) + 0x80000000;
    if ((param_1 & 2) != 0) {
      uVar3 = uVar3 | 0xc00000;
    }
    if ((param_1 & 8) != 0) {
      uVar3 = uVar3 | 0xc80000;
    }
    if ((param_1 & 0x10) != 0) {
      uVar3 = uVar3 | 0x20000;
    }
    if ((param_1 & 0x20) != 0) {
      uVar3 = uVar3 | 0x10000;
    }
  }
  else {
    uVar3 = 0x90000000;
  }
  return uVar3;
}

