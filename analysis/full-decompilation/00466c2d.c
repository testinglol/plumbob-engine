
void __thiscall FUN_00466c2d(int param_1,undefined4 param_2)

{
  ushort *puVar1;
  uint uVar2;
  int local_8;
  
  local_8 = param_1;
  FUN_0046913f(&local_8,&param_2);
  if (local_8 != *(int *)(param_1 + 4)) {
    puVar1 = *(ushort **)(local_8 + 0x14);
    *(undefined1 *)(puVar1 + 0x38) = 1;
    uVar2 = (*puVar1 & 0xc00) >> 10;
    if (uVar2 == 0) {
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
    }
    else if (uVar2 == 1) {
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 2;
    }
  }
  return;
}

