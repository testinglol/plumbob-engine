
void __fastcall FUN_00466c7b(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) == 0) {
    DAT_006c740c = 0x3f800000;
  }
  else {
    DAT_006c740c = 0x3f4ccccd;
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    iVar1 = *(int *)(iVar2 + 0x14);
    if (*(int *)(iVar1 + 0x34) != 0) {
      *(undefined1 *)(iVar1 + 0x70) = 1;
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  *(undefined4 *)(param_1 + 0x34) = 3;
  return;
}

