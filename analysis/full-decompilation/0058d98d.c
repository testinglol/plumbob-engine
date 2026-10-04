
undefined1 FUN_0058d98d(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 8) == 0) {
    uVar3 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(extraout_ECX + 8) + 4);
    uVar4 = FUN_005b870f(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar5 = FUN_005b870f(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
    uVar2 = DAT_006f6b64;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar3 = FUN_0058372c(uVar2,uVar1,uVar5,uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

