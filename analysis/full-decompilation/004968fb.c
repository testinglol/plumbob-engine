
void FUN_004968fb(void)

{
  char *pcVar1;
  char *pcVar2;
  int *piVar3;
  undefined1 uVar4;
  char cVar5;
  char cVar8;
  undefined4 uVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar7 = *(int *)(extraout_ECX + 0xe040);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0xe058) = 0;
  *(undefined4 *)(extraout_ECX + 0xe05c) = 0;
  if ((iVar7 != 0) && (iVar7 != 1)) {
    if (iVar7 == 2) {
      cVar5 = (char)*(undefined4 *)(unaff_EBP + 8);
      pcVar1 = (char *)(extraout_ECX + 0xe02c);
      cVar8 = (char)((uint)*(undefined4 *)(unaff_EBP + 8) >> 8);
      if (((*(char *)(extraout_ECX + 0xe02c) == cVar5) &&
          (*(char *)(extraout_ECX + 0xe02d) == cVar8)) &&
         (*(char *)(extraout_ECX + 0xe02e) == *(char *)(unaff_EBP + 10))) {
        FUN_00495076();
      }
      else if (((*(char *)(extraout_ECX + 0xe030) != cVar5) ||
               (*(char *)(extraout_ECX + 0xe031) != cVar8)) ||
              (*(char *)(extraout_ECX + 0xe032) != *(char *)(unaff_EBP + 10))) {
        FUN_00494fb9();
        *(undefined1 *)(unaff_EBP + -0x12) = 0;
        *(undefined1 *)(unaff_EBP + -0xe) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        cVar5 = FUN_004965e8(pcVar1,unaff_EBP + 8,unaff_EBP + -0x14,unaff_EBP + -0x10);
        if (cVar5 == '\0') {
          FUN_00492c37();
          FUN_00494fb9();
          uVar6 = *(undefined4 *)(unaff_EBP + 8);
          *(char *)(extraout_ECX + 0xe030) = (char)uVar6;
          uVar4 = *(undefined1 *)(unaff_EBP + 10);
          *(char *)(extraout_ECX + 0xe031) = (char)((uint)uVar6 >> 8);
          *(undefined1 *)(extraout_ECX + 0xe032) = uVar4;
          uVar4 = *(undefined1 *)(extraout_ECX + 0xe060);
          FUN_004965e8(pcVar1,extraout_ECX + 0xe048,unaff_EBP + -0x14,unaff_EBP + -0x10);
          *(undefined1 *)(extraout_ECX + 0xe060) = uVar4;
          if (((*pcVar1 == *(char *)(extraout_ECX + 0xe04b)) &&
              (*(char *)(extraout_ECX + 0xe02d) == *(char *)(extraout_ECX + 0xe04c))) &&
             (*(char *)(extraout_ECX + 0xe02e) == *(char *)(extraout_ECX + 0xe04d))) {
            uVar6 = *(undefined4 *)(unaff_EBP + 8);
            *(char *)(extraout_ECX + 0xe04b) = (char)uVar6;
            uVar4 = *(undefined1 *)(unaff_EBP + 10);
            *(char *)(extraout_ECX + 0xe04c) = (char)((uint)uVar6 >> 8);
            *(undefined1 *)(extraout_ECX + 0xe04d) = uVar4;
          }
          *(undefined1 *)(extraout_ECX + 0xe030) = *(undefined1 *)(extraout_ECX + 0xe04b);
          *(undefined1 *)(extraout_ECX + 0xe031) = *(undefined1 *)(extraout_ECX + 0xe04c);
          *(undefined1 *)(extraout_ECX + 0xe032) = *(undefined1 *)(extraout_ECX + 0xe04d);
        }
        else {
          *(undefined1 *)(extraout_ECX + 0xe030) = *(undefined1 *)(unaff_EBP + -0x10);
          *(undefined1 *)(extraout_ECX + 0xe031) = *(undefined1 *)(unaff_EBP + -0xf);
          *(undefined1 *)(extraout_ECX + 0xe032) = *(undefined1 *)(unaff_EBP + -0xe);
          *(undefined1 *)(extraout_ECX + 0xe048) = *(undefined1 *)(extraout_ECX + 0xe030);
          *(undefined1 *)(extraout_ECX + 0xe049) = *(undefined1 *)(extraout_ECX + 0xe031);
          *(undefined1 *)(extraout_ECX + 0xe04a) = *(undefined1 *)(extraout_ECX + 0xe032);
          *(char *)(extraout_ECX + 0xe04b) = *pcVar1;
          *(undefined1 *)(extraout_ECX + 0xe04c) = *(undefined1 *)(extraout_ECX + 0xe02d);
          *(undefined1 *)(extraout_ECX + 0xe04d) = *(undefined1 *)(extraout_ECX + 0xe02e);
        }
        uVar6 = FUN_00636bef((int)*pcVar1 - (int)*(char *)(extraout_ECX + 0xe030));
        *(undefined4 *)(extraout_ECX + 0xe058) = uVar6;
        uVar6 = FUN_00636bef((int)*(char *)(extraout_ECX + 0xe02d) -
                             (int)*(char *)(extraout_ECX + 0xe031));
        *(undefined4 *)(extraout_ECX + 0xe05c) = uVar6;
      }
    }
    goto LAB_0049695e;
  }
  if (*(int *)(extraout_ECX + 0xe034) == 8) {
    iVar7 = FUN_00494906(extraout_ECX + 0xe02c,unaff_EBP + 8);
    *(int *)(extraout_ECX + 0xe034) = iVar7;
    if (iVar7 != 8) goto LAB_00496b25;
  }
  else {
LAB_00496b25:
    pcVar1 = (char *)(extraout_ECX + 0xe02c);
    FUN_004949f0(pcVar1,unaff_EBP + 8,*(undefined4 *)(extraout_ECX + 0xe034));
    if (((*pcVar1 != (char)*(undefined4 *)(unaff_EBP + 8)) ||
        (*(char *)(extraout_ECX + 0xe02d) != (char)((uint)*(undefined4 *)(unaff_EBP + 8) >> 8))) ||
       (*(char *)(extraout_ECX + 0xe02e) != *(char *)(unaff_EBP + 10))) {
      FUN_00494fb9();
      pcVar2 = (char *)(extraout_ECX + 0xe030);
      cVar5 = FUN_0049651f(pcVar1,unaff_EBP + 8,*(undefined4 *)(extraout_ECX + 0xe034),
                           *(undefined4 *)(extraout_ECX + 0xe040),pcVar2);
      if (cVar5 == '\0') {
        FUN_00492c37();
        if (*(char *)(extraout_ECX + 0xe060) == '\x01') {
          if (((*pcVar1 == *(char *)(extraout_ECX + 0xe04b)) &&
              (*(char *)(extraout_ECX + 0xe02d) == *(char *)(extraout_ECX + 0xe04c))) &&
             (*(char *)(extraout_ECX + 0xe02e) == *(char *)(extraout_ECX + 0xe04d))) {
            uVar6 = *(undefined4 *)(unaff_EBP + 8);
            *(char *)(extraout_ECX + 0xe04b) = (char)uVar6;
            uVar4 = *(undefined1 *)(unaff_EBP + 10);
            *(char *)(extraout_ECX + 0xe04c) = (char)((uint)uVar6 >> 8);
            *(undefined1 *)(extraout_ECX + 0xe04d) = uVar4;
          }
          *pcVar2 = *(char *)(extraout_ECX + 0xe04b);
          *(undefined1 *)(extraout_ECX + 0xe031) = *(undefined1 *)(extraout_ECX + 0xe04c);
          *(undefined1 *)(extraout_ECX + 0xe032) = *(undefined1 *)(extraout_ECX + 0xe04d);
        }
        else {
          *pcVar2 = *(char *)(extraout_ECX + 0xe048);
          *(undefined1 *)(extraout_ECX + 0xe031) = *(undefined1 *)(extraout_ECX + 0xe049);
          *(undefined1 *)(extraout_ECX + 0xe032) = *(undefined1 *)(extraout_ECX + 0xe04a);
          *(char *)(extraout_ECX + 0xe04b) = *pcVar1;
          *(undefined1 *)(extraout_ECX + 0xe04c) = *(undefined1 *)(extraout_ECX + 0xe02d);
          *(undefined1 *)(extraout_ECX + 0xe04d) = *(undefined1 *)(extraout_ECX + 0xe02e);
        }
      }
      else {
        uVar6 = *(undefined4 *)(unaff_EBP + 8);
        *pcVar2 = (char)uVar6;
        uVar4 = *(undefined1 *)(unaff_EBP + 10);
        *(char *)(extraout_ECX + 0xe031) = (char)((uint)uVar6 >> 8);
        *(undefined1 *)(extraout_ECX + 0xe032) = uVar4;
        *(char *)(extraout_ECX + 0xe048) = *pcVar2;
        *(undefined1 *)(extraout_ECX + 0xe049) = *(undefined1 *)(extraout_ECX + 0xe031);
        *(undefined1 *)(extraout_ECX + 0xe04a) = *(undefined1 *)(extraout_ECX + 0xe032);
        *(char *)(extraout_ECX + 0xe04b) = *pcVar1;
        *(undefined1 *)(extraout_ECX + 0xe04c) = *(undefined1 *)(extraout_ECX + 0xe02d);
        *(undefined1 *)(extraout_ECX + 0xe04d) = *(undefined1 *)(extraout_ECX + 0xe02e);
        uVar6 = FUN_00636bef((int)*pcVar1 - (int)*pcVar2);
        *(undefined4 *)(extraout_ECX + 0xe058) = uVar6;
        iVar7 = FUN_00636bef((int)*(char *)(extraout_ECX + 0xe02d) -
                             (int)*(char *)(extraout_ECX + 0xe031));
        *(int *)(extraout_ECX + 0xe05c) = iVar7;
        if (*(int *)(extraout_ECX + 0xe058) == iVar7) {
          *(undefined4 *)(extraout_ECX + 0xe058) = 0;
        }
        piVar3 = (int *)(extraout_ECX + 0xe054);
        while (*piVar3 < *(int *)(extraout_ECX + 0xe050)) {
          FUN_00492cca();
          *piVar3 = *piVar3 + 1;
        }
      }
      goto LAB_0049695e;
    }
  }
  FUN_00495076();
  *(undefined4 *)(extraout_ECX + 0xe054) = 0;
LAB_0049695e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

