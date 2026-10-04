
uint __thiscall FUN_0056c46f(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)(param_1 + 0x154);
  do {
    if ((*(uint *)(*piVar1 + 0x1b4) & param_2) != 0) {
      return CONCAT31((int3)((uint)piVar1 >> 8),1);
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 9);
  return (uint)piVar1 & 0xffffff00;
}

