
undefined1 FUN_0057d349(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int extraout_ECX;
  undefined1 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 0x128);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 0x128);
  (**(code **)(iVar1 + 4))();
  piVar3 = *(int **)(extraout_ECX + 0x2c);
  piVar2 = *(int **)(extraout_ECX + 0x30);
  uVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    if (piVar3 == piVar2) {
LAB_0057d39f:
      iVar1 = *(int *)(extraout_ECX + 0x128);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      (**(code **)(iVar1 + 8))();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar4;
    }
    if (*piVar3 == *(int *)(unaff_EBP + 8)) {
      if (piVar3 != piVar2) {
        FUN_005db2f2(piVar3);
        uVar4 = 1;
      }
      goto LAB_0057d39f;
    }
    piVar3 = piVar3 + 1;
  } while( true );
}

