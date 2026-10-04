
int FUN_00608217(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  int iStack_34;
  uint *puStack_30;
  
  FUN_00634c24();
  puVar1 = *(uint **)(unaff_EBP + 8);
  iStack_34 = unaff_EBP + 8;
  puStack_30 = puVar1;
  FUN_005a5c09();
  iVar5 = *(int *)(unaff_EBP + 8);
  if ((iVar5 == *extraout_ECX) || (*puVar1 < *(uint *)(iVar5 + 0x10))) {
    puStack_30 = (uint *)0x60824d;
    puStack_30 = (uint *)FUN_005d48d9();
    uVar2 = *puVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(uint *)(unaff_EBP + -0x30) = uVar2;
    iStack_34 = 0x60825f;
    FUN_005b86bd();
    puStack_30 = (uint *)(unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(int **)(unaff_EBP + -0x10) = &iStack_34;
    FUN_00602c56(unaff_EBP + 8);
    puVar4 = (undefined4 *)FUN_006082ea(unaff_EBP + -0x14);
    uVar3 = *puVar4;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
    puStack_30 = (uint *)0x608292;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    puStack_30 = (uint *)0x60829e;
    FUN_005b8770();
    iVar5 = *(int *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5 + 0x14;
}

