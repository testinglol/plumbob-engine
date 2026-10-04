
void FUN_005963ab(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(*extraout_ECX + 0x1c);
  uVar2 = FUN_00595f4e();
  uVar2 = FUN_0049b9e6(unaff_EBP + -0x94,extraout_ECX + 1,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_0049b9e6(unaff_EBP + -0x50,uVar2,iVar1 + 0x1c);
  iVar1 = *(int *)(unaff_EBP + 8);
  FUN_00462f2f(iVar3);
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

