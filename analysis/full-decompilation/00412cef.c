
undefined4 * FUN_00412cef(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  iVar2 = piVar1[1];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_00401aae((iVar2 - iVar3) + 2);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00401a79();
  iVar2 = piVar1[1];
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00412d8a(iVar3,iVar2);
  FUN_004015e4(*(undefined4 *)(unaff_EBP + 0x10));
  puVar4 = *(undefined4 **)(unaff_EBP + 8);
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00401729();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar4;
}

