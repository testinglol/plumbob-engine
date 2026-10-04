
undefined4 FUN_00606ef3(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 8);
  if (iVar4 == 1) {
    iVar4 = *(int *)(unaff_EBP + 0xc);
    if (iVar4 == extraout_ECX[0x43]) {
      if (extraout_ECX[0x42] != 0) {
        iVar4 = *(int *)(extraout_ECX[0x42] + 0xf8);
        if (iVar4 == -1) {
          piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          piVar2 = (int *)(**(code **)(*piVar2 + 8))();
          (**(code **)(*piVar2 + 0x1c0))(&DAT_006de560);
        }
        else {
          uVar3 = FUN_005f565b(iVar4);
          FUN_005b86bd(uVar3);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_004015e4(0x20);
          piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          piVar2 = (int *)(**(code **)(*piVar2 + 8))();
          (**(code **)(*piVar2 + 0x1c0))(*(undefined4 *)(unaff_EBP + -0x18));
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar2 = (int *)(**(code **)(*piVar2 + 8))();
        (**(code **)(*piVar2 + 0x1c4))(1);
      }
    }
    else if (iVar4 != extraout_ECX[0x44]) {
      uVar3 = 1;
      goto LAB_006070ac;
    }
    FUN_005dac30(0x10,extraout_ECX,0);
  }
  else {
    if (iVar4 == 9) {
      if (*(int *)(unaff_EBP + 0xc) == -1) {
        iVar4 = extraout_ECX[0x44];
      }
      else {
        iVar4 = extraout_ECX[0x43];
      }
      uVar3 = (**(code **)(*extraout_ECX + 300))(1,iVar4);
      goto LAB_006070b3;
    }
    if (iVar4 != 0x15) {
      iVar4 = *(int *)(unaff_EBP + 0xc);
      uVar3 = *(undefined4 *)(unaff_EBP + 8);
LAB_006070ac:
      uVar3 = FUN_005dd97f(uVar3,iVar4);
      goto LAB_006070b3;
    }
    uVar1 = *(uint *)(unaff_EBP + 0xc);
    if ((uVar1 == 0xffffffff) || ((uint)(extraout_ECX[0x4a] - extraout_ECX[0x49] >> 2) <= uVar1)) {
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x1a0))(&DAT_006de560);
    }
    else {
      iVar4 = extraout_ECX[0x49];
      *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(*(int *)(extraout_ECX[0x46] + 0x10) + 8);
      iVar4 = *(int *)(iVar4 + uVar1 * 4);
      if (0 < iVar4) {
        do {
          FUN_0041674f();
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x9c))(*(int *)(unaff_EBP + 0xc) + 0x1c);
      (**(code **)(*(int *)(extraout_ECX[0x45] + 0xd4) + 0x1c))(0);
    }
  }
  uVar3 = 1;
LAB_006070b3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

