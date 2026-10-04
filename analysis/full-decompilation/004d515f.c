
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d515f(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  HWND hWnd;
  int *piVar5;
  int iVar6;
  bool bVar7;
  tagPOINT *lpPoint;
  tagPOINT local_14;
  int local_c;
  int local_8;
  
  param_1[0xe] = 0;
  if (param_1[1] != 1) {
    return;
  }
  if ((((char)param_1[9] == '\0') && ((char)param_1[0x11] == '\0')) &&
     (*(char *)((int)param_1 + 0x45) == '\0')) {
    (**(code **)(*param_1 + 8))(param_1[10],param_1[0xb],0);
  }
  cVar4 = FUN_004b3f7c();
  if (cVar4 == '\0') {
LAB_004d52c9:
    (**(code **)(*param_1 + 0x38))();
  }
  else {
    if (*(int *)(DAT_006e486c + 0x2c) != 0) {
      GetCursorPos(&local_14);
      lpPoint = &local_14;
      hWnd = (HWND)FUN_005caf13();
      ScreenToClient(hWnd,lpPoint);
      if (((local_14.x < 0) || (local_14.y < 0)) ||
         ((piVar5 = (int *)FUN_005caed9(), *piVar5 <= local_14.x ||
          (iVar6 = FUN_005caed9(), *(int *)(iVar6 + 4) <= local_14.y)))) goto LAB_004d52c9;
    }
    if ((char)param_1[9] == '\0') {
      bVar7 = DAT_006e5490 != param_1[4];
      param_1[4] = DAT_006e5490;
      if (bVar7) {
        FUN_004a84c4(&local_8,&local_c);
        iVar6 = __ftol();
        local_8 = local_8 + iVar6;
        iVar6 = __ftol();
        local_c = local_c + iVar6;
        FUN_004a83dc(local_8,local_c,0);
      }
    }
    else {
      iVar6 = param_1[10];
      iVar1 = param_1[0xb];
      iVar2 = param_1[0xf];
      iVar3 = param_1[0x10];
      if ((iVar6 - iVar2 != 0) || (iVar1 - iVar3 != 0)) {
        FUN_004a84c4(&local_c,&local_8);
        local_8 = local_8 + (iVar1 - iVar3);
        local_c = local_c + (iVar6 - iVar2);
        FUN_004a83dc(local_c,local_8,0);
      }
      param_1[0xf] = param_1[10];
      param_1[0x10] = param_1[0xb];
    }
  }
  return;
}

