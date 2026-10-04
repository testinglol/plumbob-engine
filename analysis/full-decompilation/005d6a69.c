
UINT __thiscall FUN_005d6a69(int *param_1,HWND param_2,uint param_3,HWND param_4,LPARAM param_5)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  HDC pHVar4;
  UINT UVar5;
  undefined4 uVar6;
  tagPAINTSTRUCT local_54;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  
  if ((char)param_1[0x3a] != '\0') goto LAB_005d6f04;
  iVar2 = FUN_005f1654(param_2,param_3,param_4);
  if (iVar2 != 0) {
    return 0;
  }
  if (param_3 < 0x201) {
    if (param_3 != 0x200) {
      if (param_3 < 0x15) {
        if (param_3 == 0x14) {
          return 1;
        }
        if (param_3 == 2) {
          (**(code **)(*DAT_006fe8bc + 0x24))(0);
          return 0;
        }
        if ((param_3 == 3) || (param_3 == 5)) {
          (**(code **)(*param_1 + 0x1a8))();
          return 0;
        }
        if (param_3 == 0xf) {
          BeginPaint(param_2,&local_54);
          if (DAT_006fe8d0 == 0) {
            iVar2 = (**(code **)(*DAT_006fe8bc + 0x1c))();
            DAT_006fe8d0 = (**(code **)(*(int *)((-(uint)(iVar2 != 0) & iVar2 - 0x48U) + 0x48) +
                                       0x24))();
            if (DAT_006fe8d0 == 0) goto LAB_005d6b9f;
          }
          if ((*(char *)(DAT_006fe8d0 + 0x91) != '\0') &&
             (FUN_005cad45(&local_54.rcPaint), DAT_006e4870 == '\0')) {
            FUN_005caf53(&local_54.rcPaint);
          }
LAB_005d6b9f:
          EndPaint(param_2,&local_54);
          return 0;
        }
        if (param_3 == 0x10) {
          if (DAT_006fe8bc == (int *)0x0) {
            return 0;
          }
          iVar2 = (**(code **)*DAT_006fe8bc)();
          if (iVar2 == 0) {
            return 0;
          }
          SetForegroundWindow(param_2);
          piVar3 = (int *)(**(code **)*DAT_006fe8bc)();
          (**(code **)(*piVar3 + 0x28))();
          return 0;
        }
LAB_005d6e93:
        if ((param_3 == 0x104) || (param_3 == 0x100)) {
          (**(code **)(*DAT_006fe8f8 + 0x1c))(param_4);
        }
        else if ((param_3 == 0x105) || (param_3 == 0x101)) {
          (**(code **)(*DAT_006fe8f8 + 0x20))(param_4);
        }
      }
      else {
        if (param_3 == 0x1c) {
          if (param_4 == (HWND)0x0) {
            DAT_006d6f9c = 0;
            FUN_005d7b21(param_2);
            if ((param_1[0x3e] != 0) && (cVar1 = FUN_005f034e(), cVar1 != '\0')) {
              FUN_005f0352(1);
            }
            FUN_005dadbc(0,0);
          }
          else {
            DAT_006d6f9c = 1;
            FUN_005d7bfa(param_2);
          }
          if ((DAT_006fe8bc != (int *)0x0) && (iVar2 = (**(code **)*DAT_006fe8bc)(), iVar2 != 0)) {
            piVar3 = (int *)(**(code **)*DAT_006fe8bc)();
            (**(code **)(*piVar3 + 0x20))(DAT_006d6f9c);
          }
          param_1 = param_1 + 0x35;
          if (*param_1 == 0) {
            return 0;
          }
          pHVar4 = GetDC(param_2);
          UnrealizeObject((HGDIOBJ)*param_1);
          SelectPalette(pHVar4,(HPALETTE)*param_1,0);
          RealizePalette(pHVar4);
          ReleaseDC(param_2,pHVar4);
          return 0;
        }
        if (param_3 == 0x20) {
          return 1;
        }
        if (param_3 == 0x7e) {
          if (DAT_006fe8bc == (int *)0x0) {
            return 0;
          }
          iVar2 = (**(code **)(*DAT_006fe8bc + 0x1c))();
          if (iVar2 == 0) {
            return 0;
          }
          piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          iVar2 = (**(code **)(*piVar3 + 0x44))();
          if (iVar2 == 1) {
            return 0;
          }
          piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          cVar1 = (**(code **)(*piVar3 + 0x18))();
          if (cVar1 != '\0') {
            return 0;
          }
          if (param_4 == (HWND)0xf) {
            return 0;
          }
          if (param_4 == (HWND)0x10) {
            return 0;
          }
          piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          (**(code **)(*piVar3 + 0x48))();
          piVar3 = (int *)(**(code **)*DAT_006fe8bc)();
          (**(code **)(*piVar3 + 0x38))();
          return 1;
        }
        if (param_3 == 0xa0) {
          uVar6 = 0xa0;
          goto LAB_005d6d80;
        }
        if (param_3 != 0x112) goto LAB_005d6e93;
        if (((uint)param_4 & 0xfff0) == 0xf140) {
          return 0;
        }
        if (((uint)param_4 & 0xfff0) == 0xf170) {
          return 0;
        }
      }
      iVar2 = FUN_005d6f91(param_3);
      if (iVar2 != 0) {
        FUN_005d6695(local_14,param_3,param_4,param_5);
        cVar1 = FUN_005da854(local_14);
        if (cVar1 != '\0') {
          return 0;
        }
      }
LAB_005d6f04:
      UVar5 = DefWindowProcA(param_2,param_3,(WPARAM)param_4,param_5);
      return UVar5;
    }
    uVar6 = 0x200;
LAB_005d6d80:
    FUN_005d6695(local_14,uVar6,param_4,param_5);
    param_1[0x38] = local_10;
    param_1[0x39] = local_c;
    goto LAB_005d6f79;
  }
  uVar6 = 0x206;
  if (param_3 < 0x207) {
    if ((param_3 == 0x206) || (uVar6 = 0x201, param_3 == 0x201)) goto LAB_005d6f5e;
    if (param_3 == 0x202) {
      ReleaseCapture();
      uVar6 = 0x202;
    }
    else if (param_3 == 0x203) {
      SetCapture(param_2);
      uVar6 = 0x203;
    }
    else if (param_3 == 0x204) {
      SetCapture(param_2);
      uVar6 = 0x204;
    }
    else {
      if (param_3 != 0x205) goto LAB_005d6e93;
      ReleaseCapture();
      uVar6 = 0x205;
    }
  }
  else {
    uVar6 = 0x20a;
    if (param_3 != 0x20a) {
      if (param_3 == 0x30f) {
LAB_005d6f17:
        if (param_1[0x35] == 0) {
          return 0;
        }
        pHVar4 = GetDC(param_2);
        SelectPalette(pHVar4,(HPALETTE)param_1[0x35],0);
        UVar5 = RealizePalette(pHVar4);
        ReleaseDC(param_2,pHVar4);
        if (UVar5 != 0) {
          InvalidateRect(param_2,(RECT *)0x0,0);
          return UVar5;
        }
        return 0;
      }
      if (param_3 == 0x311) {
        if (param_4 == param_2) {
          return 0;
        }
        goto LAB_005d6f17;
      }
      if ((0xbff < param_3) && (param_3 < 0xc02)) {
        piVar3 = (int *)(**(code **)*DAT_006fe8bc)();
        iVar2 = (**(code **)(*piVar3 + 0x3c))(param_2,param_3,param_4,param_5);
        if (iVar2 != 0) {
          return 0;
        }
        goto LAB_005d6f04;
      }
      goto LAB_005d6e93;
    }
LAB_005d6f5e:
    SetCapture(param_2);
  }
  FUN_005d6695(local_14,uVar6,param_4,param_5);
LAB_005d6f79:
  FUN_005da854(local_14);
  return 0;
}

