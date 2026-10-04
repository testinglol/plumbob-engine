
void __fastcall FUN_00584e0f(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(*param_1 + 0xac))();
  iVar2 = *(int *)(iVar2 + 4);
  uVar3 = 0;
  if (param_1[0x34] - param_1[0x33] >> 2 != 0) {
    do {
      iVar1 = *(int *)(param_1[0x33] + uVar3 * 4);
      FUN_0058372c(DAT_006f6b64,iVar2,iVar1 + 4,iVar1 + 0x10);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(param_1[0x34] - param_1[0x33] >> 2));
  }
  *(int *)(iVar2 + 0xac) = *(int *)(iVar2 + 0xac) + 1;
  *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;
  *(undefined4 *)(iVar2 + 0x98) = 1;
  return;
}

