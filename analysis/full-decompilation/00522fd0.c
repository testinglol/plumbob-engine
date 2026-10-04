
undefined4 __thiscall FUN_00522fd0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(param_2 + 0x10c);
  iVar2 = FUN_0042573e(*(undefined4 *)(param_1 + 0x10c));
  if ((*(short *)(iVar2 + 0xee) != iVar3) &&
     ((1999 < iVar3 || ((iVar3 != 0 && (0 < *(int *)(param_2 + 0x110))))))) {
    iVar3 = FUN_004102e1();
    iVar2 = 0;
    if (0 < iVar3) {
      do {
        uVar4 = FUN_004102ab(iVar2);
        cVar1 = FUN_00523046(uVar4);
        if (cVar1 != '\0') {
          return 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
  }
  return 0;
}

