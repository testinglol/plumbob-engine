
undefined1 __fastcall FUN_005bf04f(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_c;
  undefined3 uStack_8;
  undefined1 local_5;
  
  uStack_8 = (undefined3)param_1;
  local_5 = 1;
  local_c = *(DWORD *)(param_1 + 0x7c);
  if (local_c != 0) {
    BVar1 = WriteFile(*(HANDLE *)(param_1 + 0x1c),*(LPCVOID *)(param_1 + 0x6c),local_c,&local_c,
                      (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0x1c),0,(PLONG)0x0,1);
      *(DWORD *)(param_1 + 0x4c) = DVar2;
      *(DWORD *)(param_1 + 0x78) = DVar2;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      local_5 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + local_c;
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x4c);
    }
  }
  return local_5;
}

