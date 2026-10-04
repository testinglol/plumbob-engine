
void __fastcall FUN_0041607b(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  char local_8;
  char local_7;
  char local_6;
  char local_5;
  
  FUN_00444cf9(&local_c,&local_10,&local_7,&local_8,&local_6,&local_14);
  iVar2 = FUN_0047b178(&local_5);
  if ((local_5 != '\0') || (local_5 = '\0', local_6 != '\0')) {
    local_5 = '\x01';
  }
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x10c) != 0) {
    puVar3 = (uint *)(*(int *)(param_1 + 0x10) + 0x138);
    *puVar3 = *puVar3 & 0xfffffffe;
    if (local_7 != '\0') {
      *puVar3 = *puVar3 | 1;
    }
    iVar1 = *(int *)(param_1 + 0x10);
    puVar3 = (uint *)(iVar1 + 0x138);
    *puVar3 = *puVar3 & 0xfffffffd;
    puVar3 = (uint *)(iVar1 + 0x138);
    if (local_8 != '\0') {
      *puVar3 = *puVar3 | 2;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0xa0) = local_c;
  *(int *)(*(int *)(param_1 + 0x20) + 0xa4) = iVar2 + local_10;
  FUN_0046dae0(0x17,*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10));
  FUN_0046dae0(0x16,local_5);
  FUN_0046dae0(0x25,local_14);
  return;
}

