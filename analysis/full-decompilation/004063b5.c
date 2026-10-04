
int FUN_004063b5(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_004706f0();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047034e(piVar1,*(undefined4 *)(unaff_EBP + 0xc),0x43545353,0,0xffffffff);
  FUN_0047132c(1,*extraout_ECX,0xffffffff);
  FUN_0047132c(2,extraout_ECX[3],0xffffffff);
  iVar2 = FUN_0047078e();
  if (iVar2 == 0) {
    iVar3 = (**(code **)(*piVar1 + 0x38))(0x43415453,*(undefined4 *)(unaff_EBP + 0xc),0);
    if (iVar3 != 0) {
      (**(code **)(*piVar1 + 0x80))(iVar3);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004712d0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

