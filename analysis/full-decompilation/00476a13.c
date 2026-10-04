
void FUN_00476a13(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = FUN_0042573e((int)*(short *)(unaff_EBP + 8));
  if (iVar2 != 0) {
    uVar3 = FUN_00401f73();
    uVar3 = FUN_004e988f(uVar3);
    FUN_005a5dea(0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004e93e4(uVar3,unaff_EBP + 8);
    if (cVar1 != '\0') {
      uVar3 = FUN_004096c2();
      uVar3 = FUN_00476603(uVar3);
      piVar4 = (int *)FUN_00476aa2(uVar3);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x160))(*(undefined4 *)(unaff_EBP + 0xc));
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005a5e09();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

