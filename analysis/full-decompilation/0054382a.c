
void __fastcall FUN_0054382a(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  iVar2 = *(int *)(param_1 + 0xe0);
  *(undefined4 *)(param_1 + 0xe8) = 0;
  if (iVar2 == 0) {
    if (*(char *)(param_1 + 0x169) == '\0') {
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xe4) = 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xe4) = 2;
  }
  if (*(char *)(param_1 + 0x169) == '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x1e4) + 0xd4);
    if (iVar2 == 0) {
      (**(code **)(iVar1 + 0x10))(DAT_006f2a44);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x1e8) + 0xd4) + 0x10))(DAT_006f2a44);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x1f0) + 0xd4) + 0x10))(DAT_006f2a44);
      iVar2 = *(int *)(*(int *)(param_1 + 0x1ec) + 0xd4);
      uVar5 = DAT_006f2a44;
      goto LAB_005439a7;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x1e4) + 0xd4);
    if (iVar2 == 0) {
      (**(code **)(iVar1 + 0x10))(DAT_006f2a48);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x1e8) + 0xd4) + 0x10))(DAT_006f2a48);
      (**(code **)(*(int *)(*(int *)(param_1 + 0x1f0) + 0xd4) + 0x10))(DAT_006f2a48);
      iVar2 = *(int *)(*(int *)(param_1 + 0x1ec) + 0xd4);
      uVar5 = DAT_006f2a48;
      goto LAB_005439a7;
    }
  }
  (**(code **)(iVar1 + 0x10))(DAT_006f2a4c);
  (**(code **)(*(int *)(*(int *)(param_1 + 0x1e8) + 0xd4) + 0x10))(DAT_006f2a4c);
  (**(code **)(*(int *)(*(int *)(param_1 + 0x1f0) + 0xd4) + 0x10))(DAT_006f2a4c);
  iVar2 = *(int *)(*(int *)(param_1 + 0x1ec) + 0xd4);
  uVar5 = DAT_006f2a4c;
LAB_005439a7:
  (**(code **)(iVar2 + 0x10))(uVar5);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8) >> 2 != 0) {
    puVar4 = (undefined4 *)(param_1 + 0x194);
    do {
      (**(code **)(*(int *)*puVar4 + 0x90))(2,*(int *)(param_1 + 0xe0) != 0);
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b8) >> 2));
  }
  return;
}

