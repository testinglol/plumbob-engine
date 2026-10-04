
bool FUN_0045d377(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  undefined2 extraout_var;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  iVar2 = FUN_0041f101();
  if (iVar2 != 0) {
    if ((*(uint *)(iVar2 + 0x14) >> 2 & 1) == 0) {
      iVar2 = extraout_ECX + 0x820;
      *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar5 + 0x1c);
      FUN_0041f15a();
      if ((*(uint *)(iVar5 + 0x40) >> 1 & 1) == 0) {
        iVar4 = *(int *)(extraout_ECX + 0xa44) - *(int *)(extraout_ECX + 0xa40);
        *(int *)(unaff_EBP + -0x14) = iVar4;
        *(int *)(unaff_EBP + -0x10) = iVar4;
        while ((iVar4 != 0 &&
               (iVar4 = *(int *)(unaff_EBP + -0x10) + -1,
               *(int *)((*(int *)(extraout_ECX + 0xa40) + iVar4 & 7U) * 0x44 + 0x1c + iVar2) <
               *(int *)(unaff_EBP + 8)))) {
          *(int *)(unaff_EBP + -0x10) = iVar4;
        }
        if (*(int *)(unaff_EBP + -0x10) != *(int *)(unaff_EBP + -0x14)) {
          FUN_0045f887();
          *(undefined4 *)(unaff_EBP + 8) = 0;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (*(int *)(unaff_EBP + -0x10) != 0) {
            do {
              FUN_0045f8b0((*(int *)(extraout_ECX + 0xa40) + *(int *)(unaff_EBP + 8) & 7U) * 0x44 +
                           iVar2);
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
            } while (*(uint *)(unaff_EBP + 8) < *(uint *)(unaff_EBP + -0x10));
          }
          while (*(uint *)(unaff_EBP + 8) <
                 (uint)(*(int *)(extraout_ECX + 0xa44) - *(int *)(extraout_ECX + 0xa40))) {
            if (*(int *)((*(int *)(extraout_ECX + 0xa40) + *(int *)(unaff_EBP + 8) & 7U) * 0x44 +
                         iVar2 + 8) != 0) {
              FUN_00422d79(4,CONCAT22((short)((uint)*(int *)(unaff_EBP + 8) >> 0x10),
                                      *(undefined2 *)(extraout_ECX + 0xf0)),0);
            }
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
          }
          iVar2 = *(int *)(unaff_EBP + -0x10);
          *(undefined4 *)(extraout_ECX + 0xa44) = 0;
          *(undefined4 *)(extraout_ECX + 0xa40) = 0;
          *(undefined4 *)(unaff_EBP + 8) = 0;
          if (iVar2 != 0) {
            do {
              FUN_0045f8b0(unaff_EBP + -0x484 +
                           (*(int *)(unaff_EBP + -0x264) + *(int *)(unaff_EBP + 8) & 7U) * 0x44);
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
            } while (*(uint *)(unaff_EBP + 8) < *(uint *)(unaff_EBP + -0x10));
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00635f6d(unaff_EBP + -0x484,0x44,8,FUN_004434c5);
        }
        if ((DAT_006e5244 != 0) && (extraout_ECX == DAT_006e5248)) {
          if ((*(uint *)(iVar5 + 0x40) >> 6 & 1) != 0) {
            uVar3 = FUN_0041f169();
            FUN_0041f1b0(uVar3);
          }
          FUN_0041edc1(iVar5);
        }
        cVar1 = FUN_0045f8b0(iVar5);
        bVar7 = cVar1 != '\0';
        goto LAB_0045d753;
      }
      if ((*(uint *)(iVar5 + 0x40) >> 6 & 1) != 0) {
        uVar3 = FUN_0041f169();
        FUN_0041f1b0(uVar3);
      }
      FUN_0045f887();
      *(undefined4 *)(unaff_EBP + -4) = 1;
      cVar1 = FUN_0045f8b0(iVar5);
      if (cVar1 != '\0') {
        iVar5 = *(int *)(extraout_ECX + 0xa40);
        if ((uint)(*(int *)(extraout_ECX + 0xa44) - iVar5) < 8) {
          uVar6 = 0;
          if (*(int *)(extraout_ECX + 0xa44) != iVar5) {
            do {
              cVar1 = FUN_0045f8b0((iVar5 + uVar6 & 7) * 0x44 + iVar2);
              if (cVar1 == '\0') goto LAB_0045d557;
              iVar5 = *(int *)(extraout_ECX + 0xa40);
              uVar6 = uVar6 + 1;
            } while (uVar6 < (uint)(*(int *)(extraout_ECX + 0xa44) - iVar5));
          }
          iVar5 = *(int *)(unaff_EBP + -0x38);
          *(undefined4 *)(extraout_ECX + 0xa44) = 0;
          *(undefined4 *)(extraout_ECX + 0xa40) = 0;
          uVar6 = 0;
          if (iVar5 != *(int *)(unaff_EBP + -0x3c)) {
            do {
              FUN_0045f8b0(unaff_EBP + -0x25c + (*(int *)(unaff_EBP + -0x3c) + uVar6 & 7) * 0x44);
              uVar6 = uVar6 + 1;
            } while (uVar6 < (uint)(*(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x3c)));
          }
        }
        else {
          iVar5 = 0;
          do {
            cVar1 = FUN_0045f8b0((*(int *)(extraout_ECX + 0xa40) + iVar5 & 7U) * 0x44 + iVar2);
            if (cVar1 == '\0') goto LAB_0045d557;
            iVar5 = iVar5 + 1;
          } while (iVar5 < 7);
          iVar5 = 0;
          *(undefined4 *)(extraout_ECX + 0xa44) = 0;
          *(undefined4 *)(extraout_ECX + 0xa40) = 0;
          do {
            FUN_0045f8b0(unaff_EBP + -0x25c + (*(int *)(unaff_EBP + -0x3c) + iVar5 & 7U) * 0x44);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 7);
        }
        bVar7 = true;
        goto LAB_0045d559;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00635f6d(unaff_EBP + -0x25c,0x44,8,FUN_004434c5);
    }
    else {
      iVar2 = *(int *)(iVar5 + 8);
      FUN_00458419(extraout_ECX,iVar2,0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00458485(iVar5,0);
      if ((*(uint *)(iVar5 + 0x40) >> 3 & 1) != 0) {
        if (DAT_006e5244 == 0) {
          DAT_006e5244 = iVar5;
          *(undefined2 *)(unaff_EBP + 8) = *(undefined2 *)(extraout_ECX + 0x5ce);
          uVar3 = *(undefined4 *)(iVar5 + 0x1c);
          *(short *)(extraout_ECX + 0x5ce) = (short)uVar3;
          FUN_00474c68(*(undefined4 *)(*(int *)(iVar2 + 0x11c) + 0xc),
                       CONCAT22(extraout_var,*(undefined2 *)(iVar2 + 0xf0)),
                       CONCAT22((short)((uint)uVar3 >> 0x10),*(undefined2 *)(iVar5 + 0x20)),
                       iVar5 + 0x14);
          DAT_006e5244 = 0;
          DAT_006e5248 = 0;
          *(undefined2 *)(extraout_ECX + 0x5ce) = *(undefined2 *)(unaff_EBP + 8);
          if (*(int *)(iVar5 + 0x3c) == 0) {
            FUN_0041f15a();
          }
          bVar7 = true;
        }
        else {
          bVar7 = false;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00458449();
        goto LAB_0045d753;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00458449();
    }
  }
  bVar7 = false;
  goto LAB_0045d753;
LAB_0045d557:
  bVar7 = false;
LAB_0045d559:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00635f6d(unaff_EBP + -0x25c,0x44,8,FUN_004434c5);
LAB_0045d753:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar7;
}

