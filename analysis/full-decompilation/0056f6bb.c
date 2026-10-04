
undefined4 * FUN_0056f6bb(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_005d23b8(*(undefined4 *)(unaff_EBP + 8));
  uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
  iVar2 = *(int *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006714f0;
  extraout_ECX[5] = uVar3;
  puVar1 = extraout_ECX + 6;
  if (iVar2 == 0) {
    *(undefined1 *)puVar1 = 0;
  }
  else {
    FUN_006358b0(puVar1,*(undefined4 *)(unaff_EBP + 0x10));
  }
  uVar3 = FUN_005caeef();
  FUN_005c2dc3(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046f824(unaff_EBP + -300,0,0x104);
  *(undefined ***)(unaff_EBP + -0x138) = &PTR_FUN_006664e8;
  uVar3 = FUN_0041532c(0xf,0,unaff_EBP + -0x138);
  FUN_004ee9ce(uVar3);
  uVar3 = FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x134));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005caef6(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c2ee6();
  *(undefined4 *)(unaff_EBP + 8) = 0;
  FUN_005cad3e();
  FUN_005d27ca(unaff_EBP + 8,puVar1);
  if (*(int **)(unaff_EBP + 8) == (int *)0x0) {
    FUN_006358b0(puVar1,&DAT_006cea94);
  }
  else {
    (**(code **)(**(int **)(unaff_EBP + 8) + 8))();
  }
  FUN_005caef6(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c2ee6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

