
void FUN_004eae06(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_0045741b();
  if (iVar2 != 0) {
    iVar1 = *(int *)(*DAT_006e486c + 0x14);
    piVar4 = *(int **)(iVar1 + 0x84);
    if (piVar4 != *(int **)(iVar1 + 0x88)) {
      do {
        iVar3 = FUN_0045741b();
        if ((iVar3 == iVar2) && ((param_2 == 0 || (*piVar4 == param_2)))) {
          piVar4 = (int *)*piVar4;
          if ((piVar4 != (int *)0x0) && (((uint)piVar4[0x45] >> 7 & 1) != 0)) {
            piVar4 = (int *)(**(code **)(*piVar4 + 0x8c))();
            (**(code **)(*piVar4 + 0x14))();
            FUN_00458278(1);
          }
          break;
        }
        piVar4 = piVar4 + 1;
      } while (piVar4 != *(int **)(iVar1 + 0x88));
    }
  }
  FUN_004cee86(0x20000000);
  return;
}

