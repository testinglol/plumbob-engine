
undefined1 FUN_00410398(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 0xc) < 0) {
    extraout_ECX[0x43] = 0xffffffff;
    *(undefined2 *)(extraout_ECX + 2) = 0;
    *(undefined1 *)extraout_ECX[1] = 0;
    uVar3 = 0;
  }
  else {
    cVar2 = FUN_004106e8(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                         unaff_EBP + -0x18);
    *(char *)(unaff_EBP + -0xd) = cVar2;
    if ((cVar2 != '\0') && (4 < *(int *)(unaff_EBP + -0x18))) {
      FUN_004706f0();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0047034e(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),0x46414d73,0,
                   0xffffffff);
      iVar4 = FUN_00470d9f(0,0);
      if (iVar4 == 0) {
        uVar5 = FUN_00471509(1,0xffffffff);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
        FUN_0046f824(unaff_EBP + -400,0,0x100);
        *(undefined ***)(unaff_EBP + -0x19c) = &PTR_FUN_00666524;
        FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x19c);
        iVar4 = (**(code **)*extraout_ECX)();
        if ((iVar4 == 0) && (iVar4 = FUN_00470d9f(1,0), iVar4 == 0)) {
          uVar5 = FUN_00471557(1,0);
          *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
          FUN_0046f824(unaff_EBP + -400,0,0x100);
          *(undefined ***)(unaff_EBP + -0x19c) = &PTR_FUN_00666524;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x19c);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004712d0();
    }
    if (extraout_ECX[0x50] != 0) {
      FUN_00420028(extraout_ECX[0x50]);
      extraout_ECX[0x50] = 0;
    }
    if (extraout_ECX[0x51] != 0) {
      FUN_00410204(1);
      extraout_ECX[0x51] = 0;
    }
    piVar1 = *(int **)(unaff_EBP + 8);
    iVar4 = (**(code **)(*piVar1 + 0x38))(0x46414d68,*(undefined4 *)(unaff_EBP + 0xc),0);
    extraout_ECX[0x50] = iVar4;
    if (iVar4 != 0) {
      (**(code **)(*piVar1 + 100))(iVar4);
    }
    uVar3 = *(undefined1 *)(unaff_EBP + -0xd);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

