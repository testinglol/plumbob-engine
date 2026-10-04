
uint __fastcall FUN_005bef90(int param_1)

{
  int iVar1;
  uint in_EAX;
  int iVar2;
  
  if (*(char *)(param_1 + 0x18) != '\0') {
    iVar1 = *(int *)(param_1 + 0x7c);
    FUN_005bf04f();
    iVar2 = 1;
    if (0 < iVar1) {
      iVar2 = FlushFileBuffers(*(HANDLE *)(param_1 + 0x1c));
      if (iVar2 == 0) {
        FUN_005bfa81();
      }
    }
    return (uint)(iVar2 != 0);
  }
  return in_EAX & 0xffffff00;
}

