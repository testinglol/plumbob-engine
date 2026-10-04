
undefined4 FUN_00579ea3(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (extraout_ECX[3] == 0) {
    uVar2 = 0;
  }
  else {
    if ((char)extraout_ECX[5] != '\0') {
      FUN_00577447();
      *(undefined1 *)(extraout_ECX + 5) = 0;
    }
    if ((int *)extraout_ECX[1] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[1] + 0x28))();
      (**(code **)(*(int *)extraout_ECX[1] + 100))();
      (**(code **)(*(int *)extraout_ECX[1] + 4))();
      extraout_ECX[1] = 0;
    }
    piVar1 = *(int **)(*extraout_ECX + 0x38);
    if (piVar1 != (int *)0x0) {
      uVar2 = FUN_00412ab1(unaff_EBP + -0x24,*extraout_ECX + 0x4094,extraout_ECX[3]);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005b86bd(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00401729();
      (**(code **)(*piVar1 + 0x24))(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    extraout_ECX[3] = 0;
    *(undefined1 *)((int)extraout_ECX + 0x15) = 0;
    extraout_ECX[2] = 0;
    uVar2 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

