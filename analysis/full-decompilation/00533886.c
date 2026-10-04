
void FUN_00533886(void)

{
  int *piVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *_Str2;
  char *_Str1;
  undefined4 uVar6;
  int extraout_ECX;
  uint uVar7;
  int unaff_EBP;
  float10 fVar8;
  
  FUN_00634c24();
  if (0 < *(int *)(unaff_EBP + 0xc)) {
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 0xc);
    do {
      FUN_005d4956();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005343fd(unaff_EBP + -0x10,unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x10) == *(int *)(extraout_ECX + 0xe8)) {
        uVar6 = FUN_00533c7d();
        *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b86bd();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_00533d58();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00534366(unaff_EBP + -0x20,unaff_EBP + -0x8c);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
      }
      else {
        FUN_00533de5();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      piVar1 = (int *)(unaff_EBP + 8);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
    uVar6 = *(undefined4 *)(extraout_ECX + 0xec);
    uVar3 = FUN_00533d37();
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_00534230(uVar6,uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    FUN_005e8037();
    iVar5 = *(int *)(extraout_ECX + 0xe8);
    iVar4 = *(int *)(unaff_EBP + 0xc);
    *(int *)(unaff_EBP + -0x14) = iVar5;
    if (iVar4 != iVar5) {
      do {
        *(int *)(unaff_EBP + 8) = iVar4 + 0x20;
        iVar5 = FUN_004096c2();
        if (iVar5 == 0) {
          FUN_004096c2();
          FUN_00533cd8();
          *(undefined4 *)(unaff_EBP + -4) = 6;
          FUN_00533dae();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        else {
          FUN_00533dae();
        }
        FUN_0041674f();
        iVar4 = *(int *)(unaff_EBP + 0xc);
      } while (iVar4 != *(int *)(unaff_EBP + -0x14));
    }
  }
  if (1 < (uint)((*(int *)(extraout_ECX + 0xf8) - *(int *)(extraout_ECX + 0xf4)) / 0x28)) {
    FUN_005347f1();
  }
  if (*(int *)(extraout_ECX + 0xd4) == *(int *)(extraout_ECX + 0xd8)) {
    FUN_004096c2();
LAB_00533ba0:
    FUN_005d4bbf();
    *(undefined4 *)(extraout_ECX + 0xe0) = 0;
  }
  else {
    *(undefined4 *)(extraout_ECX + 0xe0) = 0xffffffff;
    uVar7 = 0;
    if ((*(int *)(extraout_ECX + 0xf8) - *(int *)(extraout_ECX + 0xf4)) / 0x28 != 0) {
      do {
        _Str2 = (char *)FUN_004096c2();
        _Str1 = (char *)FUN_004096c2();
        iVar5 = _strcmp(_Str1,_Str2);
        if (iVar5 == 0) {
          *(uint *)(extraout_ECX + 0xe0) = uVar7;
          break;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)((*(int *)(extraout_ECX + 0xf8) - *(int *)(extraout_ECX + 0xf4)) / 0x28
                             ));
    }
    iVar5 = *(int *)(extraout_ECX + 0xe0);
    if (iVar5 == -1) {
      FUN_004096c2();
      goto LAB_00533ba0;
    }
    if (*(int *)(extraout_ECX + 0x148) == 1) {
      *(uint *)(extraout_ECX + 0xe0) = iVar5 + 1U;
      if ((uint)((*(int *)(extraout_ECX + 0xf8) - *(int *)(extraout_ECX + 0xf4)) / 0x28) <=
          iVar5 + 1U) {
        *(undefined4 *)(extraout_ECX + 0xe0) = 0;
      }
      *(undefined4 *)(extraout_ECX + 0x148) = 0;
      FUN_004096c2();
      FUN_005d4bbf();
      goto LAB_00533bb3;
    }
    if (*(int *)(extraout_ECX + 0x148) != 2) goto LAB_00533bb3;
    *(int *)(extraout_ECX + 0xe0) = iVar5 + -1;
    if (iVar5 + -1 < 0) {
      *(int *)(extraout_ECX + 0xe0) =
           (*(int *)(extraout_ECX + 0xf8) - *(int *)(extraout_ECX + 0xf4)) / 0x28 + -1;
    }
    FUN_004096c2();
    FUN_005d4bbf();
  }
  *(undefined4 *)(extraout_ECX + 0x148) = 0;
LAB_00533bb3:
  *(undefined1 *)(extraout_ECX + 0x150) = 0;
  if (*(int *)(extraout_ECX + 0x14c) == 0) {
    iVar4 = *(int *)(*(int *)(extraout_ECX + 0xf4) + 0x20 + *(int *)(extraout_ECX + 0xe0) * 0x28);
    iVar5 = *(int *)(extraout_ECX + 0xf4) + *(int *)(extraout_ECX + 0xe0) * 0x28;
    if (iVar4 < 2) {
      __ftol();
      uVar6 = FUN_004096c2();
      FUN_00635858(extraout_ECX + 0x150,s__s__d_006cce50,uVar6);
    }
    else {
      if (iVar4 == 0) {
        fVar2 = 1.0;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        *(int *)(unaff_EBP + -0x18) = iVar4;
        fVar2 = *(float *)(iVar5 + 0x18) / (float)*(longlong *)(unaff_EBP + -0x18);
      }
      uVar6 = *(undefined4 *)(iVar5 + 0x18);
      *(float *)(unaff_EBP + 8) = fVar2;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
      uVar6 = FUN_004096c2();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      fVar8 = (float10)FUN_00533e2c();
      uVar6 = __ftol(iVar4,(double)*(float *)(unaff_EBP + 8),(double)fVar8);
      FUN_00635858(extraout_ECX + 0x150,s__s__d_Count____d_Avg____f_StdDev_006cce28,
                   *(undefined4 *)(unaff_EBP + -0x10),uVar6);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

