
undefined4 FUN_005977ba(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x34);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  iVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_0059780a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar3;
  *(undefined4 *)(iVar3 + 0x10) = extraout_ECX;
  FUN_0059b0f4(unaff_EBP + -0x10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x10);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

