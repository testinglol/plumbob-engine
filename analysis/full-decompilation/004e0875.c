
void FUN_004e0875(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  int iVar5;
  HANDLE pvVar6;
  undefined1 local_120 [260];
  _SYSTEMTIME local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004e0eba(s__________________________________006c9388);
  puVar1 = (undefined4 *)*param_1;
  uVar3 = FUN_004e0a5f(*puVar1);
  FUN_004e0eba(s_Exception_code___08X__s_006c936c,*puVar1,uVar3);
  DVar4 = GetCurrentThreadId();
  FUN_004e0eba(s_Thread_ID___d_006c935c,DVar4);
  if ((DAT_006f29f0 != 0) && (DVar4 == DAT_006f29f0)) {
    FUN_004e0eba(s__Sims_main__006c934c);
  }
  FUN_004e0eba(&DAT_006c8578);
  FUN_004e0eba(s_Sound_exec_count___d_006c9334,DAT_006f29fc);
  GetLocalTime(&local_1c);
  FUN_004e0eba(s_Crash_occurred___02d__02d__d______006c9300,local_1c.wMonth,local_1c.wDay,
               local_1c.wYear,local_1c.wHour,local_1c.wMinute,local_1c.wSecond);
  FUN_004e0eba(s_Executable_version___s_006c92e4,PTR_s_Sep_25_2003__14_23_46_006c7b6c);
  FUN_004e0bbc(puVar1[3],local_120,0x104,&local_8,&local_c);
  FUN_004e0eba(s_Fault_address___08X__02X__08X__s_006c92c0,puVar1[3],local_8,local_c,local_120);
  iVar2 = param_1[1];
  FUN_004e0eba(s_Registers__006c92b0);
  FUN_004e0eba(s_EAX__08X_EBX__08X_ECX__08X_EDX___006c9270,*(undefined4 *)(iVar2 + 0xb0),
               *(undefined4 *)(iVar2 + 0xa4),*(undefined4 *)(iVar2 + 0xac),
               *(undefined4 *)(iVar2 + 0xa8),*(undefined4 *)(iVar2 + 0xa0),
               *(undefined4 *)(iVar2 + 0x9c));
  FUN_004e0eba(s_CS_EIP__04X__08X_006c925c,*(undefined4 *)(iVar2 + 0xbc),
               *(undefined4 *)(iVar2 + 0xb8));
  FUN_004e0eba(s_SS_ESP__04X__08X_EBP__08X_006c923c,*(undefined4 *)(iVar2 + 200),
               *(undefined4 *)(iVar2 + 0xc4),*(undefined4 *)(iVar2 + 0xb4));
  FUN_004e0eba(s_DS__04X_ES__04X_FS__04X_GS__04X_006c9214,*(undefined4 *)(iVar2 + 0x98),
               *(undefined4 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 0x90),
               *(undefined4 *)(iVar2 + 0x8c));
  FUN_004e0eba(s_Flags__08X_006c9204,*(undefined4 *)(iVar2 + 0xc0));
  iVar5 = FUN_004e0ef9();
  if (iVar5 == 0) {
    FUN_004e0eba(s_IMAGEHLP_DLL_or_its_exported_pro_006c91d4);
    FUN_004e0c4d(iVar2);
  }
  else {
    FUN_004e0d55(iVar2);
    pvVar6 = GetCurrentProcess();
    (*DAT_006f2340)(pvVar6);
    FUN_004e0eba(&DAT_006c8578);
  }
  return;
}

