
undefined4 __thiscall FUN_005f0f59(int *param_1,HWND param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  HIMC pHVar5;
  LONG LVar6;
  uint uVar7;
  uint uVar8;
  byte local_104 [256];
  
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x58))(0);
  piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  iVar1 = *piVar2;
  uVar4 = (**(code **)(*piVar3 + 0x1c))();
  (**(code **)(iVar1 + 0x78))(uVar4);
  pHVar5 = ImmGetContext(param_2);
  if (pHVar5 != (HIMC)0x0) {
    if ((param_3 & 0x18) != 0) {
      if ((param_3 & 0x10) != 0) {
        LVar6 = ImmGetCompositionStringA(pHVar5,0x10,param_1 + 0x144,0x400);
        param_1[0x644] = LVar6;
      }
      if ((param_3 & 8) != 0) {
        LVar6 = ImmGetCompositionStringA(pHVar5,8,param_1 + 0x44,0x400);
        *(undefined1 *)(LVar6 + 0x110 + (int)param_1) = 0;
      }
      (**(code **)(*param_1 + 0x168))();
    }
    if ((param_3 & 0x800) == 0) {
      ImmReleaseContext(param_2,pHVar5);
    }
    else {
      uVar7 = ImmGetCompositionStringA(pHVar5,0x800,local_104,0x100);
      ImmReleaseContext(param_2,pHVar5);
      uVar8 = 0;
      if (uVar7 != 0) {
        do {
          PostMessageA(param_2,0x102,(uint)local_104[uVar8],0);
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar7);
      }
    }
  }
  return 0;
}

