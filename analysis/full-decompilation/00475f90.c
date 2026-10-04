
undefined2 * FUN_00475f90(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined2 *extraout_ECX;
  undefined2 *puVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined2 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  iVar4 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x10) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0xe) = 0x32;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 10) = 0;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  *(int *)(extraout_ECX + 2) = iVar4;
  pvVar2 = operator_new(iVar4 * 6);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else if (-1 < iVar4 + -1) {
    puVar3 = (undefined2 *)((int)pvVar2 + 4);
    do {
      puVar3[-2] = 0;
      puVar3[-1] = 0;
      *puVar3 = 0;
      puVar3 = puVar3 + 3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(void **)(extraout_ECX + 4) = pvVar2;
  *(undefined4 *)(extraout_ECX + 6) = 3;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

