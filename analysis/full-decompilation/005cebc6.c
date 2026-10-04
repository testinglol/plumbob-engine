
int FUN_005cebc6(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005c35b0();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(extraout_ECX + 0x90) = iVar1;
  iVar2 = iVar1;
  if ((iVar1 == 0) && (iVar2 = *(int *)(extraout_ECX + 0x94), *(int *)(extraout_ECX + 0x94) == 0)) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0x43c80000;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar2 = FUN_00462f96(unaff_EBP + -0xa0,unaff_EBP + -0x18);
    FUN_00462f2f(iVar2);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar2 + 0x40);
    FUN_005c4890();
  }
  else {
    FUN_00462f2f(iVar2 + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar2 + 0x8c);
  }
  iVar2 = FUN_005ce90a(unaff_EBP + -0x5c,0);
  if (iVar2 == 0) {
    iVar2 = FUN_005d068a(iVar1 + 0xbc,iVar1 + 0xc0,iVar1 + 0xc4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

