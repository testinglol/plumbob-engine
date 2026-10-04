
void FUN_004e1b96(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x290,0,0x104);
  *(undefined ***)(unaff_EBP + -0x29c) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(0x57,0,unaff_EBP + -0x29c);
  FUN_004eea6b(uVar1);
  FUN_0046f824(unaff_EBP + -0x180,0,0x104);
  *(undefined ***)(unaff_EBP + -0x18c) = &PTR_FUN_006664e8;
  FUN_00410947(unaff_EBP + -0x18c);
  FUN_004a0820();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f8e4(unaff_EBP + -0x18c);
  FUN_00412825(unaff_EBP + -0x29c);
  iVar2 = *(int *)(unaff_EBP + -0x1c);
  if (iVar2 != *(int *)(unaff_EBP + -0x18)) {
    do {
      uVar1 = *(undefined4 *)(iVar2 + 4);
      FUN_005b8e25(uVar1);
      FUN_005b9796(uVar1);
      iVar2 = iVar2 + 0x110;
    } while (iVar2 != *(int *)(unaff_EBP + -0x18));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004a08ab();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

