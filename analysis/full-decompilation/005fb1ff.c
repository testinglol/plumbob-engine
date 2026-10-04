
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fb1ff(void)

{
  int *piVar1;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar2;
  int iVar3;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  iVar3 = *(int *)(extraout_ECX + 0x3c);
  *(int **)(unaff_EBP + -0x14) = (int *)(extraout_ECX + 0x3c);
  (**(code **)(iVar3 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar2 = (int *)(extraout_ECX + 0x178);
  *(undefined4 *)(unaff_EBP + -0x10) = 8;
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      _DAT_006fed68 = _DAT_006fed68 + 1;
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    piVar1 = (int *)(unaff_EBP + -0x10);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  piVar2 = (int *)(extraout_ECX + 0x80);
  iVar3 = 8;
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      _DAT_006fed58 = _DAT_006fed58 + 1;
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(extraout_ECX + 0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

