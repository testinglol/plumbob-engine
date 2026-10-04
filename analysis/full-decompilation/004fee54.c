
undefined4 * FUN_004fee54(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  sVar4 = _strlen(*(char **)(unaff_EBP + 0xc));
  piVar1 = *(int **)(unaff_EBP + 0x10);
  *(size_t *)(unaff_EBP + -0x10) = sVar4;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_00401aae((sVar4 - iVar2) + piVar1[1] + 1);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00401a79();
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00412d8a(*(int *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x10) + *(int *)(unaff_EBP + 0xc));
  FUN_00412d8a(*piVar1,piVar1[1]);
  puVar3 = *(undefined4 **)(unaff_EBP + 8);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00401729();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar3;
}

