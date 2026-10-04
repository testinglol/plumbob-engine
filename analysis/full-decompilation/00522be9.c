
undefined4 FUN_00522be9(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  if (iVar1 == 1) {
    iVar1 = *(int *)(unaff_EBP + 0xc);
    if (iVar1 == *(int *)(extraout_ECX + 0x118)) {
      FUN_005dac30(0x10,extraout_ECX,0);
    }
    else {
      if (iVar1 != *(int *)(extraout_ECX + 0x11c)) {
        uVar2 = 1;
        goto LAB_00522df3;
      }
      FUN_005dac30(0x10,extraout_ECX,0);
      *(undefined1 *)(extraout_ECX + 0x1ac) = 1;
    }
  }
  else if (iVar1 == 9) {
    if (extraout_ECX != 0) {
      FUN_005da644(extraout_ECX,3,1,*(undefined4 *)(extraout_ECX + 0x118),0);
    }
  }
  else {
    if (iVar1 != 0x15) {
      iVar1 = *(int *)(unaff_EBP + 0xc);
      uVar2 = *(undefined4 *)(unaff_EBP + 8);
LAB_00522df3:
      uVar2 = FUN_005dd97f(uVar2,iVar1);
      goto LAB_00522dfa;
    }
    iVar1 = *(int *)(*(int *)(extraout_ECX + 0x110) + 0xf8);
    if (iVar1 == *(int *)(extraout_ECX + 0x138)) {
      *(undefined4 *)(extraout_ECX + 0x13c) = *(undefined4 *)(*(int *)(extraout_ECX + 0x114) + 0xf8)
      ;
      FUN_00523306();
    }
    else {
      *(int *)(extraout_ECX + 0x138) = iVar1;
      FUN_005230a9();
      iVar1 = FUN_005f51ce();
      if (iVar1 != 0) {
        FUN_005f5543(0);
      }
    }
    if ((-1 < *(int *)(extraout_ECX + 0x138)) && (-1 < *(int *)(extraout_ECX + 0x13c))) {
      uVar2 = FUN_005f565b(*(int *)(extraout_ECX + 0x138));
      FUN_005b86bd(uVar2);
      uVar2 = *(undefined4 *)(extraout_ECX + 0x13c);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar2 = FUN_005f565b(uVar2);
      FUN_005b86bd(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar2 = FUN_004705f2(1,0xffffffff);
      FUN_006358b0(unaff_EBP + -0x424,uVar2);
      FUN_006358c0(unaff_EBP + -0x424,&DAT_006c3d7c);
      uVar2 = FUN_004096c2();
      FUN_006358c0(unaff_EBP + -0x424,uVar2);
      FUN_006358c0(unaff_EBP + -0x424,&DAT_006c3d7c);
      uVar2 = FUN_004096c2();
      FUN_006358c0(unaff_EBP + -0x424,uVar2);
      FUN_006358c0(unaff_EBP + -0x424,&DAT_006c26dc);
      (**(code **)(**(int **)(extraout_ECX + 0x120) + 0x1a0))(unaff_EBP + -0x424);
      (**(code **)(*(int *)(*(int *)(extraout_ECX + 0x120) + 0xd4) + 0x1c))(0);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  uVar2 = 1;
LAB_00522dfa:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

