
undefined1 __fastcall FUN_005befd3(uint param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_1 & 0xffffff;
  if (*(int *)(param_1 + 0x54) == *(int *)(param_1 + 0x58)) {
    uStack_8 = param_1 & 0xffff;
    local_c = param_1;
    FUN_005bfb21(*(undefined4 *)(param_1 + 0x50),(int)&uStack_8 + 2);
  }
  local_c = *(DWORD *)(param_1 + 0x50);
  BVar1 = ReadFile(*(HANDLE *)(param_1 + 0x1c),*(LPVOID *)(param_1 + 0x54),local_c,&local_c,
                   (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0x1c),0,(PLONG)0x0,1);
    *(DWORD *)(param_1 + 0x4c) = DVar2;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  else {
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x4c);
    *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + local_c;
    *(uint *)(param_1 + 100) = local_c;
    uStack_8 = 0x1000000;
  }
  return uStack_8._3_1_;
}

