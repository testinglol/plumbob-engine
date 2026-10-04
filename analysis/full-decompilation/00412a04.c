
undefined4 * FUN_00412a04(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  size_t sVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  sVar5 = _strlen(*(char **)(unaff_EBP + 0x10));
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(size_t *)(unaff_EBP + -0x10) = sVar5;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_00401aae((sVar5 - iVar2) + piVar1[1] + 1);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00401a79();
  iVar2 = piVar1[1];
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00412d8a(iVar3,iVar2);
  FUN_00412d8a(*(int *)(unaff_EBP + 0x10),*(int *)(unaff_EBP + -0x10) + *(int *)(unaff_EBP + 0x10));
  puVar4 = *(undefined4 **)(unaff_EBP + 8);
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00401729();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar4;
}

