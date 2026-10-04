
void __fastcall FUN_00588d9e(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(param_1 + 0x278) - *(int *)(param_1 + 0x274) >> 2 != 0) {
    do {
      FUN_00583714(DAT_006f6b64,iVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x278) - *(int *)(param_1 + 0x274) >> 2));
  }
  *(int *)(iVar1 + 0xac) = *(int *)(iVar1 + 0xac) + 1;
  *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;
  *(undefined4 *)(iVar1 + 0x98) = 1;
  return;
}

