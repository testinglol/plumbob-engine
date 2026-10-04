
void __fastcall FUN_005cab9b(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  FUN_004a891e();
  FUN_005cdecb(param_1 + 0x450);
  FUN_005cdecb(param_1 + 0x468);
  FUN_005cdecb(param_1 + 0x4c8);
  FUN_004a891e();
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 != 0) {
    local_8 = 0;
    iVar2 = *(int *)(iVar2 + 0x20) - *(int *)(iVar2 + 0x1c) >> 2;
    if (0 < iVar2) {
      do {
        uVar1 = FUN_005cf113();
        FUN_005cdecb(uVar1);
        uVar1 = FUN_005cf10c();
        FUN_005cdecb(uVar1);
        local_8 = local_8 + 1;
      } while (local_8 < iVar2);
    }
  }
  if ((*(char *)(param_1 + 0x56c) != '\0') && (*(int *)(param_1 + 0x568) != 0)) {
    FUN_005cdecb(*(int *)(param_1 + 0x568));
  }
  FUN_005cce4d(param_1 + 0x28);
  return;
}

