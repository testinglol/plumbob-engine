
void FUN_00437163(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  if ((1 < iVar1) && (iVar1 < 5)) {
    if (*(char *)(extraout_ECX + 0x68) == '\0') {
      *(int *)(extraout_ECX + 0x74) = iVar1;
    }
    else {
      *(undefined4 *)(extraout_ECX + 0x74) = 5;
    }
  }
  piVar2 = *(int **)(*(int *)(DAT_006f2a08 + 0x84) + 0x11ac);
  if ((piVar2 != (int *)0x0) && (*(char *)(extraout_ECX + 0x6c) != '\0')) {
    (**(code **)(*piVar2 + 0x94))();
    FUN_00436e16();
    FUN_004ffad0(*(undefined4 *)(extraout_ECX + 0x70));
  }
  if (*(int *)(extraout_ECX + 0x50) == 3) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00523acd(999,unaff_EBP + -0x18);
    uVar3 = FUN_005d49d6();
    uVar4 = FUN_004096c2(uVar3);
    FUN_005b8775(uVar4,uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  if (*(char *)(extraout_ECX + 0x69) == '\0') {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x70) + 0x148) = 0;
    *(undefined4 *)(extraout_ECX + 0x70) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

