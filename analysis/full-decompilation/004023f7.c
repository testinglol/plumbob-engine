
void FUN_004023f7(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  FUN_0046f8e4(iVar1);
  FUN_00402a08(DAT_006de708,DAT_006de70c);
  FUN_00632b81(1);
  uVar3 = DAT_00689070;
  uVar2 = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00632c55(uVar2,0x21,uVar3);
  if (*(int *)(unaff_EBP + -0x68 + *(int *)(*(int *)(unaff_EBP + -0x70) + 4)) == 0) {
    FUN_006326ae(unaff_EBP + 8);
    while (0 < *(int *)(unaff_EBP + 8)) {
      FUN_0046f824(unaff_EBP + -0xb8,0,0x40);
      *(undefined ***)(unaff_EBP + -0xc4) = &PTR_FUN_0066651c;
      FUN_00401d84(unaff_EBP + -0x70,unaff_EBP + -0xc4);
      FUN_0040298f(unaff_EBP + -0xc4);
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -1;
    }
    DAT_006de714 = 1;
  }
  else {
    DAT_006de714 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00632c42();
  FUN_00632b08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

