
undefined4 * FUN_0060469c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  FUN_005b86bd(piVar1 + 1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(piVar1 + 4);
  iVar2 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar2 != 0) {
    puVar4 = operator_new(0x10);
    *extraout_ECX = puVar4;
    puVar3 = (undefined4 *)*piVar1;
    *puVar4 = *puVar3;
    puVar4[1] = puVar3[1];
    puVar4[2] = puVar3[2];
    puVar4[3] = puVar3[3];
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

