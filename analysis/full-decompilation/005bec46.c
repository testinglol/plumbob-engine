
undefined1 __thiscall FUN_005bec46(int param_1,LONG param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 local_5;
  
  local_5 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    FUN_005bf04f();
    DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 0x1c),param_2,(PLONG)0x0,0);
    if ((DVar1 == 0xffffffff) || (BVar2 = SetEndOfFile(*(HANDLE *)(param_1 + 0x1c)), BVar2 == 0)) {
      FUN_005bfa81();
    }
    else {
      local_5 = 1;
    }
    DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 0x1c),0,(PLONG)0x0,1);
    *(DWORD *)(param_1 + 0x4c) = DVar1;
    *(DWORD *)(param_1 + 0x48) = DVar1;
    return local_5;
  }
  return 0;
}

