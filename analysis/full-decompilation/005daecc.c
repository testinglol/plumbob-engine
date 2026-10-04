
undefined4 FUN_005daecc(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  DWORD DVar5;
  int *piVar6;
  int unaff_EBP;
  char *_Str;
  
  FUN_00634c24();
  FUN_005d48d9();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(iVar1 + 0x178);
  if (iVar2 == 0) {
    _Str = s_kTTDown_006d73bc;
  }
  else if (iVar2 == 1) {
    _Str = s_kTTWaitingDown_006d73c8;
  }
  else if (iVar2 == 2) {
    _Str = s_kTTMotoringUp_006d73d8;
  }
  else if (iVar2 == 3) {
    _Str = s_kTTUp_006d73e8;
  }
  else {
    _Str = s_Unknown__006d73f0;
  }
  sVar4 = _strlen(_Str);
  FUN_00412d8a(_Str,_Str + sVar4);
  DVar5 = timeGetTime();
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s_now____d_006d73b0,DVar5);
  sVar4 = _strlen((char *)(unaff_EBP + -0x124));
  FUN_00412d8a(unaff_EBP + -0x124,unaff_EBP + -0x124 + sVar4);
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s_mTTStartWaitingTime____d_006d7394,
            *(undefined4 *)(iVar1 + 0x17c));
  sVar4 = _strlen((char *)(unaff_EBP + -0x124));
  FUN_00412d8a(unaff_EBP + -0x124,unaff_EBP + -0x124 + sVar4);
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s_mTTStartMotoringUpTime____d_006d7374,
            *(undefined4 *)(iVar1 + 0x180));
  sVar4 = _strlen((char *)(unaff_EBP + -0x124));
  FUN_00412d8a(unaff_EBP + -0x124,unaff_EBP + -0x124 + sVar4);
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s_mHadTip____d_006d7364,(uint)*(byte *)(iVar1 + 0x1a0));
  sVar4 = _strlen((char *)(unaff_EBP + -0x124));
  FUN_00412d8a(unaff_EBP + -0x124,unaff_EBP + -0x124 + sVar4);
  wsprintfA((LPSTR)(unaff_EBP + -0x124),s_mDrewTip____d_006d7354,(uint)*(byte *)(iVar1 + 0x1a1));
  sVar4 = _strlen((char *)(unaff_EBP + -0x124));
  FUN_00412d8a(unaff_EBP + -0x124,unaff_EBP + -0x124 + sVar4);
  FUN_005d4956(s_ToolTip_Internal_State_006d733c);
  puVar3 = DAT_006fe8bc;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar6 = (int *)(**(code **)*puVar3)();
  (**(code **)(*piVar6 + 0x2c))(unaff_EBP + -0x18,unaff_EBP + -0x24,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

