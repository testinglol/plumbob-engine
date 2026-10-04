
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577d3a(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = (**(code **)(*extraout_ECX + 0xb0))();
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
  uVar2 = (**(code **)(*extraout_ECX + 0xb4))();
  *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
  iVar3 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  iVar6 = DAT_006f63e8;
  if ((((char)iVar3 == '\0') || ((char)extraout_ECX[0xf] == '\0')) ||
     ((char)extraout_ECX[0x102a] != '\0')) goto LAB_00578138;
  *(int **)(unaff_EBP + -0x2c) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_LAB_00669c88;
  (**(code **)(iVar6 + 4))();
  _DAT_006f6418 = _DAT_006f6418 + 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((DAT_006f63e4 & 1) == 0) {
    DAT_006f63e4 = DAT_006f63e4 | 1;
    _DAT_006f63e0 = FUN_005fd8ea();
  }
  iVar3 = FUN_005fd8ea();
  if (10000 < iVar3 - _DAT_006f63e0) {
    _DAT_006f6418 = 0;
    _DAT_006f641c = 0;
    _DAT_006f6420 = 0;
    _DAT_006f6410 = 0;
    _DAT_006f6424 = 0;
    _DAT_006f63e0 = FUN_005fd8ea();
  }
  uVar4 = FUN_005fd8ea();
  if (extraout_ECX[0x10] == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = ((extraout_ECX[0x17] - extraout_ECX[0x18]) * 60000) / extraout_ECX[0x10];
  }
  _DAT_006f6414 = uVar4;
  if (uVar5 <= uVar4) {
    if (uVar4 < 0x5265c01) {
      _DAT_006f641c = _DAT_006f641c + 1;
      *(undefined1 *)(unaff_EBP + -0x20) = 0;
      if (7 < uVar4 - uVar5) {
        *(undefined1 *)(unaff_EBP + -0x20) = 1;
      }
      if (extraout_ECX[0x1029] != 0) {
        *(undefined1 *)(unaff_EBP + -0x20) = 1;
      }
      iVar3 = extraout_ECX[0xd];
      iVar6 = extraout_ECX[0x16];
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (((iVar6 == *(int *)(iVar3 + 0x30) + -1) || (iVar6 == *(int *)(iVar3 + 0x30) + -6)) &&
         ((iVar3 = (**(code **)(*extraout_ECX + 0xa8))(),
          *(int *)(extraout_ECX[0xd] + 8) != 0 &&
          (*(char *)((int)extraout_ECX + 0x3d) == '\0' && *(int *)(unaff_EBP + -0x1c) <= iVar3) &&
          (cVar1 = (**(code **)(*extraout_ECX + 0x90))(unaff_EBP + -0x14,unaff_EBP + -0x10),
          cVar1 != '\0')))) {
        *(undefined1 *)
         (extraout_ECX[*(int *)(unaff_EBP + -0x14) * 0x40 + *(int *)(unaff_EBP + -0x10) + 0x25] +
         0x15) = 1;
        iVar3 = *(int *)(*(int *)(extraout_ECX
                                  [*(int *)(unaff_EBP + -0x14) * 0x40 + *(int *)(unaff_EBP + -0x10)
                                   + 0x25] + 0xc) + 0x48);
        if (iVar3 != 0) {
          *(undefined4 *)(unaff_EBP + -0x18) =
               *(undefined4 *)
                (*(int *)(extraout_ECX
                          [*(int *)(unaff_EBP + -0x14) * 0x40 + *(int *)(unaff_EBP + -0x10) + 0x25]
                         + 0xc) + 0x2c);
        }
      }
      else {
        iVar3 = *(int *)(unaff_EBP + -0x24);
      }
      uVar2 = (**(code **)(*extraout_ECX + 0xa4))();
      iVar6 = (**(code **)(*extraout_ECX + 0xa0))();
      *(undefined4 *)(unaff_EBP + -0x24) = uVar2;
      iVar6 = iVar6 - *(int *)(unaff_EBP + -0x24);
      if (((extraout_ECX[0x16] == *(int *)(extraout_ECX[0xd] + 0x30) + -1) ||
          (extraout_ECX[0x16] == *(int *)(extraout_ECX[0xd] + 0x30) + -6)) &&
         (*(char *)((int)extraout_ECX + 0x40a9) == '\0' &&
          (*(char *)((int)extraout_ECX + 0x3d) == '\0' &&
          (iVar6 < *(int *)(unaff_EBP + -0x28) && extraout_ECX[0x1028] != 0)))) {
        cVar1 = (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x14,unaff_EBP + -0x10,iVar3);
        _DAT_006f6420 = _DAT_006f6420 + 1;
        if (cVar1 == '\0') {
          cVar1 = '\0';
          if ((iVar3 != 0) && (*(int *)(unaff_EBP + -0x18) == 0x13)) {
            cVar1 = (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x14,unaff_EBP + -0x10,iVar3);
          }
          if ((cVar1 != '\0') ||
             (((iVar3 != 0 && (*(int *)(unaff_EBP + -0x18) == 0x13)) &&
              (cVar1 = (**(code **)(*extraout_ECX + 0x8c))
                                 (unaff_EBP + -0x14,unaff_EBP + -0x10,iVar3), cVar1 != '\0'))))
          goto LAB_0057800e;
          if (iVar6 < *(int *)(unaff_EBP + -0x1c)) {
            cVar1 = (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x14,unaff_EBP + -0x10,iVar3);
            _DAT_006f6420 = _DAT_006f6420 + 1;
            if (cVar1 != '\0') goto LAB_0057800e;
          }
        }
        else {
LAB_0057800e:
          _DAT_006f6410 = _DAT_006f6410 + 1;
          FUN_00579da8(*(undefined4 *)
                        (extraout_ECX[0xd] + 0x44 +
                        (*(int *)(unaff_EBP + -0x14) * 0x40 + *(int *)(unaff_EBP + -0x10)) * 4));
          extraout_ECX[0x21] = *(int *)(unaff_EBP + -0x14);
          extraout_ECX[0x22] = *(int *)(unaff_EBP + -0x10);
        }
        if (iVar6 < *(int *)(unaff_EBP + -0x28)) {
          cVar1 = (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x14,unaff_EBP + -0x10,0);
          _DAT_006f6420 = _DAT_006f6420 + 1;
          if (cVar1 == '\0') {
            cVar1 = '\0';
            if (iVar6 < *(int *)(unaff_EBP + -0x1c)) {
              cVar1 = (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x14,unaff_EBP + -0x10,0);
              _DAT_006f6420 = _DAT_006f6420 + 1;
            }
            if (cVar1 == '\0') goto LAB_005780c2;
          }
          _DAT_006f6410 = _DAT_006f6410 + 1;
          FUN_00579da8(*(undefined4 *)
                        (extraout_ECX[0xd] + 0x44 +
                        (*(int *)(unaff_EBP + -0x14) * 0x40 + *(int *)(unaff_EBP + -0x10)) * 4));
          extraout_ECX[0x21] = *(int *)(unaff_EBP + -0x14);
          extraout_ECX[0x22] = *(int *)(unaff_EBP + -0x10);
        }
      }
LAB_005780c2:
      iVar3 = extraout_ECX[0xd];
      iVar6 = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (0 < *(int *)(iVar3 + 0x24)) {
        do {
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          if (0 < *(int *)(iVar3 + 0x28)) {
            do {
              FUN_00579a41(*(undefined4 *)(unaff_EBP + -0x20),extraout_ECX[0x16]);
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              iVar6 = *(int *)(unaff_EBP + -0x14);
            } while (*(int *)(unaff_EBP + -0x10) < *(int *)(extraout_ECX[0xd] + 0x28));
          }
          iVar3 = extraout_ECX[0xd];
          iVar6 = iVar6 + 1;
          *(int *)(unaff_EBP + -0x14) = iVar6;
        } while (iVar6 < *(int *)(iVar3 + 0x24));
      }
      extraout_ECX[0x16] = extraout_ECX[0x16] + 1;
      if (*(int *)(extraout_ECX[0xd] + 0x30) < extraout_ECX[0x16]) {
        extraout_ECX[0x16] = 1;
      }
      extraout_ECX[0x17] = extraout_ECX[0x17] + 1;
    }
    else {
      iVar3 = extraout_ECX[0xc];
      iVar6 = *(int *)(extraout_ECX[0xd] + 0x30);
      extraout_ECX[0x18] = iVar6;
      extraout_ECX[0x16] = iVar6;
      extraout_ECX[0x17] = iVar6;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0x14) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_005772e2();
      FUN_005fd8ea();
    }
  }
  iVar3 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
LAB_00578138:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

