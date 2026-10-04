
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005904d6(void)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  
  FUN_00634c24();
  if (((*(int *)(extraout_ECX + 0x144) != 0) && (*(int *)(extraout_ECX + 0x14c) != 0)) &&
     (iVar1 = *(int *)(extraout_ECX + 0x138), (*(ushort *)(iVar1 + 0x5e0) & 1) != 0)) {
    if (*(short *)(iVar1 + 0x5de) != 0) {
      iVar5 = FUN_00407498((int)*(short *)(iVar1 + 0x5de));
      if (iVar5 == 0) {
        *(undefined2 *)(iVar1 + 0x5de) = 0;
        *(undefined2 *)(iVar1 + 0x5e0) = 0x10;
      }
      else {
        if (*(short *)(*(int *)(iVar5 + 0x118) + 0x12) == 2) {
          piVar6 = (int *)FUN_006359f2(iVar5,0,&cXObject::RTTI_Type_Descriptor,
                                       &cXPerson::RTTI_Type_Descriptor,0);
          (**(code **)(*piVar6 + 0x8c))();
          FUN_005928fd(1,extraout_ECX + 0x21c);
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar5 + 0xf4);
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar5 + 0xf8);
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          puVar7 = (undefined4 *)FUN_00454f9c(unaff_EBP + -0xc0,unaff_EBP + -0x2c,unaff_EBP + -0x14)
          ;
          *(undefined4 *)(extraout_ECX + 0x21c) = *puVar7;
          uVar2 = puVar7[2];
          *(undefined4 *)(extraout_ECX + 0x220) = puVar7[1];
          *(undefined4 *)(extraout_ECX + 0x224) = uVar2;
        }
        iVar1 = *(int *)(extraout_ECX + 0x138);
        if (*(int *)(iVar5 + 0x110) != *(int *)(iVar1 + 0x110)) {
          *(undefined2 *)(iVar1 + 0x5de) = 0;
          *(undefined2 *)(iVar1 + 0x5e0) = 0x10;
        }
      }
    }
    FUN_005c35b0();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005963ab(unaff_EBP + -0xb4);
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x84);
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x7c);
    FUN_005c35b0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005963ab(unaff_EBP + -0x70);
    fVar3 = *(float *)(unaff_EBP + -0x40) - *(float *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(float *)(unaff_EBP + -0x18) = fVar3;
    fVar4 = *(float *)(unaff_EBP + -0x38) - *(float *)(unaff_EBP + -0x1c);
    *(float *)(unaff_EBP + -0x10) = fVar4;
    fVar8 = (float10)_DAT_0066c7bc;
    fVar9 = (float10)_DAT_0066657c;
    if ((float)_DAT_006669e8 < fVar3 * fVar3 + fVar4 * fVar4) {
      fVar11 = (float10)fpatan((float10)*(float *)(unaff_EBP + -0x10),
                               -(float10)*(float *)(unaff_EBP + -0x18));
      for (fVar11 = (fVar11 / ((float10)_DAT_00671ed8 + (float10)_DAT_00671ed8)) * fVar8;
          fVar11 < fVar9; fVar11 = fVar11 + fVar8) {
      }
      for (; fVar8 <= fVar11; fVar11 = fVar11 - fVar8) {
      }
      *(float *)(extraout_ECX + 0x210) = (float)fVar11;
    }
    fVar11 = (float10)*(float *)(extraout_ECX + 0x21c) - (float10)*(float *)(unaff_EBP + -0x24);
    fVar10 = (float10)*(float *)(extraout_ECX + 0x224) - (float10)*(float *)(unaff_EBP + -0x1c);
    if ((float10)_DAT_006669e8 < fVar11 * fVar11 + fVar10 * fVar10) {
      fVar11 = (float10)fpatan(fVar10,-fVar11);
      *(float *)(unaff_EBP + -0x10) =
           (float)((fVar11 / ((float10)_DAT_00671ed8 + (float10)_DAT_00671ed8)) * fVar8);
      fVar11 = (float10)*(float *)(unaff_EBP + -0x10);
      while (fVar11 < fVar9) {
        fVar11 = (float10)*(float *)(unaff_EBP + -0x10) + fVar8;
        *(float *)(unaff_EBP + -0x10) = (float)fVar11;
      }
      fVar9 = (float10)*(float *)(unaff_EBP + -0x10);
      while (fVar8 <= fVar9) {
        fVar9 = (float10)*(float *)(unaff_EBP + -0x10) - fVar8;
        *(float *)(unaff_EBP + -0x10) = (float)fVar9;
      }
      *(undefined4 *)(extraout_ECX + 0x214) = *(undefined4 *)(unaff_EBP + -0x10);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005c4890();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c4890();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

