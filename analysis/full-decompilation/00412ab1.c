
undefined4 * FUN_00412ab1(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  piVar2 = *(int **)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar3 = piVar2[1];
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  iVar4 = *piVar1;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_00401aae(((iVar3 - iVar4) - *piVar2) + piVar1[1] + 1);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00401a79();
  iVar3 = piVar1[1];
  iVar4 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00412d8a(iVar4,iVar3);
  FUN_00412d8a(*piVar2,piVar2[1]);
  puVar5 = *(undefined4 **)(unaff_EBP + 8);
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00401729();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar5;
}

