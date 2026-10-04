
void FUN_00486603(void)

{
  undefined1 uVar1;
  char cVar2;
  SHORT SVar3;
  short sVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  int *extraout_ECX;
  uint uVar10;
  int iVar11;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 0x1c))
            (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
             *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  SVar3 = GetKeyState(0x10);
  *(bool *)(unaff_EBP + -0xd) = SVar3 < 0;
  SVar3 = GetKeyState(0x11);
  if ((SVar3 < 0) && ((extraout_ECX[0xd] == 4 || (extraout_ECX[0xd] == 3)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined1 *)((int)extraout_ECX + 0x79) = uVar1;
  if ((DAT_006e4a7c == 0) && (extraout_ECX[0xd] == 2)) {
    FUN_0057a7f7(s_UI_object_place_006c5eb8,0xfffffffc);
  }
  if ((*(char *)((int)extraout_ECX + 0x77) == '\0') || (*(char *)((int)extraout_ECX + 0x79) == '\0')
     ) {
    if (extraout_ECX[0xf] != 0) {
      iVar7 = (int)*(short *)(*(int *)(unaff_EBP + 0x14) + 0xe);
      iVar11 = (int)*(short *)(*(int *)(unaff_EBP + 0x14) + 0xc);
      *(int *)(unaff_EBP + -0x1c) = iVar11;
      iVar11 = iVar11 - extraout_ECX[0x1a];
      *(int *)(unaff_EBP + -0x14) = iVar7;
      iVar7 = iVar7 - extraout_ECX[0x19];
      *(undefined1 *)(extraout_ECX + 0x1d) = 0;
      *(undefined1 *)((int)extraout_ECX + 0x7b) = 0;
      if (iVar11 * iVar11 + iVar7 * iVar7 < 4) {
        *(undefined1 *)(extraout_ECX + 0x22) = 0;
      }
      else {
        *(undefined1 *)(extraout_ECX + 0x22) = 1;
      }
      if ((char)extraout_ECX[0x22] != '\0') {
        *(undefined1 *)((int)extraout_ECX + 0x81) = 1;
      }
      if (*(char *)((int)extraout_ECX + 0x81) != '\0') {
        uVar5 = FUN_00421e75();
        iVar7 = extraout_ECX[0x24];
        *(undefined4 *)(unaff_EBP + -0x20) = uVar5;
        iVar11 = extraout_ECX[8];
        iVar9 = FUN_0046d9e5();
        uVar10 = (uint)(iVar7 + iVar11 <= iVar9);
        *(uint *)(unaff_EBP + -0x18) = uVar10;
        if (((uVar10 == 0) || (iVar7 = extraout_ECX[0xf], *(int *)(iVar7 + 0x1ac) == 0)) ||
           (*(short *)(iVar7 + 0x1b0) == 0)) {
          FUN_00492c37();
          iVar7 = *(int *)(unaff_EBP + -0x14);
          iVar9 = *(int *)(unaff_EBP + -0x1c) - extraout_ECX[0x18];
          iVar11 = iVar7 - extraout_ECX[0x17];
          if (4 < iVar9 * iVar9 + iVar11 * iVar11) {
            (**(code **)(*extraout_ECX + 0x3c))();
          }
          FUN_004d2900(0);
          DAT_006c5e40 = 0xffffffff;
          iVar11 = *(int *)(unaff_EBP + -0x1c);
          iVar9 = *(int *)(unaff_EBP + -0x18);
          extraout_ECX[0x19] = iVar7;
          extraout_ECX[0x1a] = iVar11;
          *(undefined1 *)((int)extraout_ECX + 0x81) = 1;
          *(undefined1 *)(extraout_ECX + 0x20) = 0;
          if (iVar9 == 0) {
            DAT_006e4a7c = 0x15;
            FUN_004864ed(0x15,0xffffffff);
          }
        }
        else {
          if (*(int *)(iVar7 + 0x1ac) == 0) {
            sVar4 = 0;
          }
          else {
            sVar4 = *(short *)(*(int *)(*(int *)(*(int *)(iVar7 + 0x1ac) + 0x11c) + 0x60) + 0x8a);
          }
          FUN_00486c0d();
          (**(code **)(*extraout_ECX + 0x18))();
          piVar6 = extraout_ECX + 8;
          *piVar6 = *piVar6 + extraout_ECX[0x24];
          if (*piVar6 != 0) {
            FUN_004864ed(0x1a,extraout_ECX[8]);
            FUN_00492c68();
            FUN_00492bc4();
          }
          extraout_ECX[0x24] = 0;
          *(undefined1 *)((int)extraout_ECX + 0x81) = 0;
          if (sVar4 == 6) {
            FUN_0040766a(0x91,0);
          }
          if (*(char *)((int)extraout_ECX + 0x75) != '\0') {
            if ((*(char *)(unaff_EBP + -0xd) != '\0') ||
               (cVar2 = *(char *)((int)extraout_ECX + 0x76), *(undefined1 *)(unaff_EBP + -0xd) = 0,
               cVar2 != '\0')) {
              *(undefined1 *)(unaff_EBP + -0xd) = 1;
            }
            iVar7 = FUN_0046d9e5();
            if (*(char *)(unaff_EBP + -0xd) != '\0') {
              if (*(int *)(unaff_EBP + -0x20) <= iVar7) {
                (**(code **)(*extraout_ECX + 0x14))();
                *(undefined1 *)((int)extraout_ECX + 0x97) = 1;
                *(undefined1 *)(extraout_ECX + 0x26) = 0;
                goto LAB_00486a1f;
              }
              FUN_00492c37();
            }
            FUN_004cfa7c();
            *(undefined1 *)((int)extraout_ECX + 0x75) = 0;
          }
        }
      }
    }
  }
  else {
    if (extraout_ECX[0xf] != 0) {
      cVar2 = FUN_00432644();
      if (cVar2 != '\0') {
        (**(code **)(*(int *)extraout_ECX[0xf] + 0x50))(1);
      }
    }
    uVar5 = FUN_00492b26();
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(*(int *)(unaff_EBP + 0x14) + 0xc);
    FUN_004a6a9d(unaff_EBP + -0x28,unaff_EBP + -0x1c,0);
    uVar5 = FUN_004a6abd(unaff_EBP + -0x1c,uVar5,(extraout_ECX[0xd] != 3) + '\x02');
    *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
    piVar6 = (int *)FUN_00492b10(uVar5);
    if (piVar6 != (int *)0x0) {
      uVar5 = FUN_004573f9();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
      iVar7 = FUN_00486a5e(uVar5);
      if (iVar7 == 0) {
        iVar7 = FUN_00486a5e(*(undefined4 *)(unaff_EBP + -0x14));
        if (iVar7 == 0) {
          piVar6 = (int *)0x0;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
        }
      }
    }
    FUN_00486ec8(-(uint)(piVar6 != (int *)0x0) & *(uint *)(unaff_EBP + -0x18),0);
    if (piVar6 != (int *)0x0) {
      if (*(short *)(*(int *)(piVar6[0x47] + 0x60) + 0x8a) == 6) {
        DAT_006e5780 = '\x01';
      }
      cVar2 = (**(code **)(*piVar6 + 0x70))();
      if (cVar2 != '\0') {
        sVar4 = FUN_00432249();
        iVar7 = extraout_ECX[0x1e];
        *(int *)(unaff_EBP + -0x14) = (int)sVar4;
        if ((char)iVar7 == '\0') {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
        }
        else if (*(char *)((int)extraout_ECX + 0x77) != '\0') {
          uVar5 = __ftol();
          *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
        }
        extraout_ECX[8] = extraout_ECX[8] - *(int *)(unaff_EBP + -0x14);
        FUN_00492bc4();
        if (*(int *)(unaff_EBP + -0x14) == 0) {
          FUN_00492cca();
        }
        else {
          FUN_00492c99();
        }
        pvVar8 = operator_new(0x88);
        *(void **)(unaff_EBP + -0x20) = pvVar8;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar8 == (void *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_0048bb59(*(undefined4 *)(unaff_EBP + -0x18),3,
                               *(undefined4 *)(unaff_EBP + -0x14),extraout_ECX);
          *(int *)(unaff_EBP + -0x18) = iVar7;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (iVar7 != 0) {
          *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 1;
        }
        FUN_0049341e(iVar7);
        FUN_00485b4c();
        (**(code **)(*piVar6 + 0x6c))(0);
        FUN_00487f26();
      }
    }
  }
LAB_00486a1f:
  (**(code **)(*extraout_ECX + 0x1c))
            (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
             *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  if (DAT_006e5780 != '\0') {
    FUN_0040766a(0x91,0);
    DAT_006e5780 = '\0';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

