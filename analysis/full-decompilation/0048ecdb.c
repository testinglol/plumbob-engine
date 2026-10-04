
void FUN_0048ecdb(void)

{
  undefined1 uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int extraout_ECX;
  int iVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x58) == '\0') goto LAB_0048f0c1;
  *(undefined4 *)(extraout_ECX + 0x54) = 0;
  FUN_00486459(0);
  *(char *)(unaff_EBP + -0x20) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + -0x1f) = (char)(*(int *)(unaff_EBP + 8) >> 4);
  *(undefined1 *)(unaff_EBP + -0x1e) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar4 = FUN_00492b26();
  if (iVar4 < 2) {
    iVar4 = FUN_0048f140();
    if (iVar4 != 0) {
      FUN_004616c3(*(undefined4 *)(extraout_ECX + 0x3c));
    }
    if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)*(char *)(unaff_EBP + -0x20)) &&
         ((int)*(char *)(unaff_EBP + -0x20) <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
        (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + -0x1f))) &&
       ((int)*(char *)(unaff_EBP + -0x1f) <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
      FUN_00461b74(&DAT_006e482b);
      *(undefined1 *)(unaff_EBP + -0x12) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x14);
      if ((((int)*pcVar5 < *(int *)(DAT_006e54d8 + 0x70) + 1) ||
          (*(int *)(DAT_006e54d8 + 0x74) + -1 < (int)*pcVar5)) ||
         (((int)pcVar5[1] < *(int *)(DAT_006e54d8 + 0x78) + 1 ||
          (*(int *)(DAT_006e54d8 + 0x7c) + -1 < (int)pcVar5[1])))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      if (!bVar2) {
        FUN_00461b74(&DAT_006e482b);
        *(undefined1 *)(unaff_EBP + -0x12) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        uVar6 = FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -0x2a) = 0;
        *(undefined1 *)(unaff_EBP + -0x27) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_00461b74(unaff_EBP + -0x20);
        FUN_00461b74(uVar6);
        iVar4 = extraout_ECX + 0x40;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        if (iVar4 != unaff_EBP + -0x2c) {
          FUN_00461b74(unaff_EBP + -0x2c);
          FUN_00461b74(unaff_EBP + -0x29);
        }
        iVar8 = DAT_006e54d8;
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_0048f0d1(-*(int *)(iVar8 + 0x84) & 3);
        iVar8 = DAT_006e54d8;
        iVar9 = (int)*(char *)(unaff_EBP + -0x20);
        if (*(int *)(extraout_ECX + 0x2c) == 0) {
          if ((((iVar9 < *(int *)(DAT_006e54d8 + 0x70) + 1) ||
               (*(int *)(DAT_006e54d8 + 0x74) + -1 < iVar9)) ||
              ((int)*(char *)(unaff_EBP + -0x1f) < *(int *)(DAT_006e54d8 + 0x78) + 1)) ||
             (*(int *)(DAT_006e54d8 + 0x7c) + -1 < (int)*(char *)(unaff_EBP + -0x1f))) {
            _memset((void *)(extraout_ECX + 0x50),0,4);
          }
          else {
            *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x20);
            *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x1f);
            *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x1e);
            iVar8 = *(int *)(iVar8 + 0x84);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            uVar6 = FUN_00434ffd(-iVar8 & 3);
            puVar7 = (undefined4 *)FUN_004905f5(uVar6);
            uVar6 = *puVar7;
            *(undefined1 *)(unaff_EBP + -4) = 0;
            *(undefined4 *)(extraout_ECX + 0x50) = uVar6;
          }
          cVar3 = FUN_0048fc3a(iVar4);
          if (cVar3 == '\0') {
            iVar8 = FUN_00461e56(0,0,0,0,1);
            *(int *)(unaff_EBP + 0xc) = iVar8;
            *(undefined1 *)(unaff_EBP + -4) = 8;
            if (iVar4 != iVar8) {
              FUN_00461b74(iVar8);
              iVar4 = *(int *)(unaff_EBP + 0xc);
LAB_0048ef24:
              FUN_00461b74(iVar4 + 3);
            }
          }
          else {
            *(undefined1 *)(unaff_EBP + -0x1c) = *(undefined1 *)(unaff_EBP + -0x20);
            *(undefined1 *)(unaff_EBP + -0x1b) = *(undefined1 *)(unaff_EBP + -0x1f);
            *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(unaff_EBP + -0x1e);
            iVar8 = DAT_006e54d8;
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_00434ffd(-*(int *)(iVar8 + 0x84) & 3);
            if (*(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x38) + 0x10) +
                                  *(char *)(unaff_EBP + -0x1c) * 4) +
                         (int)*(char *)(unaff_EBP + -0x1b)) < 0x10) {
              iVar8 = FUN_00461e56(0,0,0,0,1);
              *(int *)(unaff_EBP + 0xc) = iVar8;
              *(undefined1 *)(unaff_EBP + -4) = 10;
              if (iVar4 != iVar8) {
                FUN_00461b74(iVar8);
                iVar4 = *(int *)(unaff_EBP + 0xc);
                goto LAB_0048ef24;
              }
            }
            else {
              DAT_006e57e0 = *(undefined4 *)(unaff_EBP + 8);
              DAT_006e57e4 = *(undefined4 *)(unaff_EBP + 0xc);
              FUN_00461891(iVar4);
              FUN_004903f2(*(undefined4 *)(extraout_ECX + 0x38));
            }
          }
        }
        else {
          if (((iVar9 < *(int *)(DAT_006e54d8 + 0x70) + 1) ||
              (*(int *)(DAT_006e54d8 + 0x74) + -1 < iVar9)) ||
             (((int)*(char *)(unaff_EBP + -0x1f) < *(int *)(DAT_006e54d8 + 0x78) + 1 ||
              (*(int *)(DAT_006e54d8 + 0x7c) + -1 < (int)*(char *)(unaff_EBP + -0x1f)))))
          goto LAB_0048f091;
          cVar3 = FUN_0049004a(iVar4);
          if (cVar3 == '\0') {
            iVar8 = FUN_00461e56(0,0,0,0,1);
            *(int *)(unaff_EBP + 0xc) = iVar8;
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            if (iVar4 != iVar8) {
              FUN_00461b74(iVar8);
              iVar4 = *(int *)(unaff_EBP + 0xc);
              goto LAB_0048ef24;
            }
          }
          else {
            uVar1 = *(undefined1 *)(unaff_EBP + -0x20);
            *(undefined4 *)(extraout_ECX + 0x48) = 0;
            *(undefined1 *)(unaff_EBP + 0xc) = uVar1;
            *(undefined1 *)(unaff_EBP + 0xd) = *(undefined1 *)(unaff_EBP + -0x1f);
            *(undefined1 *)(unaff_EBP + 0xe) = *(undefined1 *)(unaff_EBP + -0x1e);
            iVar4 = DAT_006e54d8;
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            FUN_00434ffd(-*(int *)(iVar4 + 0x84) & 3);
            if (*(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x38) + 0x10) +
                                  *(char *)(unaff_EBP + 0xc) * 4) + (int)*(char *)(unaff_EBP + 0xd))
                < 0x10) {
              FUN_00461a14(unaff_EBP + 0xc);
            }
          }
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        goto LAB_0048f098;
      }
    }
LAB_0048f091:
    *(undefined4 *)(extraout_ECX + 0x54) = 1;
  }
  else {
    *(undefined4 *)(extraout_ECX + 0x54) = 0x1f;
  }
LAB_0048f098:
  iVar4 = *(int *)(extraout_ECX + 0x54);
  if (iVar4 == 0) {
    if ((*(int *)(extraout_ECX + 0x48) != 0) && (*(int *)(extraout_ECX + 0x2c) == 0)) {
      iVar4 = 0x1a;
      uVar6 = DAT_006c5fe8;
      goto LAB_0048f0b7;
    }
  }
  else {
    uVar6 = 0xffffffff;
LAB_0048f0b7:
    FUN_004864ed(iVar4,uVar6);
  }
  *(undefined4 *)(extraout_ECX + 0x48) = 0;
LAB_0048f0c1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

