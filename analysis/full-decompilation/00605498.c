
undefined4 FUN_00605498(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  FUN_00634c24();
  if ((char)extraout_ECX[0x57] == '\0') {
    iVar4 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    (**(code **)(iVar4 + 0x14))(unaff_EBP + -0x14);
    _memset(extraout_ECX + 0x1e,0,0x7c);
    piVar7 = *(int **)(unaff_EBP + 0x10);
    extraout_ECX[0x1e] = 0x7c;
    extraout_ECX[0x1f] = 7;
    if (*piVar7 == 3) {
      extraout_ECX[0x1f] = 0x1007;
      _memset(extraout_ECX + 0x30,0,0x20);
      extraout_ECX[0x30] = 0x20;
      extraout_ECX[0x31] = 0x60;
      extraout_ECX[0x33] = 0;
    }
    else if (DAT_006d6f9c == '\0') {
      extraout_ECX[0x1f] = 0x1007;
      puVar2 = (undefined4 *)FUN_005ec28a(unaff_EBP + -0x44);
      puVar8 = (undefined4 *)(unaff_EBP + -0x44);
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
      }
      piVar7 = (int *)(unaff_EBP + -0x44);
      piVar9 = extraout_ECX + 0x30;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
    }
    iVar4 = *(int *)(unaff_EBP + 8);
    iVar3 = *(int *)(unaff_EBP + 0x18);
    extraout_ECX[0x21] = iVar4;
    extraout_ECX[0x5c] = iVar4;
    iVar4 = *(int *)(unaff_EBP + 0xc);
    extraout_ECX[0x38] = 0x2000;
    extraout_ECX[0x20] = iVar4;
    extraout_ECX[0x5d] = iVar4;
    extraout_ECX[0x30] = 0x20;
    if (iVar3 == 1) {
      extraout_ECX[0x38] = 0x3000;
    }
    else if (*(int *)(unaff_EBP + 0x18) == 2) {
      *(byte *)((int)extraout_ECX + 0x7d) = *(byte *)((int)extraout_ECX + 0x7d) | 0x10;
      extraout_ECX[0x38] = 0x22000;
      iVar3 = (**(code **)(*DAT_006fe8bc + 0x1c))();
      piVar7 = (int *)((-(uint)(iVar3 != 0) & iVar3 - 0x48U) + 0x2d0);
      piVar9 = extraout_ECX + 0x30;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
    }
    else {
      iVar4 = *(int *)(unaff_EBP + 0x18);
      extraout_ECX[0x38] = 0x2040;
      if ((iVar4 == 3) || (**(int **)(unaff_EBP + 0x10) == 3)) {
        extraout_ECX[0x31] = 0x60;
        extraout_ECX[0x33] = 8;
      }
    }
    if (*(int *)(unaff_EBP + 0x14) == 2) {
      extraout_ECX[0x38] = extraout_ECX[0x38] | 0x20004000;
      *(undefined1 *)((int)extraout_ECX + 0x15d) = 1;
      (**(code **)(*DAT_006fe8bc + 0x1c))();
      iVar4 = FUN_005eff44(extraout_ECX,0,0);
      if (iVar4 != 0) {
        *(int *)(unaff_EBP + -0x14) = iVar4;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
        (*(code *)PTR_FUN_00675038)(0);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
        uVar5 = extraout_ECX[0x38];
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar5 = uVar5 & 0xdfffbfff;
LAB_006056f9:
        extraout_ECX[0x38] = uVar5 | 0x800;
LAB_0060570b:
        *(undefined1 *)((int)extraout_ECX + 0x15d) = 0;
        (**(code **)(*DAT_006fe8bc + 0x1c))();
        iVar4 = FUN_005eff44(extraout_ECX,0,0);
        if (iVar4 != 0) {
          *(int *)(unaff_EBP + -0x20) = iVar4;
          *(undefined4 *)(unaff_EBP + -4) = 4;
          *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00675034;
          (*(code *)PTR_FUN_00675038)(0);
          *(undefined4 *)(unaff_EBP + -4) = 5;
          (**(code **)(*(int *)(unaff_EBP + -0x24) + 0x10))();
          extraout_ECX[1] = 0;
          goto LAB_00605775;
        }
      }
LAB_00605760:
      cVar1 = (**(code **)(*extraout_ECX + 0x48))
                        (*(undefined4 *)(unaff_EBP + 0x10),extraout_ECX + 0x30);
      if (cVar1 != '\0') {
        *(undefined1 *)(extraout_ECX + 0x57) = 1;
        uVar6 = 1;
        goto LAB_00605782;
      }
    }
    else {
      if ((*(int *)(unaff_EBP + 0x14) == 0) || (DAT_006fe914 != '\0')) {
        *(byte *)((int)extraout_ECX + 0xe1) = *(byte *)((int)extraout_ECX + 0xe1) | 8;
        goto LAB_0060570b;
      }
      *(byte *)((int)extraout_ECX + 0xe1) = *(byte *)((int)extraout_ECX + 0xe1) | 0x40;
      *(undefined1 *)((int)extraout_ECX + 0x15d) = 1;
      (**(code **)(*DAT_006fe8bc + 0x1c))();
      iVar4 = FUN_005eff44(extraout_ECX,0,0);
      if (iVar4 == 0) goto LAB_00605760;
      *(int *)(unaff_EBP + -0x14) = iVar4;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
      (*(code *)PTR_FUN_00675038)(0);
      *(undefined4 *)(unaff_EBP + -4) = 3;
      (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int *)(unaff_EBP + 0x14) != 1) {
        uVar5 = extraout_ECX[0x38] & 0xffffbfff;
        goto LAB_006056f9;
      }
    }
  }
LAB_00605775:
  uVar6 = 0;
LAB_00605782:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

