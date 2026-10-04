
undefined4 * FUN_0048bb59(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *extraout_ECX;
  undefined4 uVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_00492f28();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  *(undefined1 *)(extraout_ECX + 0x18) = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  *(undefined1 *)(extraout_ECX + 0x21) = 0;
  uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *extraout_ECX = &PTR_FUN_00667ef4;
  extraout_ECX[0xe] = uVar7;
  FUN_0048bff5(uVar2);
  extraout_ECX[9] = *(undefined4 *)(unaff_EBP + 0x10);
  extraout_ECX[10] = *(undefined4 *)(unaff_EBP + 0x14);
  if ((*(char *)(extraout_ECX + 0x18) == '\0') || (iVar4 = extraout_ECX[0x10], iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0048c2f4(iVar4);
    iVar4 = *(int *)(iVar4 + 0xc);
  }
  *(undefined1 *)(extraout_ECX + 0xf) = 0;
  if (iVar4 != 0) {
    *(bool *)(extraout_ECX + 0xf) = *(short *)(*(int *)(*(int *)(iVar4 + 0x11c) + 0x60) + 0x8a) != 0
    ;
    do {
      iVar5 = *(int *)(iVar4 + 0x134);
      iVar3 = *(int *)(iVar4 + 0x130);
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
      iVar5 = (iVar5 - iVar3) / 0x24 + -1;
      *(int *)(unaff_EBP + -0x18) = iVar5;
      if (0 < iVar5) {
        *(undefined4 *)(unaff_EBP + 8) = 0x24;
        do {
          if (*(int *)(unaff_EBP + 8) < 0x24) {
LAB_0048bc50:
            iVar5 = 0;
          }
          else {
            if ((*(int *)(iVar4 + 0x134) - *(int *)(iVar4 + 0x130)) / 0x24 + -1 <=
                *(int *)(unaff_EBP + 0x10)) goto LAB_0048bc50;
            iVar5 = *(int *)(iVar4 + 0x130) + *(int *)(unaff_EBP + 8);
          }
          if (iVar5 == 0) {
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
          }
          else {
            sVar1 = *(short *)(iVar5 + 0x10);
            iVar5 = *(int *)(iVar4 + 0xdc);
            uVar7 = 0;
            *(int *)(unaff_EBP + -0x10) = (int)sVar1;
            if ((0 < sVar1) &&
               (*(uint *)(unaff_EBP + -0x10) <
                (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U)) {
              uVar7 = *(undefined4 *)(*(int *)(iVar5 + 0x18) + -4 + *(int *)(unaff_EBP + -0x10) * 4)
              ;
            }
            *(undefined4 *)(unaff_EBP + -0x10) = uVar7;
          }
          if (*(int *)(unaff_EBP + -0x10) != 0) {
            pvVar6 = operator_new(0x88);
            *(void **)(unaff_EBP + -0x20) = pvVar6;
            *(undefined1 *)(unaff_EBP + -4) = 4;
            if (pvVar6 == (void *)0x0) {
              uVar7 = 0;
            }
            else {
              uVar7 = FUN_0048bb59(CONCAT22((short)((uint)*(int *)(unaff_EBP + -0x10) >> 0x10),
                                            *(undefined2 *)(*(int *)(unaff_EBP + -0x10) + 0xf0)),
                                   *(undefined4 *)(unaff_EBP + 0xc),0,
                                   *(undefined4 *)(unaff_EBP + 0x14));
            }
            *(undefined4 *)(unaff_EBP + -0x14) = uVar7;
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0048c4a2(unaff_EBP + -0x14);
          }
          *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x24;
        } while (*(int *)(unaff_EBP + 0x10) < *(int *)(unaff_EBP + -0x18));
      }
      iVar5 = *(int *)(iVar4 + 0x118);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      if (*(short *)(iVar5 + 0x14) != 0) {
        iVar4 = FUN_006359f2(iVar4,0,&cXObject::RTTI_Type_Descriptor,
                             &cXMTObject::RTTI_Type_Descriptor,0);
        if (iVar4 != 0) {
          *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar4 + 0x18c);
        }
      }
      iVar4 = *(int *)(unaff_EBP + 8);
    } while (iVar4 != 0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

