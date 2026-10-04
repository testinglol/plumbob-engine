
void __thiscall FUN_004328f3(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xdc);
  uVar2 = 0;
  uVar3 = (uint)*(short *)(param_1 + 0x7e);
  if ((0 < (int)uVar3) && (uVar3 < (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U)) {
    uVar2 = *(undefined4 *)(*(int *)(iVar4 + 0x18) + -4 + uVar3 * 4);
  }
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  if ((((*(char *)(param_1 + 0xfc) < '\x01') ||
       (iVar4 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar4 <= *(char *)(param_1 + 0xfc))) ||
      (*(char *)(param_1 + 0xfd) < '\x01')) || (iVar4 <= *(char *)(param_1 + 0xfd))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  *(bool *)param_2 = !bVar1;
  *(int *)(param_2 + 0x10) = (int)*(short *)(param_1 + 0x66);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x110);
  return;
}

