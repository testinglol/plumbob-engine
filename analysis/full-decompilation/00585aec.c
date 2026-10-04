
undefined1 FUN_00585aec(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = (**(code **)(*extraout_ECX + 0xac))();
  if (iVar4 == 0) {
    uVar3 = 0;
  }
  else {
    iVar4 = (**(code **)(*extraout_ECX + 0xac))();
    uVar1 = *(undefined4 *)(iVar4 + 4);
    uVar5 = FUN_005b870f(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar6 = FUN_005b870f(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
    uVar2 = DAT_006f6b64;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar3 = FUN_0058372c(uVar2,uVar1,uVar6,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

