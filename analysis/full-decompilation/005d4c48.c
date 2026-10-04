
undefined4 * FUN_005d4c48(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  uVar2 = extraout_ECX[1] - *extraout_ECX;
  if (uVar2 < uVar1) {
    FUN_005d48d9();
    puVar5 = *(undefined4 **)(unaff_EBP + 8);
  }
  else {
    iVar3 = *(int *)(unaff_EBP + 0x10);
    if (uVar2 < uVar1 + iVar3) {
      iVar3 = uVar2 - uVar1;
    }
    pvVar4 = operator_new(iVar3 + 1);
    (*(code *)PTR_FUN_006d7050)(pvVar4,*extraout_ECX + *(int *)(unaff_EBP + 0xc),iVar3);
    *(undefined1 *)((int)pvVar4 + iVar3) = 0;
    FUN_005d4956(pvVar4);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_006321f0(pvVar4);
    puVar5 = *(undefined4 **)(unaff_EBP + 8);
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    FUN_00401729();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar5;
}

