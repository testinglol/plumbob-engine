
undefined4 FUN_00588f2f(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  uVar3 = 0;
  iVar1 = (**(code **)(*extraout_ECX + 0xf4))(*(undefined4 *)(unaff_EBP + 8));
  if (iVar1 != 0) {
    FUN_005972be();
    FUN_005b870f(&DAT_006c45a4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = FUN_0059783a(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)FUN_00596b7c(*(int *)(iVar1 + 0x14) + -1);
      uVar3 = 1;
      **(undefined4 **)(unaff_EBP + 0xc) = *puVar2;
      **(undefined4 **)(unaff_EBP + 0x10) = puVar2[1];
      **(undefined4 **)(unaff_EBP + 0x14) = puVar2[2];
      goto LAB_00588fc2;
    }
  }
  **(undefined4 **)(unaff_EBP + 0x14) = 0;
  **(undefined4 **)(unaff_EBP + 0x10) = 0;
  **(undefined4 **)(unaff_EBP + 0xc) = 0;
LAB_00588fc2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

