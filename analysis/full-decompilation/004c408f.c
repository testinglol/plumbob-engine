
uint FUN_004c408f(void)

{
  short sVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 extraout_var;
  uint uVar7;
  int extraout_ECX;
  int unaff_EBP;
  undefined2 uVar8;
  
  FUN_00634c24();
  sVar1 = *(short *)(unaff_EBP + 8);
  if ((sVar1 < 0x9a) || (0x9d < sVar1)) {
    if (((0x3f1 < sVar1) && (sVar1 < 0x3f6)) || ((9999 < sVar1 && (sVar1 < 0x271c)))) {
      iVar4 = FUN_006359f2(*(undefined4 *)(extraout_ECX + 0x18),0,
                           &cTerrainRenderer::RTTI_Type_Descriptor,
                           &cGouraudSwatch::RTTI_Type_Descriptor,0);
      iVar5 = FUN_006359f2(*(undefined4 *)(extraout_ECX + 0x18),0,
                           &cTerrainRenderer::RTTI_Type_Descriptor,
                           &cColorSwatch::RTTI_Type_Descriptor,0);
      sVar1 = *(short *)(unaff_EBP + 8);
      uVar6 = (uint)sVar1;
      *(int *)(unaff_EBP + -0x10) = iVar5;
      if ((int)uVar6 < 0x2719) {
        if (uVar6 == 0x2718) {
          if (iVar5 != 0) {
            FUN_0049c4f6();
            FUN_0049c5b9();
          }
        }
        else {
          if ((int)uVar6 < 0x3f2) {
LAB_004c43d4:
            uVar6 = uVar6 & 0xffff0000;
            goto LAB_004c43fb;
          }
          if ((int)uVar6 < 0x3f4) {
            if (iVar4 != 0) {
              if (sVar1 == 0x3f2) {
                FUN_004a47b8();
              }
              else {
                FUN_004a47e5();
              }
            }
          }
          else if (uVar6 == 0x3f5) {
            if (iVar4 != 0) {
              FUN_004a4848();
            }
          }
          else {
            if (((int)uVar6 < 10000) || (0x2717 < (int)uVar6)) goto LAB_004c43d4;
            if (iVar4 != 0) {
              if (sVar1 == 10000) {
                FUN_004a4869(1);
              }
              if (sVar1 == 0x2711) {
                FUN_004a4869(0xffffffff);
              }
              if (sVar1 == 0x2712) {
                FUN_004a4891(1);
              }
              if (sVar1 == 0x2713) {
                FUN_004a4891(0xffffffff);
              }
              if (sVar1 == 0x2714) {
                FUN_004a48ba(1);
              }
              if (sVar1 == 0x2715) {
                FUN_004a48ba(0xffffffff);
              }
            }
            if (*(int *)(unaff_EBP + -0x10) != 0) {
              if (sVar1 == 0x2716) {
                FUN_0049e0f1(1);
              }
              if (sVar1 == 0x2717) {
                FUN_0049e0f1(0xffffffff);
              }
            }
          }
        }
      }
      else if (uVar6 == 0x2719) {
        if (iVar4 != 0) {
          FUN_004a4812();
        }
      }
      else {
        uVar6 = uVar6 - 0x271a;
        if (uVar6 != 0) goto LAB_004c43d4;
        if (iVar5 != 0) {
          FUN_0049e121();
        }
      }
      goto LAB_004c43e3;
    }
    uVar6 = (uint)sVar1;
    if ((int)uVar6 < 0xde) {
      if (uVar6 == 0xdd) {
        (**(code **)(**(int **)(extraout_ECX + 0x18) + 0x20))
                  ((int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18));
      }
      else {
        if ((int)uVar6 < 0x84) goto LAB_004c43d4;
        uVar7 = uVar6;
        if ((int)uVar6 < 0x87) goto LAB_004c43f3;
        if (uVar6 == 0xbb) {
          *(bool *)(extraout_ECX + 0x1d) = *(char *)(extraout_ECX + 0x1d) == '\0';
        }
        else {
          if (uVar6 != 0xbc) goto LAB_004c43d4;
          *(bool *)(extraout_ECX + 0x1c) = *(char *)(extraout_ECX + 0x1c) == '\0';
        }
      }
      goto LAB_004c43e3;
    }
    uVar7 = 0;
    if ((uVar6 != 0x101) && (uVar7 = 0, uVar6 != 0x105)) {
      uVar6 = uVar6 - 800;
      if (uVar6 != 0) goto LAB_004c43d4;
      *(bool *)(extraout_ECX + 0x1f) = *(char *)(extraout_ECX + 0x1f) == '\0';
      goto LAB_004c43e3;
    }
LAB_004c43f3:
    uVar8 = (undefined2)(uVar7 >> 0x10);
    *(undefined1 *)(extraout_ECX + 0x1e) = 1;
  }
  else {
    if (sVar1 == 0x9a) {
      pvVar3 = operator_new(0x68);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
LAB_004c4151:
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)FUN_004a46d5();
      }
LAB_004c4153:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    else {
      if (sVar1 == 0x9b) {
        pvVar3 = operator_new(0x388);
        *(void **)(unaff_EBP + 8) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar3 == (void *)0x0) goto LAB_004c4151;
        piVar2 = (int *)FUN_0049c24d();
        goto LAB_004c4153;
      }
      if (sVar1 == 0x9c) {
        piVar2 = operator_new(0xc);
        if (piVar2 != (int *)0x0) {
          *piVar2 = (int)&PTR_FUN_006688a0;
          piVar2[1] = 2;
          goto LAB_004c40eb;
        }
LAB_004c40f4:
        piVar2 = (int *)0x0;
      }
      else {
        if (sVar1 != 0x9d) goto LAB_004c43e3;
        piVar2 = operator_new(0xc);
        if (piVar2 == (int *)0x0) goto LAB_004c40f4;
        *piVar2 = (int)&PTR_FUN_006688a0;
        piVar2[1] = 4;
LAB_004c40eb:
        piVar2[2] = 3;
      }
    }
    if (piVar2 != (int *)0x0) {
      sVar1 = (**(code **)(*piVar2 + 4))();
      if (sVar1 == 0) {
        (**(code **)*piVar2)(1);
        piVar2 = (int *)0x0;
      }
      if (piVar2 != (int *)0x0) {
        if (*(int **)(extraout_ECX + 0x18) != (int *)0x0) {
          (**(code **)(**(int **)(extraout_ECX + 0x18) + 8))();
          if (*(undefined4 **)(extraout_ECX + 0x18) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(extraout_ECX + 0x18))(1);
          }
        }
        *(int **)(extraout_ECX + 0x18) = piVar2;
        *(undefined1 *)(extraout_ECX + 0x1e) = 1;
      }
    }
LAB_004c43e3:
    FUN_0040766a(0x83,0);
    uVar8 = extraout_var;
  }
  uVar6 = CONCAT22(uVar8,1);
LAB_004c43fb:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

