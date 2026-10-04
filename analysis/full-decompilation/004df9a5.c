
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004df9a5(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  HANDLE pvVar3;
  int iVar4;
  undefined1 local_3c [12];
  undefined4 local_30;
  _SYSTEMTIME local_14;
  
  if (DAT_006f21ec != 0) {
    FUN_006357d8(DAT_006f21ec,s_AllocHookMessage___s_006c8d98,param_1);
    uVar2 = FUN_004dfb6a(DAT_006f21f0);
    FUN_006357d8(DAT_006f21ec,s_Normal_Bytes_Allocated____s_006c8d74,uVar2);
    uVar2 = FUN_004dfb6a(DAT_006f21f4);
    FUN_006357d8(DAT_006f21ec,s__Fake__Bytes_Allocated____s_006c8d54,uVar2);
    uVar2 = FUN_004dfb6a(DAT_006f21f8);
    FUN_006357d8(DAT_006f21ec,s_CRT_Bytes_Allocated____s_006c8d34,uVar2);
    uVar2 = FUN_004dfb6a((DAT_006f21f8 - _DAT_006f2210) + DAT_006f21f4 + DAT_006f21f0);
    FUN_006357d8(DAT_006f21ec,s_Delta____s_006c8d24,uVar2);
    _DAT_006f2210 = DAT_006f21f8 + DAT_006f21f4 + DAT_006f21f0;
    FUN_006372ee(DAT_006f21ec);
  }
  iVar4 = DAT_006c8c9c;
  if (DAT_006f21fe != '\0') {
    GetLocalTime(&local_14);
    FUN_004e066d(DAT_006c8c94,s_Memdiff_Snapshot___02d__02d__d____006c8cf0,local_14.wMonth,
                 local_14.wDay,local_14.wYear,local_14.wHour,local_14.wMinute,local_14.wSecond);
    pvVar3 = GetCurrentProcess();
    iVar4 = FUN_004dff75(pvVar3);
    if ((DAT_006c8c9c != -1) && (DAT_006c8c94 != -1)) {
      FUN_004e066d(DAT_006c8c94,s_________________________________M_006c8ca8,param_1);
      FUN_004e00a4(DAT_006c8c9c,iVar4,DAT_006c8c94,DAT_006f21ff);
      FUN_004e0167(DAT_006c8c9c);
      FUN_004e0167(iVar4);
      pvVar3 = GetCurrentProcess();
      iVar4 = FUN_004dff75(pvVar3);
    }
  }
  DAT_006c8c9c = iVar4;
  if ((DAT_006c8c98 != -1) && (cVar1 = FUN_004e076c(local_3c), cVar1 != '\0')) {
    FUN_004e066d(DAT_006c8c98,s__s__d_006c8ca0,param_1,local_30);
  }
  return;
}

