
undefined1 FUN_005fc956(void)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = DAT_006fecc8;
  if ((char)extraout_ECX[0x5f] == '\0') {
    uVar3 = 0;
    goto LAB_005fc9f0;
  }
  *(int **)(unaff_EBP + -0x14) = &DAT_006fecc8;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00575b11(unaff_EBP + -0x20,unaff_EBP + -0x10);
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(int **)(unaff_EBP + -0x10) = extraout_ECX;
    FUN_005fcfe4(unaff_EBP + -0x10);
  }
  piVar1 = (int *)extraout_ECX[0x61];
  if (piVar1 == (int *)0x0) {
LAB_005fc9dc:
    uVar3 = 1;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
    if (-1 < iVar2) goto LAB_005fc9dc;
    (**(code **)(*extraout_ECX + 0xc))();
    uVar3 = 0;
  }
  iVar2 = DAT_006fecc8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
LAB_005fc9f0:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

