
void __fastcall FUN_004a8aa5(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  if (DAT_006e53d8 != 0) {
    FUN_0046716c();
  }
  if (*(char *)(param_1 + 0x200) != '\0') {
    FUN_004abb9e(*(undefined1 *)(param_1 + 0x1f8));
    *(undefined1 *)(param_1 + 0x200) = 0;
  }
  FUN_00540a5b();
  FUN_00540eed();
  if (*(char *)(param_1 + 0x4e) != '\0') {
    iVar1 = *(int *)(param_1 + 0x18);
    local_8 = 1;
    if (0 < iVar1) {
      iVar2 = 1 - iVar1;
      do {
        iVar4 = local_8;
        if ((SBORROW4(local_8,iVar1) == iVar2 < 0) && (*(char *)(param_1 + 0x51) == '\0')) {
          iVar4 = iVar1;
          if (*(char *)(param_1 + 0x48) != '\0') {
            uVar3 = 1;
            goto LAB_004a8b2d;
          }
          if (*(char *)(param_1 + 0x49) == '\0') goto LAB_004a8b2c;
          FUN_0054074f(param_1 + 0x208,iVar1);
        }
        else {
LAB_004a8b2c:
          uVar3 = 0;
LAB_004a8b2d:
          FUN_005406d1(uVar3,iVar4);
        }
        local_8 = local_8 + 1;
        iVar2 = local_8 - iVar1;
      } while (local_8 <= iVar1);
    }
  }
  *(undefined1 *)(param_1 + 0x4e) = 0;
  return;
}

