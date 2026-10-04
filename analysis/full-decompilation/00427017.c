
undefined4 FUN_00427017(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined2 extraout_var;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  cVar2 = FUN_00423f63();
  if (cVar2 != '\0') {
    puVar1 = *(undefined4 **)(iVar4 + 8);
    uVar3 = FUN_0045741b();
    while( true ) {
      iVar4 = FUN_00440914(uVar3);
      if (iVar4 == 0) break;
      FUN_0044127f(CONCAT22(extraout_var,*(undefined2 *)(iVar4 + 0xf0)));
    }
    iVar4 = *(int *)(unaff_EBP + -0x10);
    for (iVar5 = *(int *)(iVar4 + 0x154); iVar5 != *(int *)(iVar4 + 0x158); iVar5 = iVar5 + 4) {
      cVar2 = FUN_00410285(uVar3);
      if (cVar2 != '\0') goto LAB_004270de;
      iVar4 = *(int *)(unaff_EBP + -0x10);
    }
    FUN_0046f824(unaff_EBP + -0x114,0,0x104);
    *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
    (**(code **)(*(int *)*puVar1 + 0x24))(unaff_EBP + -0x120);
    cVar2 = FUN_0043caba(puVar1);
    if (cVar2 != '\0') {
      FUN_004259ec(*(undefined4 *)(unaff_EBP + 8));
      FUN_004567a6();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar3 = FUN_0046b546(unaff_EBP + -0x120);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0045685f();
      goto LAB_00427122;
    }
  }
LAB_004270de:
  uVar3 = 0xffffffff;
LAB_00427122:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

