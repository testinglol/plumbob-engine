
void __fastcall FUN_00578cda(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_2c;
  undefined4 local_2b;
  int local_c;
  int local_8;
  
  local_2c = '\0';
  puVar4 = &local_2b;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  local_8 = *(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x78);
  if (local_8 < 0) {
    local_8 = 0;
  }
  local_c = local_8;
  iVar3 = FUN_00578f6a();
  if (local_8 <= iVar3) {
    local_8 = local_8 << 6;
    do {
      iVar3 = *(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x74);
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      iVar1 = FUN_00578f7e();
      if (iVar3 <= iVar1) {
        iVar1 = (local_8 + iVar3) * 4 + 0x44;
        do {
          iVar2 = *(int *)(*(int *)(param_1 + 0x34) + iVar1);
          if (iVar2 != 0) {
            iVar2 = *(int *)(iVar2 + 0x48);
            if (iVar2 == 0) {
LAB_00578d5e:
              *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
            }
            else if ((&local_2c)[iVar2] == '\0') {
              (&local_2c)[iVar2] = '\x01';
              goto LAB_00578d5e;
            }
            *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
          }
          iVar3 = iVar3 + 1;
          iVar1 = iVar1 + 4;
          iVar2 = FUN_00578f7e();
        } while (iVar3 <= iVar2);
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x40;
      iVar3 = FUN_00578f6a();
    } while (local_c <= iVar3);
  }
  return;
}

