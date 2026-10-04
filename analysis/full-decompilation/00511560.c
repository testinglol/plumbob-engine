
undefined4 FUN_00511560(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int *piVar3;
  int unaff_EBP;
  undefined4 uVar4;
  int iVar5;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) == 1) {
    iVar5 = *(int *)(unaff_EBP + 0xc);
    if (iVar5 == *(int *)(extraout_ECX + 0x114)) {
      FUN_005dac30(0x10,extraout_ECX,0);
      *(undefined1 *)(extraout_ECX + 0x444) = 1;
    }
    else if (iVar5 == *(int *)(extraout_ECX + 0x450)) {
      FUN_004ecf65();
      uVar2 = FUN_004ecf2e();
      uVar1 = FUN_00511851(unaff_EBP + -0x18,uVar2);
      piVar3 = *(int **)(extraout_ECX + 0x110);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*piVar3 + 0x9c))(uVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_0051193f(unaff_EBP + -0x24,uVar2);
      uVar4 = 1;
      uVar1 = 0;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar2 = FUN_004096c2(0,1);
      FUN_005f436c(uVar2,uVar1,uVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_00511d39();
      (**(code **)(**(int **)(extraout_ECX + 0x44c) + 0x90))(2,1);
      if (*(int *)(*(int *)(extraout_ECX + 0x460) + 0xd4) + 1 ==
          *(int *)(*(int *)(extraout_ECX + 0x460) + 0xd8)) {
        piVar3 = *(int **)(extraout_ECX + 0x450);
LAB_0051172e:
        (**(code **)(*piVar3 + 0x90))(2,0);
      }
    }
    else {
      if (iVar5 != *(int *)(extraout_ECX + 0x44c)) {
        uVar2 = 1;
        goto LAB_00511740;
      }
      FUN_004ecfac();
      uVar2 = FUN_004ecf2e();
      *(undefined4 *)(unaff_EBP + 8) = uVar2;
      uVar2 = FUN_00511851(unaff_EBP + -0x30,uVar2);
      iVar5 = **(int **)(extraout_ECX + 0x110);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      (**(code **)(iVar5 + 0x9c))(uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_0051193f(unaff_EBP + -0x3c,*(undefined4 *)(unaff_EBP + 8));
      uVar4 = 1;
      uVar1 = 0;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      uVar2 = FUN_004096c2(0,1);
      FUN_005f436c(uVar2,uVar1,uVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_00511d39();
      (**(code **)(**(int **)(extraout_ECX + 0x450) + 0x90))(2,1);
      if (*(int *)(*(int *)(extraout_ECX + 0x460) + 0xd4) == 0) {
        piVar3 = *(int **)(extraout_ECX + 0x44c);
        goto LAB_0051172e;
      }
    }
  }
  else {
    if (*(int *)(unaff_EBP + 8) != 0x15) {
      iVar5 = *(int *)(unaff_EBP + 0xc);
      uVar2 = *(undefined4 *)(unaff_EBP + 8);
LAB_00511740:
      uVar2 = FUN_005dd97f(uVar2,iVar5);
      goto LAB_00511747;
    }
    FUN_00511d39();
  }
  uVar2 = 1;
LAB_00511747:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

