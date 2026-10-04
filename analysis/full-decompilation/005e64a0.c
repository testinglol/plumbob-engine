
undefined1 FUN_005e64a0(void)

{
  undefined4 *puVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int extraout_ECX;
  undefined1 uVar9;
  int unaff_EBP;
  char *_Str;
  
  FUN_00634c24();
  FUN_006358b0(unaff_EBP + -400,*(undefined4 *)(unaff_EBP + 8));
  sVar3 = _strlen((char *)(unaff_EBP + -400));
  *(undefined1 *)(unaff_EBP + -399 + sVar3) = 0;
  FUN_0063864b(unaff_EBP + -400,&DAT_006c145c);
  iVar4 = FUN_0063864b(0,&DAT_006c145c);
  while (iVar4 != 0) {
    iVar4 = FUN_0063864b(0,&DAT_006c145c);
  }
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _Str = (char *)(unaff_EBP + -400);
  while (sVar3 = _strlen(_Str), sVar3 != 0) {
    uVar5 = FUN_005e5e61(_Str);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005e6afa(uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005e5e16();
    sVar3 = _strlen(_Str);
    _Str = _Str + sVar3 + 1;
  }
  iVar4 = (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) / 0x2c;
  *(int *)(unaff_EBP + -0x50) = iVar4;
  if (iVar4 != 0) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (0 < iVar4) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      do {
        iVar4 = *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + -0x18);
        if ((*(int *)(*(int *)(unaff_EBP + 8) + 8 + *(int *)(unaff_EBP + -0x18)) -
            *(int *)(iVar4 + 4)) / 0xc < 1) {
LAB_005e6812:
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005e6ab3();
          uVar9 = 0;
          goto LAB_005e6832;
        }
        iVar6 = _strcmp((char *)**(undefined4 **)(iVar4 + 4),&DAT_006c4da0);
        if (iVar6 == 0) {
          if (0 < (*(int *)(extraout_ECX + 0x24) - *(int *)(extraout_ECX + 0x20)) / 0xc) {
            if ((*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4)) / 0xc == 1) {
              FUN_005e5fd3(extraout_ECX + 0x1c);
            }
            else {
              FUN_005d4956(**(undefined4 **)(extraout_ECX + 0x20));
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_005d499c(unaff_EBP + -0x60);
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_005b8770();
            }
            goto LAB_005e6615;
          }
          FUN_005d4956(s_Sorry_006cd694);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005d4956(s_No_previous_cheat__006d765c);
          puVar1 = DAT_006fe8bc;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          piVar8 = (int *)(**(code **)*puVar1)();
          (**(code **)(*piVar8 + 0x2c))(unaff_EBP + -0x2c,unaff_EBP + -0x38,0,0);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0;
LAB_005e680d:
          FUN_005b8770();
          goto LAB_005e6812;
        }
LAB_005e6615:
        FUN_005d4956(**(undefined4 **)(iVar4 + 4));
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005343fd(unaff_EBP + -0x54,unaff_EBP + -0x38);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        iVar6 = *(int *)(unaff_EBP + -0x54);
        if (iVar6 == *(int *)(extraout_ECX + 4)) {
          uVar5 = FUN_005d4956(s_Sorry_006cd694);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          uVar7 = FUN_005d4956(s_No_such_cheat__006d764c);
          puVar1 = DAT_006fe8bc;
          *(undefined1 *)(unaff_EBP + -4) = 7;
          piVar8 = (int *)(**(code **)*puVar1)();
          (**(code **)(*piVar8 + 0x2c))(uVar7,uVar5,0,0);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          goto LAB_005e680d;
        }
        uVar5 = *(undefined4 *)(iVar6 + 0x1c);
        *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar6 + 0x20);
        puVar1 = *(undefined4 **)(iVar4 + 4);
        *(undefined4 *)(unaff_EBP + -0x48) = uVar5;
        FUN_005d4956(*puVar1);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005e6e12(unaff_EBP + -0x20,unaff_EBP + -0x2c);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        FUN_005d48d9();
        iVar6 = *(int *)(extraout_ECX + 0x10);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        if (*(int *)(unaff_EBP + -0x20) != iVar6) {
          FUN_005d4bbf(s_Usage__006d7670);
          FUN_00412d8a(*(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0x1c),
                       *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0x20));
          FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x44));
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        cVar2 = (**(code **)(unaff_EBP + -0x48))(iVar4,*(undefined4 *)(unaff_EBP + -0x4c));
        if (cVar2 == '\0') {
          uVar5 = FUN_005d4956(s_Cheat_Error_006d7640);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          uVar7 = FUN_005e6843(unaff_EBP + -0x60);
          puVar1 = DAT_006fe8bc;
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          piVar8 = (int *)(**(code **)*puVar1)();
          (**(code **)(*piVar8 + 0x2c))(uVar7,uVar5,0,0);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          goto LAB_005e680d;
        }
        FUN_005e5fd3(iVar4);
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x2c;
      } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x50));
    }
    if (*(char *)(extraout_ECX + 0x44) != '\0') {
      *(undefined1 *)(extraout_ECX + 0x49) = 1;
      uVar9 = 1;
      goto LAB_005e6824;
    }
  }
  uVar9 = 0;
LAB_005e6824:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e6ab3();
LAB_005e6832:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

