
undefined1 FUN_004e8d99(void)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 8);
  if ((uVar1 < (uint)((DAT_006f264c - DAT_006f2648) / 0x44)) &&
     (iVar8 = uVar1 * 0x44 + DAT_006f2648, iVar8 != 0)) {
    puVar4 = (undefined4 *)FUN_004e8a7a();
    if (puVar4 != (undefined4 *)0x0) {
      piVar7 = (int *)*puVar4;
      *(undefined1 *)(unaff_EBP + 0xb) = 1;
      *(int **)(unaff_EBP + -0x20) = piVar7;
      iVar5 = FUN_004e9744(uVar1);
      *(int *)(unaff_EBP + -0x14) = iVar5;
      if ((iVar5 == 0) || (*(int *)(unaff_EBP + 0xc) == 0x10)) {
        iVar5 = *piVar7;
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
        cVar2 = (**(code **)(iVar5 + 0x20))();
        if (cVar2 != '\0') {
          uVar6 = FUN_004e978e(uVar1);
          *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
        }
      }
      else {
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
      }
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        if ((*(byte *)(unaff_EBP + 0xc) & 1) != 0) {
          FUN_005c1719();
          *(undefined4 *)(unaff_EBP + -4) = 0;
          cVar2 = FUN_004e739b(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x18);
          if (cVar2 == '\0') {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
          }
          else {
            FUN_004e8ada(0,unaff_EBP + -0x18);
            if (*(int *)(unaff_EBP + 0x10) == 1) {
              FUN_004e913c(iVar8,0x7d2,s_faces_006c9e08,unaff_EBP + -0x18);
            }
            if (DAT_006f2658 != 0) {
              FUN_005c1719();
              *(undefined1 *)(unaff_EBP + -4) = 1;
              uVar6 = FUN_004096c2(DAT_006f2658,unaff_EBP + -0x1c);
              FUN_004e71be(uVar6);
              FUN_004e8ada(1,unaff_EBP + -0x1c);
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_005a5e09();
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
        }
        if ((*(byte *)(unaff_EBP + 0xc) & 8) != 0) {
          FUN_005c1719();
          *(undefined4 *)(unaff_EBP + -4) = 2;
          cVar2 = FUN_004e7584(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x1c);
          if (cVar2 == '\0') {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
          }
          else {
            FUN_004e8ada(2,unaff_EBP + -0x1c);
            if (*(int *)(unaff_EBP + 0x10) == 1) {
              FUN_004e913c(iVar8,0x7d3,s_rel__images_006c9dfc,unaff_EBP + -0x1c);
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
        }
        if ((*(byte *)(unaff_EBP + 0xc) & 2) != 0) {
          FUN_005c1719();
          piVar7 = DAT_006f265c;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          if (piVar7 != (int *)0x0) {
            uVar6 = (**(code **)(*piVar7 + 0x94))();
            FUN_005a5e48(uVar6);
          }
          cVar2 = FUN_005a5e72();
          if (cVar2 != '\0') {
            cVar2 = FUN_004e77ad(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x18);
            if (cVar2 != '\0') {
              FUN_004e8ada(3,unaff_EBP + -0x18);
              if (*(int *)(unaff_EBP + 0x10) == 1) {
                FUN_004e913c(iVar8,0x7d4,s_newimage_006c9df0,unaff_EBP + -0x18);
              }
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
        }
        if ((*(byte *)(unaff_EBP + 0xc) & 4) != 0) {
          FUN_005c1719();
          *(undefined4 *)(unaff_EBP + -4) = 4;
          cVar2 = FUN_004e8332(2,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x1c);
          if (cVar2 == '\0') {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
          }
          else {
            piVar7 = (int *)FUN_004096c2();
            (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
            FUN_004e8ada(4,unaff_EBP + -0x1c);
            if (*(int *)(unaff_EBP + 0x10) == 1) {
              FUN_004e913c(iVar8,0x7d5,s_speech_med_006c9de4,unaff_EBP + -0x1c);
            }
          }
          FUN_005c1719();
          *(undefined1 *)(unaff_EBP + -4) = 5;
          cVar2 = FUN_004e8332(3,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x18);
          if (cVar2 == '\0') {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
          }
          else {
            piVar7 = (int *)FUN_004096c2();
            (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
            FUN_004e8ada(5,unaff_EBP + -0x18);
            if (*(int *)(unaff_EBP + 0x10) == 1) {
              FUN_004e913c(iVar8,0x7d6,s_speech_large_006c9dd4,unaff_EBP + -0x18);
            }
          }
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005a5e09();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
        }
        if ((*(byte *)(unaff_EBP + 0xc) & 0x10) != 0) {
          FUN_005c1719();
          *(undefined4 *)(unaff_EBP + -4) = 6;
          cVar2 = FUN_004e853c(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + 0xc);
          if (cVar2 == '\0') {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
          }
          else {
            FUN_004e8ada(6,unaff_EBP + 0xc);
            if (*(int *)(unaff_EBP + 0x10) == 1) {
              FUN_004e913c(iVar8,0x7d7,s_web_image_006c9dc8,unaff_EBP + 0xc);
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
        }
        if (*(char *)(unaff_EBP + -0xd) != '\0') {
          FUN_0044127f(CONCAT22((short)((uint)*(int *)(unaff_EBP + -0x14) >> 0x10),
                                *(undefined2 *)(*(int *)(unaff_EBP + -0x14) + 0xf0)));
        }
        if (*(int *)(unaff_EBP + 0x10) == 1) {
          (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x1c))();
        }
        uVar3 = *(undefined1 *)(unaff_EBP + 0xb);
        goto LAB_004e912d;
      }
    }
  }
  uVar3 = 0;
LAB_004e912d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

